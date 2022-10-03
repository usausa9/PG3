#include <stdio.h>

template <typename T>
T min(T a, T b)
{
	if (a < b)
	{
		return a;
	}

	return b;
}

template<>
char min<char>(char a, char b) {
	printf("”šˆÈŠO‚Í‘ã“ü‚Å‚«‚Ü‚¹‚ñ");
	return 0;
}

int main(void) {

	int _intA = 5;
	int _intB = 6;

	float _floatA = 5.1f;
	float _floatB = 6.1f;

	double _doubleA = 5.1f;
	double _doubleB = 6.1f;

	char _charA = 'o';
	char _charB = 'p';

	printf("%d\n", min(_intA, _intB));
	printf("%f\n", min(_floatA, _floatB));
	printf("%lf\n", min(_doubleA, _doubleB));
	printf("%c\n", min(_charA, _charB));

	return 0;
}