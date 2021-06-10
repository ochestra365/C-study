#define _CRT_SECURE_NO_WARNINGS // ���ȿ��� ������
#include <stdio.h>// ǥ�� ����� ���� �߰�
#include <conio.h>// �ܼ� ������Լ� �߰�
#include <string.h>// ��Ʈ�� ���̺귯�� �߰�
#include "cursor.h"//���� Ư�� ��� ���̺귯�� �߰�
#include <assert.h>// C ǥ�� ���̺귯�� �� �ϳ���. C ��� ��ó���� ��ũ�� �� �ϳ��� assert() �� ��ũ�δ� ǥ���� �����Ͽ� ���α׷��� ������ ���� Ȯ���ϸ� ������ ��� ���� �޽����� ����Ѵ�.
#include <iostream>// �⺻ ����°� ���õ� ��ü���� �߰���.
using namespace std;// ǥ�� ���ӽ����̽� �߰�
//ȭ���д� ���� ī�尡 ���� 4���� �����ϴ� �� �ϴ�!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// �������� ����
const int MaxCard = 48; // �ִ밪 ī�带 ���ȭ���� -->48�̴�.
const int CardGap = 4;// ī���� �� ���̴� 4�̴�. 
const int Speed = 1000;//�ӵ��� 1000�̴�. 1000ms�̹Ƿ� 1�ʸ� ��Ÿ����.
const int PromptSpeed = 2000;//����Ǵ� �ӵ��� 1000�̴�.
//���� ���� �ڷ����̰�, ���д� �������� �ڷ����̴�. �������Ľ����� ���п� ������ ������. �����ڷᱸ���� �����ڷᱸ���� �� �����ϸ� �� ���α׷��� �� �� ������ �� ���� ���̴�.
// ȭ�� ������ ǥ���ϴ� Ŭ����
struct SCard
{
	char Name[4];// ȭ�� ������ ���� �� �ִ� �̸��� ũ��� 4byte�̴�.
	SCard() { Name[0] = 0; }//����Ʈ �����ڸ� ������ش�.  �迭�� �ʱ��׿� ��� �ִ� ���� 0�̴�.
	SCard(const char* pName) {//�������κ��� �о�� ���� ���ȭ�ؼ� �ʵ�� �Ѱ��ش�. �̰��� �������̴�.
		strcpy(Name, pName);
	}
	int GetNumber() const {//ȭ�����忡�� ���ڰ��� �������� ������ �� ���� �Լ��̴�. ��ȯ���� ���������� �����ϰ� ������̴�.
		if (isdigit(Name[0])) return Name[0] - '0'; // isdigit�� 10���� ���ڷ� ������ �����ϸ� ����(True), �ƴϸ� False(0)�� ��ȯ�ϴ� �Լ��� �ǹ��Ѵ�.
		if (Name[0] == 'J') return 10;//�ʱ����� J�̶�� �������� 10�� ��ȯ�Ѵ�.
		if (Name[0] == 'D') return 11;//�ʱ����� D��� �������� 11�� ��ȯ�Ѵ�.
		return 12;//�� �ܴ� 12�� ��ȯ�Ѵ�.
	};
	int GetKind() const {//ȭ�����忡�� �������� �������� ������ �� ���� �Լ��̴�. ��ȯ���� ���������� �����ϰ� ������̴�.
		if (strcmp(Name + 1, "��") == 0) return 0;//�ι�° �迭��Ұ��� ���̸� 0�� ��ȯ�Ѵ�.
		else if (strcmp(Name + 1, "��") == 0) return 1;//�ι�° �迭��Ұ��� ���̸� 1�� ��ȯ�Ѵ�.
		else if (strcmp(Name + 1, "��") == 0) return 2;//�� ��° �迭��Ұ��� ���̸� 2�� ��ȯ�Ѵ�.
		else return 3;//�������� 3�� ��ȯ�Ѵ�.
	}
	friend ostream& operator <<(ostream& c, const SCard& C) {//osstream���� friendŰ���带 �Ἥ ������ �����Ѵ�.
		return c << C.Name;
	}
	bool operator ==(const SCard& Other) const {//�Ű������� �޾ƿ� ȭ�� ������ ������ ���� ������ ��������� ��ȯ�Ѵ�.
		return (strcmp(Name, Other.Name) == 0);//�̸��� �Ű������� �޾ƿ� ȭ�� ������ �̸��� ���� ���ٸ� 0�� ��ȯ�Ѵ�.(������ ��ȯ�Ѵٴ� �Ҹ���.)
	}
	bool operator <(const SCard& Other) const {
		if (GetNumber() < Other.GetNumber()) return true;//�޾ƿ� ���ڰ��� �Ű��������� �޾ƿ� ���ڰ����� ������ ������ ��ȯ�Ѵ�.
		if (GetNumber() > Other.GetNumber()) return false;//�޾ƿ� ���ڰ��� �Ű��������� �޾ƿ� ���ڰ����� ũ�� ������ ��ȯ�Ѵ�.
		if (GetKind() < Other.GetKind()) return true;//�޾ƿ� �������� �Ű��������� �޾ƿ� ���������� ������ ������ ��ȯ�Ѵ�.
		return false;
	}
};

// ȭ���� �ʱ� ī�� ���
SCard HwaToo[MaxCard] = {// ȭ�� Ŭ������ �迭�� �ڷḦ ����� �ξ���. MaxCard���� 48�̹Ƿ� �迭��Ҵ� 48���̴�.
	"1��","1��","1��","1��","2��","2��","2��","2��","3��","3��","3��","3��",
	"4��","4��","4��","4��","5��","5��","5��","5��","6��","6��","6��","6��",
	"7��","7��","7��","7��","8��","8��","8��","8��","9��","9��","9��","9��",
	"J��","J��","J��","J��","D��","D��","D��","D��","B��","B��","B��","B��"
};

// ī���� ������ �����ϴ� Ŭ����
class CCardSet
{
protected://��Ӱ��迡 �ִ� �ڽ� Ŭ������ ������ �� �� �ְ� �ϸ� ���� ��Ű���� Ŭ������ �ٸ� ��Ű���� ����Ŭ���������� ������ �� �ִ�.
	SCard Card[MaxCard];// ȭ���� ���� �迭�� �����. ��, ī���� �� �����̰� �ִ� ���̴�.
	int Num;//ī�� ������ �����ʵ�
	const int sx, sy;//ī�� ������ x�� y�� ���� ����� ���� �ʵ�
	CCardSet(int asx, int asy) : sx(asx), sy(asy) { Num = 0; }//�����ڸ� ���� ���ο��� ���� ���� �� Ŭ������ �ʵ�� �÷��ش�.  ����Ʈ���� Num=0�̴�.

public:
	int GetNum() { return Num; }//���ڸ� �޴� �Լ��̴�. Num���� ��ȯ�Ѵ�.
	SCard GetCard(int idx) { return Card[idx]; }//ī�带 �������� �Լ��̴�. index���� �����´�. ���ο� ī���� index�� ��ȯ�Ѵ�.
	void Reset() {//ȭ������ �ʱ�ȭ�ϴ� ���̴�. ȭ������ �����ٰ� �����ص� ����.
		for (int i = 0; i < MaxCard; i++) Card[i].Name[0] = 0;//���� ī���� ��� �ʱ��̸��� 0���� ����Ʈȭ, �� ȭ������ ���� ���̴�.
		Num = 0;//�̴� ���ڴ� �ٽ� 0�̴�.
	}
	//�Լ� ��� �κ�-->���Ǵ� �ϴܿ� �����Ѵ�.
	void InsertCard(SCard C);//ȭ��ī�带 �����ϴ� ���̴�.-->����������̴�.
	SCard RemoveCard(int idx);//ī�带 �����ϴ� ���̴�.
	int FindSameCard(SCard C, int* pSame);//���� ȭ��ī�带 ã�� �Լ��̴�.(ȭ�� ����� �����ͷ� �ε����� �˻��Ѵ�.)
	int FindFirstCard(const char* pName);//ó�� ȭ��ī�带 ã�� �Լ��̴�.(�̸��� ���ȭ��Ų��.)
};

void CCardSet::InsertCard(SCard C) {//CCardSet�� InserCard�Լ��� ���� ����
	int i;//�ݺ� ���� ����

	if (C.Name[0] == 0) return;//���� ���� ī���� �ε����� 0�̶�� �Լ��� �������� �ʴ´�.
	for (i = 0; i < Num; i++) {
		if (C < Card[i]) break;//���� ���� ī���� �ε����� �ݺ����� ������ ���� �ε������� �۴ٸ� �ݺ����� Ż���Ѵ�.
		//i���� ���� ������ �����ϱ� �����̴�.
	}
	//memmove�� �޸� �̵��Լ��̴�. ù�� ° ���ڴ� ���� �� ���� �ٿ� ���� �޸𸮸� ����Ų��. �ι� ° ���ڴ� ������ �޸𸮸� ����Ű�� �������̴�. ���� ° ���ڴ� ������ ����Ʈ ũ�⸦ ��Ÿ����.
	memmove(&Card[i + 1], &Card[i], sizeof(SCard) * (Num - i));//�� ���ڴ� �ʵ� �������� ���Ἲ�� ���� ���۷����� ó���Ѵ�. i+1 �ʵ忡 i�ʵ忡 �ִ� ���� ���� ���̴�. �̶� ������ ����Ʈ ũ��� ���� ȭ���� �ε������� i���� ���ذ��̴�.
	//�� ȭ��ī�尡 ���ԵǾ� ���� �ִ� �ε����� ��ĭ �ڷ� �Ű��� ���̴�. 
	Card[i] = C;//�׸��� ���� �ִ� �ε������� ���ο� ȭ��ī�带 �ִ´�.
	Num++;//��ü ī����� �þ����Ƿ� Num���� 1���� �����ش�.
}

SCard CCardSet::RemoveCard(int idx) {//ī�带 ��� ���ŵǴ� ���� ǥ���� ���̴�. CCardSet�� RemoveCard�Լ��� ����� ���̴�.
	assert(idx < Num);//assert�� ����� ��忡�� �����ڰ� ������ ����� ġ������ ���̶� �����ϴ� ���� �ɾ���� ���� ����� �ڵ��̴�.
	//NUM���� idx���� Ŭ ��� assert�� �����Ѵ�.
	SCard C = Card[idx];//ī�� ���� ���� ī�� �ε����� �����Ѵ�.
	memmove(&Card[idx], &Card[idx + 1], sizeof(SCard) * (Num - idx - 1));//�޸𸮸� �̵����Ѽ� idx�� ��ĭ ������ �����ش�.
	Num--;//ī�带 �����Ƿ� ��� �ִ� ī���� ���� 1�� �ٿ��ش�.
	return C;//���� �ε������� ��ȯ�Ѵ�.
}

int CCardSet::FindSameCard(SCard C, int* pSame) {//�Լ������̴�. ���� ī�带 ã�� ���̴�. �� ȭ���ǿ� ���� ī�带 ã�� ���̴�.
	int i, num;//i�� �ݺ����� ����, num�� ���谪�� �ǹ��Ѵ�.
	int* p = pSame;//�����ͷ� ���ο��� ���� ���� ī���ε����� �޴´�.

	for (i = 0, num = 0; i < Num; i++) {//�ʱⰪ�� ��� 0���� �ְ� �տ� ��� �ִ� ī�� ���ڸ�ŭ �ݺ����� ������.
		if (Card[i].GetNumber() == C.GetNumber()) {//���� ���� ī�� �ε����� ã�� ī�� �ε����� ���ٸ�
			num++;//�����Ѵ�.
			*p++ = i;//�׸��� �����Ͱ��� i�� �����ϰ� 1�� ���Ѵ�.
		}
	}
	*p = -1;//�𸣰���
	return num;//��ȯ���̴�.
}

int CCardSet::FindFirstCard(const char* pName) {//ù��° ī�带 ã�´�. ù��° ī���̹Ƿ� �̸��� ������� �ش�.
	int i;

	for (i = 0; i < Num; i++) {//�տ� ��� �ִ� ī�� ���ڸ�ŭ �ݺ����� �����Ѵ�.
		if (strstr(Card[i].Name, pName) != NULL) {//strstr�Լ��� ù��° ���ڿ��� �ι�° ���ڿ� ��ġ�ϴ� ���ڿ��� �ִ� �� Ȯ���ϴ� �Լ��̴�.
			//�� �տ� ��� �ִ� ī�忡�� ���� �ε������� ��ġ�ϴ� ���� ã�� �� ���� ��� �˻��ϴ� ���̴�.
			return i;//�׸��� ��ġ�ϴ� ���ڿ��� �ִٸ� �ε������� ��ȯ�Ѵ�.
		}
	}
	return -1;//���� ��ġ�ϴ� ���� ���ٸ� �Լ��� �������� �ʴ´�.
}

// ��� �߾ӿ� ī�带 �׾� ���� ��ũ
class CDeck : public CCardSet//��� �߾ӿ� ī�带 �״� ��ũ�� ī����� ��ӹ޴´�.
{
public:
	CDeck(int asx, int asy) : CCardSet(asx, asy) { ; }//�����ڴ� CCardSet�� ī�������� ��ӹ޴´�.
	void Shuffle() {//ȭ������ ���� �Լ��̴�.
		int i, n;//i�� �ݺ����� �����̰�, n�� �������� ���� �����̴�.
		for (i = 0; i < MaxCard; i++) {//��ü ī��� 48���� �̹Ƿ� �� ���ڸ�ŭ �ݺ����� ������.
			do {//do~while���� �Ἥ ��� �ѹ� ���๮�� ������.
				n = random(MaxCard);//n�� 1~48���� �� �߿��� �������� �����Ѵ�.
			} while (Card[n].Name[0] != NULL);//ī�尡 ������ �� ���� �ݺ��Ѵ�.
			Card[n] = HwaToo[i];//ȭ�� �迭�� �ε����� ��� �߾ӿ� ���� ī�尪�� �����Ѵ�.
			Num++;//��� �߾ӿ� ���� ī�尡 ���徿 �þ��.
		}
	}
	//���� �ڷᱸ���� ������.
	SCard Pop() { return RemoveCard(Num - 1); }//��信�� ī�带 �̴� ���̴�. RemoveCard�Լ��� �Ἥ ����߾ӿ� ���� ��ü ���ڿ��� �ϳ��� ���ش�.
	bool IsEmpty() { return Num == 0; }//�����̴�. ���� ������� ����ִٸ� ī�尡 ���ٴ� ������ 0�� ��ȯ�Ѵ�.
	bool IsNotLast() { return Num > 1; }//�����̴�. ���� �������� �ƴ϶�� ȭ�� �߾ӿ� ��� 1�� �̻� �ִٴ� �ǹ��̴�.
	void Draw(bool bFlip) {//ȭ���߾ӿ��� ī�带 �������� ���̴�.
		gotoxy(sx, sy);//�ش���ǥ�� ��������
		cout << "??? " << (bFlip ? Card[Num - 1].Name : "   ");//ī�� �ε����� �����´�.
	}
};

// ������ �ϴ� �÷��̾�
class CPlayer : public CCardSet //CPlayer�� CCarSet�� �ڽ�Ŭ�����̴�.
{
public:
	CPlayer(int asx, int asy) : CCardSet(asx, asy) { ; }//�÷��̾ ī�带 ������ ��ǥ�� ��Ÿ���� ���̴�. CCardSet�� ��ǥ���� ��� �޴´�.
	void Draw(bool MyTurn) {//�� �Ͽ� ī�带 �̴� �� �Լ��� �ǹ��Ѵ�.
		int i, x;//�ݺ� ���� ������ ��ǥ ����(���) x���� ��ǥ��ġ���� ��Ÿ����.
		for (i = 0, x = sx; i < Num; i++, x += CardGap) {//ī�� ������ 4��ŭ ������ ���̴�. �׸��� �տ� �� ī�常ŭ �ݺ��ؼ� �����ش�.
			gotoxy(x, sy);//��ǥ������ �̵��Ѵ�.
			cout << Card[i];//ī���� �ε����� �ش��ϴ� ���� ����Ѵ�.
			if (MyTurn) {//���� ���� ���ʶ�� x�� ��ġ������ sy+1��ŭ �̵��Ѵ�.
				gotoxy(x, sy + 1);
				cout << '[' << i + 1 << ']';//���� ī���� �ε����̴�.
			}
		}
	}
};

// ������ ����Ǵ� ���
class CBlanket : public CPlayer //CBlanket�� CPlayer�� ��ӹ޴´�.
{
public:
	CBlanket(int asx, int asy) : CPlayer(asx, asy) { ; }//����� x,y��ǥ�� CPlayer�� ȭ���ǿ� ���� ��ǥ���� ��ӹ޴� ���̴�.
	void Draw() {
		CPlayer::Draw(false);//�� ���� �ƴ� �� ��� �÷��̾ �̴´�.
	}
	void DrawSelNum(int* pSame) {//���� �Լ����� �𸣰ڴ�.
		int n;
		int* p;
		for (n = 1, p = pSame; *p != -1; p++, n++) {
			gotoxy(sx + *p * CardGap, sy - 1);
			cout << '[' << n << ']';
		}
	}
	void DrawTempCard(int idx, SCard C) {//������ �̰��� ���� �ܿ�ī�带 ��Ÿ����.
		gotoxy(sx + idx * CardGap, sy + 1);//��ǥ�̵�
		cout << C;//���
	}
};

// �÷��̾ ���� ī���� ����
class CPlayerPae : public CCardSet // CPlayerPae�� CCardSet�� �ڽ�Ŭ�����̴�.
{
private:
	int nGo;//�� �� ���ߴ��ĸ� ���� ������ �ʵ��̴�.

public:
	int OldScore;//���� ���ھ���� �����͸� ������ ��Ʈ�� ������ �� ����
	CPlayerPae(int asx, int asy) : CCardSet(asx, asy) { OldScore = 6; nGo = 0; }//�÷��̾� ���� ��ǥ���� CCardSet�� ��ǥ���� ��ӹ޴´�. �׸��� ���� Ƚ���� ó������ �ڿ��� �ϸ��� ������ 0���� �ʱ�ȭ�Ѵ�. �������̵��� ���Ǿ���.
	void Reset() { CCardSet::Reset(); OldScore = 6; nGo = 0; }//Reset�Լ��̴�. CCardSet�� Reset�Լ��� ��� ��ӹ޴´�. �ʱ� 6���� ���п� ��� ���� 0�� ���� ���´�. ȭ������ ��밡 ���ų� ���� ���ų� ���� �� ���� ���̴�. �������̵��� ���Ǿ���.
	int GetGo() { return nGo; }//�� ������ ���̴�. ���� �޾ƿ´�.
	void IncreaseGo() { nGo++; }//�� ��ģ ��ŭ ���� �����ȴ�.
	void Draw();//�θ�Ŭ������ Draw�Լ��� �� �� �ֵ�.
	SCard RemovePee();// �Լ�����̴�. �Ʒ��� ���ǰ� �ִ�.
	int CalcScore();//���� ��� �Լ��̴�. �Ʒ��� ���ǰ� �ִ�.
};

void CPlayerPae::Draw() {//Draw�Լ��� ���� ����
	int i, kind;//�ݺ�������� ����
	int x[4] = { sx,sx,sx,sx }, py = sy + 3;//x��ǥ���� ���� 4���� �����ϰ� y��ǥ���� sy���� 3��ŭ �����Ѵ�.

	for (i = 0; i < Num; i++) {//ī�� ����ŭ �ݺ��Ѵ�. ���п� ��� �ִ� ���̴�.
		kind = Card[i].GetKind();//���п� ��� �ִ� ī�������̴�. GetKind�Լ��� ���� ī�� �ε����� �ش��ϴ� ī���� ���� �����͸� �����Ѵ�.
		if (kind < 3) {//���� ���� ���� 3���� �۴ٸ�
			gotoxy(x[kind], sy + kind);//�ش� ��ǥ�� x �ε����� �����̰�, sy��ǥ�� ��������ŭ ���ؼ� �ø���.
			x[kind] += CardGap;//x�������� ī�������� 4��ŭ ���Ѵ�.
		}
		else {//���п� ���ٸ�
			gotoxy(x[3], py);//x��ǥ�� 3�ε����� �����̰� py������ �����δ�.
			x[3] += CardGap;//x�迭��� 3���� ��ŭ ī�� ���� 4�� �������� x�� �����Ѵ�.
			if (x[3] > 75) {//���� �迭��Ұ��� 75 �̻��̶��
				x[3] = sx;//x[3]���� sx��ŭ �����ؼ� �����Ѵ�.
				py++;//y���� 1���Ѵ�.
			}
		}
		cout << Card[i];//ī���� �ε����� �ش��ϴ� ���� ����Ѵ�.
	}
	gotoxy(sx + 23, sy);//sx���� 23��ŭ ���ϰ� sy���� ��ǥ�� �����δ�.
	cout << "����:" << CalcScore() << "��, " << nGo << "��";//���� ��Ÿ����.-->CalcScore()�� ���� �Լ�����̴�. ���Ǵ� �ϴܿ� �����Ѵ�.
}

SCard CPlayerPae::RemovePee() {//�Ǹ� ���ִ� �Լ��̴�.
	int idx;//ȭ������ index���̴�.

	idx = FindFirstCard("��");//ù��° �޴� ���� �Ƕ�� ���̸� idx���� �̰��� �����Ѵ�.
	if (idx != -1) {//���� -1���� �ƴϸ�(��ġ�ϴ� ���� ���ٸ�)
		return RemoveCard(idx);//ī�� �ε����� �����.
	}
	return SCard();//�׸��� Ŭ������ ��ȯ�Ѵ�.
}

int CPlayerPae::CalcScore() {//�Լ������̴�.
	int i, kind, n[4] = { 0, };// �ݺ����� ���� i�� �����Ѵ�. �׸��� �������� ���� ������ �����Ѵ�. �׸��� n[4]�迭�� �����ϰ� 0���� �ʱ�ȭ�Ѵ�.
	int NewScore;//���ο� ������ ������ �����̴�.
	static int gscore[] = { 0,0,0,3,4,15 };//���ھ� ������ �迭��� ��ŭ �ö󰣴�. ������ ������ ���������� ��ġ�ϸ� ����Ÿ������ ������ ������ �迭 ������Ÿ���̴�.

	for (i = 0; i < Num; i++) {//�÷��̾� ���м���ŭ �ݺ����� ������.
		kind = Card[i].GetKind();//�� ī�忡 ���� �������� �޾ƿͼ� �÷��̾ ��� �ִ� ������ ���� �����Ѵ�.
		n[kind]++;//kind ���� �ϳ��� �÷��ش�.
	}
	NewScore = gscore[n[0]];//���ο� ������ ������ ���� ���ھ ������ ���̴�.
	if (n[0] == 3 && FindFirstCard("B��") != -1) NewScore--;//B���� ������ ù �迭��Ұ��� 3�̰� -1�� �ƴ϶�� ���ο� �������� 1�� �����Ѵ�.
	if (n[1] >= 5) NewScore += (n[1] - 4);//2��° �迭��Ұ��� 5�̻��̶�� ���ο� ������ 2��° �迭��ҿ��� 4�� ������ ���� ���Ѵ�.
	if (n[2] >= 5) NewScore += (n[2] - 4);//3��° �迭��Ұ��� 5�̻��̶�� ���ο� ������ 3��° �迭��ҿ��� 4�� ������ ���� ���Ѵ�.
	if (n[3] >= 10) NewScore += (n[3] - 9);//4��° �迭��Ұ��� 10�̻��̶�� ���ο� ������ 4��° �迭��ҿ��� 9�� ������ ���� ���Ѵ�.
	//�ϴ��� �� �ǹ��ϴ� �� �� �𸣰���
	if (FindFirstCard("8��") != -1 && FindFirstCard("5��") != -1 && FindFirstCard("2��") != -1) NewScore += 5;
	if (FindFirstCard("1��") != -1 && FindFirstCard("2��") != -1 && FindFirstCard("3��") != -1) NewScore += 3;
	if (FindFirstCard("4��") != -1 && FindFirstCard("5��") != -1 && FindFirstCard("7��") != -1) NewScore += 3;
	if (FindFirstCard("9��") != -1 && FindFirstCard("J��") != -1 && FindFirstCard("6��") != -1) NewScore += 3;
	return NewScore;//���ο� ������ ���ο� ��ȯ�Ѵ�.
}

// �Լ� ����
void Initialize();
void DrawScreen();
void OutPrompt(const char* Mes, int Wait = 0);
int InputInt(const char* Mes, int start, int end);

// ���� ����
CDeck Deck(18, 9);//
CPlayer South(5, 20), North(5, 1);//�÷��̾��� ��ǥ�� South�� ���� �÷��̾ �ǰ�, North�� ��ǻ�Ͱ� �÷��̾ �ȴ�.
CBlanket Blanket(5, 12);//���� ������ �÷��̾ ���� ī�尪���� ������ ���� �̴�. ��ǥ���� ���μ��� ����ִ�.
CPlayerPae SouthPae(40, 14), NorthPae(40, 4);//�� �÷��̾��� ���� ��ǥ
bool SouthTurn;//�� ���� ���̴�.

// ���α׷��� �������ϴ� main �Լ�
void main()
{
	int i, ch;//i�� �ݺ������ ch�� choice �� ���� �����ų� ���� ȭ���и� ���ϴ� ���̴�.
	int arSame[4], SameNum;
	char Mes[256];//��Ȳ���ù�
	CPlayer* Turn;//�÷��̾��� ���� ��Ÿ���� ������
	CPlayerPae* TurnPae, * OtherPae;//�� ���� �п� �ٸ� ��� ���� ��
	int UserIdx, UserSel, DeckSel;//?
	SCard UserCard, DeckCard;//������ 2�� �������, �ϳ��� User�� ī���� �������� Deck�� ī����
	bool UserTriple, DeckTriple;//?
	int nSnatch;//��信�� ������ ī������ �ε����� ����� ����
	int NewScore;//���ο��� �� ������ ���� ����

	randomize();//�����Լ�
	Initialize();//�ʱ�ȭ
	for (SouthTurn = true; !Deck.IsEmpty(); SouthTurn = !SouthTurn) {//���� ���̰�, ���� ������� ������ ������ ���������� �Ʒ� ���๮�� �ϴ� ���̴�.
		DrawScreen();//�ʱ� �̴� ȭ���� ����.
		if (SouthTurn) {//�����̴�.
			Turn = &South;//���� ���� ���̴�.
			TurnPae = &SouthPae;//���Ͽ� ���� �и� ������ �ִ�.
			OtherPae = &NorthPae;//���Ͽ� ���� ����� �и� ������ �ִ�.
		}
		else {//������̴�.
			Turn = &North;//���� ������̴�.
			TurnPae = &NorthPae;//����Ͽ� ���� ����� �и� ������ �ִ�.
			OtherPae = &SouthPae;//����Ͽ� ���� ���� �и� ������ �ִ�.
		}
		//sprintf �Լ��ؼ�: �Ͽ� ī�� ���� �޾Ƽ� 2������ ������ ��ȯ���ڿ� �����ϰ� MES�� �迭�� �����Ѵ�.
		sprintf(Mes, "���� ���� ȭ���� �����ϼ���(1~%d,0:����) ", Turn->GetNum());
		ch = InputInt(Mes, 0, Turn->GetNum());//��Ȳ���ù��� ���´�. �׸��� 0�� ������ ����� �� �Ͽ� ��Ȳ�� �ش��ϴ� ���ڸ� ������ �� �ִ�.
		if (ch == 0) {//���� 0�� Ű���带 �����ߴٸ� 
			if (InputInt("���� �����̴ϱ�?(0:��,1:�ƴϿ�)", 0, 1) == 0)//�ٽ� ������ �� �ִ� ��ȸ��. 0�� ������ ���� ����� �ƴϸ� �ٽ� ���� ������ �Ŵ�.
				return;
			else
				continue;
		}

		// �÷��̾ ī�带 ���� ����.
		UserTriple = DeckTriple = false;//������ ��� �������� �ʱ�ȭ�Ѵ�.
		UserIdx = ch - 1;//User�ε����� ���� ���ڿ��� 1��ŭ �����ش�.
		UserCard = Turn->GetCard(UserIdx);//Userī��� �Ͽ��� ī�带 �޾ƿͼ� User�� �ε����� ���μ��� �ް� ī���� ������ �������� ���̴�.
		SameNum = Blanket.FindSameCard(UserCard, arSame);//���� ���ڶ�� ��信�� ���� ī�带 ã�´�. �� ���� ���� ī�带 ��信�� ã�� ���̴�.
		switch (SameNum) {//��信�� ���� ī�带 ã���� �����ϴ� ��.
		case 0:
			UserSel = -1;//������ ������ ī���ε����� -1�� �����Ѵ�.
			Blanket.InsertCard(Turn->RemoveCard(UserIdx));//��信�� ī�带 ���ְ� ȭ�鿡 ����Ѵ�.
			DrawScreen();//ȭ�� ���
			break;
		case 1:
			UserSel = arSame[0];//���� ���� ���� �迭���� �ʱ�迭��Ҹ� ������ ������ ī�� �ε����� �����Ѵ�.
			break;
		case 2:
			if (Blanket.GetCard(arSame[0]) == Blanket.GetCard(arSame[1])) {//����� ī�尡 ����� ī�尡 ������ ��, ������ ���� �� ��䲨�� ������!
				UserSel = arSame[0];//������ ������ ī���ε����� ī���ε����� ���� �迭�� �迭��� ù���� ���� �����Ѵ�.
			}
			else {
				Blanket.DrawSelNum(arSame);//��信�� ���� ī�尡 �߸� 
				sprintf(Mes, "� ī�带 �����Ͻðڽ��ϱ�?(1~%d)", SameNum);//���� ī�带 �����ϴ� ���̴�.
				UserSel = arSame[InputInt(Mes, 1, SameNum) - 1];//������ ������ ��ȸ�� �ش�.
			}
			break;
		case 3:
			UserSel = arSame[1];//������ ������ ī�� �ε����� ���� ���� ���� �迭�� �ι�° ��ҿ� �ִ´�.
			UserTriple = true;//���� �� 3���� �����
			break;
		}
		if (UserSel != -1) {//���� ������ ������ ī���ε����� -1�� �ƴ϶�� 
			Blanket.DrawTempCard(UserSel, UserCard);//��信 ������ ������ �ε����� ī�尡 ���������� ����Ѵ�.
		}
		delay(Speed);//1�� ���� �̷����� �����̴�.

		// ��ũ���� ������ �����´�.
		Deck.Draw(true);//��ũ���� ���� �̴´�.
		delay(Speed);//1�� �����̸� �ش�.
		DeckCard = Deck.Pop();//�����ڷᱸ����. ��ũ���� ������ ���� ���� DeckCard�� �����Ѵ�.
		SameNum = Blanket.FindSameCard(DeckCard, arSame);//��ũ���� ������ ���� �ε������̴�? �׷� ��信�� �ٷ� �Ծ������. �Ʒ��� �� ��쿡 ���� ������ �ִ�.
		switch (SameNum) {//
		case 0:
			DeckSel = -1;//������ ������ ���� -1
			break;//�ݺ��� Ż�� ->������ ���� ī�尡 ��信�� �ƹ��͵� ���� �� ���� �� ��������� �ѱ�� ���̴�.
		case 1:
			DeckSel = arSame[0];//������ ���� �� ����? �׷� �Ʒ��� ���౸���� �����Ѵ�.
			if (DeckSel == UserSel) {//������ ���� �Ͱ� ������ ������ ���� ���� ���
				if (Deck.IsNotLast()) {//���� �������� �ƴ϶�� 
					Blanket.InsertCard(DeckCard);//��信 ī�带 �־��ش�.
					Blanket.InsertCard(Turn->RemoveCard(UserIdx));//��信 ī�带 �־��ְ� ī�带 �����´�.
					OutPrompt("�����߽��ϴ�.", PromptSpeed);//��Ȳ���ù�, �׸��� 2���� �����̸� �ش�.
					continue;//�׸��� �ݺ��� ������.
				}
				else {
					DeckSel = -1;//������ ���� �Ͱ� ������ ������ ī���ε����� ���� ������ �� ������ Ż��
				}
			}
			break;
		case 2:
			if (UserSel == arSame[0]) {//������ ������ �Ͱ� ���� ��
				DeckSel = arSame[1];//������ ������ ī���ε����� ���� ī���� �ι�° �迭 �ε����� ��Ÿ����.
			}
			else if (UserSel == arSame[1]) {//������ ������ �� 2��° �迭��ۿ� ������
				DeckSel = arSame[0];//������ ������ ī���ε����� ���� ���� ī�带 ��Ÿ���� �迭�� ó�� �迭��Ұ��� �����϶�
			}
			else {
				if (Blanket.GetCard(arSame[0]) == Blanket.GetCard(arSame[1])) {//��信�� ���� �� �����Ѵ�? �׷��� ����� ���� ���̴� �׳� �Դ� ���̴�.
					DeckSel = arSame[0];//������ ������ ī���ε����� ���� ���� ī�带 ��Ÿ���� �迭�� ó�� �迭��Ұ��� �����϶�
				}
				else {
					Blanket.DrawSelNum(arSame);//��信�� ������ ���� �ִ´�.
					sprintf(Mes, "� ī�带 �����Ͻðڽ��ϱ�?(1~%d)", SameNum);//��信�� ���� ī�带 �����϶�� ��Ȳ���ù�
					DeckSel = arSame[InputInt(Mes, 1, SameNum) - 1];//������ ���� �Ŵ� �÷��̾ �ϳ� �Ծ����� �������� ������� �´�
				}
			}
			break;
		case 3:
			DeckSel = arSame[1];//������ ������ �Ϳ� ���ΰ��� ���� ��Ÿ���� �迭����� 2��° ���ڸ� �����϶�.
			DeckTriple = true;//�� Ʈ������ �����ΰ�? �� �𸣰ڵ�.
			break;
		}
		if (DeckSel != -1) {//������ ������ ���� -1���� �ƴ϶��
			Blanket.DrawTempCard(DeckSel, DeckCard);//��信�� ����ī�带 �̴´�.
		}
		Deck.Draw(false);//������ �����ϴ� ���� ���߰�
		delay(Speed);//1���� �ð��� �鿩 �����Ѵ�.

		// ��ġ�ϴ� ī�带 �ŵ� ���δ�. �� ���� ���� ���� ���� ���� �´�.
		if (UserSel != -1) {//������ ���� �����Ѵٸ�(������ �帧�� Ű���忡�� -1 ���ġ���� ���� ���̴�. �׳� �ڿ��� ĥ �״� ������ ���� ������ �����ϴ� ���̶�� �ϴ� ���̴�.
			if (UserTriple) {//���� Ʈ���� ����?
				for (i = 0; i < 3; i++) {
					TurnPae->InsertCard(Blanket.RemoveCard(UserSel - 1));//�׷� ���Ͽ� ��� �Ծ����ϱ� ��信�� �ش� ī�尡 �������
				}
			}
			else {
				TurnPae->InsertCard(Blanket.RemoveCard(UserSel));//�ƴϸ� ��信 �־��ִ� ���̴�.
			}
			TurnPae->InsertCard(Turn->RemoveCard(UserIdx));//������ �п� ī�带 �ִ´�? �̰� ������ �� �𸣰ڴ�.
			if (DeckSel != -1 && DeckSel > UserSel) {//���� �����ϰ� ���� ī�� �ε����� �� ī���ε������� ����?? �̰͵� �������� �𸣰ڵ�.
				DeckSel -= (UserTriple ? 3 : 1);//Ʈ���� �Ծ��� �̶��ΰ�?
			}
		}
		if (DeckSel != -1) {//��� ������ ���� �������̴�.
			if (DeckTriple) {//Ʈ���� ����?
				for (i = 0; i < 3; i++) {//3�� ���� ����? �׷��ϱ� �ش� �ݺ������� 3�� �����ְ���
					TurnPae->InsertCard(Blanket.RemoveCard(DeckSel - 1));//�� �Ͽ� ī�带 �ִµ� (��信�� ī�带 �����Ѵ�.) ������ ������ �͵� �����Ѵ�.
				}
			}
			else {//Ʈ������ �ȶ���?
				TurnPae->InsertCard(Blanket.RemoveCard(DeckSel));//�׳� ���п��� ���� �и� ������.
			}
			TurnPae->InsertCard(DeckCard);//�Ͽ� ��ī�忡 ī�带 �����Ѵ�.
		}
		else {
			Blanket.InsertCard(DeckCard);//��信 ī�带 ������ ���� �Ÿ� ���´�.
		}

		// ��, ����, �Ͼ��� ������ �����ϰ� ������ �Ǹ� ���´�.
		nSnatch = 0;//�ո��� �ְ��� �̰Ŵ� �� �������� �Ÿ� ���ϴ� ���̴�.
		if (Deck.IsNotLast()) {//���� �������� �ƴϸ� �̰� �����ض�
			if (UserSel == -1 && SameNum == 1 && DeckCard.GetNumber() == UserCard.GetNumber()) {//������ ���� ���� ������ϰ� ������ ī�带 �̾Ҵµ� ��信 �ٷ� �ִ�?
				nSnatch++;//0���� �ϳ� �����ش�. ������ 1 ����п��� �ϳ� �����´�.
				OutPrompt("���Դϴ�.", PromptSpeed);//��Ȳ���ù��� ����Ѵ�.
			}
			if (UserSel != -1 && SameNum == 2 && DeckCard.GetNumber() == UserCard.GetNumber()) {//������ ���� ���� ������ϰ� ���� �ѹ��� 2��° ���� ī���а� ������ ���Դ�?
				nSnatch++;//0���� �ϳ� �����ش�. ������ 1 ����п��� �ϳ� �����´�.
				OutPrompt("�����Դϴ�.", PromptSpeed);//��Ȳ���ù��� ����Ѵ�.
			}
			if (Blanket.GetNum() == 0) {
				nSnatch++;//0���� �ϳ� �����ش�. ������ 1 ����п��� �ϳ� �����´�.
				OutPrompt("�Ͼ����Դϴ�.", PromptSpeed);//��Ȳ���ù��� ����Ѵ�.
			}
			if (UserTriple || DeckTriple) {//������ Ʈ���� �߰ų� ������ Ʈ���� �߰ų�
				OutPrompt("�Ѳ����� �� ���� �Ծ����ϴ�.", PromptSpeed);//�׷� ��Ȳ���ù��� �̷��� ���´�.
				nSnatch += UserTriple + DeckTriple;//����Ʈ���ð� ��Ʈ������ ���� ��ŭ �����´�.
			}
		}
		for (i = 0; i < nSnatch; i++) {//������ ȸ����ŭ �ݺ����� ������.
			TurnPae->InsertCard(OtherPae->RemovePee());//��� ���� �ʹ� �ž�
		}

		// ������ ����ϰ� ��, ���� ���θ� �����Ѵ�.
		NewScore = TurnPae->CalcScore();//���� ��� ���� ���� �� �������� �����Ѵ�.
		if (Deck.IsNotLast() && NewScore > TurnPae->OldScore) {//���� �������� �ƴϰ�, ���Ͽ� ������ 7���̻� ����?(OldScore�� 6�̴�.)
			DrawScreen();//��ũ�� ����.
			if (InputInt("�߰� ������ ȹ���߽��ϴ�.(0:����, 1:���)", 0, 1) == 1) {//��Ȳ���ù�
				TurnPae->OldScore = NewScore;//���� ���ھ�� �����ھ�� �ٲ��, �� ���� �̻����� ������ �� ���� �� ������ ������.
				TurnPae->IncreaseGo();//Go Ƚ���� ����ش�.
			}
			else {
				break;//0ġ�� ��ž
			}
		}
	}
	DrawScreen();//�ʱ� ����Ʈ ȭ���� ����.
	OutPrompt("������ �������ϴ�.", 0);//��Ȳ���ù�
}

void Initialize()//�ʱ�ȭ
{
	int i;//�ݺ������

	Deck.Shuffle();//���� �����Ѵ�.
	for (i = 0; i < 10; i++) {//10�� �����Ѵ�.
		South.InsertCard(Deck.Pop());//������ �̾Ƽ� ������ ī�带 �����ش�.
		North.InsertCard(Deck.Pop());//������ �̾Ƽ� ��뿡�� ī�带 �����ش�.
		if (i < 8) Blanket.InsertCard(Deck.Pop());//���� i�� 8�̸��̶�� ������׵� ���� �����ش�.
	}
}

void DrawScreen()//���� ī�带 ������ ȭ���̴�.
{
	clrscr();//clrscr() �Լ��� ȭ���� ����� �Լ��̰� �̿� ����� ������ �ϴ� ��ɾ �����ϸ� �ȴ�.
	South.Draw(SouthTurn);//���Ͽ� ���� ī�带 �̴´�.
	North.Draw(!SouthTurn);//������ �ƴϸ� ���� ī�带 �̴´�.
	Blanket.Draw();//������׵� ���� �����ش�.
	Deck.Draw(false);//������ ���� �̴´�.
	SouthPae.Draw();//���п��� ���� �̴´�.
	NorthPae.Draw();//���� ��� �п��� ���� �̴´�.
}

void OutPrompt(const char* Mes, int Wait/*=0*/)
{
	gotoxy(5, 23);//5,23 �ܼ� ��ǥ�� �̵��Ѵ�.
	for (int i = 5; i < 79; i++) { cout << ' '; }//��ĭ�̴�. �̰��� ȭ�鱸���� ���� ���̴�.
	gotoxy(5, 23);//�ٽ� �ش� �ܼ� ��ǥ�� �̵��Ѵ�.
	cout << Mes;//MES�� ����Ѵ�.
	delay(Wait);//�ణ�� �����̸� �ָ鼭 ȭ���� �����ϴ� �Լ��̴�.
}

int InputInt(const char* Mes, int start, int end)//����ڰ� ���ڸ� �Է��ϸ� �ڽ��� ������ ȭ���и� ��信 ������ ���̴�.
{
	int ch;

	OutPrompt(Mes);//����ó��
	for (;;) {//������ �����ش�.
		ch = tolower(_getch());//Ű����� �޾ƿ� ���� ��� �ҹ��ڷ� �����ش�.
		if (ch == 0xE0 || ch == 0) {//0xE0�� Hexa������ 16������ �ǹ��Ѵ�. 10�����δ� 224�̴�. �� ���������� �ʱⰪ�̶�� ch�� 
			ch = _getch();//Ű���忡�� ���� �޾ƿ� ���� ch�� �����Ѵ�.
			continue;
		}
		if (!(isdigit(ch) || ch == 'a')) continue;//isdigit�� ���ڰ� �������� Ȯ���ϴ� �Լ��̴�. ���� a���̰ų� ch ���� Ű���� ���� �ƴ϶�� �ش� �ݺ��� Ƚ���� �����ؼ� �ݺ����� ������.
		if (ch == 'a') ch = 10; else ch = ch - '0';//a��� ch ���� 10�� �����Ѵ�. �ƴ϶�� ch ������ 0���ڸ� ���ش�.
		if (ch >= start && ch <= end) {//Ÿ������ ���� �߰��̶�� 
			return ch;//ch�� ��ȯ�Ѵ�.
		}
		OutPrompt("��ȿ�� ��ȣ�Դϴ�. ������ ������ �°� �ٽ� �Է��� �ּ���.");//����ó������
	}
}
