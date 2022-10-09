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

pixel** Grayscale(image& data)
{
    int i, j;
    int cols = data.cols;
    int rows = data.rows;
    for (i = 0; i < data.cols; i++)
    {
        for (j = 0; j < data.rows; j++)
        {
            data.redgray[i][j] = .3 * data.redgray[i][j] + .6 * data.green[i][j] + .1 * data.blue[i][j];
        }
    }
    return data.redgray;
}


void Brighten( char* arg2, image& data)
{
    int val = atoi(arg2);
    int i, j;
    for (i = 0; i < data.cols; i++)
    {
        for (j = 0; j < data.rows; j++)
        {
            data.redgray[i][j] = (int)data.redgray[i][j] + val;
            data.green[i][j] = (int)data.green[i][j] + val;
            data.blue[i][j] = (int)data.blue[i][j] + val;
            if ((int)data.redgray[i][j] > 255 )
            {
                data.redgray[i][j] = 255;
            }
            if ((int)data.redgray[i][j] < 0)
            {
                data.redgray[i][j] = 0;
            }
            if ((int)data.green[i][j] > 255)
            {
                data.green[i][j] = 255;
            }
            if ((int)data.green[i][j] < 0)
            {
                data.green[i][j] = 0;
            }
            if ((int)data.blue[i][j] > 255)
            {
                data.blue[i][j] = 255;
            }
            if ((int)data.blue[i][j] < 0)
            {
                data.blue[i][j] = 0;
            }     
        }
    }
}
