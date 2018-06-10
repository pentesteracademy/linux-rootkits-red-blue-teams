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
#include<linux/path.h>
#include<linux/fs_struct.h>
#include<linux/dcache.h>
#include<linux/limits.h>
#include<linux/slab.h>
#include<linux/fs.h>

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

	PTR_NULL_CHECK(tsk);

	return tsk->signal->nr_threads;

}

/*
 * Print the task's binary name and location
 */
static inline int print_task_binary_name(struct task_struct *tsk) {

	char *temp_path;
	char *binary_path;

	PTR_NULL_CHECK(tsk);

	// Get the ELF binary path of this process

	// Access the process memory map 
	if(NULL != tsk->mm) {

		// hold memory map semaphore with read bias 
		down_read(&tsk->mm->mmap_sem);

		if(NULL != tsk->mm->exe_file) {
	
			temp_path = kmalloc(PATH_MAX, GFP_KERNEL);

			if(NULL == temp_path) panic("kmalloc FAILED!");

		
			binary_path = d_path(&tsk->mm->exe_file->f_path, 
							temp_path, 
							PATH_MAX);

			pr_info("Binary Path: %s\n", binary_path);

			kfree(temp_path);

		}
		else {
			pr_info("Binary Path: (none)\n");
		}

		// release memory map semaphore 
		up_read(&tsk->mm->mmap_sem);
		
	}else{
		pr_info("target_process->mm is NULL - Kernel thread?\n");
	}

	return DEFAULT_SUCCESS;	
}


/*
 * Print the task's current working directory and root path
 */
static inline int print_task_root_path_pwd(struct task_struct *tsk) {

	char *temp_path;
	struct path root_path, pwd_path;
	char *root_path_name, *pwd_path_name;

	PTR_NULL_CHECK(tsk);

	// Root and Pwd for the process

	temp_path = kmalloc(PATH_MAX, GFP_KERNEL);

	if(NULL == temp_path) panic("kmalloc FAILED!");

	get_fs_root(tsk->fs, &root_path);
	root_path_name = d_path(&root_path, temp_path, PATH_MAX);
	pr_info("Root Path: %s\n", root_path_name);

	get_fs_pwd(tsk->fs, &pwd_path);
	pwd_path_name = d_path(&pwd_path, temp_path, PATH_MAX);
	pr_info("PWD Path: %s\n", pwd_path_name);

        // release memory
        if(NULL != temp_path) kfree(temp_path);

	return DEFAULT_SUCCESS;

}


