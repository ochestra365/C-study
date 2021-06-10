#define _CRT_SECURE_NO_WARNINGS // ���ȿ��� ������
#include <stdio.h>// ǥ�� ����� ���� �߰�
#include <conio.h>// �ܼ� ������Լ� �߰�
#include <string.h>// ��Ʈ�� ���̺귯�� �߰�
#include "cursor.h"//���� Ư�� ��� ���̺귯�� �߰�
#include <assert.h>// C ǥ�� ���̺귯�� �� �ϳ���. C ��� ��ó���� ��ũ�� �� �ϳ��� assert() �� ��ũ�δ� ǥ���� �����Ͽ� ���α׷��� ������ ���� Ȯ���ϸ� ������ ��� ���� �޽����� ����Ѵ�.
#include <iostream>// �⺻ ����°� ���õ� ��ü���� �߰���.
using namespace std;// ǥ�� ���ӽ����̽� �߰�

// �������� ����
const int MaxCard = 48; // �ִ밪 ī�带 ���ȭ���� -->48�̴�.
const int CardGap = 4;// ī���� �� ���̴� 4�̴�. 
const int Speed = 1000;//�ӵ��� 1000�̴�.
const int PromptSpeed = 2000;//����Ǵ� �ӵ��� 1000�̴�.

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
class CDeck : public CCardSet
{
public:
	CDeck(int asx, int asy) : CCardSet(asx, asy) { ; }
	void Shuffle() {
		int i, n;
		for (i = 0; i < MaxCard; i++) {
			do {
				n = random(MaxCard);
			} while (Card[n].Name[0] != NULL);
			Card[n] = HwaToo[i];
			Num++;
		}
	}
	SCard Pop() { return RemoveCard(Num - 1); }
	bool IsEmpty() { return Num == 0; }
	bool IsNotLast() { return Num > 1; }
	void Draw(bool bFlip) {
		gotoxy(sx, sy);
		cout << "??? " << (bFlip ? Card[Num - 1].Name : "   ");
	}
};

// ������ �ϴ� �÷��̾�
class CPlayer : public CCardSet
{
public:
	CPlayer(int asx, int asy) : CCardSet(asx, asy) { ; }
	void Draw(bool MyTurn) {
		int i, x;
		for (i = 0, x = sx; i < Num; i++, x += CardGap) {
			gotoxy(x, sy);
			cout << Card[i];
			if (MyTurn) {
				gotoxy(x, sy + 1);
				cout << '[' << i + 1 << ']';
			}
		}
	}
};

// ������ ����Ǵ� ���
class CBlanket : public CPlayer
{
public:
	CBlanket(int asx, int asy) : CPlayer(asx, asy) { ; }
	void Draw() {
		CPlayer::Draw(false);
	}
	void DrawSelNum(int* pSame) {
		int n;
		int* p;
		for (n = 1, p = pSame; *p != -1; p++, n++) {
			gotoxy(sx + *p * CardGap, sy - 1);
			cout << '[' << n << ']';
		}
	}
	void DrawTempCard(int idx, SCard C) {
		gotoxy(sx + idx * CardGap, sy + 1);
		cout << C;
	}
};

// �÷��̾ ���� ī���� ����
class CPlayerPae : public CCardSet
{
private:
	int nGo;

public:
	int OldScore;
	CPlayerPae(int asx, int asy) : CCardSet(asx, asy) { OldScore = 6; nGo = 0; }
	void Reset() { CCardSet::Reset(); OldScore = 6; nGo = 0; }
	int GetGo() { return nGo; }
	void IncreaseGo() { nGo++; }
	void Draw();
	SCard RemovePee();
	int CalcScore();
};

void CPlayerPae::Draw() {
	int i, kind;
	int x[4] = { sx,sx,sx,sx }, py = sy + 3;

	for (i = 0; i < Num; i++) {
		kind = Card[i].GetKind();
		if (kind < 3) {
			gotoxy(x[kind], sy + kind);
			x[kind] += CardGap;
		}
		else {
			gotoxy(x[3], py);
			x[3] += CardGap;
			if (x[3] > 75) {
				x[3] = sx;
				py++;
			}
		}
		cout << Card[i];
	}
	gotoxy(sx + 23, sy);
	cout << "����:" << CalcScore() << "��, " << nGo << "��";
}

SCard CPlayerPae::RemovePee() {
	int idx;

	idx = FindFirstCard("��");
	if (idx != -1) {
		return RemoveCard(idx);
	}
	return SCard();
}

int CPlayerPae::CalcScore() {
	int i, kind, n[4] = { 0, };
	int NewScore;
	static int gscore[] = { 0,0,0,3,4,15 };

	for (i = 0; i < Num; i++) {
		kind = Card[i].GetKind();
		n[kind]++;
	}
	NewScore = gscore[n[0]];
	if (n[0] == 3 && FindFirstCard("B��") != -1) NewScore--;
	if (n[1] >= 5) NewScore += (n[1] - 4);
	if (n[2] >= 5) NewScore += (n[2] - 4);
	if (n[3] >= 10) NewScore += (n[3] - 9);
	if (FindFirstCard("8��") != -1 && FindFirstCard("5��") != -1 && FindFirstCard("2��") != -1) NewScore += 5;
	if (FindFirstCard("1��") != -1 && FindFirstCard("2��") != -1 && FindFirstCard("3��") != -1) NewScore += 3;
	if (FindFirstCard("4��") != -1 && FindFirstCard("5��") != -1 && FindFirstCard("7��") != -1) NewScore += 3;
	if (FindFirstCard("9��") != -1 && FindFirstCard("J��") != -1 && FindFirstCard("6��") != -1) NewScore += 3;
	return NewScore;
}

// �Լ� ����
void Initialize();
void DrawScreen();
void OutPrompt(const char* Mes, int Wait = 0);
int InputInt(const char* Mes, int start, int end);

// ���� ����
CDeck Deck(18, 9);
CPlayer South(5, 20), North(5, 1);
CBlanket Blanket(5, 12);
CPlayerPae SouthPae(40, 14), NorthPae(40, 4);
bool SouthTurn;

// ���α׷��� �������ϴ� main �Լ�
void main()
{
	int i, ch;
	int arSame[4], SameNum;
	char Mes[256];
	CPlayer* Turn;
	CPlayerPae* TurnPae, * OtherPae;
	int UserIdx, UserSel, DeckSel;
	SCard UserCard, DeckCard;
	bool UserTriple, DeckTriple;
	int nSnatch;
	int NewScore;

	randomize();
	Initialize();
	for (SouthTurn = true; !Deck.IsEmpty(); SouthTurn = !SouthTurn) {
		DrawScreen();
		if (SouthTurn) {
			Turn = &South;
			TurnPae = &SouthPae;
			OtherPae = &NorthPae;
		}
		else {
			Turn = &North;
			TurnPae = &NorthPae;
			OtherPae = &SouthPae;
		}

		sprintf(Mes, "���� ���� ȭ���� �����ϼ���(1~%d,0:����) ", Turn->GetNum());
		ch = InputInt(Mes, 0, Turn->GetNum());
		if (ch == 0) {
			if (InputInt("���� �����̴ϱ�?(0:��,1:�ƴϿ�)", 0, 1) == 0)
				return;
			else
				continue;
		}

		// �÷��̾ ī�带 ���� ����.
		UserTriple = DeckTriple = false;
		UserIdx = ch - 1;
		UserCard = Turn->GetCard(UserIdx);
		SameNum = Blanket.FindSameCard(UserCard, arSame);
		switch (SameNum) {
		case 0:
			UserSel = -1;
			Blanket.InsertCard(Turn->RemoveCard(UserIdx));
			DrawScreen();
			break;
		case 1:
			UserSel = arSame[0];
			break;
		case 2:
			if (Blanket.GetCard(arSame[0]) == Blanket.GetCard(arSame[1])) {
				UserSel = arSame[0];
			}
			else {
				Blanket.DrawSelNum(arSame);
				sprintf(Mes, "� ī�带 �����Ͻðڽ��ϱ�?(1~%d)", SameNum);
				UserSel = arSame[InputInt(Mes, 1, SameNum) - 1];
			}
			break;
		case 3:
			UserSel = arSame[1];
			UserTriple = true;
			break;
		}
		if (UserSel != -1) {
			Blanket.DrawTempCard(UserSel, UserCard);
		}
		delay(Speed);

		// ��ũ���� ������ �����´�.
		Deck.Draw(true);
		delay(Speed);
		DeckCard = Deck.Pop();
		SameNum = Blanket.FindSameCard(DeckCard, arSame);
		switch (SameNum) {
		case 0:
			DeckSel = -1;
			break;
		case 1:
			DeckSel = arSame[0];
			if (DeckSel == UserSel) {
				if (Deck.IsNotLast()) {
					Blanket.InsertCard(DeckCard);
					Blanket.InsertCard(Turn->RemoveCard(UserIdx));
					OutPrompt("�����߽��ϴ�.", PromptSpeed);
					continue;
				}
				else {
					DeckSel = -1;
				}
			}
			break;
		case 2:
			if (UserSel == arSame[0]) {
				DeckSel = arSame[1];
			}
			else if (UserSel == arSame[1]) {
				DeckSel = arSame[0];
			}
			else {
				if (Blanket.GetCard(arSame[0]) == Blanket.GetCard(arSame[1])) {
					DeckSel = arSame[0];
				}
				else {
					Blanket.DrawSelNum(arSame);
					sprintf(Mes, "� ī�带 �����Ͻðڽ��ϱ�?(1~%d)", SameNum);
					DeckSel = arSame[InputInt(Mes, 1, SameNum) - 1];
				}
			}
			break;
		case 3:
			DeckSel = arSame[1];
			DeckTriple = true;
			break;
		}
		if (DeckSel != -1) {
			Blanket.DrawTempCard(DeckSel, DeckCard);
		}
		Deck.Draw(false);
		delay(Speed);

		// ��ġ�ϴ� ī�带 �ŵ� ���δ�. �� ���� ���� ���� ���� ���� �´�.
		if (UserSel != -1) {
			if (UserTriple) {
				for (i = 0; i < 3; i++) {
					TurnPae->InsertCard(Blanket.RemoveCard(UserSel - 1));
				}
			}
			else {
				TurnPae->InsertCard(Blanket.RemoveCard(UserSel));
			}
			TurnPae->InsertCard(Turn->RemoveCard(UserIdx));
			if (DeckSel != -1 && DeckSel > UserSel) {
				DeckSel -= (UserTriple ? 3 : 1);
			}
		}
		if (DeckSel != -1) {
			if (DeckTriple) {
				for (i = 0; i < 3; i++) {
					TurnPae->InsertCard(Blanket.RemoveCard(DeckSel - 1));
				}
			}
			else {
				TurnPae->InsertCard(Blanket.RemoveCard(DeckSel));
			}
			TurnPae->InsertCard(DeckCard);
		}
		else {
			Blanket.InsertCard(DeckCard);
		}

		// ��, ����, �Ͼ��� ������ �����ϰ� ������ �Ǹ� ���´�.
		nSnatch = 0;
		if (Deck.IsNotLast()) {
			if (UserSel == -1 && SameNum == 1 && DeckCard.GetNumber() == UserCard.GetNumber()) {
				nSnatch++;
				OutPrompt("���Դϴ�.", PromptSpeed);
			}
			if (UserSel != -1 && SameNum == 2 && DeckCard.GetNumber() == UserCard.GetNumber()) {
				nSnatch++;
				OutPrompt("�����Դϴ�.", PromptSpeed);
			}
			if (Blanket.GetNum() == 0) {
				nSnatch++;
				OutPrompt("�Ͼ����Դϴ�.", PromptSpeed);
			}
			if (UserTriple || DeckTriple) {
				OutPrompt("�Ѳ����� �� ���� �Ծ����ϴ�.", PromptSpeed);
				nSnatch += UserTriple + DeckTriple;
			}
		}
		for (i = 0; i < nSnatch; i++) {
			TurnPae->InsertCard(OtherPae->RemovePee());
		}

		// ������ ����ϰ� ��, ���� ���θ� �����Ѵ�.
		NewScore = TurnPae->CalcScore();
		if (Deck.IsNotLast() && NewScore > TurnPae->OldScore) {
			DrawScreen();
			if (InputInt("�߰� ������ ȹ���߽��ϴ�.(0:����, 1:���)", 0, 1) == 1) {
				TurnPae->OldScore = NewScore;
				TurnPae->IncreaseGo();
			}
			else {
				break;
			}
		}
	}
	DrawScreen();
	OutPrompt("������ �������ϴ�.", 0);
}

void Initialize()
{
	int i;

	Deck.Shuffle();
	for (i = 0; i < 10; i++) {
		South.InsertCard(Deck.Pop());
		North.InsertCard(Deck.Pop());
		if (i < 8) Blanket.InsertCard(Deck.Pop());
	}
}

void DrawScreen()
{
	clrscr();
	South.Draw(SouthTurn);
	North.Draw(!SouthTurn);
	Blanket.Draw();
	Deck.Draw(false);
	SouthPae.Draw();
	NorthPae.Draw();
}

void OutPrompt(const char* Mes, int Wait/*=0*/)
{
	gotoxy(5, 23);
	for (int i = 5; i < 79; i++) { cout << ' '; }
	gotoxy(5, 23);
	cout << Mes;
	delay(Wait);
}

int InputInt(const char* Mes, int start, int end)
{
	int ch;

	OutPrompt(Mes);
	for (;;) {
		ch = tolower(_getch());
		if (ch == 0xE0 || ch == 0) {
			ch = _getch();
			continue;
		}
		if (!(isdigit(ch) || ch == 'a')) continue;
		if (ch == 'a') ch = 10; else ch = ch - '0';
		if (ch >= start && ch <= end) {
			return ch;
		}
		OutPrompt("��ȿ�� ��ȣ�Դϴ�. ������ ������ �°� �ٽ� �Է��� �ּ���.");
	}
}
