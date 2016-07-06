#include <cmath>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Core>
extern "C" {
#include "propng.h"
}
using namespace std;
 using namespace Eigen;

int main(int argc, char **argv)
{
    int width =960;
	int height =960;
	float focal = 595;

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
      	float x, y, z,px,py,pz;
	int r,g,b; 
	in>>x>>y>>z>>r>>g>>b;
	MatrixXf P(4,1),PRT(4,1);
	MatrixXf RT(3,4);
	P<<x,y,z,1.0;
	RT<<0.999897,-0.010837,0.009367,0.189848,
	0.010407,0.998942,0.044801,0.067492,
	-0.009843, -0.044699 ,0.998952,-0.992342;
	PRT=RT*P;
	px=PRT(0,0);
	py=PRT(1,0);
	pz=PRT(2,0);
	
	int xj=width/2-px*focal/pz;
	int yj=height/2-py*focal/pz;
	if (xj>width-10||xj<0||yj>width-10||yj<0){
	cout <<i<<" "<<xj<<" "<<yj<<endl;	
	}else{
	i++;
	png_byte* row = pr[xj];
	png_byte* ptr = &(row[yj*3]);
	ptr[0] = r;
	ptr[1] = g;
	ptr[2] = b;
	}
}

     //   png_byte* row = row_pointers[y];

       write_png_file(argv[2],pr,width,height);

        return 0;
}
