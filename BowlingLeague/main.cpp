//group members:

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

//global variables
const int rows = 10;
const int columns = 4;

//struct
struct bowler {
	string name;
	int fourScores[columns];
	int averageScore;
};

bool FillArrays(string scoresfile, bowler strutcure[]);
void outputResults(bowler bowlers[]);
void CalculateAverage(bowler bowlers[columns]);

int main() {
	//file variables
	string scoresfile = "BowlingScores.txt";

	//array of structures
	bowler structArray[rows];

	cout << endl << endl << endl;

	FillArrays(scoresfile, structArray);

	//call Average function
	CalculateAverage(structArray);

	outputResults(structArray);
}
void CalculateAverage(bowler bowlers[]) {
	int total = 0;
	int avg;
	for (int i = 0; i < rows; i++) {
		for (int c = 0; c < columns; c++) {
			total = total + bowlers[i].fourScores[c];
		}
		avg = total / columns;
		bowlers[i].averageScore = avg;
	}
}
bool FillArrays(string scoresfile, bowler bowlers[]) {
	//populate the name variable of the bowler structure
	ifstream scoresData;
	scoresData.open(scoresfile);
	char temp;
	int c = 0;
	string tempscore;
	string tempname;
	while (scoresData.get(temp)) {
		if (temp != ' ') {
			tempname = tempname + temp;
		}
		else {
			bowlers[c].name = tempname;
			//create an array of scores for each bowler
			for (int j = 0; j < 4; j++) {
				//the below line confirms that the next character is valid
				while (scoresData.peek() != ' ' && scoresData.peek() != '\n' && !scoresData.eof()) {
					scoresData.get(temp);
					//append the present character to a string to store in a two dimensional array
					tempscore = tempscore + temp;
				}
				//statements to add score elements (string) to specified index
				bowlers[c].fourScores[j] = stoi(tempscore);
				scoresData.get(temp);
				tempscore.clear();
			}
			c++;
			tempname.clear();
		}
	}
	scoresData.close();
	////////////////////////////
	return true;
}
////////////////////////////
//////////////////////////////////////////////////////////
void outputResults(bowler bowlers[]) {
	ofstream outputFile("scores.dat");

	cout << setfill('.');
	outputFile << setfill('.');
	for (int i = 0; i < rows; i++) {
		//ouput bowler names
		cout << bowlers[i].name << setw(15 - bowlers[i].name.length());
		outputFile << bowlers[i].name << setw(15 - bowlers[i].name.length());
		//output bowler scores
		for (int j = 0; j < columns; j++) {
			cout << bowlers[i].fourScores[j] << setw(15);
			outputFile << bowlers[i].fourScores[j] << setw(15);
		}
		//ouput bowler averages
		cout << bowlers[i].averageScore;
		outputFile << bowlers[i].averageScore;

		cout << endl;
		outputFile << endl;
	}
	outputFile.close();
}
///////////////////////////////////////////////////////////