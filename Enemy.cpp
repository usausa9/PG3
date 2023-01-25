#include "Enemy.h"

void Enemy::Update()
{
	(this->*State[phase_])();

	stateChangeTimer--;
}

void Enemy::MeleeAttack()
{
	StateChange();
}

void Enemy::ShootingAttack()
{
	StateChange();
}

void Enemy::Withdrawal()
{
	StateChange();
}

void Enemy::StateChange()
{
	if (stateChangeTimer == 0)
	{
		stateChangeTimer = maxStateChangeTimer;

		if (phase_ == MELEE)
		{
			phase_ = SHOT;
		}
		else if (phase_ == SHOT)
		{
			phase_ = ESCAPE;
		}
		else if (phase_ == ESCAPE)
		{
			phase_ = MELEE;
		}
	}
}

void (Enemy::* Enemy::State[])() =
{
	&Enemy::MeleeAttack,	// —v‘f1
	&Enemy::ShootingAttack, // —v‘f2
	&Enemy::Withdrawal		// —v‘f3
};