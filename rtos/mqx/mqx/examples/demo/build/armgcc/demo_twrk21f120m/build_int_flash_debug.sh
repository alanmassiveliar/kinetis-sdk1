#!/usr/bin/env bash
(cd  ../../../../../build/armgcc/mqx_twrk21f120m && source build_debug.sh nopause) 
(cd  ../../../../../../mqx_stdlib/build/armgcc/mqx_stdlib_twrk21f120m && source build_debug.sh nopause) 
(cd  ../../../../../../../../lib/ksdk_mqx_lib/armgcc/K21FA12 && source build_debug.sh nopause) 
cmake -DCMAKE_TOOLCHAIN_FILE=armgcc.cmake -DCMAKE_BUILD_TYPE="int flash debug" -G "Unix Makefiles" 
make all 
if [ "${1}" != "nopause" ]; then
read -p "Press any key to continue... " -n1 -s
fi
