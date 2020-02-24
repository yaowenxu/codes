#include <stdio.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <iostream>
using namespace std;

int main(){
	int epfd, nfds;
	struct epoll_event ev, events[5];
	epfd = epoll_create(1);
	ev.data.fd = STDOUT_FILENO;
	ev.events = EPOLLOUT|EPOLLET;
	epoll_ctl(epfd, EPOLL_CTL_ADD, STDIN_FILENO, &ev);
	for(;;){
		nfds = epoll_wait(epfd, events, 5, -1);
		for(int i =0; i < nfds; i++){
			if(events[i].data.fd == STDOUT_FILENO){
				cout << "welcome to epoll's world!";//<< endl;		
				//cout << (events[i].data.ptr) << endl;
				epoll_ctl(epfd, EPOLL_CTL_MOD, STDIN_FILENO, &ev);
			}
		}
	}
	return 0;
}
