#include <stdio.h>

class Time {
private:
	int hour, min, sec;

public:
	Time(int h, int m, int s) {
		hour = h;
		min = m;
		sec = s;
	}
	void OutTime() {
		printf("���� �ð��� %d:%d:%d�Դϴ�.\n", hour, min, sec);
	}
};

int main() {
	Time now(12, 34, 56);
	Time then = now;//���簡 �����ϴ�. �ڵ����� ��������ڰ� ȣ��Ǳ� ������ Ŭ������ �ʵ��� ������ �����ؼ� ����Ѵ�.
	//������ Ÿ���� ��ü�� ���� ����ϴ� ���� �����ϴ�.
	then.OutTime();
}