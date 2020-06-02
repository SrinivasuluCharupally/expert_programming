// Call In Order: Suppose we have the following code:public class Foo {public Foo() { ... }public void first() { ... } 
public void second() { ... } 
public void third() { ... }}The same instance of Foo will be passed to three different threads. ThreadA will call first threadB will call second, and thread( will call third. Design a mechanism to ensure that first is called be re second and second is called before third.



#include<iostream>
#include<pthread.h>
using namespace std;

pthread_mutex_t mvar[3] = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cvar[3] = PTHREAD_COND_INITIALIZER;

class foo {
	int controller;
  public:
	foo() : controller(0) {}
	void set_value(int i) { controller = i; }
	int get_value() { return controller; }
	void first() {
	        //pthread_mutex_lock(mvar+tid);
		
		cout << "i am first" << endl;
	}

	void second() {
		cout << "i am second" << endl;
	}

	void third() {
		cout << "i am third" << endl;
	}

};
typedef struct args { // if you want to pass mutiple args then use struct
        foo *f;
        int id;
 }args_t;

void* thread_fun(void* args) {
	args_t local_args = *(args_t*)args;

	int tid = local_args.id;
	foo* local_f = local_args.f;
	
	while(local_f->get_value() != tid) { //pthread_cond_wait(cvar+tid, mvar+tid);
	} 
                if(local_f->get_value() == 0) local_f->first();
                if(local_f->get_value() == 1) local_f->second();
                if(local_f->get_value() == 2) local_f->third();
	pthread_mutex_lock(mvar+tid);
		local_f->set_value(tid+1);
	pthread_mutex_unlock(mvar+tid);
	//pthread_cond_signal(cvar+tid);
	pthread_exit(0);
}

int main() {
	pthread_t thread_id[3];
	foo obj;
	args_t args[3];
	args[0].id = 0; args[0].f = &obj;
	args[1].id = 1; args[1].f = &obj;
	args[2].id = 2; args[2].f = &obj;
	
	pthread_create(&thread_id[0], NULL, thread_fun, &args[0]);
        pthread_create(&thread_id[1], NULL, thread_fun, &args[1]);
        pthread_create(&thread_id[2], NULL, thread_fun, &args[2]);

	pthread_join(thread_id[0], NULL);
	pthread_join(thread_id[1],NULL);
	pthread_join(thread_id[2],NULL);

}
