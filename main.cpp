#include <stdio.h>
#include <windows.h>
#include <time.h>

typedef void (*PFunc)(int *,int *);

// �R�[���o�b�N�֐�1
void CallBack1(int* s , int* ans) {
	srand(time(NULL));

	int result = rand() % 6 + 1;

	printf("\n�o�� : %d\n", result);

	if (result % 2 == 0)
	{
		printf("Result : ����\n\n");
	}
	else
	{
		printf("Result : �\n\n");
	}

	if (result % 2 == *ans)
	{
		printf("�����I�I�I\n");
	}
	else
	{
		printf("�s����...\n");
	}
}

void SetTimeOut(PFunc p, int second , int ans) {
	// �R�[���o�b�N�֐����Ăяo��
	Sleep(second * 1000);

	p(&second , &ans);
}

int main(void) {

	printf("�T�C�R����U��܂���!\n\n���ʂ��������Ǝv���Ȃ� 0 \n���ʂ�����Ǝv���Ȃ� 1 ����͂��Ă�������\n\n");
	printf("���͂��󂯕t����...  ");

	int answer;
	scanf_s("%d", &answer);

	if (answer == 0)
	{
		printf("\nAnswer : ����\n");
	}
	else if (answer == 1)
	{
		printf("\nAnswer : �\n");
	}
	else
	{
		printf("\nError!\n");
		return 0;
	}


	printf("\n�����́E�E�E\n");

	PFunc p;
	p = CallBack1;
	SetTimeOut(p, 3 , answer);

	return 0;
}