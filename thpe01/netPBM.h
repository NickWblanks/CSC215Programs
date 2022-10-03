#pragma once

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

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

bool openOut(ofstream& fout, char* fileName);

bool readWriteAscii(ifstream& fin, ofstream &fout);


//error message functions

void invalidCount(bool check);

void badOption(char* argOpt);

bool cmdCheck(int cmdCount);

bool optionCheck(char* option, char* bNum);

// mem allocation functions

pixel** allocRed( int rows, int columns);

pixel** allocGreen( int rows, int columns);

pixel** allocBlue( int rows, int columns);


//other functions









