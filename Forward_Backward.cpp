#include <iostream>
using namespace std;

class LunarCraft {
private:
    int x, y, z; // Current position (x, y, z)
    char direction;// Current direction (N, S, E, W, U, D)

public:
    LunarCraft() {
        x = 0;
        y = 0;
        z = 0;
        direction = 'N';
    }

    void move(char command) {
        if (command == 'f') {
            moveForward();
        } else{
            moveBackward();
        } 
    }

    void moveForward() {
        if (direction == 'N') {
            y++;
        } else {
            y--;
        }
    }

    void moveBackward() {
        if (direction == 'N') {
            y--;
        } else {
            y++;
        } 
    }
   void printPosition() {
        cout << "Final Position: (" << x << ", " << y << ", " << z << ")" << endl;
        cout << "Final Direction: " << direction << endl;
    }
};

int main() {
    LunarCraft chandrayaan3;
    char commands[] = {'f','b','f'};

    for (char command : commands) {
        chandrayaan3.move(command);
    }

    chandrayaan3.printPosition();

    return 0;
}
