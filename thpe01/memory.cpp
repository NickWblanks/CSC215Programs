#include "netPBM.h"

bool allocRed(int rows, int columns)
{
    int i = 0;
    int j = 0;
    pixel** rptr;
    rptr = new(nothrow) pixel* [rows];
    if (rptr == nullptr)
    {
        cout << "Memory Allocation Error" << endl;
        return false;
    }
    for (i = 0; i < rows; i++)
    {
        rptr[i] = new (nothrow) pixel[columns];
        if (rptr[i] == nullptr)
        {
            for (j = 0; j < i; j++)
            {
                delete[] rptr[j];
            }
            delete[] rptr;
            cout << "Memory Allocation Error" << endl;
            return false;
        }
    }
    return true;
}

bool allocGreen(int rows, int columns)
{
    int i = 0;
    int j = 0;
    pixel** gptr;
    gptr = new(nothrow) pixel * [rows];
    if (gptr == nullptr)
    {
        cout << "Memory Allocation Error" << endl;
        return false;
    }
    for (i = 0; i < rows; i++)
    {
        gptr[i] = new (nothrow) pixel[columns];
        if (gptr[i] == nullptr)
        {
            for (j = 0; j < i; j++)
            {
                delete[] gptr[j];
            }
            delete[] gptr;
            cout << "Memory Allocation Error" << endl;
            return false;
        }
    }
    return true;
}

bool allocBlue(int rows, int columns)
{
    int i = 0;
    int j = 0;
    pixel** bptr;
    bptr = new(nothrow) pixel * [rows];
    if (bptr == nullptr)
    {
        cout << "Memory Allocation Error" << endl;
        return false;
    }
    for (i = 0; i < rows; i++)
    {
        bptr[i] = new (nothrow) pixel[columns];
        if (bptr[i] == nullptr)
        {
            for (j = 0; j < i; j++)
            {
                delete[] bptr[j];
            }
            delete[] bptr;
            cout << "Memory Allocation Error" << endl;
            return false;
        }
    }
    return true;
}

