#include <stdio.h>

class DBQuery {
private:
	static int hCon;//�ѹ� �����س����� ��� ��� ������ ���°� �ȴ�.
	int nResult;
public:
	DBQuery() {};
	static void DBConnect(const char* Server, const char* ID, const char* Pass);//����
	static void DBDisConnect();//���� ����
	bool RunQuery(const char* SQL);//���� ������. �Ұ�
};
int DBQuery::hCon;//�ܺ� ���� ����

void DBQuery::DBConnect(const char* Server, const char* ID, const char* Pass) {
	// ���⼭ DB������ �����Ѵ�. 
	hCon = 1234;//���� ���
	puts("����Ǿ����ϴ�.");
}
void DBQuery::DBDisConnect(){
	hCon = NULL;//���� ����
	puts("������ ���������ϴ�.");
}
bool DBQuery::RunQuery(const char* SQL) {
	//Query(hCon,SQL);
	puts(SQL);
	return true;
}
int main() {
	DBQuery::DBConnect("Secret", "Adult", "dasfdafa");
	DBQuery Q1, Q2, Q3;
	//�ʿ��� DB���Ǹ� �Ѵ�.

	Q1.RunQuery("select*from tblBuja where ����ģ�ѻ��");

	DBQuery::DBDisConnect();
}