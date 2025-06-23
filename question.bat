::(1)write a shell script to read n numbers as command arguments and sort them in decending order*/
echo "Enter n numbers: "
numbers=()
for (( i=0; i<$count; i++ ))
do
  echo "Enter number $((i+1)):"
  read num
  numbers+=("$num")
done
printf "%s\n" "${numbers[@]}" | sort -nr
------------------------------------------------------------
[2021ict89@fedora ~]$ vi pract.sh
[2021ict89@fedora ~]$ chmod 777 pract.sh
[2021ict89@fedora ~]$ ./pract.sh
How many numbers do you want to enter?
4
Enter number 1:
12
Enter number 2:
5
Enter number 3:
87
Enter number 4:
36
87
36
12
5

=========================================================================================================================================================================================
::(2)write a shell script to generate a marksheet of a student. take 3 subjects, calculate and diplay the total marks,average and grades of each subject obtained by the studnets*/
echo "Enter student's name:"
read name

echo "Enter marks for Subject 1:"
read sub1
echo "Enter marks for Subject 2:"
read sub2
echo "Enter marks for Subject 3:"
read sub3

# Calculate total and average
total=$((sub1 + sub2 + sub3))
average=$((total / 3))

# Function to assign grade
get_grade() {
  if [ $1 -ge 90 ]; then
    echo "A+"
  elif [ $1 -ge 80 ]; then
    echo "A"
  elif [ $1 -ge 70 ]; then
    echo "B"
  elif [ $1 -ge 60 ]; then
    echo "C"
  elif [ $1 -ge 50 ]; then
    echo "D"
  else
    echo "F"
  fi
}

# Assign grades
grade1=$(get_grade $sub1)
grade2=$(get_grade $sub2)
grade3=$(get_grade $sub3)

# Display the marksheet
echo ""
echo "====== Student Marksheet ======"
echo "Name       : $name"
echo "Subject 1  : $sub1 (Grade: $grade1)"
echo "Subject 2  : $sub2 (Grade: $grade2)"
echo "Subject 3  : $sub3 (Grade: $grade3)"
echo "Total      : $total"
echo "Average    : $average"
echo "==============================="

------------------------------------------------------------

[2021ict89@fedora ~]$ vi pract.sh
[2021ict89@fedora ~]$ chmod 777 pract.sh
[2021ict89@fedora ~]$ ./pract.sh
Enter student's name:
Tikku
Enter marks for Subject 1:
56
Enter marks for Subject 2:
87
Enter marks for Subject 3:
90

====== Student Marksheet ======
Name       : Tikku
Subject 1  : 56 (Grade: D)
Subject 2  : 87 (Grade: A)
Subject 3  : 90 (Grade: A+)
Total      : 233
Average    : 77
===============================

=========================================================================================================================================================================================
::(3)write a shell to display the multiplication table of a given number*/
echo "Enter a number"
read num
echo "Multiplication Table of $num"
for((i=1;i<=12;i++))
do
mul=$(($i*$num))
echo "$i x $num = " $mul
done
------------------------------------------------------------

[2021ict89@fedora ~]$ vi pract.sh
[2021ict89@fedora ~]$ chmod 777 pract.sh
[2021ict89@fedora ~]$ ./pract.sh
Enter a number
6
Multiplication Table of 6
1 x 6 =  6
2 x 6 =  12
3 x 6 =  18
4 x 6 =  24
5 x 6 =  30
6 x 6 =  36
7 x 6 =  42
8 x 6 =  48
9 x 6 =  54
10 x 6 =  60
11 x 6 =  66
12 x 6 =  72

=========================================================================================================================================================================================
::(4)write a shell to find the factorial of a given number n*/
fact=1
echo "Enter the number: "
read num
 for((i=num;i>=1;i--))
 do
    fact=$(($fact*$i))	
done
echo $fact
------------------------------------------------------------

[2021ict89@fedora ~]$ vi pract.sh
[2021ict89@fedora ~]$ chmod 777 pract.sh
[2021ict89@fedora ~]$ ./pract.sh
Enter the number:
7
5040

=========================================================================================================================================================================================
::(5)write a script to find whether the given year is a leap year or not n*/
echo "Enter a year:"
read year

# Leap year logic:
# 1. Divisible by 4
# 2. Not divisible by 100, unless divisible by 400

if (( year % 4 == 0 )); then
  if (( year % 100 == 0 )); then
    if (( year % 400 == 0 )); then
      echo "$year is a leap year."
    else
      echo "$year is not a leap year."
    fi
  else
    echo "$year is a leap year."
  fi
else
  echo "$year is not a leap year."
fi
------------------------------------------------------------

[2021ict89@fedora ~]$ vi pract.sh
[2021ict89@fedora ~]$ chmod 777 pract.sh
[2021ict89@fedora ~]$ ./pract.sh
Enter a year:
2014
2014 is not a leap year.
[2021ict89@fedora ~]$ ./pract.sh
Enter a year:
2004
2004 is a leap year.

=========================================================================================================================================================================================
::(6)write a script to wish for a birthday if the current date and month are the same as the date of birth recieved from the user n*/
# Get current day and month
current_day=$(date +%d)
current_month=$(date +%m)

# Ask user for birth date and month
echo "Enter your birth day (dd):"
read birth_day

echo "Enter your birth month (mm):"
read birth_month

# Check if today is their birthday
if [ "$birth_day" -eq "$current_day" ] && [ "$birth_month" -eq "$current_month" ]; then
  echo "🎉 Happy Birthday! 🎂 Hope you have a wonderful day! 🎈"
else
  echo "Today is not your birthday, but hope you have a great day anyway!"
fi
------------------------------------------------------------
[2021ict89@fedora ~]$ vi pract.sh
[2021ict89@fedora ~]$ chmod 777 pract.sh
[2021ict89@fedora ~]$ ./pract.sh
Enter your birth day (dd):
28
Enter your birth month (mm):
07
Today is not your birthday, but hope you have a great day anyway!
[2021ict89@fedora ~]$ ./pract.sh
Enter your birth day (dd):
23
Enter your birth month (mm):
06
🎉 Happy Birthday! 🎂 Hope you have a wonderful day! 🎈
