//group members:

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool FillArrays(string scoresfile, string names[], string scores[][4]);
int CalculateAverage(string names[], string scores[][4]);
void Output(string names[],char scores[],char average[]);
void outputResults(string bowlers[], string scores[][4], int averages[]);

int main() {
	char temp;
	//file variables
	ifstream scoresData;
	string scoresfile = "BowlingScores.txt";
	//scoresData.open("BowlingScores.txt");
	ofstream outData;

	//array variables
	string names[10];//array listing the names of the bowlers
	string scores[10][4];//multidimensional array of the scores
	int average[10];//array of the average scores

	/*while (scoresData.get(temp)) {
		cout << temp;
	}*/
	//scoresData.close();

	cout << endl << endl << endl;

	cout << FillArrays(scoresfile, names, scores);

	scoresData.close();

	//call Average function
	int test = CalculateAverage(names, scores);

	outputResults(names, scores, average);
}
int CalculateAverage(string names[], string scores[][4]) {
	int averages[10];
	int index = 0;
	int total = 0;
	int avg;
	for (int c = 0; c < 10; c++) {
		for (int i = 0; i < 4; i++) {
			total = total + stoi(scores[c][i]);
		}
		avg = total / 4;
		averages[index] = avg;
		index++;
		total = 0;
	}
	for (int c = 0; c < 10; c++) {
		cout << "Average: " << averages[c] << endl;
	}

	return 1;
}
bool FillArrays(string scoresfile, string names[], string scores[10][4]) {//unfinished function
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
			scoresData.ignore(100,'\n');
			names[c] = tempname;
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
	////////////////////////////
	//everything below this line just makes sure that the arrays are filling properly (ouputs every element)
	for (int i = 0; i < c; i++) {
		cout << names[i] << endl;
	}
	cout << endl << endl;

	int index = 0;
	for (int q = 0; q < 10; q++) {
		for (int k = 0; k < 4; k++) {

			cout << "index: " << index << "   " << scores[q][k] << endl << endl;
			index++;
		}
	}

	return true;
}
////////////////////////////
//create an array of the bowler's average scores
//////////////////////////////////////////////////////////
void outputResults(string bowlers[], string scores[][4], int averages[]) {
//	ofstream outputFile("scores.dat");
//	return;
//
//
	for (int i = 0; i < 10; i++) {
		cout << bowlers[i] << endl;
//		//outputFile << bowlers[i] << endl;
//
		for (int j = 0; j < 4; j++) {
			cout << scores[i][j] << endl;
//			//outputFile << scores[i][j] << endl;
		}
//
		cout << endl;
//		//outputFile << endl;
	}
//	outputFile.close();
}