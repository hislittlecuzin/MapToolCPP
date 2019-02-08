#pragma once
#include <SFML/Graphics.hpp>
#include <array>
#include "Globals.h"

using namespace sf;
class Tile {
public:
	Tile(float xInput, float yInput, float wholeBox);
	void DrawTile(RenderWindow &wind);
	void ChangeColour(int value);
	void GetCoords();
	void ChangeType(int input[3]);
	float GetXLocation();
	float GetYLocation();
	int GetA();
protected:

private:
	float x, y;
	int a, b, c;
	std::array<int, 3> typeT;
	//Color colour;

	RectangleShape rect;




};