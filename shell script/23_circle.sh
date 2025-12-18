r=5


for (( i =0; i< 360; i=i+5 ))
do
    th=$(echo "scale=5; 3.14*180*$i" | bc -l )

    ix=$( echo "scale=3; $r * s($th)" | bc -l | awk '{print int($1)}' )
    iy=$( echo "scale=3; $r * c($th)" | bc -l | awk '{print int($1)}' )

    x=$((ix+20))
    y=$((iy+20))

    tput cup "$x" "$y"
    echo '*'
done
# tput cup 
