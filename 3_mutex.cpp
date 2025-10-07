/***************************************************
 *MUTEXES:
 *	for resolving race conditions 
 *	it locks the critical section where resources are manipulated
 *
 *RACE CONDITION:
 *	When two threads manipulate common resources then updation is not correct
 *	
 * **************************************************/

#include<iostream>
#include<mutex>
#include<thread>


using namespace std;
mutex m1;
mutex m2;

void thread_func1()
{
	m1.lock();
	cout<<"this is thread func1:"<<endl;
}
int main()
{
	
	return 0;
}
