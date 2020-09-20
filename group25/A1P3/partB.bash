#  NAME: Xudong Li
#  NSID:xul395
#  Student Number:11206927

# 	NAME:Tong Wang   
#   NSID: tow087 
#   Student Number: 11201222
#   CMPT 332 Term 1 2019
#   group25

#!/bin/bash

# Program:
# This is an interactive shell script that executes Parts A.1, A.2, A.3 or A.4 (bonus) according to the user's instructions
# Get the version information as the first command line args
partaVersion=$1
OS="`uname -o`"
# if condition about the partaVersion
if [ $partaVersion = "A1" ]; then
	# partA1 run
	# check the OS first because A1 only can run on Windows
	# if OS equals Msys it means it is Winows
	# uname -o is check operating system	
	if [ $OS = "Msys" ]; then
		#In windows system can run the program
		#Read the input by line
		echo "This is partA1. Please enter the correct input." 
		echo "The input should be 3 positive integer divided by space." 
		echo "The order is threadNumber deadlineTime sizeNumber "
		echo "Also you could have a input txt file. Every line contains those three input parameters"
		echo "The order is same with the enter order "
		while read line
		do
			#Check the input argument is leagl or not
			#Using awk to check whether the input is 3 positive 
			#integer or not and then assign them into correct
			#parameter
			threadsNumber=`echo $line | awk '{if ((NF == 3)&&($1~/^[0-9]*$/)){print $1} else{print "NULL"}}'`
			deadlineTime=`echo $line | awk '{if ((NF == 3)&&($1~/^[0-9]*$/)){print $2} else{print "NULL"}}'`
			sizeNumber=`echo $line | awk '{if ((NF == 3)&&($1~/^[0-9]*$/)){print $3} else{print "NULL"}}'`
			#echo $threadsNumber
			#echo $deadlineTime
			#echo $sizeNumber
			if [ $threadsNumber == "NULL" ]; then
				echo "Invalid input"

			else
				if [ $threadsNumber == "0" ]; then
					echo "See you!"
					break;
				else
					./partA1.exe $threadsNumber $deadlineTime $sizeNumber
					echo "Please enter threadNumber deadlineTime sizeNumber"
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
    if [ $OS = "GNU/Linux" ]; then
		#In windows system can run the program
		#Read the input by line
		echo "This is partA2. Please enter the correct input." 
		echo "The input should be 3 positive integer divided by space." 
		echo "The order is threadNumber deadlineTime sizeNumber "
		echo "Also you could have a input txt file. Every line contains those three input parameters"
		echo "The order is same with the enter order "
		while read line
		do
			#Check the input argument is leagl or not
			#Using awk to check whether the input is 3 positive 
			#integer or not and then assign them into correct
			#parameter
			threadsNumber=`echo $line | awk '{if ((NF == 3)&&($1~/^[0-9]*$/)){print $1} else{print "NULL"}}'`
			deadlineTime=`echo $line | awk '{if ((NF == 3)&&($1~/^[0-9]*$/)){print $2} else{print "NULL"}}'`
			sizeNumber=`echo $line | awk '{if ((NF == 3)&&($1~/^[0-9]*$/)){print $3} else{print "NULL"}}'`
			if [ $threadsNumber == "NULL" ]; then
				echo "Invalid input"

			else
				if [ $threadsNumber == "0" ]; then
					echo "See you!"
					break;
				else
					./partA2 $threadsNumber $deadlineTime $sizeNumber
					echo "Please enter threadNumber deadlineTime sizeNumber"
					echo "If you want to quit please enter 0 0 0"
				fi
				#statements
			fi
		done

		 
	else
		echo "Wrong system"
		#Not in windows system
	fi
elif [ $partaVersion = "A3" ] ; then
	#partA3 run
	echo "PartA3 no code right now"
elif [ $partaVersion = "A4" ] ; then
	#partA4 run
	echo "PartA4 no code right now"
else
	echo "I don't know your version choice, please enter the right version"
fi
