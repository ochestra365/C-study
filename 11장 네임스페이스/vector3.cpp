#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(int a, int b) { return a > b; }//�������� ����
int main() {// ���� ó������ ������ ������� ���⼺�� �߿��� �� �ַ� ����Ѵ�. 
	vector<int>	arr;
	arr.push_back(7);
	arr.push_back(3);
	arr.push_back(5);
	arr.push_back(2);
	arr.push_back(6);

	//sort(arr.begin(), arr.end());
	sort(arr.begin(), arr.end(), compare);
	for (auto i = 0; i < arr.size(); i++) {//�ڵ����� �������� �ڷ����� �����ش�.
		cout << arr[i] << endl;
	}
	return 0;
}