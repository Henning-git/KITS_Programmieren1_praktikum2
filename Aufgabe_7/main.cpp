#include <iostream>
#include <limits>
#include <vector>

using namespace std;

// define programm state type
enum class state_t {
    set_n,
    input,
    output_min,
    exit
};

// variables to store program state
state_t state = state_t::set_n;

// amount of numbers to be input
int n = 0;

// vector to hold numbers to be compared
vector<int> numbers;
int input_position = 0;

int main() {
    while(true) {
        switch(state) {
            // user input of n
            case state_t::set_n: {
                // instruct user
                cout << "Wie viele Zahlen möchtest du vergleichen? n = ";

                // read integer
                int new_n = 0;
                cin >> new_n;

                // check for errors (e.g. wront type) or smaler than 1
                if(cin.fail() || new_n <= 1) {
                    // reset cin error
                    cin.clear();

                    // ignore all characters until line break
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    // instruct user
                    cout << "invalid input" << endl;
                    break;
                }

                // safe new valid n
                n = new_n;

                // goto next state
                state = state_t::input;
                break;
            }

            // user input of numbers
            case state_t::input: {
                // instruct user
                cout << "Gib die " << input_position + 1 << ". Zahl ein. x" << input_position + 1 << " = ";

                // read integer
                int new_x = 0;
                cin >> new_x;

                // check for errors (e.g. wront type) or smaler than 1
                if(cin.fail() || new_x < 0) {
                    // reset cin error
                    cin.clear();

                    // ignore all characters until line break
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    // instruct user
                    cout << "invalid input" << endl;
                    break;
                }

                // safe new valid x
                numbers.push_back(new_x);

                // if input finished
                if(input_position == n-1) {
                    // goto next state
                    state = state_t::output_min;
                    break;
                }

                input_position++;
                break;
            }

            // find and output min
            case state_t::output_min: {
                int min = INT_MAX;
                int min_index = -1;

                for(int i = 0; i < n; i++) {
                    if(numbers[i] < min) {
                        min = numbers[i];
                        min_index = i;
                    }
                }

                cout << "Die kleinste Zahl ist X" << min_index + 1 << " = " << min << endl;

                // goto next state
                state = state_t::exit;

            }

            // wait for user to quit application
            case state_t::exit: {
                static bool entry = true;
                if(entry) {
                    cout << "Drück x+Enter um das Programm zu beenden.";
                    entry = false;
                }

                char x;
                cin >> x;
                if(x == 'x') {
                    return 0;
                }
            }
        }
    }

    return 0;
}
