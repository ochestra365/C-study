#define _CRT_SECURE_NO_WARNINGS // 보안에러 막아줌
#include <stdio.h>// 표준 입출력 버퍼 추가
#include <conio.h>// 콘솔 입출력함수 추가
#include <string.h>// 스트링 라이브러리 추가
#include "cursor.h"//저자 특수 헤더 라이브러리 추가
#include <assert.h>// C 표준 라이브러리 중 하나다. C 언어 전처리기 매크로 중 하나인 assert() 이 매크로는 표명을 구현하여 프로그램이 추정한 것을 확인하며 거짓인 경우 진단 메시지를 출력한다.
#include <iostream>// 기본 입출력과 관련된 객체들을 추가함.
using namespace std;// 표준 네임스페이스 추가

// 전역변수 설정
const int MaxCard = 48; // 최대값 카드를 상수화해줌 -->48이다.
const int CardGap = 4;// 카드의 각 차이는 4이다. 
const int Speed = 1000;//속도는 1000이다.
const int PromptSpeed = 2000;//장려되는 속도는 1000이다.

// 화투 한장을 표현하는 클래스
struct SCard
{
	char Name[4];// 화투 한장이 가질 수 있는 이름의 크기는 4byte이다.
	SCard() { Name[0] = 0; }//디폴트 생성자를 만들어준다.  배열의 초기항에 들어 있는 값은 0이다.
	SCard(const char* pName) {//메인으로부터 읽어온 값을 상수화해서 필드로 넘겨준다. 이것은 생성자이다.
		strcpy(Name, pName);
	}
	int GetNumber() const {//화투한장에서 숫자값을 메인으로 가져올 때 쓰는 함수이다. 반환값은 정수형으로 존재하고 상수값이다.
		if (isdigit(Name[0])) return Name[0] - '0'; // isdigit은 10진수 숫자로 변경이 가능하면 숫자(True), 아니면 False(0)을 반환하는 함수를 의미한다.
		if (Name[0] == 'J') return 10;//초기항이 J이라면 메인으로 10을 반환한다.
		if (Name[0] == 'D') return 11;//초기항이 D라면 메인으로 11을 반환한다.
		return 12;//그 외는 12로 반환한다.
	};
	int GetKind() const {//화투한장에서 종류값을 메인으로 가져올 때 쓰는 함수이다. 반환값은 정수형으로 존재하고 상수형이다.
		if (strcmp(Name + 1, "광") == 0) return 0;//두번째 배열요소값이 광이면 0을 반환한다.
		else if (strcmp(Name + 1, "십") == 0) return 1;//두번째 배열요소값이 십이면 1을 반환한다.
		else if (strcmp(Name + 1, "오") == 0) return 2;//두 번째 배열요소값이 오이면 2를 반환한다.
		else return 3;//나머지는 3을 반환한다.
	}
	friend ostream& operator <<(ostream& c, const SCard& C) {//osstream에게 friend키워드를 써서 정보를 공개한다.
		return c << C.Name;
	}
	bool operator ==(const SCard& Other) const {//매개변수로 받아온 화투 한장의 정보에 대한 논리값을 상수값으로 반환한다.
		return (strcmp(Name, Other.Name) == 0);//이름과 매개변수로 받아온 화투 한장의 이름이 서로 같다면 0을 반환한다.(거짓을 반환한다는 소리다.)
	}
	bool operator <(const SCard& Other) const {
		if (GetNumber() < Other.GetNumber()) return true;//받아온 숫자값이 매개변수에서 받아온 숫자값보다 작으면 참값을 반환한다.
		if (GetNumber() > Other.GetNumber()) return false;//받아온 숫자값이 매개변수에서 받아온 숫자값보다 크면 거짓을 반환한다.
		if (GetKind() < Other.GetKind()) return true;//받아온 종류값이 매개변수에서 받아온 종류값보다 작으면 참값을 반환한다.
		return false;
	}
};

// 화투의 초기 카드 목록
SCard HwaToo[MaxCard] = {// 화투 클래스의 배열형 자료를 만들어 두었다. MaxCard값은 48이므로 배열요소는 48개이다.
	"1광","1오","1피","1피","2십","2오","2피","2피","3광","3오","3피","3피",
	"4십","4오","4피","4피","5십","5오","5피","5피","6십","6오","6피","6피",
	"7십","7오","7피","7피","8광","8십","8피","8피","9십","9오","9피","9피",
	"J십","J오","J피","J피","D광","D피","D피","D피","B광","B십","B오","B피"
};

// 카드의 집합을 관리하는 클래스
class CCardSet
{
protected://상속관계에 있는 자식 클래스만 정보를 쓸 수 있게 하며 같은 패키지의 클래스와 다른 패키지의 서브클래스에서도 접근할 수 있다.
	SCard Card[MaxCard];// 화투에 대한 배열을 만든다. 즉, 카드의 한 뭉텅이가 있는 것이다.
	int Num;//카드 집합의 숫자필드
	const int sx, sy;//카드 집합의 x와 y에 대한 상수값 숫자 필드
	CCardSet(int asx, int asy) : sx(asx), sy(asy) { Num = 0; }//생성자를 만들어서 메인에서 받은 값을 이 클래스의 필드로 올려준다.  디폴트값은 Num=0이다.

public:
	int GetNum() { return Num; }//숫자를 받는 함수이다. Num값을 반환한다.
	SCard GetCard(int idx) { return Card[idx]; }//카드를 가져오는 함수이다. index값을 가져온다. 메인에 카드의 index를 반환한다.
	void Reset() {//화투판을 초기화하는 것이다. 화투판을 엎었다고 이해해도 좋다.
		for (int i = 0; i < MaxCard; i++) Card[i].Name[0] = 0;//뽑은 카드의 모든 초기이름을 0으로 디폴트화, 즉 화투판을 엎은 것이다.
		Num = 0;//뽑는 숫자는 다시 0이다.
	}
	//함수 헤더 부분-->정의는 하단에 존재한다.
	void InsertCard(SCard C);//화투카드를 삽입하는 것이다.-->복사생성자이다.
	SCard RemoveCard(int idx);//카드를 제거하는 것이다.
	int FindSameCard(SCard C, int* pSame);//같은 화투카드를 찾는 함수이다.(화투 한장과 포인터로 인덱스를 검색한다.)
	int FindFirstCard(const char* pName);//처음 화투카드를 찾는 함수이다.(이름을 상수화시킨다.)
};

void CCardSet::InsertCard(SCard C) {//CCardSet의 InserCard함수에 대한 정의
	int i;//반복 제어 변수

	if (C.Name[0] == 0) return;//만약 뽑은 카드의 인덱스가 0이라면 함수를 실행하지 않는다.
	for (i = 0; i < Num; i++) {
		if (C < Card[i]) break;//만약 뽑은 카드의 인덱스가 반복제어 변수에 대한 인덱스보다 작다면 반복문을 탈출한다.
		//i값에 대한 논리값을 누계하기 위함이다.
	}
	//memmove는 메모리 이동함수이다. 첫번 째 인자는 복사 한 것을 붙여 넣을 메모리를 가리킨다. 두번 째 인자는 복사할 메모리를 가리키는 포인터이다. 세번 째 인자는 복사할 바이트 크기를 나타낸다.
	memmove(&Card[i + 1], &Card[i], sizeof(SCard) * (Num - i));//각 인자는 필드 데이터의 무결성을 위해 레퍼런스로 처리한다. i+1 필드에 i필드에 있는 것을 넣을 것이다. 이때 복사할 바이트 크기는 뽑은 화투의 인덱스에서 i값을 뺴준것이다.
	//즉 화투카드가 삽입되어 원래 있던 인덱스가 한칸 뒤로 옮겨진 것이다. 
	Card[i] = C;//그리고 원래 있던 인덱스에는 새로운 화투카드를 넣는다.
	Num++;//전체 카드수가 늘었으므로 Num값을 1증가 시켜준다.
}

SCard CCardSet::RemoveCard(int idx) {//카드를 내어서 제거되는 것을 표현할 것이다. CCardSet의 RemoveCard함수를 사용할 것이다.
	assert(idx < Num);//assert는 디버깅 모드에서 개발자가 오류가 생기면 치명적일 것이라 생각하는 곳에 심어놓는 에러 검출용 코드이다.
	//NUM값이 idx보다 클 경우 assert를 실행한다.
	SCard C = Card[idx];//카드 값에 뽑은 카드 인덱스를 대입한다.
	memmove(&Card[idx], &Card[idx + 1], sizeof(SCard) * (Num - idx - 1));//메모리를 이동시켜서 idx를 한칸 앞으로 땡겨준다.
	Num--;//카드를 냈으므로 들고 있는 카드의 수는 1장 줄여준다.
	return C;//뽑은 인덱스명을 반환한다.
}

int CCardSet::FindSameCard(SCard C, int* pSame) {//함수정의이다. 같은 카드를 찾는 것이다. 즉 화투판에 던질 카드를 찾는 것이다.
	int i, num;//i는 반복제어 변수, num은 누계값을 의미한다.
	int* p = pSame;//포인터로 메인에서 받은 같은 카드인덱스를 받는다.

	for (i = 0, num = 0; i < Num; i++) {//초기값을 모두 0으로 주고 손에 쥐고 있는 카드 숫자만큼 반복문을 돌린다.
		if (Card[i].GetNumber() == C.GetNumber()) {//만약 뽑은 카드 인덱스가 찾은 카드 인덱스와 같다면
			num++;//누계한다.
			*p++ = i;//그리고 포인터값에 i를 대입하고 1을 더한다.
		}
	}
	*p = -1;//모르겠음
	return num;//반환값이다.
}

int CCardSet::FindFirstCard(const char* pName) {//첫번째 카드를 찾는다. 첫번째 카드이므로 이름은 상수값을 준다.
	int i;

	for (i = 0; i < Num; i++) {//손에 쥐고 있는 카드 숫자만큼 반복문을 실행한다.
		if (strstr(Card[i].Name, pName) != NULL) {//strstr함수는 첫번째 인자에서 두번째 인자와 일치하는 문자열이 있는 지 확인하는 함수이다.
			//즉 손에 들고 있는 카드에서 택한 인덱스명을 일치하는 값을 찾을 때 까지 모두 검색하는 것이다.
			return i;//그리고 일치하는 문자열이 있다면 인덱스값을 반환한다.
		}
	}
	return -1;//만약 일치하는 값이 없다면 함수를 실행하지 않는다.
}

// 담요 중앙에 카드를 쌓아 놓는 데크
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

// 게임을 하는 플레이어
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

// 게임이 진행되는 담요
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

// 플레이어가 먹은 카드의 집합
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
	cout << "점수:" << CalcScore() << "점, " << nGo << "고";
}

SCard CPlayerPae::RemovePee() {
	int idx;

	idx = FindFirstCard("피");
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
	if (n[0] == 3 && FindFirstCard("B광") != -1) NewScore--;
	if (n[1] >= 5) NewScore += (n[1] - 4);
	if (n[2] >= 5) NewScore += (n[2] - 4);
	if (n[3] >= 10) NewScore += (n[3] - 9);
	if (FindFirstCard("8십") != -1 && FindFirstCard("5십") != -1 && FindFirstCard("2십") != -1) NewScore += 5;
	if (FindFirstCard("1오") != -1 && FindFirstCard("2오") != -1 && FindFirstCard("3오") != -1) NewScore += 3;
	if (FindFirstCard("4오") != -1 && FindFirstCard("5오") != -1 && FindFirstCard("7오") != -1) NewScore += 3;
	if (FindFirstCard("9오") != -1 && FindFirstCard("J오") != -1 && FindFirstCard("6오") != -1) NewScore += 3;
	return NewScore;
}

// 함수 원형
void Initialize();
void DrawScreen();
void OutPrompt(const char* Mes, int Wait = 0);
int InputInt(const char* Mes, int start, int end);

// 전역 변수
CDeck Deck(18, 9);
CPlayer South(5, 20), North(5, 1);
CBlanket Blanket(5, 12);
CPlayerPae SouthPae(40, 14), NorthPae(40, 4);
bool SouthTurn;

// 프로그램을 총지휘하는 main 함수
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

		sprintf(Mes, "내고 싶은 화투를 선택하세요(1~%d,0:종료) ", Turn->GetNum());
		ch = InputInt(Mes, 0, Turn->GetNum());
		if (ch == 0) {
			if (InputInt("정말 끝낼겁니까?(0:예,1:아니오)", 0, 1) == 0)
				return;
			else
				continue;
		}

		// 플레이어가 카드를 한장 낸다.
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
				sprintf(Mes, "어떤 카드를 선택하시겠습니까?(1~%d)", SameNum);
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

		// 데크에서 한장을 뒤집는다.
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
					OutPrompt("설사했습니다.", PromptSpeed);
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
					sprintf(Mes, "어떤 카드를 선택하시겠습니까?(1~%d)", SameNum);
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

		// 일치하는 카드를 거둬 들인다. 세 장을 먹은 경우는 전부 가져 온다.
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

		// 쪽, 따닥, 싹쓸이 조건을 점검하고 상대방의 피를 뺏는다.
		nSnatch = 0;
		if (Deck.IsNotLast()) {
			if (UserSel == -1 && SameNum == 1 && DeckCard.GetNumber() == UserCard.GetNumber()) {
				nSnatch++;
				OutPrompt("쪽입니다.", PromptSpeed);
			}
			if (UserSel != -1 && SameNum == 2 && DeckCard.GetNumber() == UserCard.GetNumber()) {
				nSnatch++;
				OutPrompt("따닥입니다.", PromptSpeed);
			}
			if (Blanket.GetNum() == 0) {
				nSnatch++;
				OutPrompt("싹쓸이입니다.", PromptSpeed);
			}
			if (UserTriple || DeckTriple) {
				OutPrompt("한꺼번에 세 장을 먹었습니다.", PromptSpeed);
				nSnatch += UserTriple + DeckTriple;
			}
		}
		for (i = 0; i < nSnatch; i++) {
			TurnPae->InsertCard(OtherPae->RemovePee());
		}

		// 점수를 계산하고 고, 스톱 여부를 질문한다.
		NewScore = TurnPae->CalcScore();
		if (Deck.IsNotLast() && NewScore > TurnPae->OldScore) {
			DrawScreen();
			if (InputInt("추가 점수를 획득했습니다.(0:스톱, 1:계속)", 0, 1) == 1) {
				TurnPae->OldScore = NewScore;
				TurnPae->IncreaseGo();
			}
			else {
				break;
			}
		}
	}
	DrawScreen();
	OutPrompt("게임이 끝났습니다.", 0);
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
		OutPrompt("무효한 번호입니다. 지정한 범위에 맞게 다시 입력해 주세요.");
	}
}
