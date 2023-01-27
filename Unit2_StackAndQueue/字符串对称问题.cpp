#include<iostream>
#include<stack>
using namespace std;

// 定义判断函数1，采用栈空间方式，对称返回true，不对称返回false
bool isSymmetry1(char str[], int n) {
    stack<char> stack;
    // 首先将str字符数组中的所有字符全部压入栈空间
    for (int i = 0; i < n; ++i) {
        stack.push(str[i]);
    }
    // 再次遍历字符串，并且与出栈的的元素进行对比
    for (int i = 0; i < n; ++i) {
        char c = stack.top();
        if (str[i] != c)  return false;
        stack.pop();
    }
    return true;
}

// 定义判断函数2，采用最原始的方式，对称返回true，不对称返回false
bool isSymmetry2(char str[], int n) {
    for (int i = 0; i <= n / 2 - 1; ++i) {
        if (str[i] != str[n - i - 1])  return false;
    }
    return true;
}


int main() {
    char str[] = {'a', 'b', 'c', 'a'};
    if (isSymmetry2(str, 3)) {
        cout << "对称" << endl;
    } else {
        cout << "不对称" << endl;
    }
}