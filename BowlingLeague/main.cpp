//group members:

#include <iostream>
#include <fstream>

using namespace std;

int main() {
	char temp;
	//variables
	ifstream scoresData;
	scoresData.open("BowlingScores.txt");
	ofstream outData;

	while (scoresData.get(temp)) {
		cout << temp;
	}
	scoresData.close();
}