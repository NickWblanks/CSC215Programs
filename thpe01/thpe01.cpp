#include "netPBM.h"


int main(int argc, char** argv)
{
    ifstream fin;
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
    readAscii(fin);

    return 0;
}

int RGB(int flick)
{
    if (flick == 1)
    {
        return 2;
    }
    if (flick == 2)
    {
        return 3;
    }
    if (flick == 3)
    {
        return 1;
    }
}