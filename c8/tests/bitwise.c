#include <stdio.h>

void print(int x)
{
	printf("%d\n", x);
}

int main()
{
	int x = 5;
	int y = 7;
	int z = 9;
	print(x & y);
	print(x & z);
	print(y & z);
	print(x | y);
	print(x | z);
	print(y | z);
	print(~x);
	print(~y);
	print(~z);
	print(x ^ y);
	print(x ^ z);
	print(y ^ z);
	print(x ^ y ^ z);
	print(x & y | z);
	print(x | y & z);
	print(x & (y | z));
	print((x & y) | z);
	print(x & y ^ z);
	print(x | y ^ z);
	return 0;
}
