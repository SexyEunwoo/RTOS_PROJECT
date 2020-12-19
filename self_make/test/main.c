#include "test.h"

extern void Func1(void);

int main(void)
{
	printf("Hello World! \n");
	Func1();

	return 0;
}

void Func1(void)
{
	printf("I'm Func1! \n");
}
