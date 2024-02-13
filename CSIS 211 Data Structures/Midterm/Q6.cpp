void q6(int s, int n)
{
	for (unsigned int i = 1; i < n; ++i)
	{
		for (unsigned int j = 0; j < (i * i); ++j)
		{
			if (j % i == 0)
			{
				for (unsigned int k = 0; k < j; ++k)
				{
					++s;
					std::cout << "Time Complexity: " << (2 * i + n) * (2 * j + n) * (2 * k + n) << std::endl;
				}
			}
		}
	}
}
int main()
{
	int sum = 0;

	//q5(sum, 1);
	//q5(sum, 2);
	//q6(sum, 3);
	//q5(sum, 4);
	q5(sum, 8);
}
/*
the lowest report the time complexity can make is 1, which is hardcoded into the outer loop from which then the inner loops calculate.
j relies on an increasing exponential i but eliminates half of the calculations because of the modulus i % j == 0.
T(N) = O(N) * O(i*i) * O(log2 N)
*/