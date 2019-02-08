// CPPMapTool.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*thread is std. Runs on creation. 
* thread th (FUNCTION);
* thread th (Function, paramater0);
* th.join(); //pauses main thread until th is completed. 
*/
//Thread is SF. Runs on run call. (Thread t(&function); t.launch()) 

//C++ Includes
#include <iostream>
#include <fstream>
#include <thread>
//#include <Windows.h>

//External Libraries
#include <SFML/Graphics.hpp>

//Headers
#include "Globals.h"
#include "hlcFiles.h"
#include "Tile.h"

//Namespaces
using namespace std;
using namespace sf;

//Defines
#define TileSize 50.0f
#define xWindow 800
#define yWindow 600
#define mapSize 100

//float TileSize = 50.0f;

//Functions
void ArrangeTiles();
void ConsoleInput();
void HandleInput(Event& event);

//Variables
//RenderWindow WINDOW(sf::VideoMode(xWindow, yWindow), "Map Tool");
Vector2f RECTsIZE(TileSize, TileSize);
int oneLine;
int halfLine;

TileType typeToSetTo;
std::vector<Tile> tiles;

fstream fs;
string filePath = "";

//Color Brown(70.0f, 15.0f, 0.0f);

int main()
{

	cout << "Welcome to the map tool. Press the function keys 1-5 to change the tile type." << endl <<
		"Click on tiles to change the tile to the currently selected tile type." << endl << endl << endl;
		

	RenderWindow wind(sf::VideoMode(xWindow, yWindow), "Map Tool");

	//fs.open("C:/Users/hislittlecuzin/Documents/Magnum/CPPMapTool/Test.txt");
	
	
	ArrangeTiles();
	//tiles[0].GetCoords();


	thread ConsoleInputThread(ConsoleInput);
	//Files::ReadFile(fs, tiles);
	

	while (wind.isOpen())
	{
		Event event;
		while (wind.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				wind.close();
			}
			HandleInput(event);
		}

		wind.clear();
		
		for (int i = 0; i < tiles.size(); i++) {
			
			tiles[i].DrawTile(wind);
		}

		wind.display();

	}


    //cout << "Hello World!\n";
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
void ArrangeTiles() {
	oneLine = (int)sqrt(100);
	halfLine = oneLine / 2;
	int line = 0;

	float xSpacing = 800 / oneLine; //x
	float ySpacing = 600 / oneLine; //y

	typeToSetTo = TileType::Dirt;
	cout << "Tile Type: Dirt " << typeToSetTo << endl;

	//cout << xSpacing << " " << ySpacing << endl;
	for (int y = 0; y < oneLine; y++) {
		for (int x = 0; x < oneLine; x++) {

			Tile temp(x * xSpacing + (TileSize * .75), y * ySpacing + (TileSize * .65), TileSize);
			tiles.push_back(temp);
		}
	}

}

void ConsoleInput() {
	string input = "";
	string choice = "";

	while (true) {
		cout << "Console awaiting input. Capitals only." << endl;
		if (choice == "") {
			cout << "Default actions:" << endl;
			cout << "LOAD" << endl;
			cout << "SAVE" << endl;
			cin >> choice;
		} 
		
		
		//Loading
#pragma region Loading
		else if (choice == "LOAD") {
			cout << endl << "Load from DIRectory? ESC to clear choices." << endl;
			cin >> input;
			if (input == "DIR") {
				cout << "Enter directory:" << endl;
				cin >> filePath;

				cout << endl << "Your current file path is: " << endl << filePath << endl;
				cout << "Would you like to load the file now? YES or NO. ESC to clear choices." << endl;
				cin >> input;
				if (input == "YES") {
					try {
						fs.open(filePath);
						Files::ReadFile(fs, tiles);
						fs.close();
						fs.clear();
					}
					catch (const exception& e) {
						cout << "Error. You typed in the file path incorrectly." << endl;
						cout << e.what() << endl;
					}
				}
				else if (input == "NO") {
					cout << endl;
				}
				else if (input == "ESC") {
					choice = "";
				}

				input = "";
				cout << endl << endl;

			}
			else if (input == "FILE") {

			}
			else if (input == "ESC") {
				choice = "";
				input = "";
			}
			
		}
#pragma endregion 



#pragma region Save
		else if (choice == "SAVE") {
			cout << endl << "Navigate to save DIRectory? ESC to clear choices." << endl;
			cin >> input;

			if (input == "DIR") {
				cout << "Enter directory:" << endl;
				cin >> filePath;

				cout << endl << "Your current file path is: " << endl << filePath << endl;
				cout << "Would you like to save the file now? YES or NO. ESC to clear choices." << endl;
				cin >> input;
				if (input == "YES") {
					try {
						fs.open(filePath);
						Files::WriteFile(fs, tiles, filePath);
						fs.close();
						fs.clear();
					}
					catch (const exception& e) {
						cout << "Error. You typed in the file path incorrectly." << endl;
						cout << e.what() << endl;
					}
				}
				else if (input == "NO") {
					cout << endl;
				}
				else if (input == "ESC") {
					choice = "";
				}

				input = "";
				cout << endl << endl;
			}
			else if (input == "ESC") {
				choice = "";
				input = "";
			}
		}
#pragma endregion

		else {
			cout << "Invalid choice." << endl;
			choice = "";
		}
		

		
	}
}
/*
string getexepath()
{
	char result[MAX_PATH];
	return std::string(result, GetModuleFileName(NULL, result, MAX_PATH));
}*/

void HandleInput(Event& event) {
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == Mouse::Left)
		{
			float halfBox = TileSize / 2.0f;

			float mouseX = event.mouseButton.x;
			float mouseY = event.mouseButton.y;
			
			for (int i = 0; i < tiles.size(); i++) {
				if (mouseX <= tiles[i].GetXLocation() + halfBox &&
					mouseX >= tiles[i].GetXLocation() - halfBox &&
					mouseY <= tiles[i].GetYLocation() + halfBox &&
					mouseY >= tiles[i].GetYLocation() - halfBox) {
					cout << "Box found. Box: " << i << endl;
					tiles[i].ChangeColour(typeToSetTo);
					break;
				}
			}
			cout << "the right button was pressed" << endl;
			cout << "mouse x: " << event.mouseButton.x << endl;
			cout << "mouse y: " << event.mouseButton.y << endl;
			
		}

	}
	
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Escape)
		{
			std::cout << "the escape key was pressed" << std::endl;
			std::cout << "control:" << event.key.control << std::endl;
			std::cout << "alt:" << event.key.alt << std::endl;
			std::cout << "shift:" << event.key.shift << std::endl;
			std::cout << "system:" << event.key.system << std::endl;
		}

		//0 dirt
	//1 stone
	//2 pavement
	//3 grass
	//4 mud
#pragma region TileType select
		if (event.key.code == Keyboard::F1) {
			typeToSetTo = TileType::Dirt;
			cout << "Tile Type: Dirt " << typeToSetTo << endl;
		}
		else if (event.key.code == Keyboard::F2) {
			typeToSetTo = TileType::Stone;
			cout << "Tile Type: Stone " << typeToSetTo << endl;
		}
		else if (event.key.code == Keyboard::F3) {
			typeToSetTo = TileType::Pavement;
			cout << "Tile Type: Pavement " << typeToSetTo << endl;
		}
		else if (event.key.code == Keyboard::F4) {
			typeToSetTo = TileType::Grass;
			cout << "Tile Type: Grass " << typeToSetTo << endl;
		}
		else if (event.key.code == Keyboard::F5) {
			typeToSetTo = TileType::Mud;
			cout << "Tile Type: Mud " << typeToSetTo << endl;
		}
#pragma endregion

		
	}

}

