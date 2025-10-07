/*********************************************
 *Join:
 * Use function .joinable() to check if it can be joined
 * Double join can terminate the program
 * this will make sure thread is completed then only program turns off
 *
 *Detach:
 * Use function joinable to check if it is detachable
 * Double detach can terminate the program
 * this will detach from main thread
 * DETACH THREAD RUNS IN BACKGROUND TILL THE TIME MAIN THREAD IS IN PROGESS
 *
 *
 *
 * It is compulsory to call either one of them as on thread destructor if it is joinable than program is terminated
 * *****************************************/
 
#include <iostream>
#include <thread>

using namespace std;

void detachthread()
{
	cout<<"This is before of detach thread"<<endl;


	cout<<"This is after detach thread"<<endl;
}

void jointhread()
{
	cout<<"This is joined thread before"<<endl;
	this_thread::sleep_for(chrono::seconds(3));
	cout<<"This is joined after thread"<<endl;
}


int main()
{
	thread t1(jointhread);

	t1.join();

	thread t2(detachthread);
	t2.detach();
	return 0;
}
