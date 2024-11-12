#include <iostream>
#include <limits>

using namespace std;

// diskriminante
double d = 0.0;

int main()
{
    while(true) {
        // instruct user
        cout << "Aus wlecher Zahl willst du die Wurzel ziehen? d = ";

        // read integer
        double new_d = 0;
        cin >> new_d;

        // check for errors (e.g. wront type) or <= 0.0
        if(cin.fail() || new_d <= 0.0) {
            // reset cin error
            cin.clear();

            // ignore all characters until line break
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            // instruct user
            cout << "invalid input" << endl;
        }
        else {
            d = new_d;
            break;
        }
    }

    // calculate root
    double x = d;
    double y = 1;
    // do while to cover initial x < y
    do {
        x = (x + y) / 2.0;
        y = d / x;
        cout << x << " " << y << endl;
    } while (x > y + 0.0000001);
    // it can happen, that x > y but only in the last 2 digits or so (e.g. x = 234567)
    // to abort the while, we just add a bit to y. That prevents x from being slightly smaller than y

    cout << "Die Quadratwurzel von " << d << " ist " << x << "." << endl;

    return 0;
}
