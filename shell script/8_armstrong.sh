
armstrong(){
    num=$1
    count=${#num} #count chaarcter
    ref=$num
    sum=0
    while [ $ref -ne 0 ]
    do
        reminder=$((ref%10))
        term=$(echo "$reminder^$count" | bc )
        sum=$((sum+term))
        ref=$((ref/10))
    done

    if [ $num -eq $sum ]; then
        echo "$num is Armstrong"
    else
        echo "$num is not Armstrong" 
    fi
} 

for i in "$@"
do
    armstrong $i >> "armstrong.txt"
done