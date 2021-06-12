#include <iostream>
#include <thread>
int sum;
void do_work(){
    for(auto i =0;i<50000000;i++) sum+=2;
}

using namespace std;
int main(){
    // thread t1{f}; // 분리된 thread가 f를 실행시킨다
    // t1.join(); // t1을 끝낼때까지 기다리기.
    // // f가 리턴하면 종료되겠지?
    while (1){
        sum =0;
        thread t1{do_work};
        thread t2{do_work};
        printf("sum = %d",sum);
    }
    system("pause");
    return 0;
}