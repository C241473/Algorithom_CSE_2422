#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> countingSort(const vector<int>& A) {
    int n = A.size();
    if (n == 0) {
        return {};
    }
    int maxv = *max_element(A.begin(), A.end());
    vector<int> count(maxv + 1, 0);
    for (int x : A) {
        count[x]++;
    }
    for (int i = 1; i <= maxv; i++) {
        count[i] += count[i - 1];
    }
    vector<int> output(n);
    for (int i = n - 1; i >= 0; i--) {
        int x = A[i];
        output[ count[x] - 1 ] = x;
        count[x]--;
    }
    return output;
}

int linearSearch(const vector<int>& A, int target) {
    for (int i = 0; i < (int)A.size(); i++) {
        if (A[i] == target) return i;
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements (non-negative integers):\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> sorted = countingSort(arr);
    cout << "Sorted array: ";
    for (int x : sorted) {
        cout << x << " ";
    }
    cout << "\nEnter target to search: ";
    int target;
    cin >> target;
    int idx = linearSearch(sorted, target);
    if (idx >= 0) {
        cout << "Found at index (0-based): " << idx << "\n";
    } else {
        cout << "Not found\n";
    }
    return 0;
}
