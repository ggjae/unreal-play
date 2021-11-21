#include <iostream>
#include <cstring>
using namespace std;
const int NAME_LEN = 20;

void ShowMenu();
void MakeAccount();
void DepositMoney();
void WithdrawMoney();
void ShowAllAccInfo();

enum {Make=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};
typedef struct {
    int addr;
    char cusName[NAME_LEN];
    int remain;
} Account;

Account accArr[100];
int accNum = 0;

int main(){
    int choice;
    while(1){
        ShowMenu();
        cout << "����";
        cin >> choice;
        cout << endl;

        switch(choice){
            case Make:
                MakeAccount();
                break;
            case DEPOSIT:
                DepositMoney();
                break;
            case WITHDRAW:
                WithdrawMoney();
                break;
            case INQUIRE:
                ShowAllAccInfo();
                break;
            case EXIT:
                return 0;
            default:
                cout << "Illegal Selection." << endl;
        }
    }
    return 0;
}
void ShowMenu(){
    cout << "-----Menu-----" << endl;
    cout << "1. ���� ����" << endl;
    cout << "2. �� ��" << endl;
    cout << "3. �� ��" << endl;
    cout << "4. ���� ���� ���" << endl;
    cout << "5. ���α׷� ����" << endl;
}
void MakeAccount(){
    int id;
    char name[NAME_LEN];
    int remain;

    cout << "[���°���]" << endl;
    cout << "���� ID : "; cin >> id;
    cout << "�̸� : "; cin >> name;
    cout << "�Աݾ� : "; cin >> remain;
    cout << endl;

    accArr[accNum].addr = id;
    accArr[accNum].remain = remain;
    strcpy(accArr[accNum].cusName, name);
    accNum++;
}

void DepositMoney(){
    int money;
    int id;
    cout << "[�� ��]" << endl;
    cout << "���� ID : "; cin >> id;
    cout << "�Աݾ�"; cin >> money;

    for(int i=0;i<accNum;i++){
        if(accArr[i].addr == id){
            accArr[i].remain += money;
            cout << "�Ա� �Ϸ�" << endl;
            return;
        }
    }
    cout << "��ȿ���� ���� ID �Դϴ�" << endl;
}

void WithdrawMoney(){
    int money;
    int id;
    cout << "[�� ��]" << endl;
    cout << "���� ID : "; cin >> id;
    cout << "��ݾ� : "; cin >> money;
    for(int i=0;i<accNum;i++){
        if(accArr[i].addr == id){
            if(accArr[i].remain < money){
                cout << "�ܾ׺���" << endl;
                return;
            }
            accArr[i].remain -= money;
            cout << " ��� �Ϸ� " << endl;
            return;
        }
    }
    cout << "��ȿ���� ���� ID �Դϴ�." << endl;
}
void ShowAllAccInfo(){
    for(int i=0;i<accNum;i++){
        cout << " ���� ID : " << accArr[i].addr<<endl;
        cout << " �� �� : " << accArr[i].cusName << endl;
        cout << " �� �� : " << accArr[i].remain << endl ;
    }
}