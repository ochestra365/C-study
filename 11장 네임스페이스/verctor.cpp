#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v;//�迭�� ���͸� ���ؼ� ������ �� �ִ�. �迭���� �� �� �ִ�.
	vector<int> v1 = { 1,2,3,4,5 };
	vector<int> v2[5];

	v.push_back(10);
	vector<int> ::iterator iter = v.begin();//��ü�ε� �����Ͱ��� ��ü�̴�. ���ø����� ������� ���̺귯���� ����� �� �ִ�. ���ø� ���̺귯���� ������ �� �ִ�.
	iter = v.insert(iter, 2);//v��� vector�� 2��� ���� ����־�� 
	v.pop_back();
	v.erase(v.begin()+10);
	v.clear();
	return 0;
}
