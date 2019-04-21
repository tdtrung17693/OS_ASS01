#include <linux/linkage.h>
#include <linux/sched.h>
#include <linux/proc_fs.h>
#include <linux/sched.h>
#include <linux/uaccess.h>

struct proc_segs
{
	unsigned long mssv;
	unsigned long pcount;
	unsigned long long run_delay;
	unsigned long long last_arrival;
	unsigned long long last_queued;
};

asmlinkage long
sys_procsched(int pid, struct proc_segs * info)
{
	struct task_struct * task;
	struct proc_segs tInfo;
	int r;

 	task = find_task_by_vpid(pid);

	if (task != NULL) return -1;
	
	tInfo.mssv = 1820081;
	tInfo.pcount = task->sched_info.pcount;
	tInfo.run_delay = task->sched_info.run_delay;
	tInfo.last_arrival = task->sched_info.last_arrival;
	tInfo.last_queued = task->sched_info.last_queued;
	
	r = copy_to_user(info, &tInfo, sizeof(tInfo));
	if (r != 0) {
		printk("Unexpected error occurred.\n");
		return -1;
	}
	
	return 0;
}
