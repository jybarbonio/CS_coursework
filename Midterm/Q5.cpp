void q5(int s, int n)
{
	for (unsigned int i = 0; i < n; ++i)
	{
		for (unsigned int j = 0; j < (i * i); ++j)
		{
			for (unsigned int k = 0; k < j; ++k)
			{
				++s;
				std::cout << s << std::endl;
				std::cout << "Time Complexity: " << (2 * i + n) * (2 * j + n) * (2 * k + n) << std::endl;
			}
		}
	}
}
int main()
{
	int sum = 0;

	//q5(sum, 1);
	//q5(sum, 2);
	q5(sum, 3);
	//q5(sum, 4);
	//q5(sum, 8);
}
/*
three for loops, the first inner loop "j" calculates based on i^2, and k calculates from j which in turn is from i^2,
T(N) = O(N(O(i*i))). The reliable calculation of time complexity is limited to a certain range as it does not calculate accurately below a certain point
*/