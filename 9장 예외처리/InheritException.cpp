#include <stdio.h>

class ExNegative {
protected:
	int number;
public:
	ExNegative(int n) : number(n) {}
	virtual void PrintError() {
		printf("%d는 음수이므로 잘못된 값입니다.\n", number);
	}
};

class ExTooBig : public ExNegative {
public:
	ExTooBig(int n) : ExNegative(n) {}
	virtual void PrintError() {
		printf("%d는 너무 큽니다. 100보다 작아야 합니다.\n", number);
	}
};
class ExOdd : public ExTooBig {
public:
	ExOdd(int n) :ExTooBig(n) {}
	virtual void PrintError() {
		printf("%d는 홀수다.\n", number);
	}

};

int main() {
	int n;
	while (1) {
		try {
			puts("숫자를 입력해라(끝낼 때 0):");
			scanf("%d", &n);
			if (n == 0)break;
			if (n < 0)throw ExNegative(n);
			if (n > 100)throw ExTooBig(n);
			if (n % 2 != 0)throw ExOdd(n);

			printf("%d는 규칙에 맞다.\n", n);
		}
		catch (ExNegative& e) {
			e.PrintError();
		}
	}
}