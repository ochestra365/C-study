#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

class CMember {
private:
	char Name[12];
	int Phone;
	char Addr[100];
	static int cnt;

public://�ֿ� ���� �� �ϳ��� �����͸� �����ؼ� Ŭ������ �ʵ忡 ���� �����ϴ� ���̴�.
	void setName(char* aName, int aPhone, char* aAddr, int acnt) {//�迭�� �Ѱܹ޾Ƽ� �ʵ�� �÷��ش�.
		strcpy(this->Name, aName);
		Phone = aPhone;
		strcpy(this->Addr, aAddr);
		cnt++;
	}
	void getName() {//�ֿ� ���� �� �ϳ��� �ʵ��� �����Ϳ� ����� ������ �ҷ����� ���̴�.
		printf("\n>�̸�: %s\n>�ڵ��� ��ȣ : %d\n>�ּ� : %s\n>ȸ����: %d",Name,Phone,Addr,cnt);
	}
};
int CMember::cnt = 0;
int main() {
	CMember i;//��� ��ü�� ���������.
	//��� ��ü���� �������� �ʱ�ȭ���ش�.
	char tempName[100] = "�ڼ�ö";
	int tempPhone = 28741479;
	char tempAddr[100] = "����Ư����ġ�� ���ֽ� ����10�� 180 �ƶ����";
	int tempcnt=1;
	i.setName(tempName, tempPhone, tempAddr, tempcnt);
	i.getName();


	CMember j;// ������ ������ ���� �� �����µ�, static ��� ���� ���� �˾ƺ� �ʿ䰡 �ִ�.
	char jName[100] = "�����";
	int jphone = 2929;
	char jAddr[100] = "���� ���α� �� 1����";
	int jcnt = 2;
	j.setName(jName, jphone, jAddr, jcnt);
	j.getName();

	return 0;
}