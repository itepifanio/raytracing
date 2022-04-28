#include "../include/background.h"
#include "../include/pixel.h"

Background::Background() {
    Pixel white(255, 255, 255);
    this->color = white;
}

Pixel Background::fromCoord(int i, int j)
{
    return this->color;
}

void Background::setColor(Pixel pixel)
{
    this->color = pixel;
}

Pixel Background::getColor()
{
    return this->color;
}

vec3 Background::interpolate(float x, float y){
    
    float calculo_x = RGBtoFloat(bl.x)*(1-x)*(1-y) + RGBtoFloat(br.x)*x*(1-y) + RGBtoFloat(tl.x)*(1-x)*y + RGBtoFloat(tr.x)*x*y;
    float calculo_y = RGBtoFloat(bl.y)*(1-x)*(1-y) + RGBtoFloat(br.y)*x*(1-y) + RGBtoFloat(tl.y)*(1-x)*y + RGBtoFloat(tr.y)*x*y;
    float calculo_z = RGBtoFloat(bl.z)*(1-x)*(1-y) + RGBtoFloat(br.z)*x*(1-y) + RGBtoFloat(tl.z)*(1-x)*y + RGBtoFloat(tr.z)*x*y;

    std::string v = to_string(FloattoRGB(calculo_x)) + " " + to_string(FloattoRGB(calculo_y)) + " " + to_string(FloattoRGB(calculo_z));

    return vec3(v);
}

float Background::RGBtoFloat(int value){
    float value_ = float(value)/255.0;
    return value_;
}