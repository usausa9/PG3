#include <stdio.h>
#include <functional>
#include <Windows.h>
#include <time.h>

typedef void (*PFunc)(int);

void callback(int num)
{
	srand(time(NULL));
	int result = rand() % 6 + 1;

	printf("\n�o�� : %d\n", result);

	if (result % 2 == num % 2)
	{
		printf("�����I�I�I\n\n");
	}
	else
	{
		printf("�s����...\n\n");
	}
}

int main(int argc, const char *argv[]) {

	PFunc p;
	p = callback;

	int answer = 0;

	printf("�T�C�R����U��܂���!\n\n���ʂ��������Ǝv���Ȃ� 0 \n���ʂ�����Ǝv���Ȃ� 1 ����͂��Ă�������\n\n");
	printf("���͂��󂯕t����...  ");

	scanf_s("%d", &answer);

	std::function<void(PFunc, int)>setTimeout = [=](PFunc p, int sec)
	{
		printf("���ʂ́E�E�E\n");

		Sleep(sec *= 1000);
		p(answer);
	};

	if (answer == 0)
	{
		printf("\nAnswer : ����\n");
		setTimeout(p, 3);
	}
	else if (answer == 1)
	{
		printf("\nAnswer : �\n");
		setTimeout(p, 3);
	}
	else
	{
		printf("\nError!\n");
		return 0;
	}
	

	return 0;
}