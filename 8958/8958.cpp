#include <cstdio>


int main(void)
{
	int n;
	scanf("%d ", &n);
	for (int i = 0; i< n; i++)
	{
		int score = 0;
		int sum =0;
		char c;


		while (true)
		{
			scanf("%c", &c);
			if (c == 'O')
			{
				sum += ++score;
			}
			else if (c == 'X')
				score = 0;
			else
				break;
		}
		printf("%d\n", sum);

	}

}