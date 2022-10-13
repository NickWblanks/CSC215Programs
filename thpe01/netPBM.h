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

typedef unsigned char pixel;

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




// mem allocation functions

pixel** allocRed( int rows, int columns);

pixel** allocGreen( int rows, int columns);

pixel** allocBlue( int rows, int columns);

pixel** allocGray(int cols, int rows);

void free2D(pixel** arr, int cols);

//pixel** allocNewRed(int columns, int rows);

//pixel** allocNewGreen(int columns, int rows);

//pixel** allocNewBlue(int columns, int rows);






//other functions

bool allocArray(image &data);

bool noOptions(char* arg1, char* arg2, char* arg3, image& data, ifstream& fin, ofstream& fout);

bool options(char* arg1, char* arg2, char* arg3, char* arg4, ifstream& fin, ofstream& fout, image& data);


// operations functions

void negate(image& data);

void Grayscale(image& data);

void writeGray(ofstream& fout, image& data);

void writeGrayB(ofstream& fout, image& data);

void Brighten(char* arg2, image& data);

void contrast(image& data);













