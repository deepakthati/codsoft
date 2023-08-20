#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(nullptr));
    
    int lowerBound = 1;
    int upperBound = 100;
    int secretNumber = rand() % (upperBound - lowerBound + 1) + lowerBound;
    
    cout << "Welcome to the Mysterious Number Guessing Game!" << endl;
    cout << "I'm thinking of a number between " << lowerBound << " and " << upperBound << ". Can you guess it?" << endl;
    
    int guess;
    int attempts = 0;
    
    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;
        
        if (guess < secretNumber) {
            cout << "Oops, your guess is a bit low. Try again!" << endl;
        } else if (guess > secretNumber) {
            cout << "Oops, your guess is a bit high. Try again!" << endl;
        } else {
            cout << "Congratulations! You've guessed the number " << secretNumber << " in " << attempts << " attempts." << endl;
        }
        
    } while (guess != secretNumber);
    
    cout << "Thanks for playing! Have a great day!" << endl;
    
    return 0;
}
