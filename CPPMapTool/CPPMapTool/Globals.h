#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

extern sf::Vector2f RECTsIZE;
//extern sf::RenderWindow WINDOW;
extern int oneLine;
extern int halfLine;



	//0 dirt
	//1 stone
	//2 pavement
	//3 grass
	//4 mud
enum TileType { Dirt, Stone, Pavement, Grass, Mud };