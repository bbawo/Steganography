#ifndef IMAGE_H
#define IMAGE_H

#include <vector>
#include <string>

class image
{
    public:
		image(std::string );
		static std::string colors [3] ;
		void setfiletype(std::string);
		void setcomment(std::string);
		void setWidth(int);
		void setHeight(int);
		void setMax_color(int);
		void EditComment(const std::string &);
		std::string getFiletype() const;
		std::string getComment() const;
		void encoding(std::string);
		std::string decoding();
		int getMax_color() const;
		int getwidth() const;
		int getHeight() const;
    	std::string hashValue();
		std::vector<std::vector<std::vector<int>>> getPixel() const;

	private:
		std::vector<std::vector<std::vector<int>>> pixel;
		std::string filetype;
		std::string comment;
		int width, height, max_color;
};

#endif // IMAGE_H
