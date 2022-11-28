/** **********************************************************************
 * @file
 ************************************************************************/

 /** **************************************************************************
  * @mainpage Take Home Programming Exam 03 - Bucket Fill
  *
  * @section course_section Course Information
  *
  * @author Nick Wilk
  *
  * @par Professor:
  *         Dr. Rodger Schrader
  *
  * @par Course:
  *         CSC215 - M001 - Programming Techniques
  *
  * @par Location:
  *         Classroom Building - M205
  *
  * @date Due November 27, 2022
  *
  * @section program_section Program Information
  *
  * @details
  * This program allows a user to bucket fill regions of an image with
  * a color of their choice. The progam is designed to work on net PBM 
  * images and only works on colored images of either ascii or binary format.
  * 
  * This program recursively fills each pixel with a new value. The user
  * must first specify the starting pixel, and then the program will search
  * for all pixels of the same color values and replace them with the new color
  * values. It will stop when it finds pixel values that do not match the 
  * original value, or if the program steps beyond the bounds of the picture.
  * 
  * Usage 
  * The program requires 7 arguments to be supplied via the command line
  * The first argument being the executable thpe03.exe
  * The second argument is the file. The file provided will be both the
  * input and output file.
  * The third argument is the row to access in the image.
  * The fourth argument is the column to access in the image.
  * The fifth argument is the new red value to fill in.
  * The sixth argument is the new green value to fill in.
  * The seventh argument is the new blue value to fill in.
  * The 3rd -> 7th arguments must be within range of the image
  * Row and column cannot be less than 0, and must be within range of the image.
  * The red, green and blue values must be within the range of 0 -> 255.
  * 
  * @section compile_section Compiling and Usage
  *
  * @par Compiling Instructions:
  *      Stack reserve size and stack commit size should both be 
  *      adjusted to 4 billion
  *
  * @par Usage:
    @verbatim
    c:\> thpe03.exe --file --row --column redvalue greenvalue bluevalue
             --file - The image file to read in and write back to.
             --row - The row of the image to find.
             --column - The column of the image to find.
             redvalue - the new red value of a color to fill.
             greenvalue - the new green value of a color to fill.
             bluevalue - the new red value of a color to fill.


    @endverbatim
  *
  * @section todo_bugs_modification_section Todo, Bugs, and Modifications
  *
  * @bug Program doesnt do error checking on the inputs. User can input
  * letters or symbols. It will also crash if invalid row and column are given.
  * 
  * 
  * 
  * @par Modifications and Development Timeline:
  * This is a link to gitlab's commit as an example. To view <a target="_blank"
  * href="https://gitlab.cse.sdsmt.edu/101095827/csc215f22programs/-/tree/main/thpe03">click here.</a>
  *
  *****************************************************************************/


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
 * @brief An unsigned character with a byte value of 0-255 that represents a pixel
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


/** **********************************************************************
 *
 *  @struct color
 *
 *  @par Description
 *  Color is a structure that holds 3 pixel values that pertain to the
 *  red, green and blue spectrums of a color.
 * 
 *
 *  @var color::red
 *  Member 'red' Contains a pixel value representing the red spectrum.
 *
 *  @var color::green
 *  Member 'green' Contains a pixel value representing the green spectrum.
 *
 *  @var color::blue
 *  Member 'blue' Contains a pixel value representing the blue spectrum..
 *
 *
 *
 *************************************************************************/

struct color
{
    pixel red;
    pixel green;
    pixel blue;
};

#endif


//file functions

bool openBFile(ifstream& fin, char* fileName);

bool openBOut(ofstream& fout, char* fileName);

void readHeader(ifstream &fin, image &data);

void readFile(ifstream& fin, image &data);

void readAscii(ifstream& fin, image &data);

void writeAscii(ofstream& fout, image &data);

void readBin(ifstream& fin, image &data);

void writeBinary(ofstream& fout, image &data);


//error message functions


bool outGray(char* type, ofstream& fout, image& data, char* fileOut);




// mem allocation functions

pixel** allocRed( int rows, int columns);

pixel** allocGreen( int rows, int columns);

pixel** allocBlue( int rows, int columns);

void free2D(pixel** arr, int cols);

bool allocArray(image& data);

bool allocNArray(pixel**& arr, image& data);


//other functions

void writeGray(ofstream& fout, image& data);

void writeGrayB(ofstream& fout, image& data);

void floodFill(int row, int col, image& data, color& newColor, color &oldColor);






