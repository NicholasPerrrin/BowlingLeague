//group members:

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool FillArrays(ifstream& scoresData, string names[], int scores[][10]);
int CalculateAverage(string names[], int scores[]);
void Output(string names[],int scores[],int average[]);

int main() {
	char temp;
	//file variables
	ifstream scoresData;
	scoresData.open("BowlingScores.txt");
	ofstream outData;

	//array variables
	string names[10];//array listing the names of the bowlers
	int scores[4][10];//multidimensional array of the scores
	int average[10];//array of the average scores

	/*while (scoresData.get(temp)) {
		cout << temp;
	}*/
	//scoresData.close();

	cout << endl << endl << endl;

	cout << FillArrays(scoresData, names, scores);

	scoresData.close();
}
bool FillArrays(ifstream& scoresData, string names[], int scores[][10]) {//unfinished function. Any ideas on how to extract names? This is extracting characters.
	char temp;
	int c = 0;
	while (scoresData.get(temp) && temp != ' ') {
			cout << temp;
			names[c] = temp;
			c++;
	}

	for (int i = 0; i < 10; i++) {
		cout << names[i];
	}

	return true;
}