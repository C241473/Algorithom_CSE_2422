#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int linearSearch(const vector<int>& arr, int key) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n, key;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Enter element to search: ";
    cin >> key;

    int result = linearSearch(arr, key);

    if (result != -1)
        cout << "Element " << key << " found at index " << result << " in sorted array." << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}
