#include <iostream>
#include <cstdlib>
using namespace std;

// TopK����
// ��10�ڸ����е�100����С�ģ���������ѣ�����ÿ��������Ƚϣ�����ȸ���㻹��,�򲻿��ܳ�Ϊ��С��100����֮һ
// ��10�ڸ����е�100�����ģ�����С���ѣ�����ÿ��������Ƚ�, ����ȸ���㻹ҪС���򲻿��ܳ�Ϊ����100����֮һ

// ��������
void SiftDown(int* arr, int n, int i);
void HeapSort(int* arr, int n);
void TopK(int* arr, int n, int* minArr, int minN);

int main() {
    // ����һ������Ϊ10000����������
    int* arr = (int*)malloc(sizeof(int) * 10000);
    // ʹ��random��������10000�������
    for (int i = 0; i < 10000; ++i) {
        arr[i] = rand() % 10000 + 1;
    }
    // ����һ������Ϊ20���������飬�����10000�����е���С��20����
    int* minArr = (int*)malloc(sizeof(int) * 20);
    // ����TopK�������ҵ���10000�����е���С��20����
    TopK(arr, 10000, minArr, 20);
    cout << "��10000��������С��20����������ʾ��" << endl;
    // ��ӡ��20����С������
    for (int i = 0; i < 20; ++i) {
        cout << minArr[i] << " ";
    }
    return 0;
}

void SiftDown(int* arr, int n, int i) {
    bool flag = true;  // flag��־������־�Ƿ�������µ���
    // ����ڵ㲢����Ҫ����������ʱ�����
    while (2 * i + 1 < n && flag) {
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
            // ����Ļ���˵�����ڵ�������ӽڵ㶼ҪС���˳�ѭ��
            flag = false;
        } 
    }
}

void HeapSort(int* arr, int n) {
    // �����ǵ������ǵĴ����
    for (int i = n / 2 - 1; i >= 0; --i) {
        SiftDown(arr, n, i);
    }
    // ������������Ѿ������õĴ���ѵģ�Ҳ��������arr�Ѿ��Ǵ������
    // ÿ�γ�ͷԪ�أ�Ȼ�������һ��Ԫ�ؽ�����֮���ٵ�����һ��Ԫ��
    
    for (int i = n - 1; i >= 1; --i) {
        // ��ʼ����
        int temp = arr[0];
        arr[0] = arr[n - 1];
        arr[n - 1] = temp;
        // Ȼ��ʼ����ͷ���
        --n;
        SiftDown(arr, n, 0);
    }
    // ��󽻻�һ��arr[0]��arr[1]
}

void TopK(int* arr, int n, int* minArr, int minN) {
    // ���Ƚ�arr�е�ǰminN��������䵽���ǵ�minArr��
    for (int i = 0; i < minN; ++i) {
        minArr[i] = arr[i];
    }
    // �������ǵ���20������ʹ��������С�ѵ���ʽ
    for (int i = minN / 2 - 1; i >= 0; --i) SiftDown(minArr, minN, i);
    // Ȼ��ӵ�minN + 1������ʼ������������С�ѵĸ����Ƚ�
    // �������20����������ֵ��ҪС�Ļ����Ͳ����ܳ�Ϊ����20����֮һ���ͼ���
    // ����Ļ������������Сֵ������ȥ�滻����㣬Ȼ��������ڵ�ʹ���Ϊ����
    for (int i = minN; i < n; ++i) {
        if (arr[i] <= minArr[0]) {
            minArr[0] = arr[i];
            SiftDown(minArr, minN, 0);
        }
    }
    // �������ǵ�minArr����ʹ�ö���
    HeapSort(minArr, minN);
}