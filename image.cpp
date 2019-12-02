#include "image.h"
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <string>
#include <bitset>

std::string image::colors [3] = {"Red", "Green", "Blue"};

image::image(std::string filename)
{
    std::vector<std::vector<int>> tempfile2;
    std::vector<int> tempfile3;
    std::string line;

    std::ifstream read(filename);

    if(read)
    {
       std::getline(read, line);  //Filetype
       setfiletype(line);
       int ptrPos = read.tellg();
       std::getline(read, line); //comment
       setcomment(line);
       std::getline(read, line, ' ') ; // Width
       setWidth(atoi(line.c_str()));
       std::getline(read, line) ; // Height
       setHeight(atoi(line.c_str()));
       std::getline(read, line);   //Max_color
       setMax_color(atoi(line.c_str()));

       for(int i = 0; i < getHeight(); i++)
       {
           for(int j = 0; j < getwidth(); j++)
           {
               for(int k = 0; k < 3; k++)
               {
                   std::getline(read, line);
                   tempfile3.push_back(atoi(line.c_str()));
               }
            tempfile2.push_back(tempfile3);
            tempfile3.clear();
            }
        pixel.push_back(tempfile2);
        tempfile2.clear();
        }
    }
    std::cout << "Reading in from " << filename << " of size "
            << height << " by " << width  << std::endl;
}
void image::setfiletype(std::string new_filetype)
{
    filetype = new_filetype;
}

void image::setcomment(std::string new_comment)
{
    comment = new_comment;
}

void image::setWidth(int new_width)
{
    width = new_width;
}

void image::setHeight(int new_height)
{
    height = new_height;
    pixel.reserve(height);
}

void image::setMax_color(int new_Max_color)
{
    max_color = new_Max_color;
}

void image::EditComment(const std::string &myName)
{
    comment.replace(2, 7, myName);
}

std::string image::getFiletype() const
{
   return filetype;
}

std::string image::getComment() const
{
   return comment;
}

int image::getMax_color() const
{
   return max_color;
}

int image::getwidth() const
{
   return width;
}

int image::getHeight() const
{
   return height;
}

std::vector<std::vector<std::vector<int>>> image::getPixel() const
{
    return pixel;
}

std::string image::hashValue()
{
   int evensAndOdds[6] = {0};
   std::string hash = "";

  for ( int i = 0;  i < height; i++ ){
    for ( int j = 0;  j < width; j++ ){
      for ( int color_index = 0;  color_index < 3; color_index++ ){
        if( color_index == 0 && (pixel[i][j][color_index] % 2) == 0 ){
          evensAndOdds[0] += pixel[i][j][color_index] ; // counting evenReds
        }
        else if ( color_index == 0 && (pixel[i][j][color_index] % 2) == 1 ){
          evensAndOdds[1]+= pixel[i][j][color_index] ; // counting oddReds
        }
        else if ( color_index == 1 && (pixel[i][j][color_index] % 2) == 0 ){
          evensAndOdds[2]+= pixel[i][j][color_index] ;  //counting evenGreens
        }
        else if ( color_index == 1 && (pixel[i][j][color_index] % 2) == 1 ){
          evensAndOdds[3]+= pixel[i][j][color_index] ;  //counting oddGreens
        }
        else if ( color_index == 2 && (pixel[i][j][color_index] % 2) == 0 ){
          evensAndOdds[4]+= pixel[i][j][color_index] ;  //counting evenBlues
        }
        else
          evensAndOdds[5]+= pixel[i][j][color_index] ;  //counting oddBlues
        }
      }
    }
    for(int x = 0; x < 6; x++)
    hash = hash + char(evensAndOdds[x]%26+65);

    return hash;
}

std::string image::decoding()
{
std::string message , chunk = "";
char c =' ';
int count = 0;

for(int i = 0; i < height && c!='#'; i++){
    for(int j = 0; j < width && c!='#'; j++){
        for(int k = 0; k < 3 && c!='#'; k++){
            count++;
            if ((pixel[i][j][k]) % 2 ==  0){
                chunk += '0'; 
            } 
            else
                chunk += '1';
              
            if(count == 8){
                std::bitset<8> mybit(chunk);
                c = char(mybit.to_ulong());
                if(c == '#') break; 
                message += c;
                count = 0;
                chunk.clear();
            }
        }
    }
}
return message;
}

void image::encoding(std::string toEncode)
{
    std::cout << "Encoding '" << toEncode << "'\n" << std::endl; 
    std::string bitstr = "";
    int ascii;
    toEncode = toEncode + '#';
    for (int i = 0; i < toEncode.length(); i++){
        ascii = toEncode[i];
        std::bitset<8> binary(ascii);
        bitstr += binary.to_string();
    }

    int bitIndex = 0;
    for (int x = 0; x < height && bitIndex != bitstr.length(); x++){
        for(int y = 0; y < width && bitIndex != bitstr.length(); y++){
            for(int z = 0; z < 3  && bitIndex != bitstr.length(); z++){
                if(bitstr[bitIndex] == '1' && pixel[x][y][z] % 2 == 0)
                    pixel[x][y][z] += 1;
                     
                if(bitstr[bitIndex] == '0' && pixel[x][y][z] % 2 == 1)
                    pixel[x][y][z] -= 1;     
                bitIndex++;
            }
        }
    }
}