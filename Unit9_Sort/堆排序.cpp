#include <iostream>
using namespace std;

// ��������
void SiftDown(int* arr, int n, int i);
void SiftUp(int* arr, int i);
void InitHeap(int* arr, int n);
void HeapSort(int* arr, int n);

int main() {
    // ����һ����������
    int arr[] = {1, 2, 1, 0, 4, 2, 11, 3, 2, 1, 1, 1};
    // ��ӡ����ǰ�Ľ��
    cout << "����ǰ�Ľ��������ʾ��" << endl;
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
    // ����ֱ�Ӳ���������
    HeapSort(arr, 12);
    // ��ӡ�����Ľ��
    cout << "�����Ľ��������ʾ��" << endl;
    for (int i : arr) {
        cout << i << " ";
    }

    return 0;
}

// ��ʼ����
void InitHeap(int* arr, int n) {
    // ��ʽһ�����Բ������µ����㷨��ʼ��
    // for (int i = n / 2 - 1; i >= 0; --i) {
    //     SiftDown(arr, n, i);
    // }
    
    // ��ʽ�������Բ������ϵ����㷨��ʼ��
    for (int i = 0; i < n; ++i) {
        SiftUp(arr, i);
    }
}

// ���ϵ����㷨
void SiftUp(int* arr, int i) {
    int parent = (i - 1) / 2;
    while (i > 0) {
        if (arr[parent] < arr[i]) {
            int temp = arr[parent];
            arr[parent] = arr[i];
            arr[i] = temp;
            i = parent;
            parent = (parent - 1) / 2;
        } else {
            break;
        }
    }
}

void SiftDown(int* arr, int n, int i) {
    // ����ڵ㲢����Ҫ����������ʱ�����
    while (2 * i + 1 < n) {
        // �����ҳ����ڵ�����ӽڵ����Сֵ
        int max = arr[i];
        int maxPos = i;
        if (arr[i] < arr[2 * i + 1]) {
            max = arr[2 * i + 1];
            maxPos = 2 * i + 1;
        }
        // ����������max�ǲ��Ǳ����ӽڵ㻹��
        if (2 * i + 2 < n) {
            if (max < arr[2 * i + 2]) {
                max = arr[2 * i + 2];
                maxPos = 2 * i + 2;
            }
        }
        // ���maxPos�������Լ��Ļ�˵����Ҫ����
        if (maxPos != i) {
            int temp = arr[maxPos];
            arr[maxPos] = arr[i];
            arr[i] = temp;
            // ���ܻ�Ҫ�����������������ǵ�i
            i = maxPos;
        } else {
            break;  // ���ü������µ����Ļ���ֱ���˳�
        }
    }
}

void HeapSort(int* arr, int n) {
    // ���������
    InitHeap(arr, n);
    
    // ������ʼ
    for (int i = n - 1; i >= 1; --i) {
        // ��ʼ����
        int temp = arr[0];
        arr[0] = arr[n - 1];
        arr[n - 1] = temp;
        // Ȼ��ʼ����ͷ���
        --n;
        SiftDown(arr, n, 0);
    }
}