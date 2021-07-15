#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v = { 10,20,30,40,50 };
	for (auto i = 0; i < v.size(); i++) {
		printf("%d\t", v[i]);
	}

	for (auto i = v.begin(); i != v.end(); i++) {//자료형태를 맞춰준다. 
		cout << *i << ' ';//포인터를 통해서 가리키고 있는 것의 값을 읽어온다.
	}
	return 0;
}
//벡터는 방향이니까 원소 출력 방향을 주로 보는 것이다.