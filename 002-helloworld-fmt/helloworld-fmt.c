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


static int __init lkm_init(void) {

	pr_info("Hello Cruel World of Kernel Programming!\n");

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


