#include <iostream>
#include <fstream>
#include <charconv>

#include "hlcFiles.h"
//#include "Tile.h"


void Files::ReadFile(fstream &fs, vector<Tile> &tiles) {

	char ch;
	int tileDataIndex = 0;
	int vectorIndex = 0;
	bool noErrors = true;

	int tileData[3] = { 0, 0, 0 };

	while (!fs.eof()) {
		fs.get(ch);
		cout << ch;

		switch (ch) {
		case ';':
		//case '\n': //Not needed. Can fek things up with vectorIndex++
			tileDataIndex = 0;
			vectorIndex++;
			break;
		default:
			if ('0' <= ch && ch <= '9') {
				tileData[tileDataIndex] = ch - 48;//std::stoi(std::string(&ch, 1));
			}
			else {
				cout << endl << "ERROR! Value of character is not a digit: " << ch << endl;
				tileData[tileDataIndex] = -1;
				noErrors = false;
			}
			cout << tileDataIndex << endl;
			tileDataIndex++;
			break;
		}


		if (tileDataIndex >= 3) {
			//cout << endl << "Tile " << vectorIndex << " tile index " << tileDataIndex << endl;
			tiles[vectorIndex].ChangeType(tileData);

		}
	}
	if (noErrors)
		cout << endl << "File read successfully." << endl;
	else
		cout << endl << "File had errors. Open the file to verify there are numbers grouped in 3s and ending with semi-colons." << endl;

	/*
	char ch;
	int tileDataIndex = 0;
	int vectorIndex = 0;

	int tileData[3] = {-1, -1, -1};

	while (!fs.eof()) {
		fs.get(ch);
		cout << ch;

		if (tileDataIndex < 3) {
			tileData[tileDataIndex] = Interpret(&ch, &tileDataIndex, &vectorIndex);
		}

		Incriment(&ch, &tileDataIndex, &vectorIndex);

		if (tileDataIndex >= 3) {
			cout << endl << "Tile " << vectorIndex << " tile index " << tileDataIndex << endl;
			tiles[vectorIndex].ChangeType(tileData);
		}

		if (tileDataIndex >= 3) {
			cout << "Ran0" << endl;
			Interpret(&ch, &tileDataIndex, &vectorIndex);
		}
	}

	cout << endl << "File read." << endl;*/
}
/*
void Files::Incriment(char * ch, int * tileDataIndex, int * vectorIndex) {
	if (*ch != ';' && *ch != '\n')
		*tileDataIndex += 1;

	else if (*ch == ';' || *ch == '\n') {
		*tileDataIndex = 0;
		*vectorIndex += 1;
	}

}

int Files::Interpret(char * ch, int  * tileDataIndex, int  * vectorIndex) {
	if (*ch == '\n') {
		return -1;
	} else if (*ch == ';') {
		//*tileDataIndex = 0;
		//*vectorIndex += 1;
		return -1;
	} else {
		try {
			if ((int)ch > 48 || (int)ch <= 57) {
				
				int returnVariable = (int)ch;// -48;
				return returnVariable;
			}
			else {
				int foo;
				cout << endl << "ERROR! Value of character is not a digit." << endl;
				cin >> foo;
				return -1;
			}
		}
		catch (const exception& e) {
			int foo;
			cout << e.what() << endl;
			cin >> foo;
			return -1;
		}
	}
}
*/

void Files::WriteFile(fstream &fs, vector<Tile> &tiles, string fileName) {
	//if oneLine (sqrt(tiles.size())%10 == 0), new line. 
	//fs.open(fileName);
	for (int i = 0; i < tiles.size(); i++) {
		//string data = reinterpret_cast<char*>(tiles[i].GetA()); //returns integer
		//data += "0";
		//data += "0";
		//data += ";";
		
		//fs << reinterpret_cast<char*>(tiles[i].GetA()) << reinterpret_cast <char*>(0) << reinterpret_cast <char*>(0) << ';';
		//fs << data;
		if (i % oneLine == 0 && i > 0)
			fs << "\n";
		fs << tiles[i].GetA() << "00;";
	}
}
