#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "rules.h"

using std::cout;
using std::cin;
using std::string;

int main()
{
    rules r;
    r.Rules();

    string playerName;
    int balance; //it stores the balance
    int bettingAmount;
    int guess;
    int dice; //random number
    char choice; //if one wants to keep playing
    srand(unsigned int(0)); //I chose unsigned int in order to get rid of the warning but you could've written time(0)

    cout << "\n\t\t ===== WELCOME TO CASINO BAR ==== \n\n";
    cout << "\n\n Please your name: ";
    getline(cin, playerName);
    cout << "\n\nEnter the starting balance to play the game : $";
    cin >> balance; //chosen balance

    do {
        system("cls");
        cout << "\n\nYour current balance is $ " << balance << "\n";

        do {
            cout << playerName << ", please enter the amount to bet : $";
            cin >> bettingAmount;

            if (bettingAmount > balance)
                cout << "Your bet can't be more than current balance!\n" << "\n Please place your bet again\n";
        } while (bettingAmount > balance);

        do {
            cout << "Guess any betting number between 1 and 10 :";
            cin >> guess;

            if (guess <= 0 || guess > 10)
                cout << "\n Number should be between 1 to 10\n" << "Please play another number:\n";

        } while (guess <= 0 || guess > 10);
        
        dice = rand() % 11 + 1; //math of the game

        if (dice == guess) {
            cout << "\n\nYou are in luck! You won! $" << bettingAmount * 10;
            balance = balance + bettingAmount *10;
        }

        else
        {
            cout << "ops, better luck next time!! You lost $" << bettingAmount<<"\n";
            balance = balance - bettingAmount;
        }

        cout << "\n The winning number was : " << dice << "\n";
        cout << "\n" << playerName << ", your balance is $" << balance << "\n";

        if (balance == 0)
        {
            cout << "You have no money to play ";
            break;
        }

        cout << "\n\n Do you want to play again? (y/n)";
        cin >> choice;
            
    } while (choice == 'y');
    
    cout << "\n\n\n";
    cout << "\n\nThanks for playing the game. Your final balance is $ " << balance << "\n\n";
    return 0;
        
}
