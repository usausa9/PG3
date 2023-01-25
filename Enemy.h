#pragma once

class Enemy
{

public:
	enum stateTable
	{
		MELEE,
		SHOT,
		ESCAPE
	}phase_ = MELEE;

public:
	void MeleeAttack();
	void ShootingAttack();
	void Withdrawal();

	void StateChange();

	void Update();

private:
	static void(Enemy::*State[])();

	int stateChangeTimer = 120;
	const int maxStateChangeTimer = stateChangeTimer;
};

