#include <stdio.h>//ǥ�� ����� ���� ��ó��
class Time {//��ü ����
private://����
	int hour, min, sec;//�ʵ�
public:
	Time(int h, int m, int s) {//�� �ú��� �����ٶ� �����ε�
		hour = h;
		min = m;
		sec = s;
	}
	Time(int abssec) {//�����ʹ��� �� ó�� �����ε�
		hour = abssec / 3600;
		min=(abssec / 60) % 60;
		sec = abssec % 60;
	}
	void OutTime() {//���
		printf("%d:%d:%d", hour, min, sec);
	}
};
void printTime(Time when) {
	when.OutTime();
}
int main() {
	Time noon(40000);
	Time now = 60000;
	now.OutTime();
	now = 70000;
	now.OutTime();
	printTime(80000);//�Ͻ������� Time��ü�� �ٲ�
}