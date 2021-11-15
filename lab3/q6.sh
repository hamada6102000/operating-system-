echo "welcome in the sixth program "
sum=0
flag=1
counter=0
while [ $flag -eq 1 ]
do
echo "please enter the positive number "
read positive_number
if [ $positive_number -gt 0 ]
then
sum=$(($positive_number + $sum))
counter=$(($counter + 1))
elif   [ $positive_number -lt 0 ]
then
echo "ERROR "
else
if [ $counter -eq 0 ]
then
echo " NO AVERAGE "
fi
flag=0
fi
done
if [ $sum -ne 0 ] && [ $counter -ne 0 ] 
then

average=$(echo "$sum / $counter" | bc -l)
echo "the average = $average "
fi

