#include<stdio.h>
#include<string.h>

int main()
{

	char word[20000][51];
	int n;
	scanf_s("%d", &n);

	//단어 입력 받기 
	getc(stdin);
	for (int i = 0; i < n; i++)
	{
		gets(word[i]);

	}

	int i, j;

	int c[50] = { 0, };
	//문자열 길이 순서대로 정렬 시키기 
	for (i = 0; i < n - 1; i++)
	{
		j = i;
		while (j >= 0 && strlen(word + j) > strlen(word + j + 1))
		{
			char temp[51];
			strcpy(temp, word + j);
			strcpy(word + j, word + j + 1);
			strcpy(word + j + 1, temp);

			j--;
		}

		//각각의 자리수의 해당하는개 몇개인지 
		c[strlen(word[i])]++;
	}



	for (int i = 0; i < n; i++)
		puts(word + i);
	c[strlen(word[n - 1])]++;
	int check = 0;
	int same[10] = { 0, };
	int same_count = 0;
	int num = 0;

	//문자열 길이가 같은 것끼리 사전식으로 정렬 
	while (check != n)
	{

		while (c[num] != 0)
		{
			if (c[num] == 1)
				check++;
			else {
				for (int i = check; i < check + c[num] - 1; i++)
				{
					int j = i;
					while (strcmp(word[j], word[j + 1]) != -1)
					{
						char temp[100];
						strcpy(temp, word + j);
						strcpy(word + j, word + j + 1);
						strcpy(word + j + 1, temp);

						//같은 문자열은 제외시키기
						if (strcmp(word[j], word[j + 1]) == 0)
						{
							same[same_count] = j;
							same_count++;
						}
						j--;

					}
				}
				check = check + c[num];
			}
			num++;

		}
		num++;
		check++;

	}
	/*
	printf("result");

	int same_n = 0;

	for (int i = 0; i < n; i++)
	{
		if (same[same_n] != i)
			puts(word[i]);
		else
			same_n++;
	}
	*/
	return 0;
}
