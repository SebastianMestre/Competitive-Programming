
./gen > /tmp/casito.in
./bruto < /tmp/casito.in > /tmp/casito.ans
./m < /tmp/casito.in > /tmp/casito.out

if diff /tmp/casito.out /tmp/casito.ans
then
	cat /tmp/casito.in
	c
fi
