#include <stdio.h>

class DBQuery {
private:
	static int hCon;//한번 연결해놓으면 계속 모두 연결인 상태가 된다.
	int nResult;
public:
	DBQuery() {};
	static void DBConnect(const char* Server, const char* ID, const char* Pass);//연결
	static void DBDisConnect();//연결 끊기
	bool RunQuery(const char* SQL);//쿼리 돌린다. 불값
};
int DBQuery::hCon;//외부 공통 선언

void DBQuery::DBConnect(const char* Server, const char* ID, const char* Pass) {
	// 여기서 DB서버에 접속한다. 
	hCon = 1234;//연결 비번
	puts("연결되었습니다.");
}
void DBQuery::DBDisConnect(){
	hCon = NULL;//연결 끊기
	puts("연결이 끊어졌습니다.");
}
bool DBQuery::RunQuery(const char* SQL) {
	//Query(hCon,SQL);
	puts(SQL);
	return true;
}
int main() {
	DBQuery::DBConnect("Secret", "Adult", "dasfdafa");
	DBQuery Q1, Q2, Q3;
	//필요한 DB질의를 한다.

	Q1.RunQuery("select*from tblBuja where 나랑친한사람");

	DBQuery::DBDisConnect();
}