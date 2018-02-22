#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/module.h>

asmlinkage int print_self (void)
{
	struct task_struct *task;

	for(task = current;task != &init_task;task=task->parent)
	{
		printk(KERN_EMERG "Name:[%s]  PID:[%d]  State[%ld] \n",
			task->comm,task->pid,task->state);
	}

	return 0;
}
