#include <stdio.h>
class Some {
public:
	const int total;//���ȭ ���ÿ����� ����Ǵ� ���� �ƴ϶� ���������Ϳ����� ����ȴ�.
	//const ���¿����� ����� � ���� ������� �� ����. ����� ���ÿ� �ٷ� ���� �־�� �����ϴ�.
	//������ ���Կ������� ���� �� ����.
	/*Some(int atotal) { �Ϲ����� ��񿬻��� ���� �ʱ�ȭ ����� �Ұ����ϴ�.
		total = atotal;
	}*/
	Some(int atotal): total(atotal){}//����� ���ÿ� ���� ����ִ� �Ͱ� ����.
	void OutTotal() { printf("%d\n", total); }
 };
int main() {
	Some S(5);
	S.OutTotal();
}