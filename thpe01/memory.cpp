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

bool allocArray(image &data)
{
    data.redgray = allocRed(data.cols, data.rows);
    if (data.redgray == nullptr)
    {
        return false;
    }
    data.green = allocGreen(data.cols, data.rows);
    if (data.green == nullptr)
    {
        return false;
    }
    data.blue = allocBlue(data.cols, data.rows);
    if (data.blue == nullptr)
    {
        return false;
    }
    return true;
}

pixel** allocGray(int cols, int rows)
{
    int i = 0;
    int j = 0;
    pixel** grayptr = nullptr;
    grayptr = new(nothrow) pixel * [cols];
    if (grayptr == nullptr)
    {
        cout << "Memory Allocation Error" << endl;
        return nullptr;
    }
    for (i = 0; i < cols; i++)
    {
        grayptr[i] = new (nothrow) pixel[rows];
        if (grayptr[i] == nullptr)
        {
            for (j = 0; j < i; j++)
            {
                delete[] grayptr[j];
            }
            delete[] grayptr;
            cout << "Memory Allocation Error" << endl;
            grayptr = nullptr;
            return grayptr;
        }
    }
    return grayptr;
}


void free2D(pixel** arr, int cols)
{
    int i;
    if (arr == nullptr)
    {
        return;
    }
    for (i = 0; i < cols; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    arr = nullptr;
}


