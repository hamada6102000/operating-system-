echo "welcome in the third program "
echo "please enter the salary "
read salary
if [ $salary -gt 2000 ]
then 
tax=$((($salary * 15) / (100)))
salary=$(($salary - $tax))
echo " the net salary after tax reductior is $salary"
elif [ $salary -ge 1000 ] && [ $salary -lt 2000 ]
 then 
tax=$((($salary * 10) / (100)))
salary=$(($salary - $tax))
echo " the net salary after tax reductior is $salary"
else
echo "the salary still $salary no tax "
fi


