//#include <stdio.h>
//class Some {
//public:
//	const int total;//상수화 스택영역에 저장되는 것이 아니라 정적데이터영역에 저장된다.
//	//const 상태에서는 상수라서 어떤 값도 집어넣을 수 없다. 선언과 동시에 바로 집어 넣어야 가능하다.
//	//별도의 대입연산으로 넣을 수 없다.
//	/*Some(int atotal) { 일반적인 댕비연산을 통한 초기화 방식은 불가능하다.
//		total = atotal;
//	}*/
//	Some(int atotal): total(atotal){}//선언과 동시에 값을 집어넣는 것과 같다.
//	void OutTotal() { printf("%d\n", total); }
// };
//int main() {
//	Some S(5);
//	S.OutTotal();
//}
////객체가 만들어지고 나서 객체이름으로 값을 할당받는다. 객체이름으로 메모리를 할당받으면 생성자를 만들어서 값을 집어넣기 전에 초기화 리스트부터 진행해야 한다.