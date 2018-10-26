#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/slab.h>
#include "mem_layout.h"

static int mem_size = 32;
module_param(mem_size, int, S_IRUGO);

static int head_size = 32;
module_param(head_size, int, S_IRUGO);

static int foot_size = 64;
module_param(foot_size, int, S_IRUGO);

static char *buf;

static int __init my_test_init(void)
{
	printk("greenricky: init\n");
	buf = kmalloc(mem_size, GFP_KERNEL);
	printk("===============kmalloc=================\n");
	print_mem_detail(buf, head_size, mem_size, foot_size);
	
	memset(buf, 0x57, mem_size);	
	printk("\n===============memset buf to 0x57======\n");
	print_mem_detail(buf, head_size, mem_size, foot_size);
	
	//left red_zone
	*(buf-1) = 0x88;
	*(buf-2) = 0x88;

	kfree(buf);
	printk("\n===============free buf====================\n");
	print_mem_detail(buf, head_size, mem_size, foot_size);

	return 0;
}

static void __exit my_test_exit(void)
{
	printk("greenricky: exit\n");
}

MODULE_LICENSE("GPL");
module_init(my_test_init);
module_exit(my_test_exit);
