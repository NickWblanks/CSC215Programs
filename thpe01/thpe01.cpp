#include "netPBM.h"


int main(int argc, char** argv)
{
    image imgData;
    ifstream fin;
    ofstream fout;
    bool check, count, output;
    int option;
    count = cmdCheck(argc);
    if (count == false)
    {
        cout << "Invalid Startup" << endl;
        usageState();
        return 0;
    }
    if (argc == 6)
    {
        option = optionCheck(argv[1]);
        if (option == 2)
        {
            check = readManip(imgData, fin, argv[5]);
            if (check == false)
            {
                return 0;
            }
            Brighten(argv[2], imgData);
            output = outputType(argv[3], fin, fout, imgData, argv[4]);
        }
    }
    if (argc == 5)
    {
        bool opt = options(argv[1], argv[2], argv[3], argv[4], fin, fout, imgData);
        if (opt == false)
        {
            return 0;
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
    //free2D(imgData.redgray, imgData.rows);
    //free2D(imgData.green, imgData.rows);
    //free2D(imgData.blue, imgData.rows);
    fin.close();
    fout.close();
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
    return true;
}


bool readManip(image& data, ifstream& fin, char* file)
{
    bool checkFile2, mCheck;
    checkFile2 = openFile(fin, file); //argv[4]
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
    return true;
}


bool options(char* arg1, char* arg2, char* arg3, char* arg4, ifstream& fin, ofstream& fout, image& data)
{
    int option;
    bool check, output;
    option = optionCheck(arg1);
    if (option == 1)
    {
        check = readManip(data, fin, arg4);
        if (check == false)
        {
            return false;
        }
        negate(data);
        output = outputType(arg2, fin, fout, data, arg3);
    }
    if (option == 5)
    {
        check = readManip(data, fin, arg4);
        if (check == false)
        {
            return false;
        }
        Grayscale(data);
        output = outGray(arg2, fin, fout, data, arg3);
    }
    if (option == 6)
    {
        check = readManip(data, fin, arg4);
        if (check == false)
        {
            return false;
        }
        Grayscale(data);
        contrast(data);
        output = outGray(arg2, fin, fout, data, arg3);
    }
    if (option == 0)
    {
        return false;
    }
    return true;
}



