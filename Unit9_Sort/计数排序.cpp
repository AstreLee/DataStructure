#include<iostream>
using namespace std;

// ������������㷨(������������о���0 ~ 9֮�������)
void countSort(int* arr, int n) {
    int pt[10] = {0};
    // ����ԭ���飬���ֶ�Ӧ�Ƕ��٣����ڶ�Ӧ�±괦��һ
    for (int i = 0; i < n; ++i) {
        pt[arr[i]]++;
    }
    // ����pt���飬��Ӧλ�õ�Ԫ��Ϊ�����ͱ�ʾ������ֳ����˶��ٴΣ��ظ���ӡ����
    for (int i = 0; i < 10; ++i) {
        for (int j = pt[i]; j >= 1; --j) {
            cout << i << " ";
        }
    }
} 

int main() {
    // ����һ����������
    int arr[] = {2, 5, 8, 1, 1, 5, 9, 9, 3, 5};
    // ��ӡ����ǰ�Ľ��
    cout << "����ǰ�Ľ��������ʾ��" << endl;
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
    // ����ֱ�Ӳ���������
    countSort(arr, 10);
}