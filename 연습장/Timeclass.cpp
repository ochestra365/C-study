#include <stdio.h>//ǥ�� ����� ����
class Time {//��ü ����
private://����
	int hour, min, sec;//�ʵ�
public://����
	Time(int h, int m, int s) {//��ü
		hour = h;//���� ���� ���� �ʵ�
		min = m;//���� ���� ���� �ʵ�
		sec = s;//���� ���� ���� �ʵ�
	}
	void OutTime() {//���
		printf("%d:%d:%d", hour, min, sec);
	}
};

int main() {//����
	Time now(12, 34, 56);//��ü ����
	Time then = now;//���� �� ���Կ����ڸ� ���� ����, ������� 1�� 1����
	//�ٸ� ���� ���� ���� x 
	//���� ����

	then.OutTime();//��� ����� ��� ����
}

/*Time(const Time &other){//������ ���۷���
	hour = other.hour;
	min = other.min;
	sec = other.sec;
*/
