#include <iostream>
#include "Tile.h"
//#include "Globals.h"
#include<array>
#include "SFML/Graphics.hpp"



Color Brown(70.0f, 15.0f, 0.0f);

Tile::Tile(float xInput, float yInput, float wholeBox) {
	x = xInput;
	y = yInput;
	rect.setSize(RECTsIZE);
	a = 0;
	b = 0;
	c = 0;
	std::array<int, 3> typeT{ { 0, 0, 0 } };
	/*for (int i = 0; i < sizeof(type); i++) {
		typeT[i] = 0;
	}*/

	
	rect.setFillColor(Brown);
	//rect.setFillColor(Color(255, 0, 0));

	float halfBox = wholeBox / 2.0f;
	rect.setOrigin(halfBox, halfBox);

	//GetCoords();
	rect.setPosition(x, y);
}

void Tile::DrawTile(RenderWindow &wind) {
	
	
	wind.draw(rect);
	//std::cout << "ran" << std::endl;
	return;
}

int Tile::GetA() {
	return a;
}

void Tile::GetCoords() {
	std::cout << "x " << x << " y " << y << std::endl;
}

float Tile::GetXLocation() {
	return x;
}

float Tile::GetYLocation() {
	return y;
}

void Tile::ChangeColour(int value) {//TileType value) {
	//0 dirt
	//1 stone
	//2 pavement
	//3 grass
	//4 mud

	a = value;

	if (a == TileType::Dirt) {
		rect.setFillColor(Brown);
	}
	else if (a == TileType::Stone) {
		rect.setFillColor(Color(105.0f, 105.0f, 105.0f));
	}
	else if (a == TileType::Pavement) {
		rect.setFillColor(Color(192.0f, 192.0f, 192.0f));
	}
	else if (a == TileType::Grass) {
		rect.setFillColor(Color::Green);
	}
	else if (a == TileType::Mud) {
		rect.setFillColor(Color::Magenta);
	}
	else {
		std::cout << "Invalid value sent to Tile.cpp/ChangeColour(int value);" << std::endl;
	}

}

void Tile::ChangeType(int input[3]) {
	a = input[0];
	b = input[1];
	c = input[2];
	ChangeColour(a);
	//std::cout << a << "A" << std::endl;
	/*for (int i = 0; i < sizeof(typeT); i++) {
		typeT[i] = input[i];
	}*/
}