#include<stdio.h>//ǥ�� ����� ����
class Time {//��ü ����
private://����
	int hour, min, sec;//�ʵ�
public:
	Time(int h, int m, int s) {//��ü ����
		hour = h;
		min = m;
		sec = s;
	}
	Time(int abssec) {//�����ε�
		hour = abssec / 3600;
		min = (abssec / 60) % 60;
		sec = abssec % 60;
	}
	operator int() {//��ȯ ������ ��ȣ ��ȯ
		return hour * 3600 + min * 60 + sec;
	}
	void OutTime() {//���
		printf("%d:%d:%d\n", hour, min, sec);
	}
};
int main() {//����
	Time now(12, 34, 56);//��ü ����
	int i = now;//����
	printf("i=%d\n", i);
}