֧�ֻ����汾
    [���һ������汾��������]
    cmake ndk-10e
    standalone ndk-10e
    standalone vs 2013 64bit
    cmake vs 2013 64bit
    mingw w64
    vs 2015 32bit
    
��֪�İ汾����
    ��vs1015 64bit�ϱ������
        libxml
        leveldb
        osgbullet
        
����˳��
    prebuild_ffmpeg (�� prebuild_osg ֮ǰ)
    prebuild_opencv (����ffmpeg)
    prebuild_boost
    prebuild
    prebuild_osg
    prebuild_osgbullet
    prebuild_osgearth
    prebuild_vtk
    prebuild_pcl
    
������Ԥ����[cmake]

    windows-vc:
        ����vcvarsall.bat
        �޸�common.py�е�cmake·��
        ����python.exe prebuild.py vc
        (�ļ��Զ���װ��3rdpartyĿ¼)
        
    windows-mingw:
        ����msys.bat(��Ҫ��װwin32�汾�� cmake python2)
        �޸�common.py�е�cmake·��
        ����python.exe prebuild.py mingw
        (�ļ��Զ���װ��3rdpartyĿ¼)
        
    windows-ndk:
        (��װNDK������Ŀ¼)
        ����msys
        ���û������� export ANDROID_NDK=/d/android-ndk-r10d
        �޸�common.py�е�cmake·��
        ����prebuild.py ndk
        (���ɵ��ļ������ABI���ƶ�Ӧ��Ŀ¼�У�������Ϊ��׼�Ⲣ��֧��obj/loacl/ABI·��������Ҫ�ֹ�������)

        
������Ԥ����[��cmake]

    boost(�޷�cmake����)
        vc�汾��
            �޸�common.py�е�������Ϣ
            ��vc����̨ ����prebuild_boost.py vc
        
    ffmpeg+x264(�޷�cmake����)
    
        mingw-dll:
            (widnows��ֻ����mingw����dll��ʽ �ֹ�����h��dll����)
            (ע��wrt�汾 Ŀǰ321�汾�Ǵ���� ֻ��ʹ��320-2)
            (����64bit�汾 �ɰ�װmingw w64 Ȼ���޸�fstab�ļ��ڵ� /mingw���ص�  ·��������/�޿ո�)
            ���밲װyasm(32 64���ݻ����Զ�ʶ��)
                ./configure
                make install
            ���밲װx264 static�汾 ��֪��ΪʲôֻҪ����/usr/local/lib·������ʾ�Ҳ���libx264
                ��32bit��
                ./configure --enable-static --enable-shared
				make install
                ��64bit��
                ./configure --prefix=/mingw --enable-win32thread --host=x86_64-w64-mingw32 --enable-static --enable-shared 
				make install
			python prebuild_ffmpeg vc

        ����gcc������
            ֱ�Ӿ�̬���밲װ��ȫ�Զ���
            
        android�汾
            mingw������루��ȷ���Ƿ������mingw32��
            ����Ϊֻ��ʹ��ndk��toolchian���룬���Զ��arch�汾�޷�ͬʱ�������ã�
            �޸�һ�� common.py setup_ndk_standalone.sh �ű��е� ndk·�� api�汾 arch �������汾
            ����һ��������:
                python make_ndk_standalone.py      �ڸ�����������ʱ�����Ҫ����ִ��(��ҪϵͳȨ�� ��Ϊtmp��c�� �п�����Ҫִ������ ��ΪĿ¼���ڹ�ϵ������)
                source setup_ndk_standalone.sh     �趨������Ҫ�Ļ�������
                python prebuild_ffmpeg.py ndk      ִ�б���  �ں�x264����

            ndk-10e ֮��İ汾���޷�ͨ��
            
��Ŀ����
    ��Ϊ��԰�׿�����ĳ���ֻ����һ����� ������Ŀ�ǰ����������ֵ�
    build.py vc test_cube(��Ŀ����)
    
    
codework��cmake�������뷽ʽ
    1 ����vs������
    2 set ANDROID_NDK=d:\NVPACK\android-ndk-r10e
    3 "C:\Program Files (x86)\CMake\bin\cmake.exe" -DCMAKE_TOOLCHAIN_FILE=..\android.toolchain.cmake -G "Visual Studio 11 2012" ..

    