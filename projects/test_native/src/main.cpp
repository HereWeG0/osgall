
#include "myNativeApp.h"

#include <osg/PositionAttitudeTransform>
#include <osg/ShapeDrawable>
#include <osg/Shape>
#include <osg/MatrixTransform>
#include <osgDB/ReadFile>
#include <osgDB/WriteFile>
#include <osgViewer/Viewer>
#include <osgViewer/ViewerEventHandlers>
#include <osgGA/StateSetManipulator>

#if 1
#include <osgText/String>
#include <osgText/Text>
class myTextNode
{
public:
	myTextNode(const osg::Vec3& pos)
	{
		mPAT = new osg::PositionAttitudeTransform();
		mGeode = new osg::Geode();
		mText = new osgText::Text();
		mGeode->addDrawable(mText);
		mPAT->addChild(mGeode);
		mPAT->setPosition(pos);


        mText->setCharacterSize(24);
        mText->setCharacterSizeMode(osgText::Text::SCREEN_COORDS);
	}

	osg::PositionAttitudeTransform* mPAT;
	osg::Geode* mGeode;
	osgText::Text* mText;
};
#endif

//ʵ��ִ�е�APP����
class myAPP
    :public myNativeApp
{
public:

    myAPP()
    {
        r = 0.0;
    }
    virtual ~myAPP(){}
    
    float r;
    osg::ref_ptr<osg::MatrixTransform> mt;

    //GL��ʼ�� ��Ϣ
    virtual void onGLCreate( int x,int y,int width,int height )
    {
        _viewer = new osgViewer::Viewer();
        _viewer->setUpViewerAsEmbeddedInWindow(x, y, width, height);
        _viewer->realize();
        
        
        //std::cout << "osgCg "<< osgCgGetVersion() << "\n";

        //setup viewer
        //osgViewer::Viewer viewer;
        osg::Group* root = new osg::Group();
        _viewer->setSceneData(root);
        //viewer.setLightingMode(osg::View::NO_LIGHT);

        _viewer->getCamera()->setClearColor( osg::Vec4(1,0,1,1));
        _viewer->setThreadingModel(osgViewer::Viewer::SingleThreaded);


        //BOX
        osg::ShapeDrawable* sd = new osg::ShapeDrawable(
            new osg::Box(osg::Vec3(0,0,0),1.0));
        osg::Geode* geode = new osg::Geode();
        geode->addDrawable(sd);
        //root->addChild(geode);

        mt = new osg::MatrixTransform();
        mt->addChild(geode);
        root->addChild(mt);


    #if 1
        //load font
        //osgText::Font* font = osgText::readFontFile("../data/_osgxi/_font/msyh.ttf");


        //HUD
        osg::Camera* hud = new osg::Camera();
        hud->setReferenceFrame(osg::Camera::ABSOLUTE_RF);
        hud->setProjectionMatrixAsOrtho(0,640,0,480,-1,1);
        hud->setClearMask(GL_DEPTH_BUFFER_BIT);
        hud->getOrCreateStateSet()->setMode(GL_LIGHTING,false);
        root->addChild(hud);

        //////////////////////////////////////////////////////////////////////////
        //������ʾ�����ֽӿ� �����ֿ��У�
        //////////////////////////////////////////////////////////////////////////

        myTextNode* MTN_01 = new myTextNode(osg::Vec3(0,24*0,0));
        //MTN_01->mText->setFont(font);
        MTN_01->mText->setText("01_ABC������ʾ123 wchar_t");
        hud->addChild(MTN_01->mPAT);

        myTextNode* MTN_02 = new myTextNode(osg::Vec3(0,24*1,0));
        //MTN_02->mText->setFont(font);
        MTN_02->mText->setText("02_ABC������ʾ123 std::string + ENCODING");
        hud->addChild(MTN_02->mPAT);

        myTextNode* MTN_03 = new myTextNode(osg::Vec3(0,24*2,0));
        //MTN_03->mText->setFont(font);
        MTN_03->mText->setText(std::string("03_ABC������ʾ123 std::string"));//����ӿ�ò���޷�ʵ������������ʾ
        hud->addChild(MTN_03->mPAT);

        myTextNode* MTN_04 = new myTextNode(osg::Vec3(0,24*3,0));
        osgText::String osgStr("04_ABC������ʾ123");
        //MTN_04->mText->setFont(font);
        MTN_04->mText->setText(osgStr);
        hud->addChild(MTN_04->mPAT);

    #endif



        // add the state manipulator
        _viewer->addEventHandler( new osgGA::StateSetManipulator(_viewer->getCamera()->getOrCreateStateSet()) );
        // add the stats handler
        _viewer->addEventHandler(new osgViewer::StatsHandler);
    
    }
    
    //GL���� ��Ϣ
    virtual void onGLDistroy()
    {
    }
    
    //GL���� ��Ϣ
    virtual void onGLDraw()
    {
#if 0
        // Just fill the screen with a color.
        glClearColor(
            ((float)this->state.x)/this->width
            , this->state.angle
            ,((float)this->state.y)/this->height
            , 1);
        glClear(GL_COLOR_BUFFER_BIT);
#endif
        
        r += 1.0;
        mt->setMatrix(
            osg::Matrix::rotate(osg::DegreesToRadians(r),osg::Vec3(0,1,0))
            * osg::Matrix::translate(0,0,-3)
            );
            
        _viewer->frame();
    }
    
    osg::ref_ptr<osgViewer::Viewer> _viewer;
};


/**
 * This is the main entry point of a native application that is using
 * android_native_app_glue.  It runs in its own thread, with its own
 * event loop for receiving input events and doing other things.
 */
void android_main(struct android_app* state) 
{
    // Make sure glue isn't stripped.
    app_dummy();
    
    //����APP����
    myAPP engine;
    engine.Create(state);
    
    //����
    engine.run();
}
//END_INCLUDE(all)
