#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1("1234567890");
	string s2("^-^");
	cout << s1 << endl;
	s1.insert(5, "XXX");//�ϳ��� �迭��ҷ� �νĵ�
	cout << s1 << endl;
	s1.insert(5, s2);//�ϳ��� �迭��ҷ� �νĵ�
	cout << s1 << endl;
	s1.erase(5, 6);
	cout << s1 << endl;
	return 0;
}