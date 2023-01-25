#include "Rectangle.h"
#include <stdio.h>

void Rectangle::Size()
{
	size = height * width;
}

void Rectangle::Draw()
{
	printf("Rectangle size : %d\n", size);
}
