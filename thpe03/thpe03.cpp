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

     thpe03.exe file --row --column redvalue greenvalue bluevalue
     Returns 0 if the program ran successfully.

     @endverbatim
  ************************************************************************/

int main(int argc, char** argv)
{
    int red, green, blue, row, col;
    bool ifCheck, ofcheck, arrCheck;
    image imgData;
    ifstream fin;
    ofstream fout;
    color newColor;
    color Old;
    string usage = "thpe03.exe imageFile row col redValue greenValue blueValue";
    if (argc != 7)
    {
        cout << usage << endl;
        return 0;
    }
    ifCheck = openBFile(fin, argv[1]);
    if (ifCheck == false)
    {
        return 0;
    }
    //getting the row and column
    row = stoi(argv[2]);
    col = stoi(argv[3]);
    //obtaining new vals, storing them in struct
    red = stoi(argv[4]);
    newColor.red = red;
    green = stoi(argv[5]);
    newColor.green = green;
    blue = stoi(argv[6]);
    newColor.blue = blue;
    //reading the header in
    readHeader(fin, imgData);
    arrCheck = allocArray(imgData); //checking mem allocation
    if (arrCheck == false)
    {
        cout << "Memory allocation failed" << endl;
        return 0;
    }
    readFile(fin, imgData); //reading file
    //storing the value in each array into a new struct
    Old.red = imgData.redgray[row][col];
    Old.green = imgData.green[row][col];
    Old.blue = imgData.blue[row][col];
    floodFill(row, col, imgData, newColor, Old);//bucket filling the region.
    if (imgData.magicNumber == "P3") //checking if file was ascii
    {
        fin.close();
        ofcheck = openBOut(fout, argv[1]);
        if (ofcheck == false)
        {
            cout << "Unable to open output file: " << argv[1] << endl;
            return 0;
        }
        writeAscii(fout, imgData); //writing out new data
    }
    if (imgData.magicNumber == "P6") //checking if file was binary
    {
        fin.close();
        ofcheck = openBOut(fout, argv[1]);
        if (ofcheck == false)
        {
            cout << "Unable to open output file: " << argv[1] << endl;
            return 0;
        }
        writeBinary(fout, imgData);//write out new data
    }
    return 0;
}

