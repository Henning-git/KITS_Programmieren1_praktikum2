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
    while((int)(x * 10000) > (int)(y * 10000)) {
        x = (x + y) / 2.0;
        y = d / x;
        cout << x << " " << y << endl;
    }

    cout << "Die Quadratwurzel von " << d << " ist " << x << "." << endl;

    return 0;
}
