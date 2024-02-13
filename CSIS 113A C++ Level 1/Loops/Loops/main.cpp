/*
John Barbonio
0518876
28 August, 2018
Lab 4: Mileage
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() 
{
	double mileage, total;
	cout << "Enter the number of miles driven " << endl;
	cin >> mileage;

	if(mileage <= 100) 
	{
		total = mileage * .25;
	}
	else
	{
		double hiMile = mileage - 100;
		double lowMile = mileage - hiMile;
		total = lowMile * .25 + (hiMile * .15);
	}
	cout << fixed << setprecision(2) << "You are owed $ " << total << endl;
	
	system("pause");
	return 0;
}