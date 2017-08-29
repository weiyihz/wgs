#include <linux/slab.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/fs.h>
#include <linux/errno.h>
#include <linux/mm.h>
#include <linux/sched.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <asm/io.h>
//#include <asm/system.h>
#include <asm/uaccess.h>

#include "memdev.h"





/*�ļ��򿪺���*/ 
int mem_open(struct inode *inode, struct file *filp) 
{
    
    
	/*��ȡ���豸�� */ 
    int num = MINOR(inode->i_rdev);
    
	
    
    
	/*���豸�����ṹָ�븳ֵ���ļ�˽������ָ�� */ 
	filp->private_data = dev;
    



/*�ļ��ͷź���*/ 
int mem_release(struct inode *inode, struct file *filp) 
{
    



/*������*/ 
static ssize_t mem_read(struct file *filp, char __user * buf, size_t size,
			loff_t * ppos) 
{
    
    
    
    
    
	/*�ж϶�λ���Ƿ���Ч */ 
	if (p >= MEMDEV_SIZE)
	
    
	
    
	/*�����ݵ��û��ռ� */ 
	if (copy_to_user(buf, (void *) (dev->data + p), count))
	
	
	
    
    else
	
	
	
	
	
    



/*д����*/ 
static ssize_t mem_write(struct file *filp, const char __user * buf,
			 size_t size, loff_t * ppos) 
{
    
    
    
    
    
	/*�����ͻ�ȡ��Ч��д���� */ 
	if (p >= MEMDEV_SIZE)
	
    
	
    
	/*���û��ռ�д������ */ 
	if (copy_from_user(dev->data + p, buf, count))
	
    
    else
	
	
	
	
	
    



/* seek�ļ���λ���� */ 
static loff_t mem_llseek(struct file *filp, loff_t offset, int whence) 
{
    
    
    
	
	
    
	
	
    
	
	
    
	
    
    
	
    
    



/*�ļ������ṹ��*/ 
static const struct file_operations mem_fops = 
    { 
mem_read, 
};


/*�豸����ģ����غ���*/ 
static int memdev_init(void) 
{
    
    
    
    
	/* ��̬�����豸�� */ 
	if (mem_major)
	
    
    else			/* ��̬�����豸�� */
	
	
	
	
    
	
    
	/*��ʼ��cdev�ṹ */ 
	cdev_init(&cdev, &mem_fops);
    
    
    
	/* ע���ַ��豸 */ 
	cdev_add(&cdev, MKDEV(mem_major, 0), MEMDEV_NR_DEVS);
    
	/* Ϊ�豸�����ṹ�����ڴ� */ 
	mem_devp =
	kmalloc(MEMDEV_NR_DEVS * sizeof(struct mem_dev), GFP_KERNEL);
    
	
	
	
	
    
    
	/*Ϊ�豸�����ڴ� */ 
	for (i = 0; i < MEMDEV_NR_DEVS; i++)
	
	
	
	
	
    
  
    



/*ģ��ж�غ���*/ 
static void memdev_exit(void) 
{
    
    
    





