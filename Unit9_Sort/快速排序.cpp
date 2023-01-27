#include <iostream>
using namespace std;

// ��������
void QuickSort(int* arr, int low, int high);

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
    QuickSort(arr, 0, 9);
    // ��ӡ�����Ľ��
    cout << "�����Ľ��������ʾ��" << endl;
    for (int i : arr) {
        cout << i << " ";
    }
}

void QuickSort(int* arr, int low, int high) {
    // ��Ҫ���ǵݹ�ı߽�����
    if (low >= high)  return;
    // ����ߵ���Ϊ��׼�ͱ�����ұ߿�ʼ
    int i = low;
    int j = high;
    int privot = arr[i];
    while (i < j) {
        while (i < j && arr[j] > privot)  --j;
        arr[i] = arr[j];
        while (i < j && arr[i] <= privot)  ++i;
        arr[j] = arr[i];
    }
    arr[i] = privot;
    QuickSort(arr, low, i - 1);
    QuickSort(arr, i + 1, high);
}