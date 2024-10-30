/*
Cameron Tyree
Program 2
February 5 2024
*/

#include "personalLibrary.h"
int getMenuItem();
double calculateAverage(float*, int);
void sortScores(float*, int);
void enterScores(float*, int&, float);
void displayScores(float*, int);

  

int main() {
    const int SIZE = 5;
    float scores[SIZE];
    float grades = 0;
    int numberOfScores = 0;
    int userChoice;
    do {
        userChoice = getMenuItem();

        switch (userChoice) {
        case 1:
            enterScores(scores, numberOfScores, grades);
            break;
        case 2:
            sortScores(scores, numberOfScores);
            displayScores(scores, numberOfScores);
            break;
        case 3:
            cout << calculateAverage(scores, numberOfScores) << endl;
            break;
        }
    } while (userChoice != 4);

    endProgram();

}
void displayScores(float* scores, int numberOfScores) {
    cout << "Scores: " << endl;
    for (int i = 0; i < numberOfScores; i++) {
        cout << fixed << setprecision(2) << *(scores + i) << endl;
    }
}
int getMenuItem() {
    int choice;
    cout << "Menu:" << endl;
    cout << "1. Enter your scores" << endl;
    cout << "2. Sort rent amounts from low to high" << endl;
    cout << "3. Average the scores" << endl;
    cout << "4. Exit the program";
    choice = validateIntRange("Enter your choice: ", 1, 4);
    return choice;
}
double calculateAverage(float* scores, int numberOfScores) {
    float sum = 0.0;
    for (int i = 0; i < numberOfScores; i++) {
        sum += *(scores + i);
    }
    double average = sum / numberOfScores;
    cout << "Average score is: ";
    return average;
}
void sortScores(float* scores, int numberOfScores) {
    for (int i = 0; i < numberOfScores - 1; i++) {
        for (int j = 0; j < numberOfScores - i - 1; j++) {
            if (*(scores + j) > *(scores + j + 1)) {

                float tempPrice = *(scores + j);
                *(scores + j) = *(scores + j + 1);
                *(scores + j + 1) = tempPrice;
            }
        }
    }
    cout << "Prices from low to high:" << endl;
}
void enterScores(float* scores, int& numberOfScores, float grades) {
    do {
        cout << "How many grades do you have? ";
        cin >> grades;
        if (grades < 0) {
            cout << "Invalid input. Please enter a positive number." << endl;
        }
    } while (grades < 0);
    for (int i = numberOfScores; i < grades; i++) {
        do {
            cout << "Enter your scores " << numberOfScores + 1 << ": ";
            cin >> *(scores + i);
            if (*scores < 0) {
                cout << "Invalid input. Please enter a positive number." << endl;
            }
        } while (*scores < 0);
        numberOfScores++;
    }
}
