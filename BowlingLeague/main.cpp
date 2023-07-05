//group members:

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

//global variables
const int rows = 10;
const int columns = 4;

bool FillArrays(string scoresfile, string names[], string scores[][columns]);
void CalculateAverage(string names[], string scores[][columns], int average[]);
void Output(string names[], char scores[], int average[]);
void outputResults(string bowlers[], string scores[][columns], int averages[]);
bool FillStructures(string scoresfile, struct bowlers[columns]);
void CalclateStructAverage(struct bowlers[columns]);

//struct
struct bowler {
	string name;
	int fourScores[rows];
	int averageScore;
};

int main() {
	//file variables
	string scoresfile = "BowlingScores.txt";

	//array variables
	string names[rows];//array listing the names of the bowlers
	string scores[rows][columns];//multidimensional array of the scores
	int average[rows];//array of the average scores

	//array of structures
	bowler structArray[columns];

	cout << endl << endl << endl;

	FillArrays(scoresfile, names, scores);

	//call Average function
	CalculateAverage(names, scores, average);

	outputResults(names, scores, average);
}
void CalculateAverage(string names[], string scores[][columns], int average[]) {
	int index = 0;
	int total = 0;
	int avg;
	for (int c = 0; c < 10; c++) {
		for (int i = 0; i < 4; i++) {
			total = total + stoi(scores[c][i]);
		}
		avg = total / 4;
		average[index] = avg;
		index++;
		total = 0;
	}
}
//bool FillArrays(string scoresfile, string names[], string scores[rows][columns]) {//unfinished function
//	//create an array of the bowler's names (complete)
//	ifstream scoresData;
//	scoresData.open(scoresfile);
//	char temp;
//	int c = 0;
//	string tempname;
//	while (scoresData.get(temp)) {
//		if (temp != ' ') {
//			tempname = tempname + temp;
//		}
//		else {
//			scoresData.ignore(100, '\n');
//			names[c] = tempname;
//			c++;
//			tempname.clear();
//		}
//	}
//	scoresData.close();
//	scoresData.open(scoresfile);
//	////////////////////////////
//	//create the multi dimensional array of bowler's scores (complete)
//	int i = 0;//index of rows
//	int j = 0;//index of columns
//	string tempscore;
//
//	//for statement to iterate through rows
//	for (i; i < 10; i++) {
//		//remove names from the file
//		scoresData.ignore(100, ' ');
//		//for statement to iterate through columns
//		for (j = 0; j < 4; j++) {
//			//the below line confirms that the next character is valid
//			while (scoresData.peek() != ' ' && scoresData.peek() != '\n' && !scoresData.eof()) {
//				scoresData.get(temp);
//				//append the present character to a string to store in a two dimensional array
//				tempscore = tempscore + temp;
//			}
//			//statements to add score elements (string) to specified index
//			scores[i][j] = tempscore;
//			scoresData.get(temp);
//			tempscore.clear();
//		}
//	}
//
//	return true;
//}
////////////////////////////
//create an array of the bowler's average scores
//////////////////////////////////////////////////////////
void outputResults(string bowlers[], string scores[][columns], int averages[]) {
	ofstream outputFile("scores.dat");

	cout << setfill('.');
	outputFile << setfill('.');
	for (int i = 0; i < 10; i++) {
		cout << bowlers[i] << setw(15 - bowlers[i].length());
		outputFile << bowlers[i] << setw(15 - bowlers[i].length());

		for (int j = 0; j < 4; j++) {
			cout << scores[i][j] << setw(15);
			outputFile << scores[i][j] << setw(15);
		}
		cout << averages[i];
		outputFile << averages[i];

		cout << endl;
		outputFile << endl;
	}
	outputFile.close();
}
///////////////////////////////////////////////////////////
bool FillStructures(string scoresfile, struct bowlers[columns]) {
	//create an array of the bowler's names (complete)
	ifstream scoresData;
	scoresData.open(scoresfile);
	char temp;
	int c = 0;
	string tempname;
	while (scoresData.get(temp)) {
		if (temp != ' ') {
			tempname = tempname + temp;
		}
		else {
			scoresData.ignore(100, '\n');
			bowlers[c].name = tempname;
			c++;
			tempname.clear();
		}
	}
	scoresData.close();
	scoresData.open(scoresfile);
	////////////////////////////
	//create the multi dimensional array of bowler's scores (complete)
	int i = 0;//index of rows
	int j = 0;//index of columns
	string tempscore;

	//for statement to iterate through rows
	for (i; i < 10; i++) {
		//remove names from the file
		scoresData.ignore(100, ' ');
		//for statement to iterate through columns
		for (j = 0; j < 4; j++) {
			//the below line confirms that the next character is valid
			while (scoresData.peek() != ' ' && scoresData.peek() != '\n' && !scoresData.eof()) {
				scoresData.get(temp);
				//append the present character to a string to store in a two dimensional array
				tempscore = tempscore + temp;
			}
			//statements to add score elements (string) to specified index
			scores[i][j] = tempscore;
			scoresData.get(temp);
			tempscore.clear();
		}
	}

	return true;
}