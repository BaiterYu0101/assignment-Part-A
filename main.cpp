// *************************************************************************************************** 
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year: Trimester 1, 2022/23 (T2215) 
// Lab: T10L | T13L | T12L
// Names: CHIN SHENG JUN | LEE KEN YU | WONG GUANG YU
// IDs: 1211311480 | 1221303813 | 1211307906 
// Emails: 1211311480@student.mmu.edu.my |1221303813@student.mmu.edu.my | 1211307906@student.mmu.edu.my 
// Phones: 010-2708852 | 013-2566198 | 012-6559100 
// ****************************************************************************************************


#include <iostream>
#include <string>
#include <vector>
#include <ctime>   //time() in srand( time(NULL) )
#include <cstdlib> //system purpose
#include <iomanip> // setw()
#include <map>
using namespace std;

class gboard
{
private:
    vector<vector<char>> map_;
    int Col, Row;
public:
    gboard(int Col = 15, int Row = 15);
    void gobj(int Row, int Col);
    void displayboard() const;
};

gboard::gboard(int col, int row)
{
    gobj(col, row);
}

void gboard::gobj(int col, int row)
{
    Col = col;
    Row = row;
    char obj[] = {' ', '^', 'v', '<', '>', 'h', 'p', 'r', ' ', ' '};
    int numObj = 10;
    map_.resize(Row);
    for (int i = 0; i < Row; ++i)
    {
        map_[i].resize(Col);
    }

    for (int i = 0; i < Row; ++i)
    {
        for (int j = 0; j < Col; ++j)
        {
            int objNo = rand() % numObj;
            map_[i][j] = obj[objNo];
        }
    }
}

void gboard::displayboard() const
{
    cout << "  ";
    string text = ".: Alien vs Zombie :.";
    const int textWidth = 21;
    int width = Col*2+1;
    int space = (width - textWidth)/2;
    for (int x=0; x < space; ++x)
    {
        cout << " ";
    }
    cout << text <<  endl;
    

    for (int i=0 ; i < Row; ++i)
    {
        cout << "  ";
        for (int j=0; j < Col; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;
        cout << setw(2) << (Row - i);
        for (int j=0; j < Col; ++j)
        {
            cout << "|" << map_[i][j];
        }
        cout << "|" << endl;
    }
    cout << "  ";
    for (int j = 0; j < Col; ++j)
    {
        cout << "+-";
    }
    cout << "+" << endl;
    cout << "  ";
    for (int j=0; j < Col; ++j)
    {
        int digit = (j + 1) / 10;
        cout << " ";
        if (digit == 0)
            cout << " ";
        else
            cout << digit;
    }
    cout << endl;
    cout << "  ";
    for (int j = 0; j < Col; ++j)
    {
        cout << " " << (j + 1) % 10;
    }
    cout << endl
         << endl;
}

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

void chgsetting(int &row, int &col, int &Zombie)
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
    cin >> Zombie;
    cout << endl;
}

int main ()
{
    int row = 10;
    int col = 15;
    int Zombie = 1;
    char quest;
    vector<vector<char>> map(row, vector<char>(col));
    
    map.resize(row); 
        for (int i = 0; i < row; ++i) 
        {
            map[i].resize(col);
        }

    int game = 0;
    do
    {
        showsetting(row, col, Zombie);
        // system("cls") cant use;
        char Quest = uppercase(quest);
        if (Quest == 'Y')
        {
            chgsetting(row, col, Zombie);
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

    gboard gboard;
    gboard.displayboard();
}