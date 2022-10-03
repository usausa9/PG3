#include <stdio.h>

int NormalWage(int wage, int hour) {

	return wage * hour;
}

int RecursiveWage(int wage, int hour) {

	if (hour <= 0)
	{
		return 0;
	}

	return wage + RecursiveWage(wage * 2 - 50, hour - 1);
}

int main(void) {

	int workHours = 8;

	printf("��ʓI�Ȓ����̌n : %d�~\n", NormalWage(1072, workHours));
	printf("�ċA�I�Ȓ����̌n : %d�~\n", RecursiveWage(100, workHours));


	if (NormalWage(1072, workHours) >= RecursiveWage(100, workHours))
	{
		printf("����Ĉ�ʓI�Ȓ����̌n�̕��������������B\n");
	}
	else
	{
		printf("����čċA�I�Ȓ����̌n�̕��������������B\n");
	}

	return 0;
}