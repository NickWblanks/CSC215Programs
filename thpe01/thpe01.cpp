#include "netPBM.h"


int main(int argc, char** argv)
{
    image imgData;
    ifstream fin;
    ofstream fout;
    bool count;
    bool opt;
    bool checkFile2;
    char fileHolder[30];
    count = cmdCheck(argc);
    if (count == false)
    {
        invalidCount(count);
        return 0;
    }
    if (argc == 5 || argc == 6)
    {
        opt = optionCheck(argv[1], argv[2]);
        if (opt == false)
        {
            cout << "Invalid Option" << endl;
            return 0;
        }
    }
    if (argc < 5)
    {
        char color[10] = ".ppm";
        char grey[10] = ".pgm";
        bool checkFile = openFile(fin, argv[argc - 1]);
        if (checkFile == false)
        {
            return 0;
        }
        readData(fin, imgData);
        bool allocCheck = allocArray(imgData);
        if (allocCheck == false)
        {
            return 0;
        }
        //read file
        readFile(fin, imgData);
        //check --bin/--ascii
        if (strcmp(argv[1], "--ascii") == 0)
        {
            strcpy(fileHolder, argv[argc - 2]);
            strcat(fileHolder, color);
            checkFile2 = openAOut(fout, fileHolder);
            if (checkFile == false)
            {
                return 0;
            }
            //write in specified format
            writeAscii(fout, imgData);
        }
        if (strcmp(argv[1], "--binary") == 0)
        {
            strcpy(fileHolder, argv[argc - 2]);
            strcat(fileHolder, color);
            checkFile2 = openBOut(fout, fileHolder);
            if (checkFile2 == false)
            {
                return 0;
            }
            writeBinary(fout, imgData);
        }
    }
    return 0;
}


