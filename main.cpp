#include <stdio.h>
#include <functional>
#include <Windows.h>
#include <time.h>

typedef void (*PFunc)(int);

void callback(int num)
{
	srand(time(NULL));
	int result = rand() % 6 + 1;

	printf("\n出目 : %d\n", result);

	if (result % 2 == num % 2)
	{
		printf("正解！！！\n\n");
	}
	else
	{
		printf("不正解...\n\n");
	}
}

int main(int argc, const char *argv[]) {

	PFunc p;
	p = callback;

	int answer = 0;

	printf("サイコロを振りました!\n\n結果が偶数だと思うなら 0 \n結果が奇数だと思うなら 1 を入力してください\n\n");
	printf("入力を受け付け中...  ");

	scanf_s("%d", &answer);

	std::function<void(PFunc, int)>setTimeout = [=](PFunc p, int sec)
	{
		printf("結果は・・・\n");

		Sleep(sec *= 1000);
		p(answer);
	};

	if (answer == 0)
	{
		printf("\nAnswer : 偶数\n");
		setTimeout(p, 3);
	}
	else if (answer == 1)
	{
		printf("\nAnswer : 奇数\n");
		setTimeout(p, 3);
	}
	else
	{
		printf("\nError!\n");
		return 0;
	}
	

	return 0;
}