#include "netPBM.h"


int main(int argc, char** argv)
{
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
        if (strcmp(argv[1], "--ascii") == 0)
        {
            strcpy(fileHolder, argv[argc - 2]);
            strcat(fileHolder, color);
            checkFile2 = openAOut(fout, fileHolder);
            if (checkFile == false)
            {
                return 0;
            }
            readWriteFile(fin,fout);
        }
        if (argv[1] == "--binary")
        {
            strcpy(fileHolder, argv[argc - 2]);
            strcat(fileHolder, color);
            checkFile = openBOut(fout, fileHolder);
            if (checkFile == false)
            {
                return 0;
            }
            readBin(fin);
        }
    }
    return 0;
}


