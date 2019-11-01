#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

int my_init(void)
{
    printk(KERN_INFO "test printk");
    return 0;
}

void my_cleanup(void)
{
    printk(KERN_INFO "unload test printk");
}

module_init(my_init);
module_exit(my_cleanup);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("zishen");
MODULE_DESCRIPTION("a test module");
MODULE_SUPPORTED_DEVICE("no device");
