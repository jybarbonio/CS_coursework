void q4(int s, int n)
{
	for (unsigned int i = 0; i < n; ++i)
	{
		for (unsigned int j = 0; j < i; ++j)
		{
			++s;
			std::cout << s << std::endl;
			std::cout << "Time Complexity: " << (2 * i + n) * (2 * j + n) << std::endl;
		}
	}
}
int main()
{
	int sum = 0;

	//q4(sum, 1);
	//q4(sum, 2);
	//q4(sum, 4);
	q4(sum, 8);
}
/*
two for loops, one nested within the other turns the time complexity graph from linear to quadratic, creating an upwards facing
parabolic increase (exponential) in time for each calculation that is added. O(N) "i" * O(N) "j" or N^2.

Within the inner j loop, the for loop is scaling based on i instead of n, but since i is calculating based on n, it is no different
in calculation than question 2. T(N) = O(N) * O(i) where i increases up to n before capping, thus being T(N) = O(N) * O(N) where i = N
after the outer loop is maxed
*/