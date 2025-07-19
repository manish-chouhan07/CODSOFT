#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

int main() {
    srand(time(0)); // Seed for random number
    cout << "Let's play a game......." << endl;
    cout << "I am guessing a number between 1 and 100" << endl;
    cout << "Can you guess it?" << endl;

    int secnum = rand() % 100 + 1; // Secret number between 1 and 100
    int guess;

    while (true) {
        cout << "Enter Your guess: ";
        cin >> guess;

        int diff = abs(secnum - guess); // Difference for hint

        if (guess == secnum) {
            cout << "🥳🥳 Congrats! You guessed it!! 🥂" << endl;
            break; // Exit the loop
        }
        else if (diff <= 5) {
            cout << "😯 Very close!!";
        }
        else if (diff <= 10) {
            cout << "😓 Close";
        }
        else if (diff < 15) {
            cout << "😒 Far";
        }
        else {
            cout << "🤦‍♂️ Very far";
        }

        // Give direction to guess
        if (guess < secnum) {
            cout << endl << "Try a higher number 🔼" << endl;
        } else {
            cout << endl << "Try a lower number 🔽" << endl;
        }
    }

    cout << endl << "The secret number was: " << secnum << endl;

    return 0;
}
