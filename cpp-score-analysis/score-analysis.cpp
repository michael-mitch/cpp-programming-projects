#include <iostream>
using namespace std;

void analyzeScores (int scores[10], int* highest, int* lowest, double* average);

int main() {
	int scores[10] = {75, 82, 63, 54, 88, 98, 45, 92, 81, 79};

	int highest, lowest;
	double average;

	analyzeScores(scores, &highest, &lowest, &average);

	cout << "Highest Score" << highest << endl;
	cout << "Lowest Score" << lowest << endl;
	cout << "Average Score" << average << endl;

	return 0;
}

void analyzeScores (int scores[10], int* highest, int* lowest, double* average) {
	int sum = 0;
	*highest = scores[0];
	*lowest = scores[0];

	for (int i = 0; i < 10; i++) {
		if (scores[i] > *highest) {
			*highest = scores[i];
		}

		if (scores[i] < *lowest) {
			*lowest = scores[i];
		}

		sum += scores[i];
	}

	*average = sum / 10.0;

}


