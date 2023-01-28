#include<iostream>
using namespace std;

void doubleBubbleSort(int* arr, int n) {
    int i = 0;  // ��ָ��
    int j = n - 1;  // ��ָ��
    while (i < j) {
        // ���ȴ�������ð��
        bool isChange = false;
        for (int k = i; k < j; ++k) {
            if (arr[k] > arr[k + 1]) {
                swap(arr[k], arr[k + 1]);
                isChange = true;
            }
        }
        if (!isChange) {
            break;
        } else {
            --j;
        }
        // �ٴ�������ð��
        isChange = false;
        for (int k = j; k > i; --k) {
            if (arr[k] < arr[k - 1]) {
                swap(arr[k], arr[k - 1]);
                isChange = true;
            }
        }
        if (!isChange) {
            break;
        } else {
            ++i;
        }
    }
}

void swap(int& a, int& b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

int main() {
    // ����һ����������
    int arr[] = {2, 5, 8, 1, 10, 5, 19, 19, 3, 5};
    // ��ӡ����ǰ�Ľ��
    cout << "����ǰ�Ľ��������ʾ��" << endl;
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
    // ����ֱ�Ӳ���������
    doubleBubbleSort(arr, 10);
    // ��ӡ�����Ľ��
    cout << "�����Ľ��������ʾ��" << endl;
    for (int i : arr) {
        cout << i << " ";
    }
}