# Tong Wang tow087 11201222

#!/bin/bash
OS="`uname -o`"
if [ $OS = "Msys" ];
then
	./thread_windows.exe 7
elif [ $OS = "GNU/Linux" ];
then
	./sample-linux 2

fi
