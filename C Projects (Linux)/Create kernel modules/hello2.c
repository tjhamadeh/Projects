#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int print2 __initdata = 2;

static int __init hello2_init(void)
{
  printk(KERN_INFO "Toufic Hamadeh: Loading Hello%d module - Hello World %d\n", print2, print2);
  return 0;
}

static void __exit hello2_exit(void)
{
  printk(KERN_INFO "Toufic Hamadeh: Exiting Hello2 module - Goodbye World 2\n");
}

module_init(hello2_init);
module_exit(hello2_exit);
