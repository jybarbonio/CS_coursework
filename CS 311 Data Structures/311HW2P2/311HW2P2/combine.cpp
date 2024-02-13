using namespace std;
#include <iostream>
#include <vector>

// Must use the algorithm that is in the notes! 

//--------------------------------------------
//CS311 HW2P2 Combine 
//Name: John Barbonio
//Compiler: g++
//--------------------------------------------

// combine two sorted lists A and B into R
// displays comparison every time it is done
void combine( vector<int> A, vector<int> B, vector<int> &R )
{
     // ** you can find out the size of A using the
     // ** size function. Treat A and B like arrays. 
    int indexA = 0;     // indexes
    int indexB = 0;
    int indexR = 0;

    while (indexA < A.size() && indexB < B.size()) 
    {
        if (A.at(indexA) < B.at(indexB)) 
        {
            cout << "comparison" << endl;       // element to element comparison
            // ** // be careful -- R comes in as an empty vector with no slots so you have to use push_back
            R.push_back(NULL);
            R.at(indexR) = A.at(indexA); indexA++;
        }
        else 
        {
            cout << "comparison" << endl;       // element to element comparison
            R.push_back(NULL);
            R.at(indexR) = B.at(indexB); indexB++;
        }
        indexR++;
    }
    if (indexA < A.size()) 
    {
        while (indexA < A.size()) 
        {
            R.push_back(NULL);
            R.at(indexR) = A.at(indexA); indexA++;
            indexR++;
        }
    }
    else if (indexB < B.size()) 
    {
        while (indexB < B.size())
        {
            R.push_back(NULL);
            R.at(indexR) = B.at(indexB); indexB++;
            indexR++;
        }
    }
    
}


int main()
{  
  vector<int> L1;
  vector<int> L2;
  vector<int> L3;
  int N;  // how many elements in each of L1 and L2
  int e;  // for each element

  cout << "How many elements in each list?" << endl;
  cin >> N;

  cout << "List1"  << endl;
  for (int i = 1; i <=N; i++)
    { cout << "element :"; cin >> e; L1.push_back(e);} 

  cout << "List2"  << endl; 
  for (int i = 1; i <=N; i++)
    { cout << "element :"; cin >> e; L2.push_back(e);} 
  

  // call combine here to combine L1 and L2 into L3
  combine(L1, L2, L3);
  
  cout << "The result is: ";
  for (int i = 0; i < N*2; i++)
    { cout << L3[i]; } cout << endl;

}// end of main
