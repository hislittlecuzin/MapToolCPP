#pragma once
#include <iostream>
#include <fstream>

#include "Tile.h"

using namespace std;

class Files {
private:
	static int Interpret(char * ch, int  * tileDataIndex, int  * vectorIndex);
	static void Incriment(char * ch, int * tileDataIndex, int * vectorIndex);
	//static int index;
	//static int tileData[3];

public: 
	static void ReadFile(fstream &fs, vector<Tile> &tiles); //fs stands for file stream
	static void WriteFile(fstream &fs, vector<Tile> &tiles, string fileName);


};