#include <iostream>
using std::iostream;

void f(int s, int n);

void f(int s, int n)
{
	for (unsigned int i = 0; i < n; i++)
	{
		++s;
		std::cout << s << std::endl;
		std::cout << "Time Complexity: " << (2 * i + n) << std::endl;
	}
	std::cout << "processing finished" << std::endl;
}
int main()
{
	int sum = 0;

	f(sum, 1);
	f(sum, 2);
	f(sum, 4);
	f(sum, 8);
}

/*
The time complexity is linear and only changes/scales linearly
based on the amount of n, it depicts a worst case scenario of
CPU processing. Everything outside the function is considered O(1)
time complexity as the only increasing calculations come from the
for loop. O(N)
*/