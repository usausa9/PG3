#pragma once

enum class State
{
	ALIVE,
	DEAD
};

class Enemy
{
public:
	int x;
	int y;

	Enemy() : x(0), y(0) {}
	Enemy(int x, int y) : x(x), y(y) {}

public:

	static bool isAllDead;

	bool GetAllDead() { return isAllDead; }
	void SetIsDead() { isDead = true; }

	void Update();

private:

	bool isDead = false;
};

