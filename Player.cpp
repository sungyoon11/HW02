#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// 플레이어 클래스 정의
class Player {
    string name;  // 플레이어 이름
public:
    void setName(string name);  // 이름 설정 메서드
    string getName() { return name; }  // 이름 가져오는 메서드
};

// 갬블링 게임 클래스 정의
class GamblingGame {
    Player* p = new Player[2];  // 두 명의 플레이어를 위한 동적 배열 (포인터 사용)
public:
    GamblingGame();  // 생성자
    void nameSet();  // 플레이어 이름 설정 메서드
    string ranNum(string n);  // 랜덤 숫자를 생성하고 결과를 반환하는 메서드
    void startGame();  // 게임 시작 메서드
    ~GamblingGame() { delete[] p; }  // 소멸자: 동적 메모리 해제
};

// 생성자: 게임 시작 메시지 출력 및 랜덤 시드 초기화
GamblingGame::GamblingGame() {
    cout << "***** 갬블링 게임을 시작합니다. *****\n";
    srand(time(NULL));  // 현재 시간으로 랜덤 시드 설정
}

// 플레이어 이름 설정 메서드
void GamblingGame::nameSet() {
    string name;
    cout << "첫번째 선수 이름>> ";
    cin >> name;  // 첫 번째 플레이어 이름 입력
    p[0].setName(name);  // 첫 번째 플레이어 이름 설정
    cout << "두번째 선수 이름>> ";
    cin >> name;  // 두 번째 플레이어 이름 입력
    p[1].setName(name);  // 두 번째 플레이어 이름 설정
}

// 랜덤 숫자를 생성하고 승리 여부를 반환하는 메서드
string GamblingGame::ranNum(string n) {
    int r[3];  // 랜덤 숫자를 저장할 배열
    cout << "\t\t";
    for (int i = 0; i < 3; i++) {
        r[i] = rand() % 3;  // 0, 1, 2 중 랜덤 숫자 생성
        cout << r[i] << "\t";  // 랜덤 숫자 출력
    }
    // 모두 같은 숫자인 경우 승리
    if (r[0] == r[1] && r[0] == r[2]) {
        n += "님 승리!!";  // 승리 메시지 추가
        return n;  // 승리 메시지 반환
    }
    else {
        return "아쉽군요!";  // 패배 메시지 반환
    }
}

// 게임 시작 메서드
void GamblingGame::startGame() {
    string n;  // 플레이어의 입력을 저장할 변수
    int i = 0;  // 턴을 위한 인덱스
    while (true) {
        string m;  // 현재 플레이어 이름 저장
        cout << p[i % 2].getName() << "의 턴입니다:\n";  // 현재 플레이어의 턴 출력
        getline(cin, n);  // 플레이어의 입력을 기다림
        m = p[i % 2].getName();  // 현재 플레이어 이름 가져오기
        n = ranNum(n);  // 랜덤 숫자 생성 및 결과 저장
        // 승리 여부 확인
        if (n == "님 승리!!") {
            cout << m + n;  // 승리 메시지 출력
            break;  // 게임 종료
        }
        else {
            cout << n << endl;  // 패배 메시지 출력
        }
        i++;  // 턴 인덱스 증가
    }
}

// 플레이어 이름 설정 메서드
void Player::setName(string n) {
    name = n;  // 이름 설정
}

// 메인 함수
int main() {
    GamblingGame game;  // 게임 객체 생성
    game.nameSet();  // 플레이어 이름 설정
    game.startGame();  // 게임 시작
    return 0;  // 프로그램 종료
}