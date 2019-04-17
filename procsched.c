#include "procsched.h"
#include <linux/kernel.h>
#include <sys/syscall.h>

long procsched(pid_t pid, struct proc_segs *info) {
	long ret;
	ret = syscall(546, pid, info);

	return ret;
}
