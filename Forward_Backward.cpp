#include <iostream>
using namespace std;

class LunarCraft {
private:
    int x, y, z; // Current position (x, y, z)
    char direction; // Current direction (N, S, E, W, U, D)
    char sub;

public:
    LunarCraft() {
        x = 0;
        y = 0;
        z = 0;
        direction = 'N'; // Initial direction is North
    }

    void move(char command) {
        if (command == 'f') {
            moveForward();
        } else if (command == 'b') {
            moveBackward();
        } else if (command == 'l') {
            turnLeft();
        } else{
            turnRight();
        } 
    }

    void moveForward() {
        if (direction == 'N') {
            y++;
        } else if (direction == 'S') {
            y--;
        } else if (direction == 'E') {
            x++;
        } else {
            x--;
        }
    }

    void moveBackward() {
        if (direction == 'N') {
            y--;
        } else if (direction == 'S') {
            y++;
        } else if (direction == 'E') {
            x--;
        } else {
            x++;
        }
    }

    void turnLeft() {
        if (direction == 'N') {
            direction = 'W';
        } else if (direction == 'S') {
            direction = 'E';
        } else if (direction == 'E') {
            direction = 'N';
        } else{
            direction = 'S';
        }
    }

    void turnRight() {
        if (direction == 'N') {
            direction = 'E';
        } else if (direction == 'S') {
            direction = 'W';
        } else if (direction == 'E') {
            direction = 'S';
        } else{
            direction = 'N';
        }
    }



    void printPosition() {
        cout << "Final Position: (" << x << ", " << y << ", " << z << ")" << endl;
        cout << "Final Direction: " << direction << endl;
    }
};

int main() {
    LunarCraft chandrayaan3;
    char commands[] = {'f', 'r', 'l', 'f', 'l', 'b'};

    for (char command : commands) {
        chandrayaan3.move(command);
    }

    chandrayaan3.printPosition();

    return 0;
}
