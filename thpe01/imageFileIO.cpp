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
    int max;
    string com;
    image imgData;
    fin >> imgData.magicNumber;
    if (imgData.magicNumber != "P3")
    {
        imgData.magicNumber = "P3";
    }
    fin.ignore();
    int pk = fin.peek();
    while (pk == 35)
    {
        getline(fin, imgData.comment, '\n');
        pk = fin.peek();
    }
    fin >> imgData.rows;
    fin >> imgData.cols;
    fin >> max;
    cout << imgData.magicNumber << endl;
    cout << imgData.comment << endl;
    cout << imgData.rows << endl;
    cout << imgData.cols << endl;
    cout << max << endl;
}