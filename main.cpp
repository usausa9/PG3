#include <stdio.h>
#include "Circle.h"
#include "Rectangle.h"

int main(void) {

	Rectangle rect;
	Circle circle;

	rect.Size();
	circle.Size();

	rect.Draw();
	circle.Draw();
	
	return 0;
}