#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int hello1_init(void)
{
  printk(KERN_INFO "Toufic Hamadeh: Loading Hello1 module - Hello World 1.\n");
  return 0;
}

static void hello1_exit(void)
{
  printk(KERN_INFO "Toufic Hamadeh: Exiting Hello1 module - Goodbye World 1.\n");
}

module_init(hello1_init);
module_exit(hello1_exit);
