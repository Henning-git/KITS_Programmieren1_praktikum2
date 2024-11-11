#include <iostream>
#include <array>
#include <limits>
#include <cmath>

using namespace std;

// number of dimensions per coordinate
const int n_dimension = 2;

// cumber of coordinates to be entered
const int n_coordinate = 2;

// type to hold numeric limits of coordinates
typedef array<int, n_dimension> coordinate_t;

// type to hold coordinates in an array
typedef array<coordinate_t, n_coordinate> coordinate_array_t;


// read coordinates from user
void read_coordinates(coordinate_array_t* a, coordinate_t min, coordinate_t max) {
    // for each coordinate
    for(int i = 0; i < n_coordinate; i++) {
        // for each dimension
        for(int j = 0; j < n_dimension; j++) {
            while(true) {
                // instruct user
                cout << "Koordinate " << i+1 << " Dimension " << j+1 << " = ";

                // get input
                int x;
                cin >> x;

                // check for type and range compatibility
                if(cin.fail() || x < min[j] || x > max[j]) {
                    // reset cin error
                    cin.clear();

                    // ignore all characters until line break
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    // instruct user
                    cout << "invalid input, try again" << endl;
                }
                else {
                    // save x
                    (*a)[i][j] = x;

                    // exit while loop
                    break;
                }
            }
        }

        // print new line
        cout << endl;
    }
}

// is coordinate b in a array
bool coordinate_match(coordinate_array_t a, coordinate_t b) {
    // for each coordinate
    for(int i = 0; i < n_coordinate; i++) {
        bool matches = true;

        // for each dimension
        for(int j = 0; j < n_dimension; j++) {
            if(a[i][j] != b[j]) {
                matches = false;
            }
        }

        if(matches) {
            return true;
        }
    }

    return false;
}

// print coordinate system that contains coordinates
void print_coordinates(coordinate_array_t a, coordinate_t max) {
    // for each line
    for(int y = max[1]; y >= 0; y--) {
        // print horizontal label
        cout << y << "|";

        // for each row
        for(int x = 1; x <= max[0]; x++) {
            // print vertical label
            if(0 == y) { // botttom line
                if(x % 10 == 0) { // every 10th number
                    cout << x / 10;
                }
                else {
                    cout << "-";
                }
            }
            // print content
            else {
                if(coordinate_match(a, {x, y})) {
                    cout << "#";
                }
                else {
                    cout << " ";
                }
            }
        }

        // print line break
        cout << endl;
    }
}

// calculate distance between coordinates
double calc_distance(coordinate_t a, coordinate_t b) {
    double res = 0;

    // for each dimension
    for(int j = 0; j < n_dimension; j++) {
        double dif = a[j] - b[j];
        res += pow(dif, 2);
    }

    return sqrt(res);
}

int main()
{
    // -------- read coordinates from user --------
    coordinate_array_t coordinates;
    coordinate_t min = {1, 1}; // min for both dimensions
    coordinate_t max = {50, 9}; // max for both dimensions

    read_coordinates(&coordinates, min, max);

    // -------- print coordinate system --------
    print_coordinates(coordinates, max);

    // -------- print distance --------
    double distance = calc_distance(coordinates[0], coordinates[1]);
    cout << "Abstand: " << distance << endl;

    return 0;
}
