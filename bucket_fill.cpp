// File: bucket_fill.cpp
// Author: John Williamson
// Recursively calls bucketFill to change a point of origin
// and its surrounding neighbors to a newly selected color.

#include <fstream>
#include <iostream>

using namespace std;

struct Pixel{
   int x;
   int y;
   char currentColor;
};

const int ROW = 6;
const int COL = 17;

void bucket_fill(Pixel arr[][COL], int x, int y, char newColor, char oldColor);
void displayImage(Pixel arr[][COL]);

int main()
{
   ifstream file;
   file.open ("fake_picture.txt");
	
   int  rowInput,      //
        colInput;     // 
   char colorInput,  // used for user input
        currentPixel; // single pixel in image array
		
   Pixel imageArr[ROW][COL]; // array of the image's contents
   Pixel singlePixel; //used for reading in a imgage file 
   
   for (int r = 0; r < ROW; ++r) // reading in data from text file
   {
     for (int c = 0; c < COL; ++c)
     {
         file >> currentPixel;
         singlePixel.x = r;
         singlePixel.y = c;
         singlePixel.currentColor = currentPixel;
         imageArr[r][c] = singlePixel;
     }
   }

   displayImage(imageArr); //inital image displayed to console
   
 while ( rowInput >= 0 || colInput >= 0 ) // user-side input
  {
	cout << '\n';
    cout << "Enter a row: ";
	cin >> rowInput;
    cout << "Enter a column: ";
        cin >> colInput;   
    cout << "Enter a color: ";
        cin >> colorInput;
	bucket_fill( imageArr, rowInput, colInput, colorInput, 
	              imageArr[rowInput][colInput].currentColor); //last parameter is oldColor
	cout << '\n';
	displayImage(imageArr); // displays image after bucketFill
  }

    cout << "\nA column/row of -1 does not exist, image left unchanged." << endl; 
    cout << "Exiting Program.\n\n";
		
    file.close();
	return 0;
}

// Changes a point of origin to a new color, and recursively checks neighbors
// and changes color accordingly.
//
// Preconditions: Point(x,y) chosen is within the bounds of the image.
// Postconditions: The origin and all surrounding neighbors of the origin will be changed
//                to the newly selected color. 
// Parameters: Array of struct type Pixel, x and y coordiantes (int), newColor,
//            oldColor (original color of origin position)

void bucket_fill(Pixel arr[][COL], int x, int y, char newColor, char oldColor)
{
    if ( arr[x][y].currentColor == newColor )   // if origin color same as new color
	return;
    if ( arr[x][y].currentColor != oldColor )   //if neighbors color is same as origin
	return;
    if (x < 0 || x >= ROW || y < 0 || y >= COL) //bounds checking
	return;
    else
    {   
      // change point to new color
       arr[x][y].currentColor = newColor;
      // recursively check origin pixel's neighbors  
       bucket_fill(arr, x-1, y-1, newColor, oldColor); // down1 left1
       bucket_fill(arr, x-1, y, newColor, oldColor);   // down1
       bucket_fill(arr, x-1, y+1, newColor, oldColor); // down1 right1 
       bucket_fill(arr, x, y-1, newColor, oldColor);   // left1
       bucket_fill(arr, x, y+1, newColor, oldColor);   // right1
       bucket_fill(arr, x+1, y-1, newColor, oldColor); // up1 left1
       bucket_fill(arr, x+1, y, newColor, oldColor);   // up1 
       bucket_fill(arr, x+1, y+1, newColor, oldColor); // up1 right1
    }
}

//Ouputs contents of the image to the console
void displayImage(Pixel arr[][COL])
{
   cout << '\n';
   for ( int r = 0; r < ROW; ++r )
   {
     for ( int c = 0; c < COL; ++c )
     {
       cout << arr[r][c].currentColor;
     }
	  cout << '\n';
   }
}
