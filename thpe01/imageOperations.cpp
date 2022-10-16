/** **********************************************************************
 * @file
 ************************************************************************/


#include "netPBM.h"


 /** **********************************************************************
  *  @author Nicholas K Wilk
  *
  *  @par Description
  *
  *  This function will take in the structure containing the data of the image
  *  and perform the --negate option. It has no return value.
  *  
  *  @param[in] data the structure containing data to manipulate.
  *
  *  @par Example
  *  @verbatim

     image imgData;
     negate(imgData)

     @endverbatim
  ************************************************************************/


void negate(image& data)
{
    int i, j;
    for (i = 0; i < data.rows; i++)
    {
        for (j = 0; j < data.cols; j++)
        {
            data.redgray[i][j] = 255 - data.redgray[i][j];
            data.green[i][j] = 255 - data.green[i][j];
            data.blue[i][j] = 255 - data.blue[i][j];
        }
    }
}


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *
 *  This function will take in the structure containing the data of the image
 *  and perform the --grayscale option. It has no return value.
 *
 *  @param[in] data the structure containing data to manipulate.
 *
 *  @par Example
 *  @verbatim
 
    image imgData;
    Grayscale(imgData)

    @endverbatim
 ************************************************************************/

void Grayscale(image& data)
{
    int i, j;
    double redVal, greenVal, blueVal, finalVal;
    int cols = data.rows;
    int rows = data.cols;
    for (i = 0; i < cols; i++)
    {
        for (j = 0; j < rows; j++)
        {
            redVal = data.redgray[i][j];
            greenVal = data.green[i][j];
            blueVal = data.blue[i][j];
            finalVal = .3 * redVal + .6 * greenVal + .1 * blueVal;
            round(finalVal);
            data.redgray[i][j] = (pixel)finalVal;
        }
    }
}


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *
 *  This function will take in the structure containing the data of the image
 *  and perform the --contrast option. It has no return value.
 *
 *  @param[in] data the structure containing data to manipulate.
 *
 *  @par Example
 *  @verbatim

    image imgData;
    contrast(imgData)

    @endverbatim
 ************************************************************************/

void contrast(image& data)
{
    int min, max;
    double minVal, maxVal;
    int i = 0, j = 0;
    double scale, finalVal;
    min = data.redgray[0][0];
    for (i = 0; i < data.rows; i++)
    {
        for (j = 1; j < data.cols; j++)
        {
            if ((int)data.redgray[i][j] < min)
            {
                min = data.redgray[i][j];
            }
        }
    }
    max = data.redgray[0][0];
    for (i = 0; i < data.rows; i++)
    {
        for (j = 1; j < data.cols; j++)
        {
            if ((int)data.redgray[i][j] > max)
            {
                max = data.redgray[i][j];
            }
        }
    }
    minVal = min;
    maxVal = max;
    scale = 255.0 / (maxVal - minVal);
    round(scale);
    for (i = 0; i < data.rows; i++)
    {
        for (j = 0; j < data.cols; j++)
        {
            finalVal = scale * ((int)data.redgray[i][j] - min);
            round(finalVal);
            data.redgray[i][j] = (pixel)finalVal;
        }
    }

}

/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *
 *  This function will take in the value to brighten, which is passed in through cmd line args. 
 *  The second argument is the structure containing the data of the image.
 *  It will perform the --brighten option. It has no return value.
 *  The value specified must be between -255 and 255.
 *
 *
 *  @param[in] val An integer value to brighten or darken the image..
 *  @param[in] data the structure containing data to manipulate.
 *
 *  @par Example
 *  @verbatim

    image imgData;
    Brighten(90, imgData)

    @endverbatim
 ************************************************************************/

void Brighten( int val, image& data)
{
    int newval, finalVal;
    int i, j;
    for (i = 0; i < data.rows; i++)
    {
        for (j = 0; j < data.cols; j++)
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


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *
 *  This fucntion takes 4 arguments, the first is the image data,
 *  the second is the new Red array, the third is the new green, 
 *  and the fourth is the new blue.
 *  It will manipulate the values of the image, store them into the new
 *  arrays and then use them to populate the imgData structure.
 *
 *
 *  @param[in] data the structure containing data to manipulate.  
 *  @param[in] Red A new 2d pointer array representing the red spectrum..
 *  @param[in] Green A new 2d pointer array representing the green spectrum.
 *  @param[in] Blue A new 2d pointer array representing the blue spectrum.
 * 
 * 
 *  @par Example
 *  @verbatim

    image imgData;
    pixel ** newRed, newGreen, newBlue;
    Sharpen(imgData,newRed, newGreen, newBlue);

    @endverbatim
 ************************************************************************/


void sharpen(image& data, pixel** &Red, pixel** &Green, pixel** &Blue)
{
    int i, j;
    int b, d, f, h;
    int val, newVal, val2;
    for (i = 0; i < data.rows; i++)
    {
        for (j = 0; j < data.cols; j++)
        {
            if (i == data.rows - 1 || i == 0 || j == 0)
            {
                Red[i][j] = 0;
                Green[i][j] = 0;
                Blue[i][j] = 0;
            }
        }
    }
    for (i = 0; i < data.rows; i++)
    {
        for (j = 0; j < data.cols; j++)
        {
            if (i != data.rows - 1 && i != 0 && j != 0 && j != data.cols - 1)
            {
                b = (int)data.redgray[i][j - 1];
                d = (int)data.redgray[i - 1][j];
                f = (int)data.redgray[i + 1][j];
                h = (int)data.redgray[i][j + 1];
                val = (int)data.redgray[i][j];
                newVal = 5 * val - b - d - f - h;
                val2 = valCheck(newVal);
                Red[i][j] = val2;
            }
        }
    }
    for (i = 0; i < data.rows; i++)
    {
        for (j = 0; j < data.cols; j++)
        {
            if (i != data.rows - 1 && i != 0 && j != 0 && j != data.cols - 1)
            {
                b = (int)data.green[i-1][j];
                d = (int)data.green[i][j-1];
                f = (int)data.green[i][j+1];
                h = (int)data.green[i+1][j];
                val = (int)data.green[i][j];
                newVal = 5 * val - b - d - f - h;
                val2 = valCheck(newVal);
                Green[i][j] = val2;
            }
        }
    }
    for (i = 0; i < data.rows; i++)
    {
        for (j = 0; j < data.cols; j++)
        {
            if (i != data.rows - 1 && i != 0 && j != 0 && j != data.cols - 1)
            {
                b = (int)data.blue[i][j-1];
                d = (int)data.blue[i-1][j];
                f = (int)data.blue[i+1][j];
                h = (int)data.blue[i][j+1];
                val = (int)data.blue[i][j];
                newVal = 5 * val - b - d - f - h;
                val2 = valCheck(newVal);
                Blue[i][j] = val2;
            }
        }
    }
    for (i = 0; i < data.rows; i++)
    {
        for (j = 0; j < data.cols; j++)
        {
            data.redgray[i][j] = Red[i][j];
            data.green[i][j] = Green[i][j];
            data.blue[i][j] = Blue[i][j];
        }
    }
}


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *
 *  This fucntion takes 4 arguments, the first is the image data,
 *  the second is the new Red array, the third is the new green,
 *  and the fourth is the new blue.
 *  It will manipulate the values of the image, store them into the new
 *  arrays and then use them to populate the imgData structure.
 *
 *
 *  @param[in] data the structure containing data to manipulate.  
 *  @param[in] Red A new 2d pointer array representing the red spectrum..
 *  @param[in] Green A new 2d pointer array representing the green spectrum.
 *  @param[in] Blue A new 2d pointer array representing the blue spectrum.
 * 
 * 
 *  @par Example
 *  @verbatim

    image imgData;
    pixel ** newRed, newGreen, newBlue;
    smooth(imgData, newRed, newGreen, newBlue);

    @endverbatim
 ************************************************************************/


void smooth(image& data, pixel**& Red, pixel**& Green, pixel**& Blue)
{
    int i, j;
    double a, b, c, d, e, f, g, h;
    int val, val2;
    double newVal;
    for (i = 0; i < data.rows; i++)
    {
        for (j = 0; j < data.cols; j++)
        {
            if (i == data.rows - 1 || i == 0 || j == 0)
            {
                Red[i][j] = 0;
                Green[i][j] = 0;
                Blue[i][j] = 0;
            }
        }
    }
    for (i = 0; i < data.rows; i++)
    {
        for (j = 0; j < data.cols; j++)
        {
            if (i != data.rows - 1 && i != 0 && j != 0 && j != data.cols - 1)
            {
                a = (int)data.redgray[i - 1][j - 1];
                b = (int)data.redgray[i - 1][j];
                c = (int)data.redgray[i - 1][j + 1];
                d = (int)data.redgray[i][j - 1];
                e = (int)data.redgray[i][j + 1];
                f = (int)data.redgray[i + 1][j - 1];
                g = (int)data.redgray[i + 1][j];
                h = (int)data.redgray[i + 1][j + 1];
                val = (int)data.redgray[i][j];
                newVal = (a + b + c + d + val + e + f + g + h) / 9.0;
                round(newVal);
                val2 = valCheck((int)newVal);
                Red[i][j] = val2;
            }
        }
    }
    for (i = 0; i < data.rows; i++)
    {
        for (j = 0; j < data.cols; j++)
        {
            if (i != data.rows - 1 && i != 0 && j != 0 && j != data.cols - 1)
            {
                a = (int)data.green[i - 1][j - 1];
                b = (int)data.green[i - 1][j];
                c = (int)data.green[i - 1][j + 1];
                d = (int)data.green[i][j - 1];
                e = (int)data.green[i][j + 1];
                f = (int)data.green[i + 1][j - 1];
                g = (int)data.green[i + 1][j];
                h = (int)data.green[i + 1][j + 1];
                val = (int)data.green[i][j];
                newVal = (a + b + c + d + val + e + f + g + h) / 9.0;
                round(newVal);
                val2 = valCheck((int)newVal);
                Green[i][j] = val2;
            }
        }
    }
    for (i = 0; i < data.rows; i++)
    {
        for (j = 0; j < data.cols; j++)
        {
            if (i != data.rows - 1 && i != 0 && j != 0 && j != data.cols - 1)
            {
                a = (int)data.blue[i - 1][j - 1];
                b = (int)data.blue[i - 1][j];
                c = (int)data.blue[i - 1][j + 1];
                d = (int)data.blue[i][j - 1];
                e = (int)data.blue[i][j + 1];
                f = (int)data.blue[i + 1][j - 1];
                g = (int)data.blue[i + 1][j];
                h = (int)data.blue[i + 1][j + 1];
                val = (int)data.blue[i][j];
                newVal = (a + b + c + d + val + e + f + g + h) / 9.0;
                round(newVal);
                val2 = valCheck((int)newVal);
                Blue[i][j] = val2;
            }
        }
    }
    for (i = 0; i < data.rows; i++)
    {
        for (j = 0; j < data.cols; j++)
        {
            data.redgray[i][j] = Red[i][j];
            data.green[i][j] = Green[i][j];
            data.blue[i][j] = Blue[i][j];
        }
    }
}
