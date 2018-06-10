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

// Let us add some custom formatting for printing
#define pr_fmt(fmt)	KBUILD_MODNAME "->%s:%d:  " fmt, __func__,__LINE__


#include<linux/module.h>
#include<linux/init.h>

#include"processlibrary.h"

static int process_id;
module_param(process_id, int, S_IWUSR | S_IRUGO);
MODULE_PARM_DESC(process_id ,"Process ID of target process");


static int __init lkm_init(void) {

	struct task_struct *target_process;
	struct task_struct *process_thread;

	// Get task_struct for userspace process ID
	target_process = get_task_struct_by_pid(process_id);

	if(!IS_ERR_OR_NULL(target_process)) {

		pr_info("****************PROCESS DETAILS***************\n\n");

		pr_info("Received Process ID: %d\n", process_id);

		// Print task Binary name (truncated), TGID, PID
		pr_info("\nTask Details: \n");
		print_task_pid_details(target_process);


		// Print task Parent details 
		pr_info("\nTask Parent Details: \n");
		print_task_parent_pid_details(target_process);

		// Print number of threads 
		pr_info("\nNumber of threads: %d\n", 
				get_task_thread_count(target_process));
		

		// Print details of each thread
		pr_info("\nDetails of threads: \n");
		for_each_thread(target_process, process_thread) {
			
			print_task_pid_details(process_thread);

		}

		// Print task's binary name with path 
		pr_info("\nTask's binary path and name: \n");
		print_task_binary_name(target_process);


		// Print the task's root path and pwd 
		pr_info("\nTask's Root path and PWD\n");
		print_task_root_path_pwd(target_process);


		pr_info("\n\n");		
		pr_info("**********************************************\n\n");


	}else{
		pr_info("Invalid Process ID: %d Received\n", process_id);
		return -EINVAL;
	}	

	return 0;
}


static void __exit lkm_exit(void) {

	pr_info("Exiting ...\n");
}

module_init(lkm_init);
module_exit(lkm_exit);

MODULE_AUTHOR("Vivek Ramachandran");
MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("Print Process Details");


