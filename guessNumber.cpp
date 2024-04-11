#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main()
{
       while (true) {
        // generating the secret number
        srand(time(0));
        int secretNumber = 1 + (rand() % 100);
        int playerChoice;

            cout << "\nYou have 10 choices for finding the secret number between 1 and 100.";
            int choicesLeft = 10;
            for (int i = 1; i <= 10; i++) {

                cout << "\nEnter the number: ";
                cin >> playerChoice;

                if (playerChoice == secretNumber) {
                    cout << "Well played! You won, "
                         << playerChoice
                         << " is the secret number" << endl;
                    break;
                }
                else {
                    cout << "Nope, " << playerChoice << " is not the right number\n";
                    if (playerChoice > secretNumber) {
                        cout << "The secret number is smaller than the number you have chosen"
                             << endl;
                    }
                    else {
                        cout << "The secret number is greater than the number you have chosen"
                             << endl;
                    }
                    choicesLeft--;
                    cout << choicesLeft << " choices left. "<< endl;
                    if (choicesLeft == 0) {
                        cout << "You couldn't find the "
                                "secret number, it was "
                             << secretNumber;
                    }
                }
            }
        }
    return 0;
}
