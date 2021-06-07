#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
class Time;//���� ��ü�� �������ش�.
class Date {
private:
	int year, month, day;
public:
	Date(int y, int m, int d) { year = y; month = m; day = d; }//���簪�� �޾Ƽ� ��������� �Ѱ��ش�.
	void OutToday(Time& t);//Ÿ�� Ŭ������ ���۷����� �����Ѵ�.
};

class Time {
	friend void Date::OutToday(Time& t);//����Ʈ Ŭ������ �ҼӵǾ���. �������� �׷��� ���� �����ڰ� �ҷ�������. �����ؾ� �Ѵ�.
private:
	int hour, min, sec;
public:
	Time(int h, int m, int s) { hour = h; min = m; sec = s; }//���簪�� �޾Ƽ� ��������� �Ѱ��ش�.
};
void Date::OutToday(Time& t) {//�μ��� Ÿ��Ŭ������ ���۷����� ��� �������ش�.
	printf("������ %d�� %d�� %d���̸� ���� �ð��� %d:%d:%d�̴�.",year,month,day,t.hour,t.min,t.sec);//���� �߿��� �� �ƴϴ�.
}
int main() {
	Date d(2018, 06, 29);//����Ʈ Ŭ���� ����
	Time t(12, 34, 56);//Ÿ��Ŭ������ ������.
	d.OutToday(t);//����Ʈ Ŭ������ ���ó��� ����Ѵ�.
}