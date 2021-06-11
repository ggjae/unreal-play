#include <iostream>
#include <time.h>

using namespace std;
int main(){
    int iLotto[45] = {};
    srand((unsigned int) time(0));
    for(int i=0;i<45;i++){
        iLotto[i] = i+1;
    }
    int iTemp, idx1, idx2;
    // shuffle
    
    for(int i=0;i<100;i++){
        idx1 = rand() % 45;
        idx2 = rand() % 45;

        iTemp = iLotto[idx1];
        iLotto[idx1] = iLotto[idx2];
        iLotto[idx2] = iTemp;
    }
    for(int i=0;i<6;i++){
        printf("%d ", iLotto[i]);
    }
    printf("bonus : %d",iLotto[6]);
    printf("\n");
    return 0;
}