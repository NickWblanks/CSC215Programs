#include "netPBM.h"

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

bool allocArray()
{
    image imgData;
    imgData.redgray = allocRed(imgData.cols, imgData.rows);
    if (imgData.redgray == nullptr)
    {
        return false;
    }
    imgData.green = allocGreen(imgData.cols, imgData.rows);
    if (imgData.green == nullptr)
    {
        return false;
    }
    imgData.blue = allocBlue(imgData.cols, imgData.rows);
    if (imgData.blue == nullptr)
    {
        return false;
    }
    return true;
}


