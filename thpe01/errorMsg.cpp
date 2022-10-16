/** **********************************************************************
 * @file
 ************************************************************************/


#include "netPBM.h"

 /** **********************************************************************
  *  @author Nicholas K Wilk
  *
  *  @par Description
  *
  *  This function does not take any arguments. When it is called
  *  it will output a message to the screen. It has no return value.
  *
  *
  *  @par Example
  *  @verbatim

     usageState();

     @endverbatim
  ************************************************************************/


void usageState()
{
    cout << "thpe01.exe [option] --outputtype basename image.ppm" << endl;
    cout << endl;
    cout << "Output Type" << endl;
    cout << "       --ascii  pixel values will be written in text form" << endl;
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

/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *
 *  This function takes a single argument which is an integer.
 *  It will return true or false based on whether the integer is in the
 *  range of 4 - 6 inclusive.
 * 
 *  @param[in] cmdCount an integer to be passed in
 * 
 *  @returns True if the number is between 4 and 6, false if not.
 *
 *  @par Example
 *  @verbatim

    int num = 5;
    bool check;
    check  = cmdCheck(num);
    return check;

    @endverbatim
 ************************************************************************/


bool cmdCheck(int cmdCount)
{
    if (cmdCount < 4 || cmdCount > 6)
    {
        return false;
    }
    return true;
}



/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *
 *  This function takes a single argument which is the structure
 *  containing the image data. It will check to see if the 
 *  Magic Number is one of P3, P6, P2, or P5.
 * 
 *  @param[in] data The structure containing data to be read.
 *
 *  @returns True if the Magic Number is one of those values, false if not.
 *
 *  @par Example
 *  @verbatim

    bool check;
    check  = magicCheck(imgData);
    return check;

    @endverbatim
 ************************************************************************/


bool magicCheck(image& data)
{
    if (data.magicNumber != "P3" && data.magicNumber != "P2" && data.magicNumber != "P5" && data.magicNumber != "P6")
    {
        return false;
    }
    return true;
}


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *
 *  This function takes a single argument which is the option 
 *  specified by the user.
 *
 *  @param[in] option An cstyle string to be passed in.
 * 
 *  @returns An integer value representing the chosen option. 
 *  Will return 0 if its an invalid option.
 *
 *  @par Example
 *  @verbatim

    int check;
    check  = optionCheck(--brighten);
    return check;

    @endverbatim
 ************************************************************************/


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


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *
 *  This function takes a single argument which is the output type
 *  specified by the user.
 *
 * 
 *  @param[in] type A cstyle string to be passed in.
 *
 *  @returns A boolean value, true or false. True if the
 *  option is valid, false otherwise.
 *
 *  @par Example
 *  @verbatim

    bool check;
    check  = invalidType(--ascii);
    return check;

    @endverbatim
 ************************************************************************/

bool invalidType(char* type)
{
    if (strcmp("--ascii", type) == 0)
    {
        return true;
    }
    if (strcmp("--binary", type) == 0)
    {
        return true;
    }
    return false;
}


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *
 *  This function takes a single argument which is an integer.
 *  It compares the integer to a set of values, 255 and 0.
 *
 *  @param[in] val An integer to be passed in and checked.
 *
 *  @returns the integer input in. If the integer is within the
 *  range of 0 and 255 nothing will happen. If it is over 255 it will
 *  be changed to 255, if it is below 0 it will become 0.
 *
 *  @par Example
 *  @verbatim

    int val = 200;
    val2 = valCheck(val);
    return val2; //200

    @endverbatim
 ************************************************************************/

int valCheck(int val)
{
    if (val > 255)
    {
        val = 255;
        return val;
    }
    if (val < 0)
    {
        val = 0;
        return val;
    }
    return val;
}

