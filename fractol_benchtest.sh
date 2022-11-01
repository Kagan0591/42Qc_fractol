#!/bin/bash

Black='\033[0;30m'        # Black
Red='\033[0;31m'          # Red
URed='\033[4;31m'         # Red
reset='\033[0m'           # Text Reset


FILE=fractol


if [[ ! -f "$FILE" ]];
then
	make re
fi

i=0
echo -e "${URed}Testing Fractol 10 times with the Mandelbrot set in argument without optionals args${reset}"
while [ $i -le '10' ]
do
	leaks --atExit -- ./fractol mandelbrot
	pkill -9 fractol
	((i+=1))
done


i=0
echo -e "${URed}Testing Fractol 10 times with the Julia set in argument without optionals args${reset}"
while [ $i -le '10' ]
do
	./fractol Julia
	pkill -9 fractol
	((i+=1))
done

xval=-0
yval=0
i=0
echo -e "${URed}Testing Fractol 10 times with the Julia set in argument and optionals arguments which increases by 0.8 each time.${reset}"
echo "The result is, at a certain point a more detailed fractal are draw because the less numbers of pixels colorized into high iteration situation."
while [ $i -le '12' ]
do
	leaks --atExit -- ./fractol julia $xval $yval
	pkill -9 fractol
	xval=$(echo "( $xval + 0.08 )" | bc -l); echo $xval
	yval=$(echo "( $yval - 0.08 )" | bc -l); echo $yval
	((i+=1))
done

xval=-2
yval=2
i=0
echo -e "${URed}Testing Fractol 10 times with the Julia set in argument and differents optionals arguments that ends up too far into x axis.${reset}"
echo "The result is, at a certain point no much pixel from the set are draw after the xval are exceed value of 2."
echo "We need to reduce numbers of iteration to see something because of the small quantity of pixels colorized in high iteration modele"
while [ $i -le '10' ]
do
	leaks --atExit -- ./fractol julia $xval $yval
	pkill -9 fractol
	xval=$(echo "( $xval - 0.1 )" | bc -l); echo $xval
	yval=$(echo "( $yval + 0.1 )" | bc -l); echo $yval
	((i+=1))
done

i=0
echo -e "${URed}Testing Fractol 5 times with no arguments filled.${reset}"
echo "Testing with : leaks --atExit -- ./fractol"
echo ""
while [ $i -le '5' ]
do
	leaks --atExit -- ./fractol
	pkill -9 fractol
	((i+=1))
	read -p "Hit a key to continue"
done

i=0
echo -e "${URed}Testing Fractol 5 times with bad arguments filled.${reset}"
echo "Testing with : leaks --atExit -- ./fractol mandel"
echo ""
while [ $i -le '5' ]
do
	leaks --atExit -- ./fractol mandel
	pkill -9 fractol
	((i+=1))
	read -p "Hit a key to continue"
done

i=0
echo -e "${URed}Testing Fractol 5 more times with bad arguments filled.${reset}"
echo "Testing with : leaks --atExit -- ./fractol juli 1 0.8"
echo ""
while [ $i -le '5' ]
do
	leaks --atExit -- ./fractol juli 1 0.8
	pkill -9 fractol
	((i+=1))
	read -p "Hit a key to continue"
done