#include <stdio.h>//ǥ�� ����¹���

class Time {//��ü ����
private://����
	int hour, min, sec;//�ʵ�
public://����
	Time(int h, int m, int s) {//��ü 
		SetHour(h);//ĸ��ȭ
		SetMinute(m);//ĸ��ȭ
		sec = s;
	}
	int GetHour() { return hour; }//�� ��ȯ
	void SetHour(int h) {//�ð� ���� ���η��� Hiding
		if (h >= 0 && h < 24) {
			hour = h;
		}
	}
	int GetMinute() { return min; }// �� ��ȯ
	void SetMinute(int m) {// �ð� ���� ���� ���� Hiding
		if (m >= 0 && m < 60) {
			min = m;
		}
	}
	int GetSecond() { return sec; }//�� ��ȯ

	void OutTime() {//��� �Լ�
		printf("%d:%d:%d\n", hour, min, sec);
	}
};
int main() {//��ü�� �Լ��� ��� ����� �����ϴ� ���� ����. �� �׷� �ڵ尡 ��������
	Time now(12, 34, 56);
	now.SetHour(40);
	now.OutTime();
	now.SetHour(9);
	now.OutTime();
}