#include "pch.h"
#include "CaptainStanding.h"



void CaptainStanding::Enter(Captain& cap, State fromState, Data&& data)
{
	cap.vel.x = cap.vel.y = 0;
	isToSittingTackle = false;
}

Data CaptainStanding::Exit(Captain& cap, State toState)
{
	Data data;
	switch (toState)
	{
		case State::Captain_Sitting:
			data.Add("is-tackle", isToSittingTackle);
			break;
	}

	return std::move(data);
}

void CaptainStanding::OnKeyUp(Captain& cap, BYTE keyCode)
{
}

void CaptainStanding::OnKeyDown(Captain& cap, BYTE keyCode)
{
	auto kControlDir = cap.nx > 0 ? KeyControls::Right : KeyControls::Left;

	// if pressdown two time in a row in direction
	if (setting.Get(kControlDir) == keyCode &&
	    cap.lastKeyDown == kControlDir && cap.lastKeyUp == kControlDir)
	{
		std::chrono::duration<float> duration = std::chrono::steady_clock::now() - cap.timeLastKeyDown;
		if (duration.count() < 0.15f)
		{
			isToSittingTackle = true;
			cap.SetState(State::Captain_Sitting);
			return;
		}
	}
	else if (keyCode == setting.Get(KeyControls::Left))
	{
		cap.nx = - 1;
		cap.SetState(State::Captain_Walking);
	}
	else if (keyCode == setting.Get(KeyControls::Right))
	{
		cap.nx = 1;
		cap.SetState(State::Captain_Walking);
	}



	//if (keyCode == keyCodeDir)
	//{
	//	if (isLastPressedDir) // first press on direction
	//	{
	//		if (timePressedDir > 0.1f)
	//		{
	//			timePressedDir = 0.0f;
	//			isLastPressedDir = false;
	//		}
	//		else
	//		{
	//			Data data;
	//			data.Add("is-tackle", true);

	//			cap.SetState(State::Captain_Sitting,);
	//		}
	//		isLastPressedDir = true;
	//	}
	//	else
	//	{

	//	}

	//}

	// set direction




	//std::optional<State> shouldBeNextState;

	//if (keyCode == setting.Get(KeyControls::Left)) {
	//	cap.vel.x -= WALKING_SPEED;
	//}
	//if (keyCode == setting.Get(KeyControls::Right)) {
	//	cap.vel.x += WALKING_SPEED;
	//}
	//if (cap.vel.x != 0.0f) {
	//	shouldBeNextState = State::Captain_Walking;
	//}
	//else {
	//	int yDir = 0;
	//	if (keyCode == setting.Get(KeyControls::Up)) {
	//		yDir --;
	//	}
	//	if (keyCode == setting.Get(KeyControls::Down)) {
	//		yDir ++;
	//	}
	//	if (yDir != 0) {
	//		shouldBeNextState = yDir > 0 ? State::Captain_Sitting : State::Captain_CoverTop;
	//	}
	//}

	//if (shouldBeNextState.has_value())
	//{
	//	cap.SetState(*shouldBeNextState);
	//}
}

void CaptainStanding::Update(Captain& cap, float dt, const std::vector<GameObject*>& coObjects)
{
	int dir = 0;
	if (wnd.IsKeyPressed( setting.Get(KeyControls::Left) ))
	{
		dir --;
	}
	if (wnd.IsKeyPressed( setting.Get(KeyControls::Right) ))
	{
		dir ++;
		cap.nx = 1;
	}
	if (dir != 0)
	{
		cap.nx = dir;
		cap.SetState(State::Captain_Walking);
	}


	//if (isLastPressedDir && wnd.IsKeyPressed(kControlDir))
	//{
	//	timePressedDir += dt;
	//}
	//else
	//{
	//	timePressedDir = 0.0f;
	//}


	// when standing, almost do nothin, only respond to collisions
	HandleCollisions(cap, dt, coObjects);
}

void CaptainStanding::HandleCollisions(Captain& cap, float dt, const std::vector<GameObject*>& coObjects)
{
}
