#include <stdio.h>

int main() {
	const char* str = "korea";
	int* pi;
	double d = 123.456;
	int i;
	int ary[] = { 1,2,3,4,5 };
	char aary[] = { 'a','b' };
	int* pary = static_cast<int*>(ary);
	pary= static_cast<int*>(ary);
	i = static_cast<int>(d);
	//pi = static_cast<int*>(str);-->���� ������ ������ ����ȯ�� �����Ѵ�.
	pi = (int*)str;
	printf("%d %d", i, pi);
}