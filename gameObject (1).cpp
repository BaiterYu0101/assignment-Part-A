#include <iostream>
#include <string>
using namespace std;

class Alien {

private:
  int arrowCount;
  int attack;

public:
  Alien() {
    //Alien attack increase 20 when it received one arrow while moving
    arrowCount = 0;
    attack = 0;
  }

  void moveUp() {
    cout << "Alien Moved Up" << endl;
    arrowCount++;
    attack += 20;
  }

  void moveDown() {
    cout << "Alien Moved Down" << endl;
    arrowCount++;
    attack += 20;
  }

  void moveLeft() {
    cout << "Alien Moved Left" << endl;
    arrowCount++;
    attack += 20;
  }

  void moveRight() {
    cout << "Alien Moved Right" << endl;
    arrowCount++;
    attack += 20;
  }

  void displayStatus() {
    cout << "Attack: " << attack << endl;
  }
};

int main() {
  Alien a;
  string command;
  cout << "Alien move = " << " ";
  //cin >> command >> endl;
  while (true) {

    if (command == "Up") {
      a.moveUp();
    } else if (command == "Down") {
      a.moveDown();
    } else if (command == "Left") {
      a.moveLeft();
    } else if (command == "Right") {
      a.moveRight();
    } else if (command == "Quit") {
      break;
    } 
  }
  a.displayStatus();
  return 0;
}
