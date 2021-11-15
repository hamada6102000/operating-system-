echo "welcome in the seventh program "
echo "please enter the number"
read num
n=$num
sum=0
counter=0
revers=0
while [ $n -gt 0 ]
do
      revers=$(($revers * 10))
      temp=$(($n % 10))
      revers=$(($revers + $temp))
      n=$(($n / 10 ))
done


while [ $num -gt 0 ]
do
      f=$(( $num % 10 ))
      num=$(( $num / 10 ))
      
      sum=$(($sum + $f ))
      
      counter=$(($counter + 1 ))
done
ave=$(echo "$sum / $counter" | bc -l)
echo "the reverse of $num is $revers  "
echo "the sum of digites $num is $sum"
echo "the average of digites $num is $ave"



