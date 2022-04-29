#include "../include/background.h"
#include "../include/pixel.h"

Background::Background()
{
    Pixel white(255, 255, 255);
    this->color = white;
}

Background::Background(std::string type, Vector3 color_s,
    Vector3 bl, Vector3 br, Vector3 tl, Vector3 tr
) {
    this->type = type;
    this->color_s = color_s;
    this->bl = bl;
    this->br = br;
    this->tl = tl;
    this->tr = tr;    
}

Pixel Background::fromCoord(int i, int j)
{
    return this->color;
}

Vector3 Background::interpolate(double x, double y){
    double calculo_x = RGBtoFloat(bl[0])*(1-x)*(1-y) + RGBtoFloat(br[0])*x*(1-y) + RGBtoFloat(tl[0])*(1-x)*y + RGBtoFloat(tr[0])*x*y;
    double calculo_y = RGBtoFloat(bl[1])*(1-x)*(1-y) + RGBtoFloat(br[1])*x*(1-y) + RGBtoFloat(tl[1])*(1-x)*y + RGBtoFloat(tr[1])*x*y;
    double calculo_z = RGBtoFloat(bl[2])*(1-x)*(1-y) + RGBtoFloat(br[2])*x*(1-y) + RGBtoFloat(tl[2])*(1-x)*y + RGBtoFloat(tr[2])*x*y;

    std::string v = std::to_string(FloattoRGB(calculo_x)) + " " + std::to_string(FloattoRGB(calculo_y)) + " " + std::to_string(FloattoRGB(calculo_z));
    return Vector3::string_to_vector(v);
}

double Background::FloattoRGB(double value){
    double value_ = float(value)*255.0;
    return value_;
}

double Background::RGBtoFloat(int value){
    double value_ = float(value)/255.0;
    return value_;
}

void Background::setColor(Pixel pixel)
{
    this->color = pixel;
}

Pixel Background::getColor()
{
    return this->color;
}
