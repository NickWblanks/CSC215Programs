#include "netPBM.h"

void invalidCount(bool check)
{
    if (check == false)
    {
        cout << "Invalid Startup" << endl;
        cout << "thpe01.exe [option] --outputtype basename image.ppm" << endl;
        cout << endl;
        cout << "Output Type" << endl;
        cout << "       --ascii pixel values will be written in text form" << endl;
        cout << "       --binary pixel values will be written in binary form" << endl;
        cout << endl;
        cout << "Option Code" << endl;
        cout << "       --negate" << endl;
        cout << "       --brighten #" << endl;
        cout << "       --sharpen" << endl;
        cout << "       --smooth" << endl;
        cout << "       --greyscale" << endl;
        cout << "       --contrast" << endl;

    }
}

bool cmdCheck(int cmdCount)
{
    if (cmdCount < 4 || cmdCount > 6)
    {
        return false;
    }
    return true;
}

bool optionCheck(char* option, char* bNum)
{
    if (strcmp(option, "--brighten") == 0 || strcmp(option, "--negate") == 0 || strcmp(option, "--sharpen") == 0 || strcmp(option, "--smooth") == 0 || strcmp(option, "--grayscale") == 0 || strcmp( option, "--contrast") == 0)
    {
        return true;
    }
    return false;
}
