//group members:

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool FillArrays(ifstream& scoresData, string names[], string scores[][4]);
int CalculateAverage(string names[], char scores[]);
void Output(string names[],char scores[],char average[]);

int main() {
	char temp;
	//file variables
	ifstream scoresData;
	scoresData.open("BowlingScores.txt");
	ofstream outData;

	//array variables
	string names[10];//array listing the names of the bowlers
	string scores[10][4];//multidimensional array of the scores
	char average[10];//array of the average scores

	/*while (scoresData.get(temp)) {
		cout << temp;
	}*/
	//scoresData.close();

	cout << endl << endl << endl;

	cout << FillArrays(scoresData, names, scores);

	scoresData.close();
}
bool FillArrays(ifstream& scoresData, string names[], string scores[10][4]) {//unfinished function
	//create an array of the bowler's names (complete)
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
	scoresData.open("BowlingScores.txt");
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
	//create an array of the bowler's average scores

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