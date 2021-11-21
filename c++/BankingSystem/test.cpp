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
        cout << "선택";
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
    cout << "1. 계좌 개설" << endl;
    cout << "2. 입 금" << endl;
    cout << "3. 출 금" << endl;
    cout << "4. 계좌 정보 출력" << endl;
    cout << "5. 프로그램 종료" << endl;
}
void MakeAccount(){
    int id;
    char name[NAME_LEN];
    int remain;

    cout << "[계좌개설]" << endl;
    cout << "계좌 ID : "; cin >> id;
    cout << "이름 : "; cin >> name;
    cout << "입금액 : "; cin >> remain;
    cout << endl;

    accArr[accNum].addr = id;
    accArr[accNum].remain = remain;
    strcpy(accArr[accNum].cusName, name);
    accNum++;
}

void DepositMoney(){
    int money;
    int id;
    cout << "[입 금]" << endl;
    cout << "계좌 ID : "; cin >> id;
    cout << "입금액"; cin >> money;

    for(int i=0;i<accNum;i++){
        if(accArr[i].addr == id){
            accArr[i].remain += money;
            cout << "입금 완료" << endl;
            return;
        }
    }
    cout << "유효하지 않은 ID 입니다" << endl;
}

void WithdrawMoney(){
    int money;
    int id;
    cout << "[출 금]" << endl;
    cout << "계좌 ID : "; cin >> id;
    cout << "출금액 : "; cin >> money;
    for(int i=0;i<accNum;i++){
        if(accArr[i].addr == id){
            if(accArr[i].remain < money){
                cout << "잔액부족" << endl;
                return;
            }
            accArr[i].remain -= money;
            cout << " 출금 완료 " << endl;
            return;
        }
    }
    cout << "유효하지 않은 ID 입니다." << endl;
}
void ShowAllAccInfo(){
    for(int i=0;i<accNum;i++){
        cout << " 계좌 ID : " << accArr[i].addr<<endl;
        cout << " 이 름 : " << accArr[i].cusName << endl;
        cout << " 잔 액 : " << accArr[i].remain << endl ;
    }
}