n=4
for ((i=0;i<n;i++))
do
    num=1
    for (( j=0;j<=i;j++))
    do
        echo -n "$num "
        num=$((num * 2))
    done
    echo
done
