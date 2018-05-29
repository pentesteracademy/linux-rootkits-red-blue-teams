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
#define iamhere(x)	pr_info("IAMHERE: " x "\n")

#include<linux/module.h>
#include<linux/init.h>
#include<linux/stat.h>

static int counter;
module_param(counter, int, S_IWUSR | S_IRUGO);
MODULE_PARM_DESC(counter, "A simple integer counter variable");

static char *message = NULL;
module_param(message, charp, S_IWUSR | S_IRUGO);
MODULE_PARM_DESC(message, "A message from user space");

// Also, check out 
// module_param_named, module_param_array, module_param_string 

static int __init lkm_init(void) {

	pr_info("Hello Cruel World of Kernel Programming!\n");

	pr_info("Param 1: Counter %d\n", counter);
	pr_info("Param 2: Message: %s\n", message);


	return 0;

}


static void __exit lkm_exit(void) {

	pr_info("Wow! You exited early\n");

	iamhere("exiting");
}

module_init(lkm_init);
module_exit(lkm_exit);




MODULE_AUTHOR("Vivek Ramachandran");
MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("A Hello World Module");


