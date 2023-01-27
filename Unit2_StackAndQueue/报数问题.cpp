#include<iostream>
#include<queue>
using namespace std;

void rank_(queue<int> q) {
    while (! q.empty()) {
        cout << q.front() << " ";
        q.pop();
        int temp = q.front();
        q.pop();
        q.push(temp);
    }
}

int main() {
    queue<int> q;
    for (int i = 1; i <= 8; ++i) {
        q.push(i);
    }
    rank_(q);

    return 0;
}