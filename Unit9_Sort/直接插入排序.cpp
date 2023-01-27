#include <iostream>
using namespace std;

// ��������
void InsertSort(int* arr, int n);

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
    InsertSort(arr, 8);
    // ��ӡ�����Ľ��
    cout << "�����Ľ��������ʾ��" << endl;
    for (int i : arr) {
        cout << i << " ";
    }
}

void InsertSort(int* arr, int n) {
    // ֱ�Ӳ������򣺽��������е�Ԫ�ز��뵽����������
    for (int i = 1; i < n; ++i) {
        if (arr[i] < arr[i - 1]) {
            int temp = arr[i];
            int j = i - 1;
            for (; j >= 0 && temp < arr[j]; --j) {
                // ��ǰ�����ȫ���Ƶ�����
                arr[j + 1] = arr[j];
            }
            arr[j + 1] = temp;
        }
    }
}