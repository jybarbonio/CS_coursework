#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

//--------------------------------------
// CS311 File mat.cpp for HW1P3 Matrix 
// Compiler: gcc
// Your name: **
//--------------------------------------

// the following can be changed and the rest of the code should work
int const R = 3;  // number of rows
int const C = 4;  // number of columns
int const VL = 3; // table entry vector length

vector<char>  T[R][C];  // 3 rows and 4 columns table for now 

// ------------------ Functions --------------------------------

int convert(char x)
{ 
  //  ** do a formula to convert a to 0, b to 1, c to 2 etc.

} 

// this reads the input file into the matrix table
void readTable()
{  int row, col;
   char col_c; 
   ifstream fin ("lines.txt", ios::in);
   // Read in the file into T
   while (fin >> row)  // per row
     { vector<char> V;
       fin >> col_c; col = convert(col_c);  // to a slot number
       char c; // one char from the file
       // ** Fill vector V with chars from the file (a for loop)
       for (int row = 0; row < R; row++) 
       {
           for (int col = 0; col < C; col++) 
           {
                
           }
       }
       // ** Put the vector in T[row][col]
     }//end of while
}

// display the vector nicely to the outstream
void showVector(vector<char> v, ostream& ost)
{if (v.size() == 0)  // empty entry will be dashes
    for (int i = 1; i <= VL; i++) ost << "- ";
  else
    { // ** show the content of v separated by blanks
    }
}


// display the matrix
void displayTable()
{
  // display T nicely labeled with row numbers
  //    by calling showVector with cout
  //    for each column
  for (int r = 0; r < R; r++)
    {    cout << r << ":";
      for (int c = 0; c < C; c++)
	{ showVector(T[r][c], cout);
	  cout << "|"; }
      cout << endl;
    }   
}

// save the matrix to the output file
void saveTable()
{
   ofstream fout ("table.txt", ios::out);

  // ** output T nicely labeled with row numbers
  //    by calling showVector with fout
  //    for each column

}


int main()
{
  cout << "reading from lines.txt" << endl;
  readTable(); 
  displayTable();  
  cout << "saving the table in table.txt" << endl;
  saveTable();
}//the end
