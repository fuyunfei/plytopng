gcc -c -o propng.o propng.c -lm -lpng -lstdc++ 
g++ -c -o pngply.o pngply.cc -I /usr/include/eigen3/  -lm -lpng -lstdc++ 
g++ -o main propng.o pngply.o -I /usr/include/eigen3/ -lm -lpng -lstdc++ 
