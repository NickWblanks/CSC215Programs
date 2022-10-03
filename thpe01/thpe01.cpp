#include "netPBM.h"


int main(int argc, char** argv)
{
    ifstream fin;
    ofstream fout;
    bool count;
    bool opt;
    count = cmdCheck(argc);
    if (count == false)
    {
        invalidCount(count);
        return 0;
    }
    if (argv[1] == "--ascii")
    {
        opt = optionCheck(argv[1], argv[2]);
        {
            if (opt == false)
            {
                badOption(argv[1]);
                return 0;
            }
        }
    }
    bool checkFile = openFile(fin, argv[argc - 1]);
    if (checkFile == false)
    {
        return 0;
    }
    checkFile = openOut(fout, argv[argc - 2]);
    bool asc = readWriteAscii(fin, fout);
    if (asc == false)
    {
        return 0;
    }


    return 0;
}

