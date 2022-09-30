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

bool readAscii(ifstream& fin);


//error message functions

void invalidCount(bool check);

void badOption(char* argOpt);

bool cmdCheck(int cmdCount);

bool optionCheck(char* option, char* bNum);

// mem allocation functions

bool allocRed(int rows, int columns);

bool allocGreen(int rows, int columns);

bool allocBlue(int rows, int columns);








