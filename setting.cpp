#include <iostream>
#include <stdlib.h>
using namespace std;

void showsetting(int Row, int Col, int Zombie)
{
    cout << "Default Game Settings" << endl;
    cout << "-----------------------" << endl;
    cout << "Board Rows    : " << Row << endl;
    cout << "Board Columns : " << Col << endl;
    cout << "Zombie Count  : " << Zombie << endl;
    cout << endl;
}

char uppercase(char quest)
{
    cout << "Do you wish to change the setting? (Y/N): ";
    cin >> quest;
    cout << endl;
    char Q;
    Q = toupper(quest);
    return Q;
}

void chgsetting(int &row, int &col, int &zombie)
{
    cout << "Board Setting \n";
    cout << "--------------- \n";
    cout << "Enter rows => ";
    cin >> row;
    cout << "Enter columns => ";
    cin >> col;
    cout << endl;
    cout << "Zombie Setting\n";
    cout << "---------------\n";
    cout << "Enter number of zombie => ";
    cin >> zombie;
    cout << endl;
}

int main()
{
    int Row = 5;
    int Col = 9;
    int Zombie = 1;
    char quest;
    int game = 0;
    do
    {
        showsetting(Row, Col, Zombie);
        // system("cls") cant use;
        char Quest = uppercase(quest);
        if (Quest == 'Y')
        {
            chgsetting(Row, Col, Zombie);
            game = ++game;
        }
        else if (Quest == 'N')
        {
            game = ++game;
        }
        else
        {
            cout << "Sorry, We don't understand the " << Quest << endl;
            cout << "Please Try again\n" << endl;
        }
    } while(game == 0);
}