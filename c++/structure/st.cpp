#include <iostream>
using namespace std;
#define NAME_SIZE 32
// 구조체 : 관련있는 변수들을 모아서 하나의 새로운 타입을 만들어주는 기능
// 배열과 구조체의 공통점 ?
// 데이터 집합. 연속된 메모리 블럭에 할당됩니다.
struct _tagStudent{
    char strName[NAME_SIZE];
    int number;
    int kor;
    int eng;
    int math;
    int total;
    float avg;
}; // 하나가 32 + 4 * 6 => 56바이트 
int main(){
    _tagStudent tstudent = {};
    _tagStudent tstudentArr[100] = {};
    // 구조체 멤버 접근시에는 . 을 이용해서 접근하게 된다.
    tstudent.kor = 100;
    // tstudent.strName = "why"; 에러가 뜨더라..

    // 문자열을 배열에 넣어줄 때에는 단순 대입으로 불가능합니다.
    // strcpy_s를 사용해서 문자열 복사할 것
    // 문자열의 끝은 항상 null로 끝나야 한다.
    // 넣어주지 않은 부분은 쓰레기값으로 그대로 출력 될 것이다.

    strcpy_s(tstudent.strName, "정희재");

    strcat_s(tstudnet.strName, "야미");
    // 오른쪽에 있는 문자열을 왼쪽에 붙여준다.
    
    return 0;
}