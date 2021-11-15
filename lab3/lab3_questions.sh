echo "first project "
for ((i=0; i<=14 ;i++)) 
do
x=$(($i * $i))
echo "the squre = $x"
sleep 1
done


echo "second project "
echo "enter the two number"
read n1
read n2
sum=0
for ((z=1; z<=n2 ;z++)) 
do
sum=$(($n1 + $sum))
done
echo "product = $sum"


echo "third project "
echo "enter the number "
read n
b=$(($n % 2))
if [ $b -eq 0 ]
then
echo "the number is even  "
else
echo "the number is odd "
fi

