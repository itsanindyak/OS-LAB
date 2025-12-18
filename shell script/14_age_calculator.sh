
read -p "Enter birthday in dd/mm/yyyy format : " dob

d=$(echo $dob | cut -d/ -f1)
m=$(echo $dob | cut -d/ -f2)
y=$(echo $dob | cut -d/ -f3)

tday=$(date "+%d")
tmonth=$(date "+%m")
tyear=$(date "+%Y")

dt=$((tday-d))
dm=$((tmonth-m))
dy=$((tyear-y))

if [ $dt -lt 0 ]; then
    dt=$((dt+30))
    dm=$((dm-1))
fi

if [ $dm -lt 0 ]; then
    dm=$((dm+12))
    dy=$((dy-1))
fi

echo "Age = $dy years $dm month $dt days "