#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& A, int low, int high) {
    int pivot = A[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (A[j] <= pivot) {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[high]);
    return i + 1;
}

void quickSort(vector<int>& A, int low, int high) {
    if (low < high) {
        int p = partition(A, low, high);
        quickSort(A, low, p - 1);
        quickSort(A, p + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nBefore sorting:\n";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << "\n";

    quickSort(arr, 0, n - 1);

    cout << "\nAfter sorting:\n";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
