#pragma once

enum AttackType
{
	PHYSIC,
	FIRE,
	ICE,
	WATER,
	SPARKS,
	DARKNESS,
	LIGHT
};

typedef struct Attack 
{
	AttackType type;
	sf::FloatRect bounds;
	int damage;
	bool playerSide;
	bool friendlyFire;
} attack;

