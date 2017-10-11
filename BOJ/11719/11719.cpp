#include <iostream>
#include <cstdio>
int main()
{
	int ch;

	do {
		ch = getchar();
		if (ch == EOF)
			return 0;
		else
			putchar(ch);
	} while (true);

}