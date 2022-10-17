#include <stdio.h>
#include <windows.h>
#include <time.h>

typedef void (*PFunc)(int *,int *);

// コールバック関数1
void CallBack1(int* s , int* ans) {
	srand(time(NULL));

	int result = rand() % 6 + 1;

	printf("\n出目 : %d\n", result);

	if (result % 2 == 0)
	{
		printf("Result : 偶数\n\n");
	}
	else
	{
		printf("Result : 奇数\n\n");
	}

	if (result % 2 == *ans)
	{
		printf("正解！！！\n");
	}
	else
	{
		printf("不正解...\n");
	}
}

void SetTimeOut(PFunc p, int second , int ans) {
	// コールバック関数を呼び出す
	Sleep(second * 1000);

	p(&second , &ans);
}

int main(void) {

	printf("サイコロを振りました!\n\n結果が偶数だと思うなら 0 \n結果が奇数だと思うなら 1 を入力してください\n\n");
	printf("入力を受け付け中...  ");

	int answer;
	scanf_s("%d", &answer);

	if (answer == 0)
	{
		printf("\nAnswer : 偶数\n");
	}
	else if (answer == 1)
	{
		printf("\nAnswer : 奇数\n");
	}
	else
	{
		printf("\nError!\n");
		return 0;
	}


	printf("\n答えは・・・\n");

	PFunc p;
	p = CallBack1;
	SetTimeOut(p, 3 , answer);

	return 0;
}