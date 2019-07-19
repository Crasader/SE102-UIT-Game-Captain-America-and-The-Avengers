#pragma once

enum class TextureId
{
	Bbox                        = 0,
	Warning                     = 1,
	KeyCodeFont                 = 2,
	CrtEffect                   = 3,
	MapCharleston               = 4,
	MapBossCharlestonLight      = 5,
	MapBossCharlestonDark       = 6,
	MapPittsburghDark           = 7,
	MapPittsburghLight          = 8,
	MapRedAlert                 = 9,
	Captain                     = 10,
	Enemies                     = 11,
	Wizard                      = 12,
	Dynamite                    = 13,
};

enum class SpriteId
{
	Invisible			            =  0,
							           
	EnemyGun_Stand			        =  1,
	EnemyGun_Walking		        =  2,
	EnemyGun_BeforeExplode          =  3,
	EnemyGun_Sitting                =  4,
	BulletEnemyGun			        =  5,

	EnemyRocket_Stand               =  6,
	EnemyRocket_Walking             =  7,
	EnemyRocket_BeforeExplode       =  8,
	EnemyRocket_Sitting             =  9,
	BulletEnemyRocket_Horizontal    = 10,
	BulletEnemyRocket_Cross         = 11,

	Explode                         = 12,

	ItemSmallPowerStone             = 13,
	ItemBigPowerStone               = 14,
	ItemFivePoint                   = 15,
	ItemOneUp                       = 16,
	ItemSmallEnergy                 = 17,
	ItemBigEnergy                   = 18,
	ItemKeyKrystal                  = 19,

	ExitSign                        = 20,
	CaptainHealth                   = 21,
	CapsuleIdle                     = 22,
	CapsuleOpenning                 = 23,

	Shield_Side                     = 24,
	Shield_Straight                 = 25,
	Shield_Down                     = 26,
	Shield_Up                       = 27,

	Captain_Standing = 100,
	Captain_Walking = 101,
	Captain_Jump = 102,
	Captain_LookUp = 103,
	Captain_Sitting = 104,
	Captain_Punching = 105,
	Captain_Throw = 106, 
	Captain_Falling = 107,
	Captain_JumpKick = 108,
	Captain_SitPunch = 109,
	Captain_Smash = 110
};

enum class SoundId
{
	Invalid          = -1,
	Greeting         =  0,
	Cursor           =  1,
	CaptainTheme     =  2,
	BossBattle       =  3,
	RedAlert         =  4,
	Ambush           =  5,
	Death            =  6,
	ItemKrystal      =  7,
	ItemEnergy       =  8,
	ItemNormal       =  9,
	BulletNormal     = 10,
	BulletLazer      = 11,
	Explosion        = 12,
	ShieldThrow      = 13,
	ShieldCollide    = 14,
	Punch            = 15,
	Tackle           = 16,
	HighJump         = 17,
	Grounding        = 18,
	Water            = 19,
};

enum class ClassId
{
	Captain              =   0,

	// static objects: load from json
	RigidBlock           =   1,
	Water                =   2,
	PassableLedge        =   3,
	ClimbableBar         =   4,
	DamageBlock          =   5,
	Switch               =   6,
	NextMap              =   7,
	Door                 =   8,
	Spawner              =   9,
	AmbushTrigger        =  10,
	Capsule              =  11,

	// moving objects: being spawned
	EnemyGun             =  100,
	EnemyRocket          =  101,
};

enum class State
{
	Invisible,
	Destroyed,

	EnemyGun_Walking,
	EnemyGun_Stand,
	EnemyGun_Sitting,
	EnemyGun_BeforeExplode,
	BulletEnemyGun,

	EnemyRocket_Walking,
	EnemyRocket_Stand,
	EnemyRocket_Sitting,
	EnemyRocket_BeforeExplode,
	BulletEnemyRocket_Horizontal,
	BulletEnemyRocket_Cross,

	Item_Hide,
	Item_Bouncing,
	Item_Falling,
	Item_Grounding,
	Item_Disappearing,
	Capsule_Idle,
	Capsule_Openning,

	Explode,

	Shield_Side,
	Shield_Straight,
	Shield_Down,
	Shield_Up,

	Captain_Standing,
	Captain_Moving,
	Captain_Jump,
	Captain_LookUp,
	Captain_Sitting,
	Captain_Punching,
	Captain_Falling,
	Captain_Throw,
	Captain_OnOneKnee,
	Captain_OnTwoKnee,
	Captain_JumpKick,
	Captain_SitPunch,
	Captain_Smash,
	Captain_Climb,
	Captain_Spin
};

enum class Behaviors // for enemy, moving ledges
{
	EnemyGun_Shoot   = 0, // Sit -> Stand& Shoot -> Repeat. Always update on toward Captain, not moving.
	EnemyGun_RunOnly = 1, // Running fast with an entry velocity, that velocity is originaly set on toward Captain.
	EnemyGun_Ambush  = 2, // Walking Right -> Stand& Shoot -> Repeat. If Captain's throwing shield => Walking->Jumping 

	EnemyRocket_ShootStraight = 10, // First walk a bit. Stand& Shoot -> Sit& Shoot -> Repeat. Always update on toward Captain, not moving.
	EnemyRocket_ShootCross    = 11, // Like above, but the bullet shot out fly cross.
	EnemyRocket_BackAndForth  = 12, // Sit& ShootStraight -> Stand -> Walking 3 cycles -> Repeat. Always face one direction, that direction is originaly set on toward Captain.
	EnemyRocket_BackAndForth2 = 13, // There's 1 enemy jumps once before in BackAndForth behavior
	EnemyRocket_Ambush        = 14, // Walking Left Only. If Captain's throwing shield => Jumping instead of Walking 
};

enum class Scene
{
	Greeting,
	Charleston,
	BossCharleston,
	Pittsburgh,
	RedAlert
};




