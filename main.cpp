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

	printf("一般的な賃金体系 : %d円\n", NormalWage(1072, workHours));
	printf("再帰的な賃金体系 : %d円\n", RecursiveWage(100, workHours));


	if (NormalWage(1072, workHours) >= RecursiveWage(100, workHours))
	{
		printf("よって一般的な賃金体系の方が賃金が多い。\n");
	}
	else
	{
		printf("よって再帰的な賃金体系の方が賃金が多い。\n");
	}

	return 0;
}