#include <math.h>
#include <stdio.h>
#include <string.h>
char str[333335];
char bin[1000003];

int main(void)
{
	/**
	1212: 8진수 2진수
	*/

	scanf("%s", str);
	int j=0, len = strlen(str);

	if (str[0] - '0' == 0)
	{
		printf("0"); return 0;
	}

	for (int i = 0; i < len; i++)
	{
		int n = str[i] - '0';
		for (int k = 0; k < 3; k++)
		{
			bin[j++] = n % 2;
			n = n / 2;
		}
	}
	len = strlen(str)*3;
	int flag = 0;
	for (int i = 0; i < len; i+=3)
	{
		for (int j = 2; j >= 0; j--)
		{
			if (flag == 0 && bin[i + j] == 0)
				continue;
			else
			{
				flag = 1;
				printf("%d", bin[i + j]);
			}
		}
	}
}
	