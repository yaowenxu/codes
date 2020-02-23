#include <iostream>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
using namespace std;
int main(){
	cout << "tid: " << syscall(SYS_gettid) << " " << (pthread_self()) << endl;
	cout << "pid: " << syscall(SYS_getpid) << endl;
	cout << "cpusize: " << CPU_SETSIZE << endl; 
	return 0;
}
