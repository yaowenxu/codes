obj-m += hello.o
obj-m += hello-packet.o

# linux kernel 变化了，很多跟随的内核接口也跟着变化了，所以下面几个模块，在 5.0版本下的内核上编译不通过；
# 这也意味着有些内核的代码要进行移植；
# obj-m += rootkit.o
obj-m += rockroll.o
# obj-m += excited_virus.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
