#include <iostream>
using namespace std;

void merge(int* arr, int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = 0;
    int* newArr = (int*)malloc(sizeof(int) * (high - low + 1));
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            newArr[k] = arr[i];
            ++i; ++k;
        } else {
            newArr[k] = arr[j];
            ++j; ++k;
        }
    }
    // �ϲ���һ�������ʣ�µ�����
    while (i <= mid) {
        newArr[k] = arr[i];
        ++i; ++k;
    }
    // �ϲ��ڶ��������ʣ�µ�����
    while (j <= high) {
        newArr[k] = arr[j];
        ++j; ++k;
    }
    // ���±����ݸ��Ƶ�arr[low...high]��
    for (int t = low; t <= high; ++t) {
        arr[t] = newArr[t - low];
    }
    free(newArr);
}

void mergePass(int* arr, int length, int n) {
    int i = 0;
    for (; i + 2 * length - 1 < n; i += 2 * length) {
        merge(arr, i, i + length - 1, i + 2 * length - 1);
    }
    // �����Ҫ�ж�һ�����µı��Ƿ���Ҫ�ϲ�
    // ����Ϊʲô��С��n - 1����Ҫ�ϲ��Ļ����һ�������Ҫ������һ��Ԫ�أ�����ǰ��һ�������Ľ���
    // λ�þ�Ӧ����n - 1��ǰ��
    if (i + length - 1 < n - 1) {
        merge(arr, i, i + length - 1, n - 1);
    }
}

void mergeSort(int* arr, int n) {
    for (int length = 1; length < n; length *= 2) {
        mergePass(arr, length, n);
    }
}

void mergeSortDC(int* arr, int low, int high) {
    if (low < high) {
        int mid = (high - low) / 2 + low;
        // �鲢���
        mergeSortDC(arr, low, mid);
        // �鲢�ұ�
        mergeSortDC(arr, mid + 1, high);
        // �ϲ����ߵ������
        merge(arr, low, mid, high);
    }
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
    mergeSortDC(arr, 0, 9);
    // ��ӡ�����Ľ��
    cout << "�����Ľ��������ʾ��" << endl;
    for (int i : arr) {
        cout << i << " ";
    }
}