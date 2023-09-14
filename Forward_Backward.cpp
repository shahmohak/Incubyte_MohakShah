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
        } else if (command == 'r') {
            turnRight();
        } else if (command == 'u') {
            turnUp();
        } else if (command == 'd') {
            turnDown();
        } else {
            // Handle the case when the command is not recognized
        }
    }

    void moveForward() {
        if (direction == 'N') {
            y++;
        } else if (direction == 'S') {
            y--;
        } else if (direction == 'E') {
            x++;
        } else if (direction == 'W') {
            x--;
        } else if (direction == 'U') {
            z++;
        } else if (direction == 'D') {
            z--;
        }
    }

    void moveBackward() {
        if (direction == 'N') {
            y--;
        } else if (direction == 'S') {
            y++;
        } else if (direction == 'E') {
            x--;
        } else if (direction == 'W') {
            x++;
        } else if (direction == 'U') {
            z--;
        } else if (direction == 'D') {
            z++;
        }
    }

    void turnLeft() {
        if (direction == 'N') {
            direction = 'W';
        } else if (direction == 'S') {
            direction = 'E';
        } else if (direction == 'E') {
            direction = 'N';
        } else if (direction == 'W') {
            direction = 'S';
        } else if (direction == 'U') {
            if (sub == 'N') {
                direction = 'W';
            } else if (sub == 'S') {
                direction = 'E';
            } else if (sub == 'E') {
                direction = 'N';
            } else if (sub == 'W') {
                direction = 'S';
            }
        } else if (direction == 'D') {
            if (sub == 'N') {
                direction = 'W';
            } else if (sub == 'S') {
                direction = 'E';
            } else if (sub == 'E') {
                direction = 'N';
            } else if (sub == 'W') {
                direction = 'S';
            }
        }
    }

    void turnRight() {
        if (direction == 'N') {
            direction = 'E';
        } else if (direction == 'S') {
            direction = 'W';
        } else if (direction == 'E') {
            direction = 'S';
        } else if (direction == 'W') {
            direction = 'N';
        } else if (direction == 'U') {
            if (sub == 'N') {
                direction = 'E';
            } else if (sub == 'S') {
                direction = 'W';
            } else if (sub == 'E') {
                direction = 'S';
            } else if (sub == 'W') {
                direction = 'N';
            }
        } else if (direction == 'D') {
            if (sub == 'N') {
                direction = 'E';
            } else if (sub == 'S') {
                direction = 'W';
            } else if (sub == 'E') {
                direction = 'S';
            } else if (sub == 'W') {
                direction = 'N';
            }
        }
    }

    void turnUp() {
        if (direction != 'U' && direction != 'D') {
            sub = direction;
            direction = 'U';
        }
    }

    void turnDown() {
        if (direction != 'U' && direction != 'D') {
            sub = direction;
            direction = 'D';
        }
    }

    void printPosition() {
        cout << "Final Position: (" << x << ", " << y << ", " << z << ")" << endl;
        cout << "Final Direction: " << direction << endl;
    }
};

int main() {
    LunarCraft chandrayaan3;
    char commands[] = {'f', 'r', 'u', 'b', 'l'};

    for (char command : commands) {
        chandrayaan3.move(command);
    }

    chandrayaan3.printPosition();

    return 0;
}
