#include <iostream>
using namespace std;

// ��������
void SelectSort1(int* arr, int n);
void SelectSort2(int* arr, int n);


int main() {
   // ����һ����������
    int arr[] = {1, 3, 2, 5, 1, 5, 4, 1};
    // ��ӡ����ǰ�Ľ��
    cout << "����ǰ�Ľ��������ʾ��" << endl;
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
    // ����ֱ�Ӳ���������
    SelectSort2(arr, 8);
    // ��ӡ�����Ľ��
    cout << "�����Ľ��������ʾ��" << endl;
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

// �����ǸĽ����ѡ������ʵ�������ǲ���Ҫÿ�ζ����������һ���Խ�����OK
void SelectSort2(int* arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int k = i;
        int temp = arr[i];
        for (int j = i + 1; j < n; ++j) {
            if (temp > arr[j]) {
                temp = arr[j];
                k = j;
            }
        }
        // ���k != i�Ļ��ͽ���λ��
        if (k != i) {
            int temp1 = arr[i];
            arr[i] = arr[k];
            arr[k] = temp1;
        }
    }
}