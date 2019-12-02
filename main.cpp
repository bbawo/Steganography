#include <iostream>
#include <fstream>
#include <string>
#include "image.h"

void writeTo(std::string , image);
int main()
{
    image obj1("image1.ppm");
    std::cout << "Hash value : " << obj1.hashValue() << std::endl;
    obj1.encoding("Congrats Biram ! You did it.");

    image obj2("image2.ppm");
    std::cout << "Hash value : " << obj2.hashValue() << std::endl;
    obj2.encoding("Home	Sweet	Home");

    image obj3("image3.ppm");
    std::cout << "Hash value : " << obj3.hashValue() << std::endl;
    obj3.encoding("Beagles are the best dogs ever");
    std::cout << "\n" << std::endl;

    writeTo("image1X.ppm", obj1);
    writeTo("image2X.ppm", obj2);
    writeTo("image3X.ppm", obj3);


    image obj4("image1X.ppm");
    std::cout << "Hash value : " << obj4.hashValue() << std::endl;
    std::cout << "Message decoded : " << obj4.decoding() << "\n"<< std::endl;

    image obj5("image2X.ppm");
    std::cout << "Hash value : " << obj5.hashValue() << std::endl;
    std::cout << "Message decoded : " << obj5.decoding() << "\n" << std::endl;

    image obj6("image3X.ppm");
    std::cout << "Hash value : " << obj6.hashValue() << std::endl;
    std::cout << "Message decoded : " << obj6.decoding() << "\n" << std::endl;
 return 0;
}

void writeTo(std::string fileName, image object)
{
    std::ofstream write(fileName);

    write << object.getFiletype() << "\n" <<
    object.getComment() << "\n" << object.getwidth() << " "
    << object.getHeight() << "\n" << object.getMax_color() << "\n";

    auto h = object.getHeight();
    auto w = object.getwidth();
    auto data = object.getPixel();
    for (int i = 0; i < h; ++i){
      for (int j = 0; j < w; ++j){
        for (int k = 0; k < 3; ++k){
          write << data[i][j][k] << std::endl;
        }
      }
    }

    write.close();
}
