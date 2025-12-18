
prime(){
    num=$1

    if [ "$num" -lt 2 ]; then
        return
    fi
    
    if [ "$num" -eq 2 ]; then
        echo "$num "
        return
    fi

    if [ $((num%2)) -eq 0 ]; then
        return
    fi

    for (( i =3; i*i <= num ;i=i+2 ))
    do
        reminder=$((num % i))

        if [ $((num % i)) -eq 0 ]; then
            return
        fi
    done

    echo "$num "

}

read -p "Lower range : " lo
read -p "Upper range : " up

echo "Prime numbers are:"
for (( j=lo; j<=up; j++ ))
do
    prime $j
done
