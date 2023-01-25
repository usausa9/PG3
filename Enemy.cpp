#include "Enemy.h"

bool Enemy::isAllDead = false;

void Enemy::Update()
{
	if (isDead) 
	{
		isAllDead = true;
	}
}