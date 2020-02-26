//必要的头文件
#include <linux/module.h> // included for all kernel modules
#include <linux/kernel.h> // include for KERN_INFO
#include <linux/init.h> // include for __init and __exit macros
//模块许可证声明（必须）
MODULE_LICENSE("Dual BSD/GPL"); // 通常使用BSD 和 GPL 双协议
//声明模块的作者（可选）
MODULE_AUTHOR("Yaowen Xu");
MODULE_AUTHOR("YaoXu");
MODULE_DESCRIPTION("This is a simple example!");
MODULE_ALIAS("A simplest example");
//模块加载函数（必须）
static int hello_init(void)
{
    printk(KERN_ALERT "Hello World enter/n");
    return 0;
}
//模块卸载函数（必须）
static void hello_exit(void)
{
    printk(KERN_ALERT "Hello World exit/n");
}
//模块的注册
module_init(hello_init);
module_exit(hello_exit);