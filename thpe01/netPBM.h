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


//error message functions

void invalidCount(bool check);

bool cmdCheck(int cmdCount);

bool optionValid(char* option);

void optionCheck(char* option, image& data);


// mem allocation functions

pixel** allocRed( int rows, int columns);

pixel** allocGreen( int rows, int columns);

pixel** allocBlue( int rows, int columns);

pixel** allocGray(int cols, int rows);



//other functions

bool allocArray(image &data);

bool noOptions(char* arg1, char* arg2, char* arg3, image& data, ifstream& fin, ofstream& fout);

bool notBrighten(char* arg1, char* arg2, char* arg3, char* arg4, image& data, ifstream& fin, ofstream& fout);


// operations functions

void negate(image& data);

void Grayscale(image& data);










