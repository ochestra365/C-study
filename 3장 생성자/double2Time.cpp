//#include <stdio.h>
//
//class Time {
//private:
//	int hour,min,sec;
//public:
//	Time(int h, int m, int s) {
//		hour = h;
//		min = m;
//		sec = s;
//	}
//	Time(int abssec) {
//		hour = abssec / 3600;
//		min = (abssec / 60) % 60;
//		sec = abssec % 60;
//	}
//	Time(double d) {//�ӽð�ü�� �����Ǿ� now�� ��ȯ�Ǿ� ���ȴ�. ��ȯ�����ڵ� �����ε��� �����ϴ�.
//		hour = int(d) % 24;
//		min = int((d - int(d)) * 100) % 60;
//		sec = 0;//��ȯ�����ڵ� �μ��� �ϳ��ε� �ٸ� Ÿ���� ��ü���·� �ٲ� ���̴�.
//		//�ݴ�Ǵ� ������ ��ü�� �ٸ� Ÿ���� ���·� �ٲ� �͵� �ִ�. �װ��� ��ȯ�Լ��� �Ҹ���.
//	}
//	void OutTime() {
//		printf("���� �ð��� %d:%d:%d�Դϴ�. \n", hour, min, sec);
//	}
//};
//int main() {
//	Time now(3.14);
//	now.OutTime();
//}