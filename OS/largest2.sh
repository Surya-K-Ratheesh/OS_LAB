echo "ENTER A NO: "
read n

fact=1
i=$n

while [ $i -ge 1 ]
do
	fact=$((fact * i))
	i=$((i - 1))
done

echo "FACTORIAL OF $n IS $fact"
