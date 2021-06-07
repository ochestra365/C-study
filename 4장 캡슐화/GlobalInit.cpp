#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
class DBQuery {
private:
	static int hCon;//static은 반드시 외부에 초기화를 시켜줘야 한다.
	int nResult;
public://함수헤더를 적어놓을 수 있다는 개념으로 이해하자.
	DBQuery() {};
	static void DBconnect(const char* Server, const char* ID, const char* pass);//정적 멤버 함수
	static void DBDisConnect();//정적 멤버 함수
	bool RunQuery(const char* SQL);
};
int DBQuery::hCon;//정적 멤버변수의 초기화는 외부에서 해야 한다.-->자동으로 0으로 초기화가 된다.

void DBQuery::DBconnect(const char* Server, const char* ID, const char* Pass) {
	//여기서 DB서버에 접속한다.
	hCon = 1234;//포트 번호 포트 번호는 변하지 않으니 저장을 시켜 놓는다.
	puts("연결되었습니다.");
}

void DBQuery::DBDisConnect() {
	//접속을 해제한다.
	hCon = NULL;
	puts("연결이 끊어졌습니다.");
}
bool DBQuery::RunQuery(const char* SQL) {
	//Query(hCon,SQL);
	puts(SQL);
	return true;
}
int main() {
	DBQuery::DBconnect("Secret", "Adult", "doemfdmsrkfk");//정보를 숨길 수 있따. 실행 시켜 보니 값이 나오지 않는다.
	DBQuery Q1, Q2, Q3;

	//필요한 DB질의를 한다.
	Q1.RunQuery("select*from tblBuja where 나랑 친한 사람");
	DBQuery::DBDisConnect();

	return 0;
}