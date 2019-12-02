#ifndef IMAGE_H
#define IMAGE_H


#include <vector>
#include <string>
#include <sstream>

class image
{
    public:
		image( );
		static std::string colors [3] ;
		void setfiletype(std::string);
		void setcomment(std::string);
		void setWidth(int);
		void setHeight(int);
		void setMax_color(int);
		void setPixel(std::vector<std::vector<std::vector<int>>> &);
		std::string getFiletype();
		std::string getComment();
		int getMax_color();
		int getwidth();
		int getHeight();
		std::vector<std::vector<std::vector<int>>> getPixel();

	private:
		std::vector<std::vector<std::vector<int>>> pixel;
		std::string filetype;
		std::string comment;
		int width;
		int height;
		int max_color;


};

#endif // IMAGE_H
