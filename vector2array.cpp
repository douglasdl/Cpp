#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> input({ 1, 2, 3, 4, 5 });
    int n = input.size();
    cout << "Number of elements: " << n << "\n";

    // Copy the elements from the Vector to the Array
    int arr[n];
    for(int i = 0; i < n; i++) {
        arr[i] = input[i];
    }

    // Print the Array
    for(int i: arr) {
        cout << i << ' ';
    }
    return 0;
}