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

bool openOut(ofstream& fout, char* fileName)
{
    fout.open(fileName);
    if (!fout.is_open())
    {
        cout << "Unable to open file: " << fileName << endl;
        return false;
    }
    return true;
}

bool readWriteAscii(ifstream& fin, ofstream& fout)
{
    int i = 0;
    int j = 0;
    int R, G, B = 0;
    pixel r, g, b;
    int max;
    string com;
    image imgData;
    fin >> imgData.magicNumber;
    if (imgData.magicNumber != "P3")
    {
        imgData.magicNumber = "P3";
    }
    fin.ignore();
    while (fin.peek() == 35)
    {
        getline(fin, com);
        imgData.comment += com;
        imgData.comment += '\n';
   
    }
    fin >> imgData.rows;
    fin >> imgData.cols;
    fin >> max;
    imgData.redgray = allocRed(imgData.rows, imgData.cols);
    if (imgData.redgray == nullptr)
    {
        return false;
    }
    imgData.green = allocGreen(imgData.rows, imgData.cols);
    if (imgData.green == nullptr)
    {
        return false;
    }
    imgData.blue = allocBlue(imgData.rows, imgData.cols);
    if (imgData.blue == nullptr)
    {
        return false;
    }
    for (i = 0; i < imgData.rows; i++)
    {
        for (j = 0; j < imgData.cols; j++)
        {
            fin >> R >> G >> B;
            r = R;
            g = G;
            b = B;
            imgData.redgray[i][j] = r;
            imgData.green[i][j] = g;
            imgData.blue[i][j] = b;
        }
    }
    fout << imgData.magicNumber << endl;
    fout << imgData.comment << endl;
    fout << imgData.rows << endl;
    fout << imgData.cols << endl;
    fout << max << endl;
    for (i = 0; i < imgData.rows; i++)
    {
        for (j = 0; j < imgData.cols; j++)
        {
            fout << (int)imgData.redgray[i][j] << " " << (int)imgData.green[i][j] << " " << (int)imgData.blue[i][j] << endl;
        }
    }
    return true;
}
