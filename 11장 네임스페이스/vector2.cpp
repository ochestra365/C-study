#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v = { 10,20,30,40,50 };
	for (auto i = 0; i < v.size(); i++) {
		printf("%d\t", v[i]);
	}

	for (auto i = v.begin(); i != v.end(); i++) {//�ڷ����¸� �����ش�. 
		cout << *i << ' ';//�����͸� ���ؼ� ����Ű�� �ִ� ���� ���� �о�´�.
	}
	return 0;
}
//���ʹ� �����̴ϱ� ���� ��� ������ �ַ� ���� ���̴�.