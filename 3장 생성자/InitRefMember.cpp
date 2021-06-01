//#include <stdio.h>
////클래스는 원본 데이터의 보존과 속성이 침해 되지 않는 것을 중요시한다.
//class Some {
//public:
//	int& total;
//	int n1, n2;
//	Some(int &atotal):total(atotal)
//	{
//		this->n1 = n1;
//		this->n2 = n2;
//	}
//	void OutTotal() { printf("%d\n", total); }
//};
//int main() {
//	int value = 8;
//	Some S(value);
//	S.OutTotal();
//}