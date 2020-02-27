# 设置模块名称
NAME := device_mod
obj-m += $(NAME).o
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
# 测试模块
test: clean all
	echo "测试："$(NAME).ko
	rmmod $(NAME).ko
	dmesg -C 
	insmod $(NAME).ko
	dmesg -H 