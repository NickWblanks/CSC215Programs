#include "netPBM.h"


int main(int argc, char** argv)
{
    int red, green, blue, row, col, r2, g2, b2;
    bool ifCheck, ofcheck, arrCheck;
    image imgData;
    ifstream fin;
    ofstream fout;
    string usage = "thpe03.exe imageFile row col redValue greenValue blueValue";
    if (argc != 7)
    {
        cout << usage << endl;
        return 0;
    }
    ifCheck = openBFile(fin, argv[1]);
    if (false)
    {
        return 0;
    }
    row = stoi(argv[2]);
    col = stoi(argv[3]);
    red = stoi(argv[4]);
    green = stoi(argv[5]);
    blue = stoi(argv[6]);
    readHeader(fin, imgData);
    arrCheck = allocArray(imgData);
    if (arrCheck == false)
    {
        cout << "Memory allocation failed" << endl;
        return 0;
    }
    readFile(fin, imgData);
    r2 = imgData.redgray[row][col];
    g2 = imgData.green[row][col];
    b2 = imgData.blue[row][col];
    if (imgData.magicNumber == "P3")
    {
        fin.close();
        ofcheck = openBOut(fout, argv[1]);
        if (ofcheck == false)
        {
            cout << "Unable to open output file: " << argv[1] << endl;
            return 0;
        }
        writeAscii(fout, imgData);
    }
    if (imgData.magicNumber == "P6")
    {
        fin.close();
        ofcheck = openBOut(fout, argv[1]);
        if (ofcheck == false)
        {
            cout << "Unable to open output file: " << argv[1] << endl;
            return 0;
        }
        writeBinary(fout, imgData);
    }
    return 0;
}

