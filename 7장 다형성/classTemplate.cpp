#include <iostream>
using namespace std;

template <typename T>
class CTest {
private:
	T num;
public:
	//CTest(T anum) : num(anum) {};//Ŭ���� ���� ��� Ÿ���� T�� �Ǿ� ������ Ŭ������ �Ѵ�.
	CTest(T);//Ŭ���� �ܺο����� �ۼ��� �� �ִ�. //����
	void printData() {
		cout << "num : " << num << endl;
	}
};
template<typename T>//���ø��� ������ �� �� �� �Ѵ�.
CTest<T>::CTest(T anum) {//T��� ����� ǥ���� ����� �Ѵ�. ���Ǻκ�

}
int main() {
	//CTest obj(10);
	CTest<int>	obj(10); //Ŭ�������ø������� ĳ������ �������� �ȵȴ�.
	obj.printData();

	return 0;
}