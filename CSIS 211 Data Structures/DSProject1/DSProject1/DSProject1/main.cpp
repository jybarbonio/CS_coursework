/*
main.cpp
John Barbonio
6/4/2020
: the main method serves as the program start and testing ground for all of the assigned code functionality
*/
#include "BigDecimal.h"
#include <fstream>
#include <thread>
#include <chrono>

int main() 
{
	Char ch;
	ch.equals('A');
	//ch.equals(Char('d'));
	//ch.equals(46);
	//Char ch("Pears");
	//Char ch(46);
	Char c('B');

	std::cout << ch + c << std::endl;	// + operator overload substitutes add function
	std::cout << ch + 'c' << std::endl;	// + operator overload substitutes add function

	std::cout << ch.toString() << std::endl;	// + operator overload substitutes add function


	std::cout << ch.toChar() << " In Hex: " << ch.toHexString() << std::endl;
	std::cout << ch.toChar() << " In Decimal: " << ch.toInt() << std::endl;
	std::cout << ch.toString() << " In Decimal: " << ch.toInt() << std::endl;

	try
	{
		std::cout << "Try to set 140 as a character" << std::endl;
		ch.equals(140);
		std::cout << ch.toChar() << std::endl;
	}
	catch(CharException ce)
	{
		std::cout << ce.query() << std::endl;
	}

	std::vector<BigDecimal>BD_list;

	std::ifstream infile("Numbers.txt");
	std::string input;

	if(!infile) 
	{
		std::cout << "Unable to open Numbers.txt for reading" << std::endl;
		exit(1);
	}
	while(std::getline(infile, input)) 
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(40));
		std::cout << "Reading " << input << " from Numbers.txt" << std::endl;

		BigDecimal temp(input);
		BD_list.push_back(temp);
	}
	infile.close();

	// integer portions stored to file
	std::ofstream i_outfile("wholeNumbers.txt", std::ios::trunc);	// trunc is used to clear the file, safety
	if (!i_outfile) 
	{
		std::cout << "Unable to open/create integer.txt for writing" << std::endl;
		exit(1);
	}

	for(unsigned int i = 0; i < BD_list.size(); i++) 
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(40));
		std::cout << "Adding " << BD_list.at(i).wholeNumber() << " into wholeNumbers.txt" << std::endl;
		i_outfile << BD_list.at(i).wholeNumber() << std::endl;
	}

	// fractional portions stored to file
	std::ofstream f_outfile("fraction.txt", std::ios::trunc);
	if (!f_outfile)
	{
		std::cout << "Unable to open/create integer.txt for writing" << std::endl;
		exit(1);
	}

	for (unsigned int i = 0; i < BD_list.size(); i++)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(40));
		std::cout << "Adding " << BD_list.at(i).fraction() << " into fraction.txt" << std::endl;
		f_outfile << BD_list.at(i).fraction() << std::endl;
	}

	// print BigDecimal vector
	for (std::vector<BigDecimal>::const_iterator i = BD_list.begin(); i != BD_list.end(); ++i)
	{
		BigDecimal temp = *i;
		std::cout << temp.toString() << std::endl;
	}

	// attempt to add an invalid number to the vector
	try
	{
		std::cout << "Trying to set 52s as a character in BigDecimal" << std::endl;
		BigDecimal errortest("52s");
		BD_list.push_back(errortest);

		BigDecimal errortest2("21.5.5");
		BD_list.push_back(errortest2);
	}
	catch (BigDecimalException bde)
	{
		std::cout << bde.query() << std::endl;
	}

	std::cout << "Size of BD_list (should be 100 despite attempting to add two invalid numbers): " << BD_list.size() << std::endl;

	std::string tStr = BD_list.at(5).at(3).toString(); // uhh just testing the BD funcs
	std::cout << tStr << std::endl;

	try
	{
		BigDecimal tAdd1;
		tAdd1.equals('5');
		//tAdd1.equals('z');

		BigDecimal tAdd2("11.2");
		BigDecimal total = tAdd1.add(tAdd2);
		// total is = 16.2

		Char siu = total.at(22);		// this should print an out of index error
		std::cout << "A char that is set equal to a BigDecimal element is: " << siu.toChar() << std::endl;
		siu = total.at(22);	// this should print 2
		std::cout << "A char that is set equal to a BigDecimal element is: " << siu.toChar() << std::endl;
		std::cout << "Whole Number of 16.2 is: " << total.wholeNumber() << std::endl;
		std::cout << "Fraction of 16.2 is:  " << total.fraction() << std::endl;

		std::cout << total.toString() << std::endl;

		tAdd1.equals("22.950838262579364");
		tAdd2.equals("3.0");
		//total = tAdd1.add(tAdd2);
		total = tAdd1.sub(tAdd2);

		// for some reason, precision is not at full??, explicitly fixed in BigDecimal's add function, or I guess not
		std::cout << total.toString() << std::endl;

		// the value returned is correct, it's precision is not
		std::cout << std::setprecision(total.toString().size() - 1) << total.toDouble() << std::endl;
		//std::cout << total.at(5).a << std::endl;
	}
	catch(BigDecimalException bde) 
	{
		std::cout << bde.query() << std::endl;
	}
}