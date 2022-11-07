#include <stdio.h>
#include <functional>
#include <Windows.h>
#include <time.h>

int main(int argc, const char *argv[]) {

	srand(time(NULL));

	printf("サイコロを振りました!\n\n結果が偶数だと思うなら 0 \n結果が奇数だと思うなら 1 を入力してください\n\n");
	printf("入力を受け付け中...  ");

	int answer = 0;

	scanf_s("%d", &answer);

	int waitSecond = 3; // 待ち時間

	std::function<void(std::function<void()>, int)>SetTimeout = [](std::function<void()> fx, int sec) { Sleep(sec * 1000);  fx(); }; // タイムアウト関数

	std::function<void()> Lottery = [=]() {rand() % 2 == answer ? printf("\n正解！\n") : printf("\n不正解...\n"); }; // 抽選する関数

	// 抽選実行
	SetTimeout(Lottery, 3);

	return 0;
}