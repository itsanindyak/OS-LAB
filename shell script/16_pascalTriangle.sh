
n=7

for (( i=0;i<n;i++))
do
    num=1

    for (( s=0; s< n-i; s++ ))
    do
        echo -n " "
    done

    for (( j=0; j<=i; j++ ))
    do
        echo -n "$num "
        num=$(( num * (i - j) / (j + 1) ))
    done
    echo
    
done