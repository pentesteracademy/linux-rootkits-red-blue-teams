/*   Licensed as GPLv2
 *
 *   Course:	Linux Rootkits for Red-Blue Teams
 *   Author: 	Vivek Ramachandran
 *   Website: 	www.PentesterAcademy.com
 *
 *   Course Page and Videos:
 *   http://www.pentesteracademy.com/course?id=37
 *
 *   If you are interested in learning how to code these from the very basics
 *   then please check out the course link above! 
 */

#include<linux/sched.h>
#include<linux/pid.h>
#include<linux/cred.h>
#include<linux/sched/signal.h>

#define DEFAULT_SUCCESS	1
#define DEFAULT_FAILURE -1

#define PTR_NULL_CHECK(ptr)	if(NULL == ptr) return DEFAULT_FAILURE;


/*
 * Get the task_struct for the given userspace process ID
 *
 */
static inline struct task_struct * get_task_struct_by_pid(int pid) {

	return pid_task(find_vpid(pid), PIDTYPE_PID);	

}


/* 
 * Print task comm, pid, tgid for a given task_struct
 *
 */
static inline int print_task_pid_details(struct task_struct *tsk) {

	PTR_NULL_CHECK(tsk);

	// print basic info
	
	pr_info("Task Binary: %s TGID: %d PID: %d\n",
			tsk->comm,
			tsk->tgid,
			tsk->pid
	       );

	return DEFAULT_SUCCESS;
}


/*
 * Print real parent task PID, TGID and Comm
 */
static inline int print_task_parent_pid_details(struct task_struct *tsk) {

	PTR_NULL_CHECK(tsk);

	// Real parent -- either process which started this or init if the original 
	// parent exited 

	pr_info("Parent Task Binary: %s TGID: %d PID: %d\n",
			tsk->real_parent->comm,
			tsk->real_parent->tgid,
			tsk->real_parent->pid
	       );

	return DEFAULT_SUCCESS;
}

/*
 * Get number of threads in task group
 */
static inline int get_task_thread_count(struct task_struct *tsk) {

	return tsk->signal->nr_threads;

}


