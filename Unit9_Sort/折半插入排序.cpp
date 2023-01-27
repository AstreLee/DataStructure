#include <iostream>
using namespace std;

// ��������
void BinaryInsertSort(int* arr, int n);

int main() {
    // ����һ����������
    int arr[] = {1, 1, 3, 2, 1, 4, 5, 8};
    // ��ӡ����ǰ�Ľ��
    cout << "����ǰ�Ľ��������ʾ��" << endl;
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
    // ����ֱ�Ӳ���������
    BinaryInsertSort(arr, 8);
    // ��ӡ�����Ľ��
    cout << "�����Ľ��������ʾ��" << endl;
    for (int i : arr) {
        cout << i << " ";
    }
}

void BinaryInsertSort(int* arr, int n) {
    // �۰��������ʵ����֪ʶ������Ԫ�رȽϵĴ�����Ԫ���ƶ���Ч�ʲ�û�м���
    for (int i = 1; i < n; ++i) {
        if (arr[i] < arr[i - 1]) {
            int low = 0;
            int high = i - 1;
            int temp = arr[i];
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (arr[mid] <= temp)  low = mid + 1;
                else  high = mid - 1;
            }
            for (int j = i - 1; j >= low; --j)  arr[j + 1] = arr[j];
            arr[low] = temp;
        }
    }
}