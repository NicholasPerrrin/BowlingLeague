//group members:

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool FillArrays(ifstream& scoresData, string names[], char scores[][4]);
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
	char scores[10][4];//multidimensional array of the scores
	char average[10];//array of the average scores

	/*while (scoresData.get(temp)) {
		cout << temp;
	}*/
	//scoresData.close();

	cout << endl << endl << endl;

	cout << FillArrays(scoresData, names, scores);

	scoresData.close();
}
bool FillArrays(ifstream& scoresData, string names[], char scores[][4]) {//unfinished function
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
	////////////////////////////
	//create the multi dimensional array of bowler's scores (incomplete)


	////////////////////////////
	for (int i = 0; i < c; i++) {
		cout << names[i] << endl;
	}

	return true;
}