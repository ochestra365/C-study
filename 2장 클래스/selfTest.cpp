#include<stdio.h>
class Date {
private:
	int year, month, day;
public:
	void SetDate(int y, int m, int d) {
		year = y;
		month = m;
		day = d;
	}
	void OutDate() {
		printf("현재 날짜는 %d년 %d월 %d일 입니다.", year, month, day);
	}
};
int main() {
	Date now;
	now.SetDate(2021, 5, 31);
	now.OutDate();
}