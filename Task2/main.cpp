#include <iostream>

long sumFib(int n, long p = 0, long c = 1, long s = 0)
{
	if (n == 0) return s;
	return sumFib(n - 1, c, c + p, s + c);
}

int main()
{
	for(int i = 1; i <= 10; i ++)
		std::cout << sumFib(i) << " -> sum of the " << i << "  elements " << std::endl;
}