#include <stdio.h>
int count = 0;//���� ���� �ܺμ���
class Simple {
private:
	int value;//�̰� ������?
public:
	Simple() { count++; }//��ü ������ ���ڰ� ī���� �ȴ�.
	~Simple() { count--; }//��ü �ı��� ���ڰ� ���̳ʽ� �ȴ�.
	void Outcount() {
		printf("%d\n", count);
	}
};

int main() {
	Simple s, * ps;//��ü�� ������ ����
	s.Outcount();//��ü�� ���� ��� �Լ� ����
	ps = new Simple;//���ο� Ŭ���� �Ҵ�
	ps->Outcount();//���� �������
	delete ps;//�ı�
	s.Outcount();//
	printf("%d\n", sizeof(s));

	return 0;
}