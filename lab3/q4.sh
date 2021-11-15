echo "welcome in the fourth program "
echo "please enter the number and the power "
read number
read power
mult=1
for ((i=1; i<=power ;i++)) 
do
mult=$(($number * $mult))
done
echo "product = $mult"

