/** **********************************************************************
 * @file
 ************************************************************************/

#include "netPBM.h"


 /** **********************************************************************
  *  @author Nicholas K Wilk
  *
  *  @par Description
  *
  *  This function will take in 2 arguments, both in the form of integers.
  *  The first argument is the rows, the second is the columns.
  *  These are used to dynamically allocate a 2d array to hold all
  *  the red values of the image.
  *
  *
  *  @returns a 2d pixel array pointer, where pixel is an unsigned char. It returns nullptr if it fails.
  *
  *  @par Example
  *  @verbatim

     pixel** rptr = allocRed(columns, rows);
     return rptr;

     @endverbatim
  ************************************************************************/


pixel** allocRed( int columns, int rows)
{
    int i = 0;
    int j = 0;
    pixel** rptr=nullptr;
    rptr = new(nothrow) pixel* [columns];
    if (rptr == nullptr)
    {
        cout << "Memory Allocation Error" << endl;
        return nullptr;
    }
    for (i = 0; i < columns; i++)
    {
        rptr[i] = new (nothrow) pixel [rows];
        if (rptr[i] == nullptr)
        {
            for (j = 0; j < i; j++)
            {
                delete[] rptr[j];
            }
            delete[] rptr;
            cout << "Memory Allocation Error" << endl;
            rptr = nullptr;
            return rptr;
        }
    }
    return rptr;
}


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *
 *  This function will take in 2 arguments, both in the form of integers.
 *  The first argument is the rows, the second is the columns.
 *  These are used to dynamically allocate a 2d array to hold all
 *  the green values of the image.
 *
 *
 *  @returns a 2d pixel array pointer, where pixel is an unsigned char. It returns nullptr if it fails.
 *
 *  @par Example
 *  @verbatim

    pixel** gptr = allocGreen(columns, rows);
    return gptr;

    @endverbatim
 ************************************************************************/


pixel** allocGreen( int columns, int rows)
{
    int i = 0;
    int j = 0;
    pixel** gptr = nullptr;
    gptr = new(nothrow) pixel *[columns];
    if (gptr == nullptr)
    {
        cout << "Memory Allocation Error" << endl;
        return nullptr;
    }
    for (i = 0; i < columns; i++)
    {
        gptr[i] = new (nothrow) pixel [rows];
        if (gptr[i] == nullptr)
        {
            for (j = 0; j < i; j++)
            {
                delete[] gptr[j];
            }
            delete[] gptr;
            cout << "Memory Allocation Error" << endl;
            gptr = nullptr;
            return gptr;
        }
    }
    return gptr;
}

/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *
 *  This function will take in 2 arguments, both in the form of integers.
 *  The first argument is the rows, the second is the columns.
 *  These are used to dynamically allocate a 2d array to hold all
 *  the blue values of the image.
 *
 *
 *  @returns a 2d pixel array pointer, where pixel is an unsigned char. It returns nullptr if it fails.
 *
 *  @par Example
 *  @verbatim

    pixel** bptr = allocBlue(columns, rows);
    return bptr;

    @endverbatim
 ************************************************************************/


pixel** allocBlue( int columns, int rows)
{
    int i = 0;
    int j = 0;
    pixel** bptr=nullptr;
    bptr = new(nothrow) pixel *[columns];
    if (bptr == nullptr)
    {
        cout << "Memory Allocation Error" << endl;
        return nullptr;
    }
    for (i = 0; i < columns; i++)
    {
        bptr[i] = new (nothrow) pixel [rows];
        if (bptr[i] == nullptr)
        {
            for (j = 0; j < i; j++)
            {
                delete[] bptr[j];
            }
            delete[] bptr;
            cout << "Memory Allocation Error" << endl;
            bptr = nullptr;
            return bptr;
        }
    }
    return bptr;
}


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *
 *  This function will take in 1 argument, which is the structure containting
 *  the data of the image. This function will then call the three dynamic allocation
 *  functions to dynamically allocate all 3 arrays.
 *
 *
 *  @returns True if all three arrays are successfully allocated, false if any fail..
 *
 *  @par Example
 *  @verbatim

    bool allocCheck = allocArray(imgData);
    return allocCheck;

    @endverbatim
 ************************************************************************/

bool allocArray(image &data)
{
    data.redgray = allocRed(data.rows, data.cols);
    if (data.redgray == nullptr)
    {
        return false;
    }
    data.green = allocGreen(data.rows, data.cols);
    if (data.green == nullptr)
    {
        return false;
    }
    data.blue = allocBlue(data.rows, data.cols);
    if (data.blue == nullptr)
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
 *  This function will take in 2 arguments, the first is the array to be deleted.
 *  The second is the columns of the array. 
 *  This function has no return, it will delete the contents of a 2d array
 *  and then it will delete the array itself, and set it to nullptr.
 *
 *
 *  @par Example
 *  @verbatim

    free2d(redarr, imgData.cols);

    @endverbatim
 ************************************************************************/


void free2D(pixel** arr, int cols)
{
    int i;
    if (arr == nullptr)
    {
        exit(0);
    }
    for (i = 0; i < cols; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    arr = nullptr;
}


bool allocNArray(pixel ** &arr, image &data)
{
    arr = allocRed(data.rows, data.cols);
    if (arr == nullptr)
    {
        return false;
    }
    return true;
}

