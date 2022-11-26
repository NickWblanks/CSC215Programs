/** **********************************************************************
 * @file
 ************************************************************************/

#include "netPBM.h"

 /** **********************************************************************
  *  @author Nicholas K Wilk
  *
  *  @par Description
  *  The FloodFill function will fill in a region within a net PBM image
  *  with a specified color.
  *  
  *
  *  @param[in] row The row to access.
  *  @param[in] col The column to access.
  *  @param[in] data The structure holding the data for the image.
  *  @param[in] newColor The color to fill the region with.
  *  @param[in] oldColor The color that was previously at the location.
  *
  *
  *  @par Example
  *  @verbatim

     floodFill(row, col, imgData, newColor, Old);

     @endverbatim
  ************************************************************************/

void floodFill(int row, int col, image& data, color &newColor, color &oldColor)
{
    int maxC = data.cols;
    int maxR = data.rows;
    if (row >= maxR || row < 0 || col >= maxC || col < 0)
    {
        return;
    }
    if (data.redgray[row][col] != oldColor.red
        && data.green[row][col] != oldColor.green
        && data.blue[row][col] != oldColor.blue)
    {
        return;
    }
    data.redgray[row][col] = newColor.red;
    data.green[row][col] = newColor.green;
    data.blue[row][col] = newColor.blue;
    floodFill(row, col + 1, data, newColor, oldColor);
    floodFill(row, col - 1, data, newColor, oldColor);
    floodFill(row + 1, col, data, newColor, oldColor);
    floodFill(row - 1, col, data, newColor, oldColor);
}

