#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

//#include "LineSegment.h"
//#include "Point.h"
//#include "Triangle.h"

using namespace std;

int main(int argc, char **argv) {

    string line;
    ifstream infile;
    infile.open ("../resources/Strecken_1000.txt");
    int a=0;
     string previousLine="";
     while(a<1) // To get you all the lines.
     {
         getline(infile,line); // Saves the line in STRING.
         if (line != "")
         {
             previousLine=line;
             cout<<line<<endl; // Prints our STRING.
         }else{
        	 a=1;
         }

     }
     infile.close();

}
