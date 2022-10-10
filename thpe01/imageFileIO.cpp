#include "netPBM.h"

bool openFile(ifstream& fin, char *fileName)
{
    fin.open(fileName, ios::binary);
    if (!fin.is_open())
    {
        cout << "Unable to open file: " << fileName << endl;
        return false;
    }
    return true;
}

bool openBOut(ofstream& fout, char* fileName)
{
    fout.open(fileName, ios::ate | ios::binary);
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

void readData(ifstream& fin, image& data)
{
    int max;
    string com;
    fin >> data.magicNumber;
    fin.ignore();
    while (fin.peek() == 35)
    {
        getline(fin, com);
        data.comment += com;
        data.comment += '\n';
    }
    fin >> data.cols;
    fin >> data.rows;
    fin >> max;
}


void readFile(ifstream& fin, image &data)
{
    if (data.magicNumber == "P3")
    {
        readAscii(fin, data);
    }
    if (data.magicNumber == "P6")
    {
        readBin(fin, data);
    }
}


void readAscii(ifstream& fin, image &data)
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


void readBin(ifstream& fin, image &data)
{
    int i = 0;
    int j = 0;
    fin.ignore();
    for (i = 0; i < data.cols; i++)
    {
        for (j = 0; j < data.rows; j++)
        {
            fin.read((char*) &data.redgray[i][j], sizeof(pixel));
            fin.read((char*)&data.green[i][j], sizeof(pixel));
            fin.read((char*)&data.blue[i][j], sizeof(pixel));
        }
    }
}

void writeAscii(ofstream& fout, image &data)
{
    int i, j;
    int max = 255;
    fout << data.magicNumber << endl;
    fout << data.comment;
    fout << data.cols << " " << data.rows << endl;
    fout << max << endl;;
    for (i = 0; i < data.cols; i++)
    {
        for (j = 0; j < data.rows; j++)
        {
            fout << (int)data.redgray[i][j] << " " << (int)data.green[i][j] << " " << (int)data.blue[i][j] << endl;
        }
    }
}


void writeBinary(ofstream& fout, image &data)
{
    int i, j;
    int max = 255;
    fout << data.magicNumber << '\n';
    fout << data.comment;
    fout << data.cols << " " << data.rows << '\n';
    fout << max << '\n';
    for (i = 0; i < data.cols; i++)
    {
        for (j = 0; j < data.rows; j++)
        {
            fout.write((char*) &data.redgray[i][j], sizeof(pixel));
            fout.write((char*)&data.green[i][j], sizeof(pixel));
            fout.write((char*)&data.blue[i][j], sizeof(pixel));
        }
    }
}

void writeGray(ofstream& fout, image& data)
{
    int i, j;
    int max = 255;
    fout << data.magicNumber << endl;
    fout << data.comment;
    fout << data.cols << " " << data.rows << endl;
    fout << max << endl;;
    for (i = 0; i < data.cols; i++)
    {
        for (j = 0; j < data.rows; j++)
        {
            fout << (int)data.redgray[i][j] << endl;
        }
    }
}

void writeGrayB(ofstream& fout, image& data)
{
    int i, j;
    int max = 255;
    fout << data.magicNumber << '\n';
    fout << data.comment;
    fout << data.cols << " " << data.rows << '\n';
    fout << max << '\n';
    for (i = 0; i < data.cols; i++)
    {
        for (j = 0; j < data.rows; j++)
        {
            fout.write((char*)&data.redgray[i][j], sizeof(pixel));
        }
    }
}

bool outputType(char* type, ifstream &fin, ofstream &fout, image &data, char *fileOut)
{
    char fileHolder[30];
    char color[10] = ".ppm";  
    if (strcmp(type, "--ascii") == 0)
    {
        data.magicNumber = "P3";
        strcpy(fileHolder, fileOut);
        strcat(fileHolder, color);
        bool checkFile2 = openAOut(fout, fileHolder);
        if (checkFile2 == false)
        {
            return false;
        }
        writeAscii(fout, data);
        return true;

    }
    if (strcmp(type, "--binary") == 0)
    {
        data.magicNumber = "P6";
        strcpy(fileHolder, fileOut);
        strcat(fileHolder, color);
        bool checkFile = openBOut(fout, fileHolder);
        if (checkFile == false)
        {
            return false;
        }
        writeBinary(fout, data);
        return true;
    }
    return true;
}

bool outGray(char* type, ifstream& fin, ofstream& fout, image& data, char* fileOut)
{
    char fileHolder[30];
    char color[10] = ".pgm";
    if (strcmp(type, "--ascii") == 0)
    {
        data.magicNumber = "P2";
        strcpy(fileHolder, fileOut);
        strcat(fileHolder, color);
        bool checkFile2 = openAOut(fout, fileHolder);
        if (checkFile2 == false)
        {
            return false;
        }
        writeGray(fout, data);
        return true;
    }
    if (strcmp(type, "--binary") == 0)
    {
        data.magicNumber = "P5";
        strcpy(fileHolder, fileOut);
        strcat(fileHolder, color);
        bool checkFile = openBOut(fout, fileHolder);
        if (checkFile == false)
        {
            return false;
        }
        writeGrayB(fout, data);
        return true;
    }
    return true;
}






