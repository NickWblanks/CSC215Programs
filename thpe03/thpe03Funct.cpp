#include "netPBM.h"

void floodFill(int &row, int &col, image& data, color &newColor)
{
    
}

void change(int r, int g, int b, image& data, int row, int col)
{
    if (data.redgray[row][col] != 0)
    {
        if (data.green[row][col] != 0)
        {
            if (data.blue[row][col] != 0)
            {
                data.redgray[row][col] = r;
                data.green[row][col] = g;
                data.blue[row][col] = b;
            }
        }
    }
}