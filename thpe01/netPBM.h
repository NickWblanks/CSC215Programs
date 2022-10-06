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

void readWriteFile(ifstream& fin, ofstream& fout);

void readAscii(ifstream& fin, image data);

void writeAscii(ofstream& fout, image data);

void readBin(ifstream& fin);



//error message functions

void invalidCount(bool check);

bool cmdCheck(int cmdCount);

bool optionCheck(char* option, char* bNum);

// mem allocation functions

pixel** allocRed( int rows, int columns);

pixel** allocGreen( int rows, int columns);

pixel** allocBlue( int rows, int columns);


//other functions

bool allocArray();









