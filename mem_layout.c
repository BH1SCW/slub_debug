#include <linux/kernel.h>

void print_layout(char *addr, int len)
{
	int i = 0;
	if(NULL==addr || len <1)
		return;

	//print addr of each 16 bytes
	while(i < len)
	{
		if(0 == i%16)
			printk("%p: ", addr);

		printk("%02x ", *addr);

		if(15 == i%16)
			printk("\n");

		i++;
		addr++;
	}
}

void print_mem_detail(char *addr, int head_size, int buf_size,int foot_size)
{
	if(NULL==addr || head_size<0 || buf_size<0 || foot_size<0)
		return;

	printk("---Ahead  %d bytes---\n", head_size);
	print_layout(addr-head_size, head_size);
	
	printk("---Buf    %d bytes---\n", buf_size);
	print_layout(addr, buf_size);

	printk("---Footer %d bytes---\n", foot_size);
	print_layout(addr+buf_size, foot_size);
}
