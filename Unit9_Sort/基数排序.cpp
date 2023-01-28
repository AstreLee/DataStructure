#include<iostream>
using namespace std;

const int MAXD = 50;  // MAXD为最大关键字的位数
typedef struct node {
    char data[MAXD];  // 要排序的序列中的数字最大位数，从低位到高位存储在data[0...MAXD-1]中
    node* next;  
} NodeType;

// r是要排序数字的基数，d是最大位数
void radixSort(NodeType* &p, int r, int d) {
    NodeType* head[MAXD], *tail[MAXD];  // 定义头指针数组和尾指针
    for (int i = 0; i < d; ++i) {
        for (int j = 0; j < r; ++j) {
            head[j] = tail[j] = NULL;  // 初始化链队的首、尾指针 
        }
        while (p != NULL) {
            int k = p->data[i] - '0';
            if (head[k] == NULL) {
                head[k] = p;
                tail[k] = p;
            } else {
                tail[k]->next = p;
                tail[k] = p;
            }
            p = p->next;  // 继续取下一个数
        }
    }
}

int main() {

}