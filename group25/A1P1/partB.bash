#  NAME: Xudong Li
#  NSID:xul395
#  Student Number:11206927

# 	NAME:Tong Wang   
#   NSID: tow087 
#   Student Number: 11201222
#   CMPT 332 Term 1 2019

#!/bin/bash

# Program:
# This is an interactive shell script that executes Parts A.1, A.2, A.3 or A.4 (bonus) according to the user's instructions
PATH="$PATH:/usr/bin:/bin"
export PATH
#echo $PATH
# Get the version information as the first command line args
partaVersion=$1
# if condition about the partaVersion
if [ $partaVersion = "A1" ]; then
	# partA1 run
	# check the OS first because A1 only can run on Windows
	OS="`uname -o`"
	if [ $OS = "Msys" ]; then
		#In windows system can run the program
		#Read the input by line
		while read line
		do
			#Check the input argument is leagl or not
			threadsNumber=`echo $line | awk '{if ((NF == 3)&&($1~/^[0-9]*$/)){print $1} else{print "NULL"}}'`
			deadlineTime=`echo $line | awk '{if ((NF == 3)&&($1~/^[0-9]*$/)){print $2} else{print "NULL"}}'`
			sizeNumber=`echo $line | awk '{if ((NF == 3)&&($1~/^[0-9]*$/)){print $3} else{print "NULL"}}'`
			echo $threadsNumber
			echo $deadlineTime
			echo $sizeNumber
			if [ $threadsNumber == "NULL" ]; then
				echo "Invalid input"

			else
				if [ $threadsNumber == "0" ]; then
					echo "See you!"
					break;
				else
					./partA1.exe $threadsNumber $deadlineTime $sizeNumber
					echo "If you want to quit please enter 0 0 0"
				fi
				#statements
			fi
		done

		 
	else
		echo "Wrong system"
		#Not in windows system
	fi
elif [ $partaVersion = "A2" ]; then
	#partA2 run
    echo "PartA2 no code right now"
elif [ $partaVersion = "A3" ] ; then
	#partA3 run
	echo "PartA3 no code right now"
elif [ $partaVersion = "A4" ] ; then
	#partA4 run
	echo "PartA4 no code right now"
else
	echo "I don't know your version choice, please enter the right version"
fi