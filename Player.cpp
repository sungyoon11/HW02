#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// �÷��̾� Ŭ���� ����
class Player {
    string name;  // �÷��̾� �̸�
public:
    void setName(string name);  // �̸� ���� �޼���
    string getName() { return name; }  // �̸� �������� �޼���
};

// ���� ���� Ŭ���� ����
class GamblingGame {
    Player* p = new Player[2];  // �� ���� �÷��̾ ���� ���� �迭 (������ ���)
public:
    GamblingGame();  // ������
    void nameSet();  // �÷��̾� �̸� ���� �޼���
    string ranNum(string n);  // ���� ���ڸ� �����ϰ� ����� ��ȯ�ϴ� �޼���
    void startGame();  // ���� ���� �޼���
    ~GamblingGame() { delete[] p; }  // �Ҹ���: ���� �޸� ����
};

// ������: ���� ���� �޽��� ��� �� ���� �õ� �ʱ�ȭ
GamblingGame::GamblingGame() {
    cout << "***** ���� ������ �����մϴ�. *****\n";
    srand(time(NULL));  // ���� �ð����� ���� �õ� ����
}

// �÷��̾� �̸� ���� �޼���
void GamblingGame::nameSet() {
    string name;
    cout << "ù��° ���� �̸�>> ";
    cin >> name;  // ù ��° �÷��̾� �̸� �Է�
    p[0].setName(name);  // ù ��° �÷��̾� �̸� ����
    cout << "�ι�° ���� �̸�>> ";
    cin >> name;  // �� ��° �÷��̾� �̸� �Է�
    p[1].setName(name);  // �� ��° �÷��̾� �̸� ����
}

// ���� ���ڸ� �����ϰ� �¸� ���θ� ��ȯ�ϴ� �޼���
string GamblingGame::ranNum(string n) {
    int r[3];  // ���� ���ڸ� ������ �迭
    cout << "\t\t";
    for (int i = 0; i < 3; i++) {
        r[i] = rand() % 3;  // 0, 1, 2 �� ���� ���� ����
        cout << r[i] << "\t";  // ���� ���� ���
    }
    // ��� ���� ������ ��� �¸�
    if (r[0] == r[1] && r[0] == r[2]) {
        n += "�� �¸�!!";  // �¸� �޽��� �߰�
        return n;  // �¸� �޽��� ��ȯ
    }
    else {
        return "�ƽ�����!";  // �й� �޽��� ��ȯ
    }
}

// ���� ���� �޼���
void GamblingGame::startGame() {
    string n;  // �÷��̾��� �Է��� ������ ����
    int i = 0;  // ���� ���� �ε���
    while (true) {
        string m;  // ���� �÷��̾� �̸� ����
        cout << p[i % 2].getName() << "�� ���Դϴ�:\n";  // ���� �÷��̾��� �� ���
        getline(cin, n);  // �÷��̾��� �Է��� ��ٸ�
        m = p[i % 2].getName();  // ���� �÷��̾� �̸� ��������
        n = ranNum(n);  // ���� ���� ���� �� ��� ����
        // �¸� ���� Ȯ��
        if (n == "�� �¸�!!") {
            cout << m + n;  // �¸� �޽��� ���
            break;  // ���� ����
        }
        else {
            cout << n << endl;  // �й� �޽��� ���
        }
        i++;  // �� �ε��� ����
    }
}

// �÷��̾� �̸� ���� �޼���
void Player::setName(string n) {
    name = n;  // �̸� ����
}

// ���� �Լ�
int main() {
    GamblingGame game;  // ���� ��ü ����
    game.nameSet();  // �÷��̾� �̸� ����
    game.startGame();  // ���� ����
    return 0;  // ���α׷� ����
}