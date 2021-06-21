#include <iostream>
#include <mutex> 
#include <thread>
#include <vector>
#include <chrono>
#include <string>

using namespace std;

int main()
{
	const int num_pro = std::thread::hardware_concurrency();

	cout << std::this_thread::get_id() << endl; // main thread ID

	std::thread t1 = std::thread([]()
	{
		cout << std::this_thread::get_id() << endl; // thread t1 ID
	});

	
	t1.join();  // join은 스레드 종료까지 대기하는 함수 대기하지않으면 main 함수에의해 종료된다.
}
