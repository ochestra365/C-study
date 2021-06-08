#include <iostream>
using namespace std;

template <typename T>
class CTest {
private:
	T num;
public:
	//CTest(T anum) : num(anum) {};//클래스 안의 멤버 타입이 T로 되어 있으면 클래스로 한다.
	CTest(T);//클래스 외부에서도 작성할 수 있다. //선언
	void printData() {
		cout << "num : " << num << endl;
	}
};
template<typename T>//템플릿을 선언을 한 번 더 한다.
CTest<T>::CTest(T anum) {//T라는 명시적 표현을 해줘야 한다. 정의부분

}
int main() {
	//CTest obj(10);
	CTest<int>	obj(10); //클래스템플릿에서는 캐스팅을 빼먹으면 안된다.
	obj.printData();

	return 0;
}