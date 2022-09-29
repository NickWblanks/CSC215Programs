#include "netPBM.h"

bool openFile(ifstream& fin, char *fileName)
{
    fin.open(fileName);
    if (!fin.is_open())
    {
        cout << "Unable to open file: " << fileName << endl;
        return false;
    }
    return true;
}

void readAscii(ifstream& fin)
{
    image imgData;
    fin >> imgData.magicNumber;
    if (imgData.magicNumber != "P3")
    {
        imgData.magicNumber = "P3";
    }
    int com = fin.peek();
    while(com == 35)
    {
        getline(fin, imgData.comment, '\n');
        int com = fin.peek();
    }
    fin >> imgData.rows;
    fin.ignore();
    fin >> imgData.cols;
    cout << imgData.magicNumber << endl;
    cout << imgData.rows << endl;
    cout << imgData.cols << endl;
}