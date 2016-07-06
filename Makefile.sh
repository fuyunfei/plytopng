gcc -c -o propng.o propng.c -lm -lpng -lstdc++ 
g++ -c -o pngply.o pngply.cc  -lm -lpng -lstdc++ 
g++ -o main propng.o pngply.o -lm -lpng -lstdc++ 
