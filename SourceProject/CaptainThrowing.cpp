#include "pch.h"
#include "CaptainThrowing.h"
#include "BulletEnemyRocket.h"



void CaptainThrowing::Enter(Captain& cap, State fromState, Data&& data)
{
	assert(fromState == State::Captain_Jumping || fromState == State::Captain_CoverTop || fromState == State::Captain_Walking);
	cap.vel.y = 0;
	cap.vel.x = 0;
	cap.shield->ThrowAway();
}

Data CaptainThrowing::Exit(Captain& cap, State toState)
{
	return Data{};
}

void CaptainThrowing::OnKeyUp(Captain& cap, BYTE keyCode)
{
}

void CaptainThrowing::OnKeyDown(Captain& cap, BYTE keyCode)
{
	assert(!cap.shieldOn);
	if (cap.animations.at(State::Captain_Throwing).IsDoneCycle()) {
		if (keyCode == setting.Get(KeyControls::Attack))
		{
			cap.SetState(State::Captain_Punching);
		}
		if (keyCode == setting.Get(KeyControls::Jump))
		{
			cap.SetState(State::Captain_Kicking);
		}
		if (keyCode == setting.Get(KeyControls::Down))
		{
			cap.SetState(State::Captain_Sitting);
		}
	}
}

void CaptainThrowing::Update(Captain& cap, float dt, const std::vector<GameObject*>& coObjects)
{
	if (cap.animations.at(State::Captain_Throwing).IsDoneCycle()) {

		cap.SetState(State::Captain_Walking); //Captain_Walking should handle nx, KeyControls::Left Right
	}
}

void CaptainThrowing::HandleCollisions(Captain& cap, float dt, const std::vector<GameObject*>& coObjects)
{
	auto coEvents = CollisionDetector::CalcPotentialCollisions(cap, coObjects, dt);

	for (auto& e : coEvents)
	{
	    if (auto bullet = dynamic_cast<Bullet*>(e.pCoObj))
		{
			if (!cap.isFlashing)
			{
				if (auto bullet = dynamic_cast<BulletEnemyRocket*>(e.pCoObj));
				cap.health.Subtract(bullet->GetDamage());
				cap.SetState(State::Captain_Injured);
				//TODO: case BulletEnemyFlying
			}
		}
		else if (auto enemy = dynamic_cast<Enemy*>(e.pCoObj))
		{
			if (cap.isFlashing) { // undamagable
				cap.CollideWithPassableObjects(dt, e);
			}
			else {
				cap.SetState(State::Captain_Injured);
				enemy->TakeDamage(1);
			}
		}
}

