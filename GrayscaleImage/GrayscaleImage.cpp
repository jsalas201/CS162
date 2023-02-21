/**
* @brief Assignment 5
* @name Jonas Salas
*/
//----------------------------------------------------------
// CS162 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may be republished without approval.
//----------------------------------------------------------

#include <stdexcept>
#include <string>
using namespace std;

#include "GrayscaleImage.h"


int GrayscaleImage::getWidth() const {
    return width;
}

int GrayscaleImage::getHeight() const {
    return height;
}

uint8_t GrayscaleImage::getPixel(int row, int col) const {
    if(row >= height || row < 0 || col >= width || col < 0)
        throw out_of_range("Bad index in getPixel");
    return pixels[row * width + col];
}
void GrayscaleImage::setPixel(int row, int col, uint8_t brightness) {
    if(row >= height || row < 0 || col >= width || col < 0)
        throw out_of_range("Bad index in setPixel");
    pixels[row * width + col] = brightness;
}
GrayscaleImage::GrayscaleImage(int heightVal, int widthVal){
    width =widthVal;
    height = heightVal;
    pixels = new uint8_t[height*width];
    for(int i = 0; i< height*width;i++){
        pixels[i]=0;
    }
}
GrayscaleImage::~GrayscaleImage(){
    delete [] pixels;
}
void GrayscaleImage::fill(uint8_t brightness){
    for(int i = 0; i< height*width;i++){
        pixels[i]=brightness;
    }
}

//not sure what im doing wrong in toString(), it prints out well but not passing

string GrayscaleImage::toString() const{
    string s = "";
    for(int i=0;i< height;i++){
        for(int j = 0;j<width;j++){
            s+= getPixel(i,j);
            if(j<width)
                s+= " ";
            if(j==width)
                s+='n';
        }
    }
    return s;
}
bool GrayscaleImage::operator==(const GrayscaleImage& other) const{
    if(width  != other.width )
        return false;
    if(height != other.height)
        return false;
    for(int i = 0; i< width*height; i++){
        if(pixels[i] != other.pixels[i])
            return false;
    }
    return true;
}
GrayscaleImage::GrayscaleImage(const GrayscaleImage& other){
    width = other.width;
    height = other.height;
    pixels = new uint8_t[other.width*other.height];
    for(int i =0;i< width*height;i++){
        pixels[i] = other.pixels[i];
    }
}
GrayscaleImage& GrayscaleImage::operator=(const GrayscaleImage& other){
    if(this != &other)
    {
        width = other.width;
        height = other.height;

        delete [] pixels;

        pixels = new uint8_t[width*height];
        for(int i = 0; i < width*height; i++)
            pixels[i] = other.pixels[i];
    }
    return *this;
}
GrayscaleImage GrayscaleImage::addFrame(int padding, uint8_t brightness) const{
    int newHeight= 2*padding + this->height;
    int newWidth= 2*padding+ this->width;
    GrayscaleImage newObject((newHeight),newWidth);
    newObject.fill(brightness);
    for(int i=padding;i< newHeight-padding;i++){
        for(int j=padding;j< newWidth-padding;j++){
            newObject.setPixel(i,j,this->getPixel(i-padding,j-padding));
        }
    }

    return newObject;
}
GrayscaleImage GrayscaleImage::crop(int startRow, int startCol, int newHeight, int newWidth) const{
    if((startRow&&startCol&&newHeight&&newWidth < 0) || startRow+newHeight> this->height || startCol+newWidth> this->width){
        throw out_of_range("OOOPS");
    }

    GrayscaleImage newObject(newHeight,newWidth);
    for(int i=0;i< newHeight;i++){
        for(int j=0;j< newWidth;j++){
            newObject.setPixel( i, j, this->getPixel(startRow+i,startCol+j));
        }
    }
    return newObject;
}
