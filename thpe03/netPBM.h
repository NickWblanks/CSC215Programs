/** **********************************************************************
 * @file
 ************************************************************************/

 /** **************************************************************************
  * @mainpage Take Home Programming Exam 01 - Image Manipulation
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
  * @date Due October 16, 2022
  *
  * @section program_section Program Information
  *
  * @details
  * This program allows the user to input a net PBM image in
  * either ascii or binary format. This program can process
  * 4 out of the six PBM image types. It can process colored 
  * images P3, and P6, as well as grayscale images P2, and P5.
  * 
  * This program is executed using command line arguments.
  * The minimum required commands are 4, the maximum is 6.
  * The user has the choice of implementing an option to
  * manipulate the image as well as an option to output
  * the image in a certain format.
  * 
  * Accepted image manipulation options are - "--negate", "--brighten #",
  * "--sharpen", "--smooth", "--grayscale", "--contrast".
  * 
  * Accepted image output formates are - "--ascii" or "--binary".
  * 
  * After inputting at least an image output option, the user
  * must specify a file name for the image. This file is where the image
  * will be output into once it has been processed.
  * 
  * The next requirement is the input file. This program only accepts 
  * .ppm images of either type P3, or P6. Any image that does not meet 
  * these requirements will not be processed.
  * 
  * Image operation descriptions:
  * 
  * Negate will create a photo negative of the image.
  * Brighten will brighten or darken the image based on a value.
  * An integer Value MUST be supplied after --brighten option.
  * Sharpen will increase the separation between colors, making them easier to identify.
  * Smooth will blend colors together.
  * Grayscale will turn the image black and white.
  * Contrast will increase the difference between white and black.
  * 
  * 
  * 
  * 
  * 
  * 
  * @section compile_section Compiling and Usage
  *
  * @par Compiling Instructions:
  *      none - a straight compile and link with no external libraries.
  *
  * @par Usage:
    @verbatim
    c:\> thpe01.exe --option --outputOption outputfile inputfile
             --option - users chosen option to process image.
             --outputOption - either ascii or binary output.
             outputfile - filename to write our analyzed data to.
             inputfile  - filename containing our data points

    @endverbatim
  *
  * @section todo_bugs_modification_section Todo, Bugs, and Modifications
  *
  * @bug Program will crash if 6 arguments are supplied, but brighten is not specified.
  *      It will also crash if brighten is specified and no value given.
  *   
  * @todo Sharpen, Smooth, and Contrast dont seem to work properly.
  *       Smooth behaves more like blend, sharpen draws white lines in image.
  * 
  * @par Modifications and Development Timeline:
  * This is a link to gitlab's commit as an example. To view <a target="_blank"
  * href="https://gitlab.cse.sdsmt.edu/101095827/csc215f22programs/-/commits/main">click here.</a>
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

bool readManip(image& data, ifstream& fin, char* file);


//error message functions

void usageState();

bool cmdCheck(int cmdCount);

bool magicCheck(image& data);

int optionCheck(char* option);

bool outputType(char* type, ofstream& fout, image& data, char* fileOut);

bool outGray(char* type, ofstream& fout, image& data, char* fileOut);

bool invalidType(char* type);



// mem allocation functions

pixel** allocRed( int rows, int columns);

pixel** allocGreen( int rows, int columns);

pixel** allocBlue( int rows, int columns);

void free2D(pixel** arr, int cols);

bool allocArray(image& data);

bool allocNArray(pixel**& arr, image& data);


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