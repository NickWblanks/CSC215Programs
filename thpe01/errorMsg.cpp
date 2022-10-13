#include "netPBM.h"

void usageState()
{
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
    cout << "       --grayscale" << endl;
    cout << "       --contrast" << endl;
}

bool cmdCheck(int cmdCount)
{
    if (cmdCount < 4 || cmdCount > 6)
    {
        return false;
    }
    return true;
}


bool magicCheck(image& data)
{
    if (data.magicNumber != "P3" && data.magicNumber != "P2" && data.magicNumber != "P5" && data.magicNumber != "P6")
    {
        return false;
    }
    return true;
}


int optionCheck(char* option)
{
    if (strcmp(option, "--negate") == 0)
    {
        return 1;
    }
    if (strcmp(option, "--brighten") == 0)
    {
        return 2;
    }
    if (strcmp(option, "--sharpen") == 0)
    {
        return 3;
    }
    if (strcmp(option, "--smooth") == 0)
    {
        return 4;
    }
    if (strcmp(option, "--grayscale") == 0)
    {
        return 5;
    }
    if (strcmp(option, "--contrast") == 0)
    {
        return 6;
    }
    cout << "Invalid Option" << endl;
    usageState();
    return 0;
}

