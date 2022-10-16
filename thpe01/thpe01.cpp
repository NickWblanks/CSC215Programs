/** **********************************************************************
 * @file
 ************************************************************************/


#include "netPBM.h"

 /** **********************************************************************
  *  @author Nicholas K Wilk
  *
  *  @par Description
  *
  *  The Main function reads in data from the command line.
  *  When the user accesses this program from the command line,
  *  they must specify the arguments, those arguments are stored into
  *  argc and argv.
  *
  *  @param[in] argc The number of arguments provided to the program.
  *  @param[in] argv An array holding all of the arguments provided..
  *
  *  @returns An integer typically 0 if the program ran successfully.
  *
  *  @par Example
  *  @verbatim

     thpe01.exe --option --outtype outfile infile
     Returns 0 if the program ran successfully.

     @endverbatim
  ************************************************************************/

int main(int argc, char** argv)
{
    image imgData;
    ifstream fin;
    ofstream fout;
    bool check, count, output, type;
    int option, value;
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
            type = invalidType(argv[3]);
            if (type == false)
            {
                cout << "Invalid Startup" << endl;
                usageState();
                return 0;
            }
            check = readManip(imgData, fin, argv[5]);
            if (check == false)
            {
                return 0;
            }
            value = atoi(argv[2]);
            Brighten(value, imgData);
            output = outputType(argv[3], fout, imgData, argv[4]);
        }
    }
    if (argc == 5)
    {
        type = invalidType(argv[2]);
        if (type == false)
        {
            cout << "Invalid Startup" << endl;
            usageState();
            return 0;
        }
        bool opt = options(argv[1], argv[2], argv[3], argv[4], fin, fout, imgData);
        if (opt == false)
        {
            return 0;
        }
    }
    if (argc < 5)
    {
        type = invalidType(argv[1]);
        if (type == false)
        {
            cout << "Invalid Startup" << endl;
            usageState();
            return 0;
        }
        check = noOptions(argv[1], argv[2], argv[3], imgData, fin, fout);
        if (check == false)
        {
            return 0;
        }
    }
    free2D(imgData.redgray, imgData.rows);
    free2D(imgData.green, imgData.rows);
    free2D(imgData.blue, imgData.rows);
    fin.close();
    fout.close();
    return 0;
}


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *
 *  This function will take in the arguments of the program and pass them to functions.
 *  It is passed only when no options are requested.
 * 
 *  arg1 is the requested output such as --binary/--ascii.
 *  arg2 is the file to be outputted to.
 *  arg3 is the input file to read data from.
 *  data is the structure containing the image data to be read in and wrote out.
 *  fin is the variable to holds the input file for reading (arg3).
 *  fout is the variable that holds the output file for writing (arg2).
 * 
 * 
 *  @param[in] arg1 A cstyle string that represents the output type.
 *  @param[in] arg2 A cstyle string that represents the output file.
 *  @param[in] arg3 A cstyle string that represents the input file.
 *  @param[in] data The structure to hold the image data.
 *  @param[in] fin An input file stream variable.
 *  @param[in] fout An output file stream variable.

 * 
 *  @returns True or False. True if all tasks completed sucesfully, false if not.
 *
 *  @par Example
 *  @verbatim

    bool check = noOptions(outType, outFile, inFile, imgData, fin, fout);
    return check;

    @endverbatim
 ************************************************************************/


bool noOptions(char* arg1, char* arg2, char* arg3, image& data, ifstream& fin, ofstream& fout)
{
    bool output, mCheck;
    bool checkFile = openBFile(fin, arg3);
    if (checkFile == false)
    {
        return false;
    }
    readHeader(fin, data);
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
    output = outputType(arg1, fout, data, arg2);
    if (output == false)
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
 *  This function will take in three arguments, the structure, the input file
 *  and the file to open. It is called to open and read the contents
 *  of the file to the structure. As well as checking if it is a valid image.
 *
 *  @param[in] data The structure containing the image data to be read in.
 *  @param[in] fin The variable to holds the input file for reading.
 *  @param[in] file A cstyle string holding the name of the file to open.
 *
 *  @returns True or False. True if the file was opened and contains a valid
 *  image, false if not.
 *
 *  @par Example
 *  @verbatim

    bool check = readManip(imgData, fin, fileInName);
    return check;

    @endverbatim
 ************************************************************************/



bool readManip(image& data, ifstream& fin, char* file)
{
    bool checkFile2, mCheck;
    checkFile2 = openBFile(fin, file); //argv[4]
    readHeader(fin, data);
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


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *
 *  This function will take in the arguments of the program and pass them to functions.
 *  It is called when options are requested.
 *
 *  arg1 is the requested option such as --grayscale/--brighten.
 *  arg2 is the requested output type.
 *  arg3 is the output file to write data to.
 *  arg4 is the input file to read data from.
 *  fin is the variable to holds the input file for reading (arg3).
 *  fout is the variable that holds the output file for writing (arg2).
 *
 *  @param[in] arg1 A cstyle string that represents the option.
 *  @param[in] arg2 A cstyle string that represents the output type.
 *  @param[in] arg3 A cstyle string that represents the output file.
 *  @param[in] arg4 A cstyle string that represents the input file.
 *  @param[in] fin An input file stream variable.
 *  @param[in] fout An output file stream variable.
 *  @param[in] data The structure to hold the data.
 * 
 *  @returns True or False. True if all tasks completed sucesfully, false if not.
 *
 *  @par Example
 *  @verbatim

    bool check = options(option, outType, outFile, inFile, fin, fout, imgData);
    return check;

    @endverbatim
 ************************************************************************/


bool options(char* arg1, char* arg2, char* arg3, char* arg4, ifstream& fin, ofstream& fout, image& data)
{
    pixel** newRed;
    pixel** newGreen;
    pixel** newBlue;
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
        output = outputType(arg2, fout, data, arg3);
    }
    if (option == 3)
    {
        check = readManip(data, fin, arg4);
        if (check == false)
        {
            return false;
        }
        newRed = allocRed(data.rows, data.cols);
        newGreen = allocGreen(data.rows, data.cols);
        newBlue = allocBlue(data.rows, data.cols);
        sharpen(data, newRed, newGreen, newBlue);
        output = outputType(arg2, fout, data, arg3);
    }
    if (option == 4)
    {
        check = readManip(data, fin, arg4);
        if (check == false)
        {
            return false;
        }
        newRed = allocRed(data.rows, data.cols);
        newGreen = allocGreen(data.rows, data.cols);
        newBlue = allocBlue(data.rows, data.cols);
        smooth(data, newRed, newGreen, newBlue);
        output = outputType(arg2, fout, data, arg3);
    }
    if (option == 5)
    {
        check = readManip(data, fin, arg4);
        if (check == false)
        {
            return false;
        }
        Grayscale(data);
        output = outGray(arg2, fout, data, arg3);
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
        output = outGray(arg2, fout, data, arg3);
    }
    if (option == 0)
    {
        return false;
    }
    return true;
}



