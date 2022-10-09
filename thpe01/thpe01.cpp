#include "netPBM.h"


int main(int argc, char** argv)
{
    image imgData;
    ifstream fin;
    ofstream fout;
    bool count;
    count = cmdCheck(argc);
    if (count == false)
    {
        invalidCount(count);
        return 0;
    }
    if (argc == 5 || argc == 6)
    {
        withOpts(argv[1], argv[2], argv[3], argv[4], argv[5], imgData, fin, fout);
    }
    if (argc < 5)
    {
        noOptions(argv[1], argv[2], argv[3], imgData, fin, fout);
    }
    return 0;
}


bool noOptions(char* arg1, char* arg2, char* arg3, image& data, ifstream& fin, ofstream& fout)
{
    char fileHolder[30];
    char color[10] = ".ppm";
    char grey[10] = ".pgm";
    bool checkFile = openFile(fin, arg3);
    if (checkFile == false)
    {
        return false;
    }
    readData(fin, data);
    bool allocCheck = allocArray(data);
    if (allocCheck == false)
    {
        return false;
    }
    readFile(fin, data);
    if (strcmp(arg1, "--ascii") == 0)
    {
        data.magicNumber = "P3";
        strcpy(fileHolder, arg2);
        strcat(fileHolder, color);
        bool checkFile2 = openAOut(fout, fileHolder);
        if (checkFile == false)
        {
            return false;
        }
        writeAscii(fout, data);
    }
    if (strcmp(arg1, "--binary") == 0)
    {
        data.magicNumber = "P6";
        strcpy(fileHolder, arg2);
        strcat(fileHolder, color);
        bool checkFile2 = openBOut(fout, fileHolder);
        if (checkFile2 == false)
        {
            return false;
        }
        writeBinary(fout, data);
    }
    fin.close();
    fout.close();
    return true;
}

bool withOpts(char* arg1, char* arg2, char* arg3, char *arg4, char * arg5, image& data, ifstream& fin, ofstream& fout)
{
    bool opt;
    char fileHolder[30];
    char color[10] = ".ppm";
    char grey[10] = ".pgm";
    bool checkFile;
    bool checkFile2;
    opt = optionValid(arg1);
    if (opt == false)
    {
        cout << "Invalid Option" << endl;
        return false;
    }
    if (strcmp(arg1, "--brighten") == 0)
    {
        checkFile = openFile(fin, arg5);
    }
    checkFile = openFile(fin, arg4);
    if (checkFile == false)
    {
        return false;
    }
    readData(fin, data);
    bool allocCheck = allocArray(data);
    if (allocCheck == false)
    {
        return false;
    }
    readFile(fin, data); // read in the file
    if (strcmp(arg2, "--ascii") == 0)
    {
        if (strcmp(arg1, "--grayscale") == 0)
        {
            strcpy(fileHolder, arg3);
            strcat(fileHolder, grey);
            data.magicNumber = "P2";
            checkFile2 = openAOut(fout, fileHolder);
            if (checkFile == false)
            {
                return false;
            }
            writeGray(fout, data);
        }
        if (strcmp(arg1, "--brighten") == 0)
        {
            Brighten(arg2, data);
            writeAscii(fout, data);
        }
    }
    if (strcmp(arg2, "--binary") == 0)
    {
        strcpy(fileHolder, arg3);
        strcat(fileHolder, grey);
        data.magicNumber = "P6";
        checkFile2 = openBOut(fout, fileHolder);
        if (checkFile2 == false)
        {
            return false;
        }
        writeGrayB(fout, data);
    }
    fin.close();
    fout.close();
    return true;
}






