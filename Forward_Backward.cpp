#include <bits/stdc++.h>
using namespace std;

class LunarCraft {
private:
    int x, y, z; // Current position (x, y, z)
    char direction;// Current direction (N, S, E, W, U, D)
    char sub;

public:
    LunarCraft() {
        x = 0;
        y = 0;
        z = 0;
        direction = 'N'; // Initial direction is North
    }

    void move(char command) {
        switch (command) {
            case 'f':
                moveForward();
                break;
            case 'b':
                moveBackward();
                break;
            case 'l':
                turnLeft();
                break;
            case 'r':
                turnRight();
                break;
            case 'u':
                turnUp();
                break;
            case 'd':
                turnDown();
                break;
            default:
                break;
        }
    }

    void moveForward() {
        switch (direction) {
            case 'N':
                y++;
                break;
            case 'S':
                y--;
                break;
            case 'E':
                x++;
                break;
            case 'W':
                x--;
                break;
            case 'U':
                z++;
                break;
            case 'D':
                z--;
                break;
        }
    }

    void moveBackward() {
        switch (direction) {
            case 'N':
                y--;
                break;
            case 'S':
                y++;
                break;
            case 'E':
                x--;
                break;
            case 'W':
                x++;
                break;
            case 'U':
                z--;
                break;
            case 'D':
                z++;
                break;
        }
    }

    void turnLeft() {
        switch (direction) {
            case 'N':
                direction = 'W';
                break;
            case 'S':
                direction = 'E';
                break;
            case 'E':
                direction = 'N';
                break;
            case 'W':
                direction = 'S';
                break;
            case 'U':
                if(sub=='N')
                direction='W';
                if(sub=='S')
                direction='E';
                if(sub=='E')
                direction='N';
                if(sub=='W')
                direction='S';
                break;
            case 'D':
                if(sub=='N')
                direction='W';
                if(sub=='S')
                direction='E';
                if(sub=='E')
                direction='N';
                if(sub=='W')
                direction='S';
                break;
            
        }
    }

    void turnRight() {
        switch (direction) {
            case 'N':
                direction = 'E';
                break;
            case 'S':
                direction = 'W';
                break;
            case 'E':
                direction = 'S';
                break;
            case 'W':
                direction = 'N';
                break;
            case 'U':
                if(sub=='N')
                direction='E';
                if(sub=='S')
                direction='W';
                if(sub=='E')
                direction='S';
                if(sub=='W')
                direction='N';
                break;
            case 'D':
                if(sub=='N')
                direction='E';
                if(sub=='S')
                direction='W';
                if(sub=='E')
                direction='S';
                if(sub=='W')
                direction='N';
                break;
            
        }
    }

    void turnUp() {
        if (direction != 'U' && direction != 'D') {
            sub=direction;
            direction = 'U';
           
        }
    }

    void turnDown() {
        if (direction != 'U' && direction != 'D') {
            sub=direction;
            direction = 'D';
        }
    }

    void printPosition() {
        cout << "Final Position: (" << x << ", " << y << ", " << z << ")" << endl;
        cout << "Final Direction: " << direction << endl;
    }
};

vector<char> inputArray() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    vector<char> commands(size);

    for (int i = 0; i < size; i++) {
        cout << "Enter command " << i + 1 << ": ";
        cin >> commands[i];
    }

    return commands;
}

int main() {
    LunarCraft chandrayaan3;

    // Call the inputArray function to get the array of commands
    vector<char> commands = inputArray();

    // Loop through and execute the commands
    for (char command : commands) {
        chandrayaan3.move(command);
    }

    // Print the final position
    chandrayaan3.printPosition();

    return 0;
}
