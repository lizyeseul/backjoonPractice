#include<stdio.h>
int main() {
	int N;
	scanf("%d", &N);
	int temp;
	int five=-1, three=-1,flag=0;
	for (temp = N / 5; temp >= (N/5 - 4); temp--) {
		if (temp < 0) {
			break;
		}
		if (N - (5*temp) == 0) {
			five = temp;
			three = 0;
			flag = 1;
			break;
		}
		else if(((N - (5 * temp)) % 3)==0){
			five = temp;
			three = (N-temp*5)/3;
			flag = 1;
			break;
		}
		
	}
	if (N % 3 == 0 && flag == 0) {
		five = 0;
		three = N/3;
		flag = 1;
	}
	if(flag == 1)
		printf("%d", five+three);
	else if (flag == 0)
		printf("-1");
	return 0;
}