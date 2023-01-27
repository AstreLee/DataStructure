#include<iostream>
#include<stack>
using namespace std;

// �����жϺ���1������ջ�ռ䷽ʽ���ԳƷ���true�����ԳƷ���false
bool isSymmetry1(char str[], int n) {
    stack<char> stack;
    // ���Ƚ�str�ַ������е������ַ�ȫ��ѹ��ջ�ռ�
    for (int i = 0; i < n; ++i) {
        stack.push(str[i]);
    }
    // �ٴα����ַ������������ջ�ĵ�Ԫ�ؽ��жԱ�
    for (int i = 0; i < n; ++i) {
        char c = stack.top();
        if (str[i] != c)  return false;
        stack.pop();
    }
    return true;
}

// �����жϺ���2��������ԭʼ�ķ�ʽ���ԳƷ���true�����ԳƷ���false
bool isSymmetry2(char str[], int n) {
    for (int i = 0; i <= n / 2 - 1; ++i) {
        if (str[i] != str[n - i - 1])  return false;
    }
    return true;
}


int main() {
    char str[] = {'a', 'b', 'c', 'a'};
    if (isSymmetry2(str, 3)) {
        cout << "�Գ�" << endl;
    } else {
        cout << "���Գ�" << endl;
    }
}