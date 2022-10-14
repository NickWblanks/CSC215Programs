/** **********************************************************************
 * @file
 ************************************************************************/

#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cstring>

using namespace std;

#ifndef _NETPBM_H_
#define _NETPBM_H_

/** **********************************************************************
 *
 *  @typedef pixel
 *
 *  @par description
 *  Pixel is an Unsigned character. It represents a single pixel 
 *  value in either the red, green, or blue spectrum.
 *
 * 
 *************************************************************************/

typedef unsigned char pixel;


/** **********************************************************************
 *
 *  @struct image
 *
 *  @par Description
 *  image is a structure that holds the data for a ppm picture. It uses strings for the magic number
 *  and the comment lines. It uses an integer to hold the rows and 
 *  columns. and it uses the pixel typedef to hold 3 2d arrays, RGB.
 *
 *  @var image::magicNumber
 *  Member 'magicNumber' Contains a string that represents the type of image
 *  whether it is in ascii or binary format.
 *
 *  @var image::comment
 *  Member 'comment' Contains a string that holds any comments at the beginning of the file..
 *
 *  @var image::rows
 *  Member 'rows' Contains an integer that is the height of the image.
 *
 *  @var image::cols
 *  Member 'cols' Contains an integer that is the width of the image..
 *
 *  @var image::redgray
 *  Member 'redgray' Is a 2d array holding the red and gray elements of the picture..
 *
 *  @var image::green
 *  Member 'green' Is a 2d array holding the green elements of the image.
 * 
 *  @var image::blue
 *  Member 'blue' Is a 2d array holding the blue elements of the image.
 *
 *
 *************************************************************************/


struct image
{
    string magicNumber;
    string comment;
    int rows;
    int cols;
    pixel** redgray;
    pixel** green;
    pixel** blue;
};

#endif


//file functions

bool openFile(ifstream& fin, char* fileName);

bool openBOut(ofstream& fout, char* fileName);

bool openAOut(ofstream& fout, char* fileName);

void readData(ifstream &fin, image &data);

void readFile(ifstream& fin, image &data);

void readAscii(ifstream& fin, image &data);

void writeAscii(ofstream& fout, image &data);

void readBin(ifstream& fin, image &data);

void writeBinary(ofstream& fout, image &data);

bool readManip(image& data, ifstream& fin, char* file);


//error message functions

void usageState();

bool cmdCheck(int cmdCount);

bool magicCheck(image& data);

int optionCheck(char* option);

bool outputType(char* type, ifstream& fin, ofstream& fout, image& data, char* fileOut);

bool outGray(char* type, ifstream& fin, ofstream& fout, image& data, char* fileOut);

bool invalidType(char* type);



// mem allocation functions

pixel** allocRed( int rows, int columns);

pixel** allocGreen( int rows, int columns);

pixel** allocBlue( int rows, int columns);

void free2D(pixel** arr, int cols);

bool allocArray(image& data);

bool allocNArray(pixel** arr, image& data);



//other functions


bool noOptions(char* arg1, char* arg2, char* arg3, image& data, ifstream& fin, ofstream& fout);

bool options(char* arg1, char* arg2, char* arg3, char* arg4, ifstream& fin, ofstream& fout, image& data);

int valCheck(int val);


// operations functions

void negate(image& data);

void Grayscale(image& data);

void writeGray(ofstream& fout, image& data);

void writeGrayB(ofstream& fout, image& data);

void Brighten(int val, image& data);

void contrast(image& data);

void sharpen(image& data, pixel** &Red, pixel** &Green, pixel** &Blue);

void smooth(image& data, pixel**& Red, pixel**& Green, pixel**& Blue);