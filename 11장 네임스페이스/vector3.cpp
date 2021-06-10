#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(int a, int b) { return a > b; }//내림차순 정렬
int main() {// 문제 처리에서 데이터 입출력의 방향성이 중요할 때 주로 사용한다. 
	vector<int>	arr;
	arr.push_back(7);
	arr.push_back(3);
	arr.push_back(5);
	arr.push_back(2);
	arr.push_back(6);

	//sort(arr.begin(), arr.end());
	sort(arr.begin(), arr.end(), compare);
	for (auto i = 0; i < arr.size(); i++) {//자동으로 컴파일이 자료형을 맞춰준다.
		cout << arr[i] << endl;
	}
	return 0;
}