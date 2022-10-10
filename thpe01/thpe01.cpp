#include "netPBM.h"


int main(int argc, char** argv)
{
    image imgData;
    ifstream fin;
    ofstream fout;
    bool check, mCheck, count, output;
    bool checkFile2;
    int option;
    count = cmdCheck(argc);
    if (count == false)
    {
        invalidCount(count);
        return 0;
    }
    if (argc == 6)
    {
        option = optionCheck(argv[1]);
        if (option == 2)
        {
            checkFile2 = openFile(fin, argv[5]);
            readData(fin, imgData);
            bool allocCheck = allocArray(imgData);
            if (allocCheck == false)
            {
                return false;
            }
            mCheck = magicCheck(imgData);
            if (mCheck == false)
            {
                cout << "Invalid Image" << endl;
                return false;
            }
            readFile(fin, imgData);
            Brighten(argv[2], imgData);
            output = outputType(argv[3], fin, fout, imgData, argv[4]);
        }
    }
    if (argc == 5)
    {
        option = optionCheck(argv[1]);
        if (option == 1)
        {
            checkFile2 = openFile(fin, argv[4]);
            readData(fin, imgData);
            bool allocCheck = allocArray(imgData);
            if (allocCheck == false)
            {
                return false;
            }
            mCheck = magicCheck(imgData);
            if (mCheck == false)
            {
                cout << "Invalid Image" << endl;
                return false;
            }
            readFile(fin, imgData);
            negate(imgData);
            output = outputType(argv[2], fin, fout, imgData, argv[3]);
        }
        if (option == 5)
        {
            checkFile2 = openFile(fin, argv[4]);
            readData(fin, imgData);
            bool allocCheck = allocArray(imgData);
            if (allocCheck == false)
            {
                return false;
            }
            mCheck = magicCheck(imgData);
            if (mCheck == false)
            {
                cout << "Invalid Image" << endl;
                return false;
            }
            readFile(fin, imgData);
            Grayscale(imgData);
            output = outGray(argv[2], fin, fout, imgData, argv[3]);
        }
    }
    if (argc < 5)
    {
        check = noOptions(argv[1], argv[2], argv[3], imgData, fin, fout);
        if (check == false)
        {
            return 0;
        }
    }
    return 0;
}


bool noOptions(char* arg1, char* arg2, char* arg3, image& data, ifstream& fin, ofstream& fout)
{
    bool output, mCheck;
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
    mCheck = magicCheck(data);
    if (mCheck == false)
    {
        cout << "Invalid Image" << endl;
        return false;
    }
    readFile(fin, data);
    output = outputType(arg1, fin, fout, data, arg2);
    if (output == false)
    {
        return false;
    }
    fin.close();
    fout.close();
    return true;
}




