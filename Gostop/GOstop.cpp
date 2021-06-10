#define _CRT_SECURE_NO_WARNINGS // 보안에러 막아줌
#include <stdio.h>// 표준 입출력 버퍼 추가
#include <conio.h>// 콘솔 입출력함수 추가
#include <string.h>// 스트링 라이브러리 추가
#include "cursor.h"//저자 특수 헤더 라이브러리 추가
#include <assert.h>// C 표준 라이브러리 중 하나다. C 언어 전처리기 매크로 중 하나인 assert() 이 매크로는 표명을 구현하여 프로그램이 추정한 것을 확인하며 거짓인 경우 진단 메시지를 출력한다.
#include <iostream>// 기본 입출력과 관련된 객체들을 추가함.
using namespace std;// 표준 네임스페이스 추가
//화투패는 같은 카드가 각각 4장이 존재하는 듯 하다!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// 전역변수 설정
const int MaxCard = 48; // 최대값 카드를 상수화해줌 -->48이다.
const int CardGap = 4;// 카드의 각 차이는 4이다. 
const int Speed = 1000;//속도는 1000이다. 1000ms이므로 1초를 나타낸다.
const int PromptSpeed = 2000;//장려되는 속도는 1000이다.
//덱은 스택 자료형이고, 손패는 시퀀스형 자료형이다. 삽입정렬식으로 손패에 들어오고 나간다. 연결자료구조랑 스택자료구조를 더 공부하면 이 프로그램을 더 잘 이해할 수 있을 것이다.
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
class CDeck : public CCardSet//담요 중앙에 카드를 쌓는 데크는 카드셋을 상속받는다.
{
public:
	CDeck(int asx, int asy) : CCardSet(asx, asy) { ; }//생성자는 CCardSet의 카드집합을 상속받는다.
	void Shuffle() {//화투판을 섞는 함수이다.
		int i, n;//i는 반복제어 변수이고, n은 랜덤값을 받을 변수이다.
		for (i = 0; i < MaxCard; i++) {//전체 카드는 48가지 이므로 이 숫자만큼 반복문을 돌린다.
			do {//do~while문을 써서 적어도 한번 실행문을 돌린다.
				n = random(MaxCard);//n에 1~48까지 수 중에서 난수값을 대입한다.
			} while (Card[n].Name[0] != NULL);//카드가 존재할 때 까지 반복한다.
			Card[n] = HwaToo[i];//화투 배열의 인덱스를 담요 중앙에 놓을 카드값에 대입한다.
			Num++;//담요 중앙에 놓인 카드가 한장씩 늘어난다.
		}
	}
	//스택 자료구조를 따른다.
	SCard Pop() { return RemoveCard(Num - 1); }//담요에서 카드를 뽑는 것이다. RemoveCard함수를 써서 담요중앙에 놓인 전체 숫자에서 하나를 빼준다.
	bool IsEmpty() { return Num == 0; }//논리값이다. 만약 담요판이 비어있다면 카드가 없다는 뜻으로 0을 반환한다.
	bool IsNotLast() { return Num > 1; }//논리값이다. 만약 마지막이 아니라면 화투 중앙에 적어도 1개 이상 있다는 의미이다.
	void Draw(bool bFlip) {//화투중앙에서 카드를 가져오는 것이다.
		gotoxy(sx, sy);//해당좌표로 움직여라
		cout << "??? " << (bFlip ? Card[Num - 1].Name : "   ");//카드 인덱스를 가져온다.
	}
};

// 게임을 하는 플레이어
class CPlayer : public CCardSet //CPlayer는 CCarSet의 자식클래스이다.
{
public:
	CPlayer(int asx, int asy) : CCardSet(asx, asy) { ; }//플레이어가 카드를 던지는 좌표를 나타내는 것이다. CCardSet의 좌표값을 상속 받는다.
	void Draw(bool MyTurn) {//내 턴에 카드를 뽑는 것 함수를 의미한다.
		int i, x;//반복 제어 변수와 좌표 평면상(담요) x값의 좌표위치값을 나타낸다.
		for (i = 0, x = sx; i < Num; i++, x += CardGap) {//카드 공차인 4만큼 움직일 것이다. 그리고 손에 쥔 카드만큼 반복해서 돌려준다.
			gotoxy(x, sy);//좌표값으로 이동한다.
			cout << Card[i];//카드의 인덱스에 해당하는 값을 출력한다.
			if (MyTurn) {//내가 뽑을 차례라면 x의 위치값에서 sy+1만큼 이동한다.
				gotoxy(x, sy + 1);
				cout << '[' << i + 1 << ']';//뽑은 카드의 인덱스이다.
			}
		}
	}
};

// 게임이 진행되는 담요
class CBlanket : public CPlayer //CBlanket은 CPlayer를 상속받는다.
{
public:
	CBlanket(int asx, int asy) : CPlayer(asx, asy) { ; }//담요의 x,y좌표는 CPlayer가 화투판에 던진 좌표값을 상속받는 것이다.
	void Draw() {
		CPlayer::Draw(false);//내 턴이 아닐 때 상대 플레이어가 뽑는다.
	}
	void DrawSelNum(int* pSame) {//무슨 함수인지 모르겠다.
		int n;
		int* p;
		for (n = 1, p = pSame; *p != -1; p++, n++) {
			gotoxy(sx + *p * CardGap, sy - 1);
			cout << '[' << n << ']';
		}
	}
	void DrawTempCard(int idx, SCard C) {//유저가 뽑고나서 덱의 잔여카드를 나타낸다.
		gotoxy(sx + idx * CardGap, sy + 1);//좌표이동
		cout << C;//출력
	}
};

// 플레이어가 먹은 카드의 집합
class CPlayerPae : public CCardSet // CPlayerPae는 CCardSet의 자식클래스이다.
{
private:
	int nGo;//몇 번 고했느냐를 묻는 정수형 필드이다.

public:
	int OldScore;//이전 스코어에대한 데이터를 저장할 인트형 데이터 값 선언
	CPlayerPae(int asx, int asy) : CCardSet(asx, asy) { OldScore = 6; nGo = 0; }//플레이어 패의 좌표값은 CCardSet의 좌표값을 상속받는다. 그리고 고한 횟수는 처음부터 자연수 일리는 없으니 0으로 초기화한다. 오버라이딩이 사용되었다.
	void Reset() { CCardSet::Reset(); OldScore = 6; nGo = 0; }//Reset함수이다. CCardSet의 Reset함수를 모두 상속받는다. 초기 6장을 손패에 들고 나는 0번 고한 상태다. 화투판을 상대가 엎거나 내가 엎거나 했을 때 쓰는 것이다. 오버라이딩이 사용되었다.
	int GetGo() { return nGo; }//고 때리는 것이다. 값을 받아온다.
	void IncreaseGo() { nGo++; }//고를 외친 만큼 값이 누적된다.
	void Draw();//부모클래스의 Draw함수를 쓸 수 있따.
	SCard RemovePee();// 함수헤더이다. 아래에 정의가 있다.
	int CalcScore();//점수 계산 함수이다. 아래에 정의가 있다.
};

void CPlayerPae::Draw() {//Draw함수에 대한 정의
	int i, kind;//반복제어변수와 종류
	int x[4] = { sx,sx,sx,sx }, py = sy + 3;//x좌표값에 대해 4개가 존재하고 y좌표값은 sy에서 3만큼 증가한다.

	for (i = 0; i < Num; i++) {//카드 수만큼 반복한다. 손패에 들고 있는 것이다.
		kind = Card[i].GetKind();//손패에 들고 있는 카드종류이다. GetKind함수를 통해 카드 인덱스에 해당하는 카드의 종류 데이터를 저장한다.
		if (kind < 3) {//만약 종류 값이 3보다 작다면
			gotoxy(x[kind], sy + kind);//해당 좌표르 x 인덱스를 움직이고, sy좌표에 종류값만큼 더해서 올린다.
			x[kind] += CardGap;//x종류값에 카드차이인 4만큼 더한다.
		}
		else {//손패에 없다면
			gotoxy(x[3], py);//x좌표는 3인덱스로 움직이고 py값까지 움직인다.
			x[3] += CardGap;//x배열요소 3번에 만큼 카드 차인 4를 움직여서 x에 대입한다.
			if (x[3] > 75) {//만약 배열요소값이 75 이상이라면
				x[3] = sx;//x[3]번에 sx만큼 대입해서 시작한다.
				py++;//y값을 1더한다.
			}
		}
		cout << Card[i];//카드의 인덱스에 해당하는 값을 출력한다.
	}
	gotoxy(sx + 23, sy);//sx에서 23만큼 더하고 sy값의 좌표로 움직인다.
	cout << "점수:" << CalcScore() << "점, " << nGo << "고";//판을 나타낸다.-->CalcScore()에 대한 함수헤더이다. 정의는 하단에 존재한다.
}

SCard CPlayerPae::RemovePee() {//피를 없애는 함수이다.
	int idx;//화투패의 index명이다.

	idx = FindFirstCard("피");//첫번째 받는 것이 피라는 것이면 idx값에 이것을 저장한다.
	if (idx != -1) {//만약 -1값이 아니면(일치하는 값이 없다면)
		return RemoveCard(idx);//카드 인덱스를 지운다.
	}
	return SCard();//그리고 클래스를 반환한다.
}

int CPlayerPae::CalcScore() {//함수정의이다.
	int i, kind, n[4] = { 0, };// 반복제어 변수 i를 선언한다. 그리고 종류값을 받을 변수를 선언한다. 그리고 n[4]배열을 선언하고 0으로 초기화한다.
	int NewScore;//새로운 점수를 저장할 변수이다.
	static int gscore[] = { 0,0,0,3,4,15 };//스코어 점수는 배열요소 만큼 올라간다. 물리적 순서와 논리적순서가 일치하며 정적타입으로 선언한 정수형 배열 데이터타입이다.

	for (i = 0; i < Num; i++) {//플레이어 손패수만큼 반복문을 돌린다.
		kind = Card[i].GetKind();//각 카드에 대한 종류값을 받아와서 플레이어가 들고 있는 손패의 값에 저장한다.
		n[kind]++;//kind 값을 하나씩 올려준다.
	}
	NewScore = gscore[n[0]];//새로운 점수에 점수를 얻을 스코어를 지시할 것이다.
	if (n[0] == 3 && FindFirstCard("B광") != -1) NewScore--;//B광이 터지고 첫 배열요소값이 3이고 -1이 아니라면 새로운 점수에서 1을 뺄셈한다.
	if (n[1] >= 5) NewScore += (n[1] - 4);//2번째 배열요소값이 5이상이라면 새로운 점수에 2번째 배열요소에서 4를 뺄셈한 것을 더한다.
	if (n[2] >= 5) NewScore += (n[2] - 4);//3번째 배열요소값이 5이상이라면 새로운 점수에 3번째 배열요소에서 4를 뺄셈한 것을 더한다.
	if (n[3] >= 10) NewScore += (n[3] - 9);//4번째 배열요소값이 10이상이라면 새로운 점수에 4번째 배열요소에서 9를 뺄셈한 것을 더한다.
	//하단은 뭘 의미하는 지 잘 모르겠음
	if (FindFirstCard("8십") != -1 && FindFirstCard("5십") != -1 && FindFirstCard("2십") != -1) NewScore += 5;
	if (FindFirstCard("1오") != -1 && FindFirstCard("2오") != -1 && FindFirstCard("3오") != -1) NewScore += 3;
	if (FindFirstCard("4오") != -1 && FindFirstCard("5오") != -1 && FindFirstCard("7오") != -1) NewScore += 3;
	if (FindFirstCard("9오") != -1 && FindFirstCard("J오") != -1 && FindFirstCard("6오") != -1) NewScore += 3;
	return NewScore;//새로운 점수를 메인에 반환한다.
}

// 함수 원형
void Initialize();
void DrawScreen();
void OutPrompt(const char* Mes, int Wait = 0);
int InputInt(const char* Mes, int start, int end);

// 전역 변수
CDeck Deck(18, 9);//
CPlayer South(5, 20), North(5, 1);//플레이어의 좌표값 South가 내가 플레이어가 되고, North는 컴퓨터가 플레이어가 된다.
CBlanket Blanket(5, 12);//담요는 각자의 플레이어가 던진 카드값들을 저장할 공간 이다. 좌표값이 실인수로 들어있다.
CPlayerPae SouthPae(40, 14), NorthPae(40, 4);//각 플레이어의 손패 좌표
bool SouthTurn;//내 턴은 참이다.

// 프로그램을 총지휘하는 main 함수
void main()
{
	int i, ch;//i는 반복제어변수 ch는 choice 즉 내가 던지거나 먹을 화투패를 택하는 것이다.
	int arSame[4], SameNum;
	char Mes[256];//상황지시문
	CPlayer* Turn;//플레이어의 턴을 나타내는 생성자
	CPlayerPae* TurnPae, * OtherPae;//내 턴의 패와 다른 사람 턴의 패
	int UserIdx, UserSel, DeckSel;//?
	SCard UserCard, DeckCard;//생성자 2개 만들어짐, 하나는 User의 카드패 나머지는 Deck의 카드패
	bool UserTriple, DeckTriple;//?
	int nSnatch;//담요에서 가져올 카드패의 인덱스를 기억할 변수
	int NewScore;//메인에서 새 점수를 담을 변수

	randomize();//랜덤함수
	Initialize();//초기화
	for (SouthTurn = true; !Deck.IsEmpty(); SouthTurn = !SouthTurn) {//나의 턴이고, 덱이 비어있지 않으면 내턴이 끝날때까지 아래 실행문을 하는 것이다.
		DrawScreen();//초기 뽑는 화면을 띄운다.
		if (SouthTurn) {//내턴이다.
			Turn = &South;//턴은 나의 턴이다.
			TurnPae = &SouthPae;//내턴에 나의 패를 가지고 있다.
			OtherPae = &NorthPae;//내턴에 상대는 상대의 패를 가지고 있다.
		}
		else {//상대턴이다.
			Turn = &North;//턴은 상대턴이다.
			TurnPae = &NorthPae;//상대턴에 상대는 상대의 패를 가지고 있다.
			OtherPae = &SouthPae;//상대턴에 나는 나의 패를 가지고 있다.
		}
		//sprintf 함수해석: 턴에 카드 값을 받아서 2번인자 구절의 변환문자에 대입하고 MES에 배열에 대입한다.
		sprintf(Mes, "내고 싶은 화투를 선택하세요(1~%d,0:종료) ", Turn->GetNum());
		ch = InputInt(Mes, 0, Turn->GetNum());//상황지시문이 나온다. 그리고 0을 누르면 종료고 내 턴에 상황에 해당하는 숫자를 선택할 수 있다.
		if (ch == 0) {//만약 0번 키보드를 선택했다면 
			if (InputInt("정말 끝낼겁니까?(0:예,1:아니오)", 0, 1) == 0)//다시 선택할 수 있는 기회다. 0을 누르면 선택 종료고 아니면 다시 내가 생각할 거다.
				return;
			else
				continue;
		}

		// 플레이어가 카드를 한장 낸다.
		UserTriple = DeckTriple = false;//논리값을 모두 거짓으로 초기화한다.
		UserIdx = ch - 1;//User인덱스는 선택 숫자에서 1만큼 감해준다.
		UserCard = Turn->GetCard(UserIdx);//User카드는 턴에서 카드를 받아와서 User의 인덱스를 실인수로 받고 카드의 정보를 가져오는 것이다.
		SameNum = Blanket.FindSameCard(UserCard, arSame);//같은 숫자라면 담요에서 같은 카드를 찾는다. 즉 내가 먹을 카드를 담요에서 찾는 것이다.
		switch (SameNum) {//담요에서 먹을 카드를 찾으면 선택하는 것.
		case 0:
			UserSel = -1;//유저가 선택한 카드인덱스에 -1을 선택한다.
			Blanket.InsertCard(Turn->RemoveCard(UserIdx));//담요에서 카드를 빼주고 화면에 출력한다.
			DrawScreen();//화면 출력
			break;
		case 1:
			UserSel = arSame[0];//같은 값을 지닌 배열값의 초기배열요소를 유저가 선택한 카드 인덱스에 대입한다.
			break;
		case 2:
			if (Blanket.GetCard(arSame[0]) == Blanket.GetCard(arSame[1])) {//담요의 카드가 담요의 카드가 같으면 즉, 덱에서 뽑은 게 담요꺼랑 같으면!
				UserSel = arSame[0];//유저가 선택한 카드인덱스에 카드인덱스가 같은 배열의 배열요소 첫번쨰 항을 대입한다.
			}
			else {
				Blanket.DrawSelNum(arSame);//담요에서 같은 카드가 뜨면 
				sprintf(Mes, "어떤 카드를 선택하시겠습니까?(1~%d)", SameNum);//먹을 카드를 선택하는 것이다.
				UserSel = arSame[InputInt(Mes, 1, SameNum) - 1];//유저가 선택할 기회를 준다.
			}
			break;
		case 3:
			UserSel = arSame[1];//유저가 선택한 카드 인덱스에 같은 값을 지닌 배열의 두번째 요소에 넣는다.
			UserTriple = true;//같은 게 3개면 설사다
			break;
		}
		if (UserSel != -1) {//만약 유저가 선택한 카드인덱스가 -1이 아니라면 
			Blanket.DrawTempCard(UserSel, UserCard);//담요에 유저가 선택한 인덱스의 카드가 던져지도록 출력한다.
		}
		delay(Speed);//1초 동안 이뤄지는 과정이다.

		// 데크에서 한장을 뒤집는다.
		Deck.Draw(true);//데크에서 한장 뽑는다.
		delay(Speed);//1초 딜레이를 준다.
		DeckCard = Deck.Pop();//스택자료구조다. 데크에서 한장이 뽑힌 값을 DeckCard에 대입한다.
		SameNum = Blanket.FindSameCard(DeckCard, arSame);//데크에서 뽑은게 같은 인덱스값이다? 그럼 담요에서 바로 먹어버린다. 아래에 그 경우에 대해 적혀져 있다.
		switch (SameNum) {//
		case 0:
			DeckSel = -1;//덱에서 선택한 값에 -1
			break;//반복문 탈출 ->덱에서 뽑은 카드가 담요에서 아무것도 같은 게 없을 때 상대턴으로 넘기는 것이다.
		case 1:
			DeckSel = arSame[0];//덱에서 뽑은 게 같다? 그럼 아래의 실행구문을 실행한다.
			if (DeckSel == UserSel) {//덱에서 뽑은 것과 유저가 선택한 것이 같을 경우
				if (Deck.IsNotLast()) {//덱이 마지막이 아니라면 
					Blanket.InsertCard(DeckCard);//담요에 카드를 넣어준다.
					Blanket.InsertCard(Turn->RemoveCard(UserIdx));//담요에 카드를 넣어주고 카드를 가져온다.
					OutPrompt("설사했습니다.", PromptSpeed);//상황지시문, 그리고 2초의 딜레이를 준다.
					continue;//그리고 반복문 점프함.
				}
				else {
					DeckSel = -1;//덱에서 뽑은 것과 유저가 선택한 카드인덱스가 같지 않으면 이 구문을 탈출
				}
			}
			break;
		case 2:
			if (UserSel == arSame[0]) {//유저가 선택한 것과 같은 것
				DeckSel = arSame[1];//덱에서 선택한 카드인덱스에 같은 카드의 두번째 배열 인덱스를 나타내라.
			}
			else if (UserSel == arSame[1]) {//유저가 선택한 게 2번째 배열요송와 같은것
				DeckSel = arSame[0];//덱에서 선택한 카드인덱스에 서로 같은 카드를 나타내는 배열의 처음 배열요소값을 대입하라
			}
			else {
				if (Blanket.GetCard(arSame[0]) == Blanket.GetCard(arSame[1])) {//담요에서 같은 게 존재한다? 그러면 재수가 좋은 것이다 그냥 먹는 것이다.
					DeckSel = arSame[0];//덱에서 선택한 카드인덱스에 서로 같은 카드를 나타내는 배열의 처음 배열요소값을 대입하라
				}
				else {
					Blanket.DrawSelNum(arSame);//담요에서 선택한 것을 넣는다.
					sprintf(Mes, "어떤 카드를 선택하시겠습니까?(1~%d)", SameNum);//담요에서 먹을 카드를 선택하라는 상황지시문
					DeckSel = arSame[InputInt(Mes, 1, SameNum) - 1];//덱에서 같은 거는 플레이어가 하나 먹었으니 논리적으로 없애줘야 맞다
				}
			}
			break;
		case 3:
			DeckSel = arSame[1];//덱에서 선택한 것에 서로같은 것을 나타내느 배열요소의 2번째 인자를 대입하라.
			DeckTriple = true;//덱 트리플은 설사인가? 잘 모르겠따.
			break;
		}
		if (DeckSel != -1) {//덱에서 선택한 것이 -1값이 아니라면
			Blanket.DrawTempCard(DeckSel, DeckCard);//담요에서 예비카드를 뽑는다.
		}
		Deck.Draw(false);//덱에서 드라우하는 것을 멈추고
		delay(Speed);//1초의 시간을 들여 시행한다.

		// 일치하는 카드를 거둬 들인다. 세 장을 먹은 경우는 전부 가져 온다.
		if (UserSel != -1) {//유저가 만약 선택한다면(어차피 흐름상 키보드에서 -1 골라치지는 않을 것이다. 그냥 자연수 칠 테니 음수로 논리를 유저가 선택하는 중이라고 하는 것이다.
			if (UserTriple) {//만약 트리플 떴다?
				for (i = 0; i < 3; i++) {
					TurnPae->InsertCard(Blanket.RemoveCard(UserSel - 1));//그럼 내턴에 모두 먹었으니까 담요에서 해당 카드가 사라지지
				}
			}
			else {
				TurnPae->InsertCard(Blanket.RemoveCard(UserSel));//아니면 담요에 넣어주는 것이다.
			}
			TurnPae->InsertCard(Turn->RemoveCard(UserIdx));//내턴의 패에 카드를 넣는다? 이거 뭔말인 지 모르겠다.
			if (DeckSel != -1 && DeckSel > UserSel) {//덱이 존재하고 덱의 카드 인덱스가 내 카드인덱스보다 높다?? 이것도 뭔말인지 모르겠따.
				DeckSel -= (UserTriple ? 3 : 1);//트리플 먹었다 이뜻인가?
			}
		}
		if (DeckSel != -1) {//계속 유저는 먹을 선택중이다.
			if (DeckTriple) {//트리플 떴다?
				for (i = 0; i < 3; i++) {//3번 먹을 거지? 그러니까 해당 반복구문을 3번 돌려주겠지
					TurnPae->InsertCard(Blanket.RemoveCard(DeckSel - 1));//내 턴에 카드를 넣는데 (담요에서 카드를 제거한다.) 덱에서 선택한 것도 제거한다.
				}
			}
			else {//트리플이 안떴다?
				TurnPae->InsertCard(Blanket.RemoveCard(DeckSel));//그냥 내패에서 담요로 패를 던진다.
			}
			TurnPae->InsertCard(DeckCard);//턴에 덱카드에 카드를 삽입한다.
		}
		else {
			Blanket.InsertCard(DeckCard);//담요에 카드를 덱에서 뽑은 거를 놓는다.
		}

		// 쪽, 따닥, 싹쓸이 조건을 점검하고 상대방의 피를 뺏는다.
		nSnatch = 0;//손맛이 최고지 이거는 슥 가져오는 거를 말하는 것이다.
		if (Deck.IsNotLast()) {//덱이 마지막이 아니면 이거 실행해라
			if (UserSel == -1 && SameNum == 1 && DeckCard.GetNumber() == UserCard.GetNumber()) {//유저가 현재 턴을 종료안하고 덱에서 카드를 뽑았는데 담요에 바로 있다?
				nSnatch++;//0값을 하나 더해준다. 최종값 1 상대패에서 하나 가져온다.
				OutPrompt("쪽입니다.", PromptSpeed);//상황지시문을 출력한다.
			}
			if (UserSel != -1 && SameNum == 2 && DeckCard.GetNumber() == UserCard.GetNumber()) {//유저가 현재 턴을 종료안하고 같은 넘버를 2번째 가진 카드패가 덱에서 나왔다?
				nSnatch++;//0값을 하나 더해준다. 최종값 1 상대패에서 하나 가져온다.
				OutPrompt("따닥입니다.", PromptSpeed);//상황지시문을 출력한다.
			}
			if (Blanket.GetNum() == 0) {
				nSnatch++;//0값을 하나 더해준다. 최종값 1 상대패에서 하나 가져온다.
				OutPrompt("싹쓸이입니다.", PromptSpeed);//상황지시문을 출력한다.
			}
			if (UserTriple || DeckTriple) {//유저가 트리플 뜨거나 덱에서 트리플 뜨거나
				OutPrompt("한꺼번에 세 장을 먹었습니다.", PromptSpeed);//그럼 상황지시문이 이렇게 나온다.
				nSnatch += UserTriple + DeckTriple;//유저트리플과 덱트리플을 더한 만큼 가져온다.
			}
		}
		for (i = 0; i < nSnatch; i++) {//가져온 회수만큼 반복문을 돌린다.
			TurnPae->InsertCard(OtherPae->RemovePee());//상대 손패 터는 거야
		}

		// 점수를 계산하고 고, 스톱 여부를 질문한다.
		NewScore = TurnPae->CalcScore();//점수 계산 때린 것을 새 점수값에 대입한다.
		if (Deck.IsNotLast() && NewScore > TurnPae->OldScore) {//덱이 마지막이 아니고, 내턴에 점수가 7점이상 났다?(OldScore는 6이다.)
			DrawScreen();//스크린 띄운다.
			if (InputInt("추가 점수를 획득했습니다.(0:스톱, 1:계속)", 0, 1) == 1) {//상황지시문
				TurnPae->OldScore = NewScore;//지난 스코어는 새스코어로 바뀌고, 이 점수 이상으로 점수가 또 나면 고 스톱을 때린다.
				TurnPae->IncreaseGo();//Go 횟수를 띄워준다.
			}
			else {
				break;//0치며 스탑
			}
		}
	}
	DrawScreen();//초기 디폴트 화면을 띄운다.
	OutPrompt("게임이 끝났습니다.", 0);//상황지시문
}

void Initialize()//초기화
{
	int i;//반복제어변수

	Deck.Shuffle();//덱을 셔플한다.
	for (i = 0; i < 10; i++) {//10번 셔플한다.
		South.InsertCard(Deck.Pop());//덱에서 뽑아서 나에게 카드를 던져준다.
		North.InsertCard(Deck.Pop());//덱에서 뽑아서 상대에게 카드를 던져준다.
		if (i < 8) Blanket.InsertCard(Deck.Pop());//만약 i가 8미만이라면 담요한테도 한장 던져준다.
	}
}

void DrawScreen()//뽑은 카드를 보여줄 화면이다.
{
	clrscr();//clrscr() 함수는 화면을 지우는 함수이고 이와 비슷한 역할을 하는 명령어를 실행하면 된다.
	South.Draw(SouthTurn);//내턴에 나는 카드를 뽑는다.
	North.Draw(!SouthTurn);//내턴이 아니면 상대는 카드를 뽑는다.
	Blanket.Draw();//담요한테도 한장 던져준다.
	Deck.Draw(false);//덱에서 한장 뽑는다.
	SouthPae.Draw();//내패에서 한장 뽑는다.
	NorthPae.Draw();//상대는 상대 패에서 한장 뽑는다.
}

void OutPrompt(const char* Mes, int Wait/*=0*/)
{
	gotoxy(5, 23);//5,23 콘솔 좌표로 이동한다.
	for (int i = 5; i < 79; i++) { cout << ' '; }//빈칸이다. 이것은 화면구성을 위한 것이다.
	gotoxy(5, 23);//다시 해당 콘솔 좌표로 이동한다.
	cout << Mes;//MES를 출력한다.
	delay(Wait);//약간의 딜레이를 주면서 화면을 구성하는 함수이다.
}

int InputInt(const char* Mes, int start, int end)//사용자가 숫자를 입력하면 자신이 보유한 화투패를 담요에 던지는 것이다.
{
	int ch;

	OutPrompt(Mes);//예외처리
	for (;;) {//영원히 돌려준다.
		ch = tolower(_getch());//키보드로 받아온 값을 모두 소문자로 내려준다.
		if (ch == 0xE0 || ch == 0) {//0xE0은 Hexa값으로 16진수를 의미한다. 10진수로는 224이다. 즉 마지막부터 초기값이라면 ch가 
			ch = _getch();//키보드에서 값을 받아온 것을 ch에 대입한다.
			continue;
		}
		if (!(isdigit(ch) || ch == 'a')) continue;//isdigit은 문자가 숫자임을 확인하는 함수이다. 만약 a값이거나 ch 값이 키보드 값이 아니라면 해당 반복문 횟수를 점프해서 반복문을 돌린다.
		if (ch == 'a') ch = 10; else ch = ch - '0';//a라면 ch 값에 10을 저장한다. 아니라면 ch 값에서 0문자를 빼준다.
		if (ch >= start && ch <= end) {//타이핑한 값이 중간이라면 
			return ch;//ch를 반환한다.
		}
		OutPrompt("무효한 번호입니다. 지정한 범위에 맞게 다시 입력해 주세요.");//예외처리사항
	}
}
