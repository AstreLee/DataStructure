#include <iostream>
using namespace std;

// ��������
void BubbleSort(int* arr, int n);

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
    BubbleSort(arr, 8);
    // ��ӡ�����Ľ��
    cout << "�����Ľ��������ʾ��" << endl;
    for (int i : arr) {
        cout << i << " ";
    }
}

void BubbleSort(int* arr, int n) {
    // ð������ʵ������ÿ�ν�һ�����������ף����������ڵ����ֽ��бȽ�,
    // ʵ�����е㶯̬�滮ά��������������˼��
    bool isChange = false;
    for (int i = 0; i < n - 1; ++i) {
        isChange = false;
        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isChange = true;
            }
        }
        // û�н��������Ѿ����������
        if (! isChange)  break;
    }
}