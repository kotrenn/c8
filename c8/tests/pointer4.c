#include <stdio.h>

void print(int x)
{
	printf("%d\n", x);
}

int main()
{
	int x = 4;
	int *y = &x;
	int *z = *&y;
	*z = 5;
	print(x);
	int **p = &z;
	int w = 7;
	*p = &w;
	*z = 8;
	print(x);
	print(w);
	print(**p);
	int ***q = &p;
	**q = &x;
	*z = 9;
	print(x);
	print(w);
	print(***q);
	
	return 0;
}
