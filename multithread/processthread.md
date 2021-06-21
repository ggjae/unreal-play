# 프로세스와 스레드
> 작성자 : [박재용](https://github.com/ggjae)
- 프로세스와 스레드가 무엇인지 이해하기
- 스레드와 프로세스를 구분해보기

---

## 프로세스란?

운영체제가 관리하는 프로그램의 단위  
실행파일을 실행하는 것이 곧 프로세스를 만드는 것. 실행파일의 실행은 운영체제가 파일을 읽어서 메모리에 복사해두고 시작 주소로 점프하는 것. 멀티코어가 아니더라도 여러개의 프로그램이 동시에 실행된다.  

프로세스의 메모리 구조  

- Code : 실행될 명령어가 들어가는 구역
- Data : 전역 변수가 들어가는 구역
- Stack : 지역변수와 함수 리턴 주소가 들어가는 구역
- Heap : malloc이나 New로 할당받은 메모리가 들어가는 구역
- PCB : Process Control Block

프로세스는 내부적으로 성격에 따라 여러개의 구역으로 나누어서 관리를 하는 것을 **세그먼트**라 한다.  

## 스레드란?

프로그램 내에서의 실행되는 흐름의 단위  
프로세스의 부분집합이다. 모든 스레드는 자신 고유의 스택을 가지고 있고 Data, Heap, Code 영역은 다른 스레드와 공유하게 된다.

한 프로그램에서의 여러개의 스레드를 사용한다면 코드와 데이터 힙 영역은 스레드간 공유가 된다. 똑같은 메모리를 같이 사용하고 한 장소에 있는 것을 자식과 부모가 같이 사용한다고 생각하면 된다.

---

## 프로세스와 스레드 관련

- 스택영역만 새로 하나 파주면 되기 때문에 스레드는 생성 시 overhead가 프로세스보다 작다. 
- 캐시 미스가 비교적 적게 일어나기 때문에 스레드는 Context Switching 비용의 overhead가 프로세스보다 적다. 
- 스레드간의 통신이 프로세스간의 통신보다 간단하다. 프로세스간의 통신은 overhead가 큼
- 하나의 스레드에서 발생한 문제가 전체 프로세스를 멈추게 한다.
- 하나의 프로그램에서 여러군데가 동시에 실행되므로 스레드의 경우 디버깅이 너무나도 어렵다.

