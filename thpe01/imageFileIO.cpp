#include "netPBM.h"

bool openFile(ifstream& fin, char *fileName)
{
    fin.open(fileName);
    if (!fin.is_open())
    {
        cout << "Unable to open file: " << fileName << endl;
        return false;
    }
    return true;
}

bool readAscii(ifstream& fin)
{
    pixel hold;
    int max;
    string com;
    image imgData;
    fin >> imgData.magicNumber;
    if (imgData.magicNumber != "P3")
    {
        imgData.magicNumber = "P3";
    }
    fin.ignore();
    int pk = fin.peek();
    while (pk == 35)
    {
        getline(fin, imgData.comment, '\n');
        pk = fin.peek();
    }
    fin >> imgData.rows;
    fin >> imgData.cols;
    fin >> max;
    cout << imgData.magicNumber << endl;
    cout << imgData.comment << endl;
    cout << imgData.rows << endl;
    cout << imgData.cols << endl;
    cout << max << endl;

   bool redCheck = allocRed(imgData.rows, imgData.cols);
   if (redCheck == false)
   {
       return false;
   }
   bool greenCheck = allocGreen(imgData.rows, imgData.cols);
   if (greenCheck == false)
   {
       return false;
   }
   bool blueCheck = allocBlue(imgData.rows, imgData.cols);
   if (blueCheck == false)
   {
       return false;
   }
}