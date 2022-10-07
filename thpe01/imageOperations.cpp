#include "netPBM.h"

void negate(image& data)
{
    int i, j;
    for (i = 0; i < data.cols; i++)
    {
        for (j = 0; j < data.rows; j++)
        {
            data.redgray[i][j] = 255 - data.redgray[i][j];
            data.green[i][j] = 255 - data.green[i][j];
            data.blue[i][j] = 255 - data.blue[i][j];
        }
    }
}

void Grayscale(image& data)
{
    int i, j;
    int cols = data.cols;
    int rows = data.rows;
    pixel** grayArr = allocGray(cols, rows);
    for (i = 0; i < data.cols; i++)
    {
        for (j = 0; j < data.rows; j++)
        {
            grayArr[i][j] = .3 * data.redgray[i][j] + .6 * data.green[i][j] + .1 * data.blue[i][j];
        }
    }
}