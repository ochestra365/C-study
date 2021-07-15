#include <stdio.h>
class Time;//Ÿ�� ��ü ���� ��ü�� �μ��� �������� Time Ŭ������ ���� ����-->���漱��
class Date {//��¥ ��ü ����
private:
	int year, month, day;//��¥�� ���� �ʵ�
public:
	Date(int y, int m, int d) { year = y; month = m; day = d; }//������
	void OutToday(Time& t);//����Լ� ĸ��ȭ(���۷��� �ο�)
};

class Time {
	friend void Date::OutToday(Time& t);//����
private:
	int hour, min, sec;
public:
	Time(int h, int m, int s) { hour = h; min = m; sec = s; }
};
void Date::OutToday(Time& t) {
	printf("%d%d%d%d%d%d", year, month, day, t.hour, t.min, t.sec);
}

int main() {
	Date d(2018, 06, 29);
	Time t(12, 34, 56);
	d.OutToday(t);
}