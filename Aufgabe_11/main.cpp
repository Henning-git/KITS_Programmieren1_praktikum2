#include <iostream>
#include <array>

using namespace std;

array<int, 5> arr = { 1, 2, 3, 4, 5 }; // true
//array<int, 5> arr = { 1, 1, 2, 3, 4 }; // true
//array<int, 5> arr = { 1, 2, 3, 2, 5 }; // false

int main()
{
    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] < arr[i-1]) {
            cout << "false" << endl;
            return 0;
        }
    }

    cout << "true" << endl;
    return 0;
}
