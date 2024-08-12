echo "ENTER A NO: "
read n

r=$((n % 2))

if [ $r -eq 0 ]
then
	echo "$n IS EVEN"
else
	echo "$n IS ODD"
fi
