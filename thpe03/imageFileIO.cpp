/** **********************************************************************
 * @file
 ************************************************************************/

#include "netPBM.h"

/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *
 *  This function takes 2 arguments. The first is the input file
 *  stream containing the file to open. The second is the file name.
 *  
 *  @param[in] fin An input file stream.
 *  
 *  @param[in] fileName The name of the file to read data from.
 *
 *  @returns A boolean value, true or false. True if the
 *  file opened properly, false otherwise.
 *
 *  @par Example
 *  @verbatim

    bool check;
    check  = openFile(fin, filename);
    return check;

    @endverbatim
 ************************************************************************/


bool openBFile(ifstream& fin, char *fileName)
{
    fin.open(fileName, ios::binary);
    if (!fin.is_open())
    {
        cout << "Unable to open file: " << fileName << endl;
        return false;
    }
    return true;
}



/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *
 *  This function takes 2 arguments. The first is the output file
 *  stream containing the file to output to. The second is the file name.
 *  This function should only be used for outputting in binary.
 *
 *  @param[in] fout An output file stream.
 *  
 *  @param[in] fileName The name of the file to write data to.
 *
 *  @returns A boolean value, true or false. True if the
 *  file opened properly, false otherwise.
 *
 *  @par Example
 *  @verbatim

    bool check;
    check  = openBOut(fout, filename);
    return check;

    @endverbatim
 ************************************************************************/


bool openBOut(ofstream& fout, char* fileName)
{
    fout.open(fileName, ios::ate | ios::binary);
    if (!fout.is_open())
    {
        cout << "Unable to open file: " << fileName << endl;
        return false;
    }
    return true;
}


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *
 *  This function takes 2 arguments. The first is the input file
 *  stream containing the file with data to read. The second is the structure to
 *  be filled with data. This function fills the header elements of the image.
 *  The magic Number, comments, rows, and columns.
 *  
 *  @param[in] fin An input file stream to read data from.
 *
 *  @param[in] data The structure to hold the data.
 *
 *
 *  @par Example
 *  @verbatim

    readData(fin, image structure);

    @endverbatim
 ************************************************************************/

void readHeader(ifstream& fin, image& data)
{
    int max;
    string com;
    fin >> data.magicNumber;
    fin.ignore();
    while (fin.peek() == 35)
    {
        getline(fin, com);
        data.comment += com;
        data.comment += '\n';
    }
    fin >> data.cols;
    fin >> data.rows;
    fin >> max;
}


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *
 *  This function takes 2 arguments. The first is the input file
 *  stream containing the file with data to read. The second is the structure to
 *  be filled with data. This function uses the magic number within
 *  the image data to determine if the rest of the file should be read
 *  in as ascii or binary.
 *
 *
 *  @param[in] fin An input file stream to read data from.
 *
 *  @param[in] data The structure to hold the data.
 * 
 *
 *  @par Example
 *  @verbatim

    readFile(fin, image structure);

    @endverbatim
 ************************************************************************/


void readFile(ifstream& fin, image &data)
{
    if (data.magicNumber == "P3")
    {
        readAscii(fin, data);
    }
    if (data.magicNumber == "P6")
    {
        readBin(fin, data);
    }
}


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *
 *  This function takes 2 arguments. The first is the input file
 *  stream containing the file with data to read. The second is the structure to
 *  be filled with data. This function will read a file in as Ascii.
 *
 *
 *  @param[in] fin An input file stream to read data from.
 *
 *  @param[in] data The structure to hold the data.
 * 
 * 
 *  @par Example
 *  @verbatim

    readAscii(fin, image structure);

    @endverbatim
 ************************************************************************/

void readAscii(ifstream& fin, image &data)
{
    int i = 0;
    int j = 0;
    fin.ignore();
    int R, G, B = 0;
    for (i = 0; i < data.rows; i++)
    {
        for (j = 0; j < data.cols; j++)
        {
            fin >> R >> G >> B;
            data.redgray[i][j] = R;
            data.green[i][j] = G;
            data.blue[i][j] = B;
        }
    }
}


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *
 *  This function takes 2 arguments. The first is the input file
 *  stream containing the file with data to read. The second is the structure to
 *  be filled with data. This function will read a file in as Binary.
 *
 *
 *  @param[in] fin An input file stream to read data from.
 *
 *  @param[in] data The structure to hold the data.
 * 
 *
 *  @par Example
 *  @verbatim

    readBin(fin, image structure);

    @endverbatim
 ************************************************************************/


void readBin(ifstream& fin, image &data)
{
    int i = 0;
    int j = 0;
    fin.ignore();
    for (i = 0; i < data.rows; i++)
    {
        for (j = 0; j < data.cols; j++)
        {
            fin.read((char*) &data.redgray[i][j], sizeof(pixel));
            fin.read((char*)&data.green[i][j], sizeof(pixel));
            fin.read((char*)&data.blue[i][j], sizeof(pixel));
        }
    }
}


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *
 *  This function takes 2 arguments. The first is the output file
 *  stream containing the file to write to. The second is the structure
 *  filled with data. This function will write to a file in Ascii.
 *
 *
 *  @param[in] &fout An output file stream to write data to.
 *
 *  @param[in] &data The structure to hold the data.
 * 
 *
 *  @par Example
 *  @verbatim

    writeAscii(fout, image structure);

    @endverbatim
 ************************************************************************/

void writeAscii(ofstream& fout, image &data)
{
    int i, j;
    int max = 255;
    fout << data.magicNumber << '\n';
    fout << data.comment;
    fout << data.cols << " " << data.rows << '\n';
    fout << max << '\n';
    for (i = 0; i < data.rows; i++)
    {
        for (j = 0; j < data.cols; j++)
        {
            fout << (int)data.redgray[i][j] << " " << (int)data.green[i][j] << " " << (int)data.blue[i][j] << '\n';
        }
    }
}


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *
 *  This function takes 2 arguments. The first is the output file
 *  stream containing the file to write to. The second is the structure
 *  filled with data. This function will write to a file in Binary.
 *
 *
 *  @param[in] fout An output file stream to write data to.
 *
 *  @param[in] data The structure to hold the data.
 * 
 *
 *  @par Example
 *  @verbatim

    writeBinary(fout, image structure);

    @endverbatim
 ************************************************************************/

void writeBinary(ofstream& fout, image &data)
{
    int i, j;
    int max = 255;
    fout << data.magicNumber << '\n';
    fout << data.comment;
    fout << data.cols << " " << data.rows << '\n';
    fout << max << '\n';
    for (i = 0; i < data.rows; i++)
    {
        for (j = 0; j < data.cols; j++)
        {
            fout.write((char*) &data.redgray[i][j], sizeof(pixel));
            fout.write((char*)&data.green[i][j], sizeof(pixel));
            fout.write((char*)&data.blue[i][j], sizeof(pixel));
        }
    }
}


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *
 *  This function takes 2 arguments. The first is the output file
 *  stream containing the file to write to. The second is the structure
 *  filled with data. This function will write to a file in Ascii.
 *  This function only outputs the redgray array, and thus is used for grayscale.
 *
 *
 *  @param[in] fout An output file stream to write data to.
 *
 *  @param[in] data The structure to hold the data.
 * 
 *
 *  @par Example
 *  @verbatim

    writeGray(fout, image structure);

    @endverbatim
 ************************************************************************/

void writeGray(ofstream& fout, image& data)
{
    int i, j;
    int max = 255;
    fout << data.magicNumber << endl;
    fout << data.comment;
    fout << data.cols << " " << data.rows << endl;
    fout << max << endl;;
    for (i = 0; i < data.rows; i++)
    {
        for (j = 0; j < data.cols; j++)
        {
            fout << (int)data.redgray[i][j] << endl;
        }
    }
}

/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *
 *  This function takes 2 arguments. The first is the output file
 *  stream containing the file to write to. The second is the structure
 *  filled with data. This function will write to a file in Binary.
 *  This function only outputs the redgray array, and thus is used for grayscale.
 *
 *
 *  @param[in] fout An output file stream to write data to.
 *
 *  @param[in] data The structure to hold the data.
 * 
 *
 *  @par Example
 *  @verbatim

    writeGrayB(fout, image structure);

    @endverbatim
 ************************************************************************/


void writeGrayB(ofstream& fout, image& data)
{
    int i, j;
    int max = 255;
    fout << data.magicNumber << '\n';
    fout << data.comment;
    fout << data.cols << " " << data.rows << '\n';
    fout << max << '\n';
    for (i = 0; i < data.rows; i++)
    {
        for (j = 0; j < data.cols; j++)
        {
            fout.write((char*)&data.redgray[i][j], sizeof(pixel));
        }
    }
}


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *
 *  This function takes 5 arguments. The first is the output
 *  type requested by the user, either --ascii or --binary.
 *  The second is the output file variable.
 *  The third is the structure containing the image data.
 *  the fourth is the file that will be output.
 *  This function will assess the output type, ascii or binary
 *  and then it will append a .ppm to the output file name.
 *  Finally, it will write out the contents of the structure
 *
 *  @param[in] type A cstyle string containing the requested output type.
 * 
 *  @param[in] fout An output file stream to write data to
 *  
 *  @param[in] data The structure containing data to pull from.
 * 
 *  @param[in] fileOut The name of the file to be written to.
 * 
 * 
 *  @returns A boolean value, true or false. True if the data has
 *  been written sucessfully to the file
 *
 *  @par Example
 *  @verbatim

    bool outCheck;
    outCheck = outputType(type, fout, imgdata, fileout);

    @endverbatim
 ************************************************************************/

bool outputType(char* type, ofstream &fout, image &data, char *fileOut)
{
    char fileHolder[30];
    char color[10] = ".ppm";  
    if (strcmp(type, "--ascii") == 0)
    {
        data.magicNumber = "P3";
        strcpy(fileHolder, fileOut);
        strcat(fileHolder, color);
        bool checkFile2 = openBOut(fout, fileHolder);
        if (checkFile2 == false)
        {
            return false;
        }
        writeAscii(fout, data);
        return true;

    }
    if (strcmp(type, "--binary") == 0)
    {
        data.magicNumber = "P6";
        strcpy(fileHolder, fileOut);
        strcat(fileHolder, color);
        bool checkFile = openBOut(fout, fileHolder);
        if (checkFile == false)
        {
            return false;
        }
        writeBinary(fout, data);
        return true;
    }
    return false;
    cout << "Invalid Startup" << endl;
    usageState();
}

/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *
 *  This function takes 5 arguments. The first is the output
 *  type requested by the user, either --ascii or --binary.
 *  The second is the output file variable.
 *  The third is the structure containing the image data.
 *  the fourth is the file that will be output.
 *  This function will assess the output type, ascii or binary
 *  and then it will append a .pgm to the output file name.
 *  Finally, it will write out the contents of the structure
 *  This function is meant for use to output grayscale images.
 *
 *  @param[in] type A cstyle string containing the requested output type.
 * 
 *  @param[in] fout An output file stream to write data to
 *  
 *  @param[in] data The structure containing data to pull from.
 * 
 *  @param[in] fileOut The name of the file to be written to.
 * 
 * 
 *  @returns A boolean value, true or false. True if the data has
 *  been written out to the file successfully.
 * 
 *  @par Example
 *  @verbatim

    bool outCheck;
    outCheck = outputGray(type, fout, imgdata, fileout);

    @endverbatim
 ************************************************************************/

bool outGray(char* type, ofstream& fout, image& data, char* fileOut)
{
    char fileHolder[30];
    char color[10] = ".pgm";
    if (strcmp(type, "--ascii") == 0)
    {
        data.magicNumber = "P2";
        strcpy(fileHolder, fileOut);
        strcat(fileHolder, color);
        bool checkFile2 = openBOut(fout, fileHolder);
        if (checkFile2 == false)
        {
            return false;
        }
        writeGray(fout, data);
        return true;
    }
    if (strcmp(type, "--binary") == 0)
    {
        data.magicNumber = "P5";
        strcpy(fileHolder, fileOut);
        strcat(fileHolder, color);
        bool checkFile = openBOut(fout, fileHolder);
        if (checkFile == false)
        {
            return false;
        }
        writeGrayB(fout, data);
        return true;
    }
    return false;
    cout << "Invalid Startup" << endl;
    usageState();
}






