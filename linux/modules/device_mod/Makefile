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
# 使用 mknod 进行挂载测试：
# sudo mknod /dev/yaoxu c MAJOR 0 # Major 处替换成dmesg输出
# cat /dev/yaoxu 进行测试； rm /dev/yaoxu 进行删除；