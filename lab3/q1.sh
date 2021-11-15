echo "welcome in the first program "
echo "please enter the seconds"
read second 
hours=$(($second / 3600))
minute=$(((($second) - ($hours * 3600)) / 60))
second=$(( ($second) - (($hours * 3600) + ($minute * 60)) ))
echo "the time is $hours hour : $minute minute : $second second "


