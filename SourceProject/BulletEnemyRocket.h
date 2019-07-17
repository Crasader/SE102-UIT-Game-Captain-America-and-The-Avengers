#pragma once
#include "Bullet.h"

class BulletEnemyRocket : public Bullet
{
private:
	static constexpr float BULLET_MOVING = 110.0f;
	int type = 0; //0 = straight, 1 = straight and up

public:
	BulletEnemyRocket(int nx, int type , const Vector2& spawnPos, Vector2 vel = { BULLET_MOVING, 0.0f });

	void Update(float dt, const std::vector<GameObject*>& coObjects) override;
};
