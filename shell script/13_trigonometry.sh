
read -p "Enter the redian value" r

sin=$(echo "scale=3; s($r)" | bc -l )
cos=$(echo "scale=3; c($r)" | bc -l )
tan=$(echo "scale=3; s($r)/c($r)" | bc -l )

echo "sin($r)=$sin"
echo "cos($r)=$cos"
echo "tan($r)=$tan"