/*
John Barbonio
0518876
26 August, 2018
Journal 2B: The If Statement
*/
#include <iostream>			//standard I/O

using namespace std;		//standard libraries

int main()					//main method
{
	char score;			//score char to get letter grade;


	cout << "Enter your score: " << endl;		//prompts user to enter a score
	cin >> score;								//gets user input for a test score
	
	if(score =='A')				//if the score is typed as 'A', then it is Excellent!
	{											//braces used for delineation
		cout << "Excellent!\n";
	}
	else if(score == 'B')		//very good grade
	{
		cout << "Very Good!\n";
	}
	else if (score == 'C')		//average
	{
		cout << "Average!\n";
	}
	else if (score == 'D')		//bad
	{
		cout << "Below Average!\n";
	}
	else if (score == 'F')		//drop the class
	{
		cout << "You're failing!\n";
	}
	else
	{
		cout << "Invalid Input. Grades N/A.\n";		//for if the input is not one of the specified above
	}
	system("pause");		//needed because program keeps closing
	return 0;
}