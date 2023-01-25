#pragma once
#include "IShape.h"

class Rectangle : public IShape
{
public:
	void Size() override;
	void Draw() override;

private:
	int height = 24;
	int width = 12;
	int size = 0;
};