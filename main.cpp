#include <stdio.h>
#include <functional>
#include <Windows.h>
#include <time.h>

int main(int argc, const char *argv[]) {

	srand(time(NULL));

	printf("�T�C�R����U��܂���!\n\n���ʂ��������Ǝv���Ȃ� 0 \n���ʂ�����Ǝv���Ȃ� 1 ����͂��Ă�������\n\n");
	printf("���͂��󂯕t����...  ");

	int answer = 0;

	scanf_s("%d", &answer);

	int waitSecond = 3; // �҂�����

	std::function<void(std::function<void()>, int)>SetTimeout = [](std::function<void()> fx, int sec) { Sleep(sec * 1000);  fx(); }; // �^�C���A�E�g�֐�

	std::function<void()> Lottery = [=]() {rand() % 2 == answer ? printf("\n�����I\n") : printf("\n�s����...\n"); }; // ���I����֐�

	// ���I���s
	SetTimeout(Lottery, 3);

	return 0;
}