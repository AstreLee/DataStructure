#include <iostream>
using namespace std;

// ��������
int BinarySearch(int* pt, int n, int target);

int main() {
    // ��������һ����������
    int arr[] = {1, 2, 3, 4, 5, 5, 5, 6, 6, 7};
    // Ȼ���ȡҪ���ҵ�����������ڷ���λ�ã���������ڷ��ز���λ��
    int target;
    cout << "������Ҫ���ҵ�����";
    cin >> target;
    // ���ú���
    cout << "���Ϊ��" << BinarySearch(arr, 10, target) << endl;
    return 0;
}

int BinarySearch(int* pt, int n, int target) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (pt[mid] <= target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;

    // �����������Ⱥż���low����high��λ����һ������
    // ѭ������һ����high��low��ǰ��һ��λ�ã�������ѭ����Ĵ��������
    // ��ôhigh����߰���high����<=target��
    // low���ұ߰���low����>=target��
    // ���target�����ڵĻ���������high����߰���high����С��target��
    // low���ұ߰���low���Ǵ���target�ģ���ô���ʱ�����ò���λ�þ���low
    // ���target���ڶ������ҽ���һ���Ļ���
    // 1. ����Ⱥż���low����Ļ�����ô�����high��low��λ�ù�ϵ��֪
    // low�ǲ���ָ��target�ģ�����high����������ȵ�λ��
    // 2. ����Ⱥż���high����Ļ�����ô�����high��low��λ�ù�ϵ��֪
    // high�ǲ���ָ��target�ģ�����low�������յ�λ��

    // ���target���ڶ����ж���Ļ�
    // 1.
    // ����Ⱥż���low����Ļ�������low��ָ����target�ĺ�һ��Ԫ�أ�highָ����target
    // 2.
    // ����Ⱥż���high����Ļ�������low��ָ����target�ĵ�һ��Ԫ�أ�highָ����lowǰ��һ��Ԫ��
    // 3. �Ⱥż���������۰����������ȶ����й�ϵ
}