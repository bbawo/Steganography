#include "image.h"
#include <iostream>
#include <sstream>
#include <vector>

std::string image::colors [3] = {"Red", "Green", "Blue"};

image::image()
{
    filetype = "";
    comment = "";
}

void image::setfiletype(std::string newfiletype)
{
    filetype = newfiletype;
}

void image::setcomment(std::string newcomment)
{
    comment = newcomment;
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

void image::setMax_color(int new_max_color)
{
   max_color = new_max_color;
}

void image::setPixel(std::vector<std::vector<std::vector<int>>> & newpixel)
{
    pixel = newpixel;
}

std::string image::getFiletype()
{
   return filetype;
}

std::string image::getComment()
{
   return comment;
}

int image::getMax_color()
{
   return max_color;
}

int image::getwidth()
{
   return width;
}

int image::getHeight()
{
   return height;
}

std::vector<std::vector<std::vector<int>>> image::getPixel()
{
 return pixel;
}

