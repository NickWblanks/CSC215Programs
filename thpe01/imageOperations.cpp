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
    for (i = 0; i < cols; i++)
    {
        for (j = 0; j < rows; j++)
        {
            data.redgray[i][j] = .3 * data.redgray[i][j] + .6 * data.green[i][j] + .1 * data.blue[i][j];
        }
    }
}


void contrast(image& data)
{
    int min, max;
    int i = 0, j = 0;
    double scale;
    min = data.redgray[i][j];
    for (i = 0; i < data.cols; i++)
    {
        for (j = 1; j < data.rows; j++)
        {
            if (data.redgray[i][j] < min)
            {
                min = data.redgray[i][j];
            }
        }
    }
    max = data.redgray[0][0];
    for (i = 0; i < data.cols; i++)
    {
        for (j = 1; j < data.rows; j++)
        {
            if (data.redgray[i][j] > max)
            {
                max = data.redgray[i][j];
            }
        }
    }
    scale = 255 / (max - min);
    for (i = 0; i < data.cols; i++)
    {
        for (j = 0; j < data.rows; j++)
        {
            data.redgray[i][j] = scale * (data.redgray[i][j] - min);
        }
    }

}

void Brighten( char* arg2, image& data)
{
    int val = atoi(arg2);
    unsigned long int newval, finalVal;
    int i, j;
    for (i = 0; i < data.cols; i++)
    {
        for (j = 0; j < data.rows; j++)
        {
            newval = data.redgray[i][j];
            finalVal = newval + val;
            if (finalVal > 255)
            {
                finalVal = 255;
                data.redgray[i][j] = (pixel)finalVal;
            }
            if (finalVal < 0)
            {
                finalVal = 0;
                data.redgray[i][j] = (pixel)finalVal;
            }
            data.redgray[i][j] = (pixel)finalVal;
            newval = data.green[i][j];
            finalVal = newval + val;
            if (finalVal > 255)
            {
                finalVal = 255;
                data.green[i][j] = (pixel)finalVal;
            }
            if (finalVal < 0)
            {
                finalVal = 0;
                data.green[i][j] = (pixel)finalVal;
            }
            data.green[i][j] = (pixel)finalVal;
            newval = data.blue[i][j];
            finalVal = newval + val;
            if (finalVal > 255)
            {
                finalVal = 255;
                data.blue[i][j] = (pixel)finalVal;
            }
            if (finalVal < 0)
            {
                finalVal = 0;
                data.blue[i][j] = (pixel)finalVal;
            }
            data.blue[i][j] = (pixel)finalVal;
        }
    }
}
