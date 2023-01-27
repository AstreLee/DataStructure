#include <iostream>
using namespace std;

// ��������
void ShellSort(int* arr, int n);

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
    ShellSort(arr, 8);
    // ��ӡ�����Ľ��
    cout << "�����Ľ��������ʾ��" << endl;
    for (int i : arr) {
        cout << i << " ";
    }
}

void ShellSort(int* arr, int n) {
    // ϣ������ʵ���Ͼ��Ƿ����������
    // ����һ����뷨�Ǵӵ�һ��Ԫ�ؿ�ʼ������һ���Ԫ��ȫ���������Ȼ���ٴӵڶ���Ԫ�ؿ�ʼ
    // ����һ���Ԫ��ȫ��������ɣ���ʵ���ϻ����Դ�λ��d��ʼ��������һ���ǰ���Ԫ��ȫ��
    // ����ã�����е���˼������뷨ʵ���Ͼ������θ������
    int d = n / 3;
    while (d > 0) {
        for (int i = d; i < n; ++i) {
            if (arr[i] < arr[i - d]) {
                int j = i - d;
                int temp = arr[i];
                for (; j >= 0 && temp < arr[j]; j -= d)  arr[j + d] = arr[j];
                arr[j + d] = temp;
            }
        }
        d /= 2;
    }
}