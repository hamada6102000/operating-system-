echo "welcome in the fifth program "
echo "please enter the integer number "
read int_number
temp=$(($int_number % 2))
temp1=$(($int_number % 3))
if [ $int_number -eq 2 ] || [ $int_number -eq 3 ] 
then 
echo " the number $int_number is prime number "
elif [ $temp -eq 0 ] || [ $temp1 -eq 0 ]
then
echo "the number $int_number is not prime number"
else
echo "the number $int_number is prime number"
fi


