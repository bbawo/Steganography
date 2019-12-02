#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <stdlib.h>
#include "image.h"

void read(std::string, image &);
int main()
{
    image obj1;
    read("image1.ppm", obj1);


 std::cout << "Filetype : " << obj1.getFiletype() << "\nComment : " << obj1.getComment() << "\nWidth = " << obj1.getwidth() << "    Height = " << obj1.getHeight() << "\nMax color = " << obj1.getMax_color() << std::endl;
 std::cout << "size of image = " << sizeof obj1  << "\nsize of main = " << sizeof main()<< std::endl;


for(int i = 0; i < obj1.getHeight(); i++)
   {
      for(int j = 0; j < obj1.getwidth(); j++)
      {
          std::cout << "(";
         for(int k = 0; k < 3; k++)
         {
            std::cout  << obj1.getPixel()[i][j][k] << " " ;
         }
        std::cout <<  ")   ";
      }
      std::cout << std::endl;
   }
 return 0;
}

void read(std::string filename, image &f1)
{
   std::vector<std::vector<std::vector<int>>> tempfile1;
   std::vector<std::vector<int>> tempfile2;
   std::vector<int> tempfile3;
   std::string line;

   std::ifstream   readfile(filename);

   std::getline(readfile, line);
   f1.setfiletype(line);

   std::getline(readfile, line);
   f1.setcomment(line);

   std::getline(readfile, line, ' ');
   f1.setWidth(atoi(line.c_str()));

   std::getline(readfile, line);
   f1.setHeight(atoi(line.c_str()));

   std::getline(readfile, line);
   f1.setMax_color(atoi(line.c_str()));

   for(int i = 0; i < f1.getHeight(); i++)
   {
      for(int j = 0; j < f1.getwidth(); j++)
      {
         for(int k = 0; k < 3; k++)
         {
            std::getline(readfile, line);
            tempfile3.push_back(atoi(line.c_str()));
         }
         tempfile2.push_back(tempfile3);
         tempfile3.clear();
      }
      tempfile1.push_back(tempfile2);
      tempfile2.clear();
   }
   f1.setPixel(tempfile1);
}
