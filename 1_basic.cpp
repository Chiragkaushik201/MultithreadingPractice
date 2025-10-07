/*Default thread: Main thread()
 * Under that multiple light weight process called threads are created. Thread helps in implemneting parallelism
 *
 * Ways to create thraed:
 * Function pointer
 * Lmabda function
 * Functor 
 * Member function
 * Static member function
 *
 * NOTES:
 * all thread uses common resources.
 * Each thread has its own stack
 *
 * *********************************************************************************************************/


#include<iostream>
#include<thread>

using namespace std;
/******************************************/
void threadfunc(int a)
{

	cout<<"This is thread:"<<a<<endl;
}


/************************FUNCTION POINTER******************************************************************/
void thread_functionpointer(int a)
{
	thread t1(threadfunc,a);
	t1.join();// important otherwise program will terminate: wait for this t1 thraed to complete then will move forward
}

/*************************LAMBDA FUNCTION*******************************************************************/
void thread_lambdafunc(int a)
{
	auto lambda_thread = [](int x)
	{
		cout<<"This is thread from lambda function:"<<x<<endl;
	};

	thread t1(lambda_thread,a);
	t1.join();
}

/**************************FUNCTOR (FUNCTION OBJECT)**********************************************************/
class thread_class
{
	public:

	void operator()(int x)
	{
		cout<<"This is thread class:"<<x<<endl;
	}
};

void thread_functor(int x)
{
	thread t1(thread_class(),x);

	t1.join();
}
/********************Non static member function**************************************************************/
class thread_class_non_static
{

	public:
		void function(int x)
		{
			cout<<"This is class thread non static function:"<<x<<endl;
		}
};

void thread_nonstatic_function(int x)
{
	thread_class_non_static obj;

	thread t1(&thread_class_non_static::function,&obj,x);
	t1.join();

}

/************************Static member function of class*************************************************/
class thread_static_functionclass
{
	public:
	static void function(int a)
	{
		cout<<"This is static member function of class:"<<a<<endl;
	}
};

void thread_static_member_func(int a)
{
	thread t1(&thread_static_functionclass::function,a);
	t1.join();

}

int main()
{
	thread_functionpointer(0);
	thread_lambdafunc(1);
	thread_functor(2);
	thread_nonstatic_function(3);
	thread_static_member_func(4);
	return 0;
}
