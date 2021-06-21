# 멀티스레드(Multithread)를 왜 사용할까?
> 작성자 : [박재용](https://github.com/ggjae)
- 멀티코어 CPU에서의 프로그램 성능 향상을 위하여
- 멀티 CPU 컴퓨터, 병렬컴퓨터에서의 프로그램 성능 향상을 위하여

---

하나의 프로그램을 더 빠르게 돌리기 위해서 사용한다.  
10 FPS 게임을 20 FPS로 올리고 싶을 때, 처리량을 높이기 위하여 **멀티스레드** 프로그래밍을 한다.  

## 멀티코어 CPU란?

**한 개 이상의 코어**로 구성된 CPU. i3, i5, i7  
2021년 현재는 모든 것이 다 멀티코어 ex) Xbox, 닌텐도 스위치  

## **멀티코어 프로세서**를 만드는 이유?

CPU의 성능을 올려야하고, 클럭 속도를 높여야 한다. 하지만 클럭 속도를 높일 수 없음. 한계가 정해져 있다.  
=> 클럭 속도가 4GHz가 되면 컴퓨터가 타고, 우주가 그렇게 설계되어 있음  
4Ghz의 벽이라고도 한다. 사용하려면 실시간으로 액체질소를 들이부어야 함.  

남은 것은 멀티코어 뿐이였고, 싱글로는 도저히 안되니까 코어 개수로 싸우고 있다.  
듀얼코어 CPU 2개, 쿼드코어 CPU 1개 차이는 크지 않다.  

여러 코어가 늦게 개발된 이유는 프로그램을 다시 짜야하는 번거로움뿐만 아니라 디버깅도 어렵고 이미 작성한 알고리즘도 사용하지 못하기 때문이다.

게임에 대한 예시를 들어 보면, 스타크래프트1 은 싱글 스레드 프로그램으로서 듀얼코어에서도 똑같이 버벅거린다.  

## 코드 상 스레드의 개수와 코어의 개수는 일치하지 않아도 상관이 없는 이유?  

프로세스가 시분할로 돌아가면서 실행되듯 스레드도 시분할로 운영되어 중간에
다른 스레드가 실행될 수 있다.

## C++ 언어에 멀티스레드 라이브러리가 표준으로 존재

과거의 멀티스레드 프로그래밍 방법:
Window에서는 Win32 라이브러리에서 지원되는 API 사용했었고, 윈도우는 멀티스레드에 특화된 OS이고 리눅스는 pthread API를 사용하면 가능했다.

Windows에서의 thread =>  
프로세스의 하위 개념 프로세스는 처음 시작 시 한개의 스레드를 갖고 시작되고 운영체제가 직접 스케쥴링하게 된다.

## 병렬 프로그램

병렬 프로그램의 특징
- 실행된 프로세스 내부의 여러곳이 동시에 실행된다.
- 병렬로 실행되는 객체 사이의 동기화가 필수이다.(synchronization)
- **공유메모리 모델**과 메세지패싱 모델이 있다.

## 병렬 프로그램의 요구사항

- 정확성 : 다양한 흐름에서 동시다발적으로 호출해도 문제 없이 실행되는 알고리즘이 필요
- 성능 : Context 증가에 따른 성능 향상이 높아야 함

## 성능을 위하여 멀티스레드 프로그래밍을 하는가?

정답은 아니다. 게임은 성능이 중요하기 때문에 상관은 있지만 게임이 느리거나, 프로그램이 느리다면 성능 개선이 우선시 되어야 한다. 다양한 자료구조와 알고리즘을 통해서 성능개선을 진행해야 하고 최후의 보루로 멀티스레드 프로그래밍을 진행하여야 한다.  
**주의** 멀티스레드 프로그래밍을 하면 더 느려질지도 모른다.

## 멀티스레드 프로그래밍이 뭐야?

- 병렬 프로그래밍의 유일한 구현 수단
- 하나의 프로세스 안에서 여러개의 스레드를 실행시켜 병렬성을 얻는 프로그래밍 방법