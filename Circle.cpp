#include "Circle.h"
#include <stdio.h>

void Circle::Size()
{
	size = radius * radius * 3.141592f;
}

void Circle::Draw()
{
	printf("   Circle size : %.2f (approximately)\n", size);
}
