obj-m += hello_mod.o
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
test:
	echo "testing: "
	dmesg -C 
	insmod hello_mod.ko
	rmmod hello_mod.ko
	dmesg -H 