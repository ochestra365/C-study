#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
class DBQuery {
private:
	static int hCon;//static�� �ݵ�� �ܺο� �ʱ�ȭ�� ������� �Ѵ�.
	int nResult;
public://�Լ������ ������� �� �ִٴ� �������� ��������.
	DBQuery() {};
	static void DBconnect(const char* Server, const char* ID, const char* pass);//���� ��� �Լ�
	static void DBDisConnect();//���� ��� �Լ�
	bool RunQuery(const char* SQL);
};
int DBQuery::hCon;//���� ��������� �ʱ�ȭ�� �ܺο��� �ؾ� �Ѵ�.-->�ڵ����� 0���� �ʱ�ȭ�� �ȴ�.

void DBQuery::DBconnect(const char* Server, const char* ID, const char* Pass) {
	//���⼭ DB������ �����Ѵ�.
	hCon = 1234;//��Ʈ ��ȣ ��Ʈ ��ȣ�� ������ ������ ������ ���� ���´�.
	puts("����Ǿ����ϴ�.");
}

void DBQuery::DBDisConnect() {
	//������ �����Ѵ�.
	hCon = NULL;
	puts("������ ���������ϴ�.");
}
bool DBQuery::RunQuery(const char* SQL) {
	//Query(hCon,SQL);
	puts(SQL);
	return true;
}
int main() {
	DBQuery::DBconnect("Secret", "Adult", "doemfdmsrkfk");//������ ���� �� �ֵ�. ���� ���� ���� ���� ������ �ʴ´�.
	DBQuery Q1, Q2, Q3;

	//�ʿ��� DB���Ǹ� �Ѵ�.
	Q1.RunQuery("select*from tblBuja where ���� ģ�� ���");
	DBQuery::DBDisConnect();

	return 0;
}