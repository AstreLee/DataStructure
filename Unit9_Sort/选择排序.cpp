#include <iostream>
using namespace std;

void SelectSort1(int* arr, int n);
void SelectSort2(int* arr, int n);


int main() {
    int arr[] = {1, 3, 2, 5, 1, 5, 4, 2222};
    cout << "before sort" << endl;
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
    SelectSort2(arr, 8);
    cout << "after sort" << endl;
    for (int i : arr) {
        cout << i << " ";
    }
}

void SelectSort1(int* arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void SelectSort2(int* arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int k = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[k]) {
                k = j;
            }
        }
        if (k != i) {
            int temp = arr[i];
            arr[i] = arr[k];
            arr[k] = temp;
        }
    }
}
