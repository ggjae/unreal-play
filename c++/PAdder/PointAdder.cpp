#include <iostream>
using namespace std;

typedef struct {
    int xpos;
    int ypos;
} Point;

Point& PntAdder(const Point &p1, const Point &p2){
    Point * pptr = new Point; // pptr 메모리 할당
    pptr->xpos = p1.xpos+p2.xpos; // 더해주기. pptr은 포인터고  p1, p2는 참조값이니
    pptr->ypos = p1.ypos+p2.ypos;
    return *pptr; // 포인트의 참조값을 전달해준 것. 메인에서 받을 애가 있어야겠다.유추가능
}
int main(){
    Point *pptr1 = new Point;
    pptr1->xpos = 3;
    pptr1->ypos = 30;

    Point *pptr2 = new Point;
    pptr2->xpos = 70;
    pptr2->ypos = 7;
    Point& pref = PntAdder(*pptr1,*pptr2);

    cout << pref.xpos << pref.ypos << endl;
    // 헷갈리지 말아야 할 것. 참조자(&)는 두가지 역할이 있어.
    // 선언된 변수 앞에 오는 &는 주소 값의 반환을 명령하지만,
    // 새로 선언되는 변수의 이름 앞에 등장하면 참조자의 선언이라고

    delete pptr1;
    delete pptr2;
    delete &pref;

    return 0;
}