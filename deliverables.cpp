#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <time.h>
using namespace std;

void healthpack(int &alienHealth)
{
    cout << "alien found a health pack" << endl;
    cout << "alien health has increased\n"
         << endl;
    
    for (int i = 0; i < 100; ++i)
    {
        if (alienHealth == 100)
        {
            break;
        }
        ++alienHealth;
        if (i ==19)
        {
            break;
        }
    }
}

void pod(int &alienatk, int &zombieH, int row, int col)
{
    cout << "alien found a pod" << endl;
    cout << "the nearest zombie health decrease by 10" << endl;
    alienatk =alienatk + 10;
}

void rock()
{
    cout << "alien stunned by the rock" << endl;
    cout << "alien stop" << endl;
    //need table to modify alien address
    //in table
    srand(time(NULL));
    char object[7] = {'^', 'v', '<', '>', 'h', 'p', '.'};
    int ranobj = rand() % 7;
    cout << object[ranobj];
}

int main()
{
    int alienHealth = 100;
    int alienatk = 0;
    int zombieH = 100;
    int Row = 5;
    int Col = 9;
    alienHealth = alienHealth - 40;
    //healthpack(alienHealth);
    //pod(alienatk, zombieH, Row, Col);
    cout << "alienHealth=" << alienHealth << endl;
    cout << "alien attack=" << alienatk << endl;
    rock();
}