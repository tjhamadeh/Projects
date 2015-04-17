#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/stat.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Toufic Hamadeh");

static char *myName = "Toufic Hamadeh";
static char *myStreet = "123 My Way";
static char *myCity = "North Newark";
static int myZip = 98765;

module_param(myName, charp, 0000);
MODULE_PARM_DESC(myName, "Name");
module_param(myStreet, charp, 0000);
MODULE_PARM_DESC(myStreet, "Street");
module_param(myCity, charp, 0000);
MODULE_PARM_DESC(myCity, "City");
module_param(myZip, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(myZip, "ZIP Code");

static int __init hello3_init(void)
{
  printk(KERN_INFO "Loading Hello 3: Hello World 3\n");
  printk(KERN_INFO "==============================\n");
  printk(KERN_INFO "Name: %s", myName);
  printk(KERN_INFO "Street: %s\n", myStreet);
  printk(KERN_INFO "City: %s\n", myCity);
  printk(KERN_INFO "ZIP code: %d\n", myZip);

  return 0;
}

static void __exit hello3_exit(void)
{
  printk(KERN_INFO "================================\n");
  printk(KERN_INFO "Exiting Hello 3: Goodbye World 3\n");
}

module_init(hello3_init);
module_exit(hello3_exit);
