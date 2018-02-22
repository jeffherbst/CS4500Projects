#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/module.h>


asmlinkage int print_other (pid_t findPID)
{
	struct task_struct *task;
	struct task_struct *thisTask;

	task = pid_task(find_vpid(findPID), PIDTYPE_PID);
	
	if(task != NULL)
	{
		for(thisTask = task; thisTask != &init_task; thisTask = thisTask->parent)
		{
			printk(KERN_EMERG "Name:[%s]  PID:[%d]  State[%ld] \n",
				thisTask->comm, thisTask->pid, thisTask->state);
		}
	}
	else
	{
		printk(KERN_EMERG "Could Not Find PID");
	}
	
	return 0;
}
