#include <stdio.h>//ǥ�� ����� ���� ��ó��
class Time {//��ü ����
private://����
	int hour, min, sec;//�ʵ�

public://����
	Time(int h, int m, int s) {//���� ->�ʵ�
		hour = h;
		min = m;
		sec = s;
	}
	Time(int abssec) {//������ ó�� �����ε�
		hour = abssec / 3600;
		min = (abssec / 60) % 60;
		sec = abssec % 60;
	}
	Time(double d) {//����ȯ ó�� �����ε�
		hour = int(d) % 24;
		min=(int(d - int(d)) * 100) % 60;
		sec = 0;
	}
	void OutTime() {//���
		printf("%d:%d:%d", hour, min, sec);
	}
};
int main() {
	Time now(3.14);
	now.OutTime();
}