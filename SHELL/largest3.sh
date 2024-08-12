echo "ENTER THREE NOS: "
read x y z

if [ $x -gt $y ] && [ $x -gt $z ]
then
	echo "$x IS LARGEST"
	
elif [ $y -gt $z ]
then
	echo "$y IS LARGEST"
	
else
	echo "$z IS LARGEST"
fi
