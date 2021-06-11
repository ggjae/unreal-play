#include <iostream>
#include <time.h>
#include <cmath>
using namespace std;
int main(){
    srand((unsigned int) time(0));
    int num[9] = {1,2,3,4,5,6,7,8,9};
    for(int i=0;i<100;i++){
        int tmp1, tmp2, tmp3;
        tmp1 = rand()%10;
        tmp2 = rand()%10;

        tmp3 = num[tmp1];
        num[tmp1] = num[tmp2];
        num[tmp2] = tmp3;
    }
    int ans[3] = {num[0], num[1], num[2]};
    int input[3];
    int tmpinput;
    while(true){
        int strk=0;
        int ball=0;
        int p = 2;
        bool out = false;
        cin >> tmpinput;
        for(int i=0;i<3;i++){
            input[i] = (tmpinput / pow(10,p--));
            input[i] = input[i] % 10;
            // printf("%d", input[i]);
            if(ans[i] == input[i]){
                strk++;
            }
        }
        // printf("정답은 %d %d %d 입니다", ans[0],ans[1],ans[2]);
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(ans[i] == input[j] && i != j) ball++;
            }
        }
        if(strk == 3) printf("끝났습니다!\n");
        else if ( strk > 0 || ball > 0 ){
            printf("%d 스트라이크 , %d 볼 입니다.\n",strk,ball);
        } else {
            printf("3 OUT !\n");
        }
        
    }
    return 0;
}