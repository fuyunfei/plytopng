#include <cmath>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
extern "C" {
#include "propng.h"
}
using namespace std;

int main(int argc, char **argv)
{
        int width =960; 
	int height =960;
	float focal = 430;

        png_bytep * pr;
        pr=read_png_file(argv[1]);
 
  	string line;
  	ifstream myfile;
  	myfile.open ("1.ply");
 	for (int i=0;i<14;i++){
 	getline (myfile,line);
 	cout << line << '\n';
	}

 int i=0;
 for( string line;  getline(myfile, line); )
 {
     	std::istringstream in(line);      //make a stream for the line itself
      	float x, y, z;
	int r,g,b; 
	in>>x>>y>>z>>r>>g>>b;
	int xj=width/2-x*focal/z;
	int yj=height/2-y*focal/z;
	if (xj>width||xj<0||yj>width||yj<0){
	cout <<i<<" "<<xj<<" "<<yj<<endl;	
	}
	i++;
	png_byte* row = pr[xj];
	png_byte* ptr = &(row[yj*3]);
	ptr[0] = r;
	ptr[1] = g;
	ptr[2] = b;
}

     //   png_byte* row = row_pointers[y];

       write_png_file(argv[2],pr,width,height);

        return 0;
}
