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

bool openBOut(ofstream& fout, char* fileName)
{
    fout.open(fileName, ios::out | ios::ate | ios::binary);
    if (!fout.is_open())
    {
        cout << "Unable to open file: " << fileName << endl;
        return false;
    }
    return true;
}

bool openAOut(ofstream& fout, char* fileName)
{
    fout.open(fileName);
    if (!fout.is_open())
    {
        cout << "Unable to open file: " << fileName << endl;
        return false;
    }
    return true;
}


void readWriteFile(ifstream& fin, ofstream &fout, image data)
{
    int i = 0;
    int j = 0;
    int max;
    string com;
    image imgData;
    imgData.magicNumber = data.magicNumber;
    fin.ignore();
    while (fin.peek() == 35)
    {
        getline(fin, com);
        imgData.comment += com;
        imgData.comment += '\n';

    }
    fin >> imgData.cols;
    fin >> imgData.rows;
    fin >> max;
    imgData.redgray = allocRed(imgData.cols, imgData.rows);
    if (imgData.redgray == nullptr)
    {
        exit(1);
    }
    imgData.green = allocGreen(imgData.cols, imgData.rows);
    if (imgData.green == nullptr)
    {
        exit(1);
    }
    imgData.blue = allocBlue(imgData.cols, imgData.rows);
    if (imgData.blue == nullptr)
    {
        exit(1);
    }
    if (data.magicNumber == "P3")
    {
        readAscii(fin, imgData);
        writeAscii(fout, imgData);
    }
    if (data.magicNumber == "P6")
    {
        //readBin(fin, imgData);
    }
}


void readAscii(ifstream& fin, image data)
{
    int i = 0;
    int j = 0;
    int R, G, B = 0;
    pixel r, g, b;
    string com;
    for (i = 0; i < data.cols; i++)
    {
        for (j = 0; j < data.rows; j++)
        {
            fin >> R >> G >> B;
            r = R;
            g = G;
            b = B;
            data.redgray[i][j] = r;
            data.green[i][j] = g;
            data.blue[i][j] = b;
            //cout << (int)data.redgray[i][j] << " " << (int)data.green[i][j] << " " << (int)data.blue[i][j] << endl;

        }
    }
}


void readBin(ifstream& fin, image data)
{
    image imgData;
    int i = 0;
    int j = 0;
    int holder = 0;
    while (fin.read((char*) &data, sizeof(int)))
    {
        
    }
    for (i = 0; i < data.cols; i++)
    {
        for (j = 0; j < data.rows; j++)
        {
            cout << (int)data.redgray[i][j] << " " << (int)data.green[i][j] << " " << (int)data.blue[i][j] << endl;

        }
    }
}

void writeAscii(ofstream& fout, image data)
{
    int i, j;
    int max = 255;
    fout << data.magicNumber << endl;
    fout << data.comment << endl;
    fout << data.cols << endl;
    fout << data.rows << endl;
    fout << max << endl;
    for (i = 0; i < data.cols; i++)
    {
        for (j = 0; j < data.rows; j++)
        {
            fout << (int)data.redgray[i][j] << " " << (int)data.green[i][j] << " " << (int)data.blue[i][j] << endl;
        }
    }
}

void writeBinary(ofstream& fout, image data)
{
    int i, j;
    int max = 255;
    fout << data.magicNumber << endl;
    fout << data.comment << endl;
    fout << data.cols << endl;
    fout << data.rows << endl;
    fout << max << endl;
    for (i = 0; i < data.cols; i++)
    {
        for (j = 0; j < data.rows; j++)
        {
            fout << data.redgray[i][j] << " " << data.green[i][j] << " " << data.blue[i][j] << endl;
        }
    }

}


