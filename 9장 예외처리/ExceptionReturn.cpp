//#include <stdio.h>
//
//int report() {
//	if (true/*예외발생*/)return -1;
//
//	//여기까지 왔으면 무사히 작업 완료 했음
//	return 0;
//}
//
//int main() {
//	int e;
//
//	e = report();
//	switch (e)
//	{
//	case1:
//		puts("메모리가 부족합니다.");
//		break;
//	case2:
//		puts("연산 범위를 초과했습니다.");
//		break;
//	case3:
//		puts("하드 디스크가 가득 찼습니다.");
//		break;
//	default:
//		puts("작업을 완료했습니다.");
//		break;
//	}
//}