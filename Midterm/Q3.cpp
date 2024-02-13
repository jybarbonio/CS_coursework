#include <iostream>
using std::iostream;

void q1(int s, int n);
void q2(int s, int n);

void q1(int s, int n)
{
	for (unsigned int i = 0; i < n; i++)
	{
		++s;
		std::cout << s << std::endl;
		std::cout << "Time Complexity: " << (2 * i + n) << std::endl;
	}
	std::cout << "processing finished" << std::endl;
}
void q2(int s, int n)
{
	for (unsigned int i = 0; i < n; i++)
	{
		for (unsigned int j = 0; j < n; ++j)
		{
			++s;
			std::cout << s << std::endl;
			std::cout << "Time Complexity: " << (2 * (i)+n) * (2 * (j)+n) << std::endl;
		}
	}
}
void q3(int s, int n)
{
	for (unsigned int i = 0; i < n; i++)
	{
		for (unsigned int j = 0; j < (n * n); ++j)
		{
			++s;
			std::cout << s << std::endl;
			std::cout << "Time Complexity: " << (2 * (i)+n) * (2 * (j)+n) << std::endl;
		}
	}
}
int main()
{
	int sum = 0;

	//q3(sum, 1);
	//q3(sum, 2);
	//q3(sum, 4);
	q3(sum, 8);
}
/*
two for loops, one nested within the other turns the time complexity graph from linear to quadratic, creating an upwards facing
parabolic increase (exponential) in time for each calculation that is added. O(N) "i" * O(N) "j" or N^2.

Within the inner j loop however, is an exponentially scaling n^2 within the for loop parameter that grows exponentionally based on n^2
until the base is finished calculating O(N) * (O(N^2))
*/