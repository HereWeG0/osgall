#!/usr/bin/python
# -*- coding: cp936 -*-

import os
import sys
import string
import subprocess
from common import *


#�ڲ�·�� ��������ܻ��滻
VTK_DIR_NAME = "VTK-8.1.0.rc1"


#    
#�⽨�춨��
#

def build_VTK( str_target ):
    print "build VTK"
    my_make_build_dir( VTK_DIR_NAME , str_target )
    
    str_ops = ""

    if( BUILD_DYNAMIC_LINK_LIBRARY ):
        str_ops += " -DBUILD_SHARED_LIBS=1";
    else:
        str_ops += " -DBUILD_SHARED_LIBS=0";
        
    my_configure(str_target , str_ops)
    my_build(str_target)


    
#main    
def main():

    ALL_TARGET = "vc" #Ĭ��vc
    if len(sys.argv) >= 2:
        ALL_TARGET = sys.argv[1]
    print( ALL_TARGET )

        
    #
    build_VTK(ALL_TARGET)

main()
