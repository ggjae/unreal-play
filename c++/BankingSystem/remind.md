remind

const int num = 10;
// 변수 num 상수화
const int * ptr1 = &val1;
// 포인터 ptr1을 이용해서 val1의 값을 변경할 수 없다
int * const ptr2 = &val2;
//  포인터 ptr2 가 상수화
const int * const ptr3 = &val3;
// ptr3이 상수화 되었으며, ptr3을 이용하여 val3의 값을 변경할 수 없다

데이터 - 전역변수가 저장되는 영역
스택 - 지역변수 및 매개변수가 저장되는 영역
힙 - malloc 함수 호출에 의해 프로그램 런타임 중 동적할당이 이뤄지는 영역
malloc free - 멀록 함수호출에 의해 할당된 메모리공간은 free 함수 호출을 통해서 소멸하지 않으면 해제되지 않는다.

call by reference, call by value 차이

변수란 뭐야?
변수란, 메모리 공간에 이름을 붙인거야.
그 이름을 통해서 해당 메모리 공간에 접근도 할 수 있어.

int &num2 = num1;
이 문장을 실행하면, num1 이라는 메모리 공간에 num2이라는 이름이 하나 더 붙게 돼

& 연산자는 변수의 주소값을 반환하는 연산자인데, 선언된 변수 앞에 이 연산자가 오면 => 주소 값의 반환을 명령하지만,
새로 선언되는 변수 이름 앞에 등장하면. **참조자** 의 선언을 뜻함.

그럼, 참조자랑 변수의 차이점이 뭔데?
참조자는 자신이 참조하는 변수를 대신할 수 있는 또 다른 이름.(닉네임)인거야!!

참조자랑 포인터가 다른 것: 포인터는 null값 체크 해줘야 하는데, 참조자는 null 일 수 없다.


그리고 포인터는 **주소값을 할당**하지만, **참조자는 대상**을 직접 할당하잖아.

int main(void)
{
    int num = 12;
    int * ptr = &num;
    int **dptr = &ptr;

    int &ref = num;
    int *(&pref) = ptr;
    int **(&dpref) = dptr;

    cout << ref;
    cout << *pref;
    cout << **dpref;
}

int Adder(const int &num1, const int &num2){
    ;
}
이 때, num1 과 num2는 임시 변수. Adder(1,2)로 쓸 수 있는거지.
처음에 참조자는 상수에 할당 못한다며, 근데 const를 쓰는 경우엔 돼.
생각해봐.. 더하기 위해서 변수에 값 넣어서 변수로 Adder(변수1,변수2) 넣어주는 게 너무 번거로운 일이잖아.

