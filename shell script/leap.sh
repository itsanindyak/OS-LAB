read -p "enter year:" x
if [ $((x%100)) -eq 0 -a $((x%400)) -eq 0 ]
then
    echo "leap year"
elif [ $((x%100)) -ne 0 -a $((x%4)) -eq 0 ] 
then
    echo "leap year"
else
    echo "not lp"  
fi      
