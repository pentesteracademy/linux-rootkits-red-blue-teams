/*   Licensed as GPLv2
 *
 *   Course:	Linux Rootkits for Red-Blue Teams
 *   Author: 	Vivek Ramachandran
 *   Website: 	www.PentesterAcademy.com
 *
 *   Course Page and Videos:
 *   http://www.pentesteracademy.com/course?id=37
 *
 */


#include<linux/module.h>
#include<linux/init.h>


static int __init lkm_init(void) {

	pr_info("Hello Cruel World of Kernel Programming!\n");

	return 0;

}


static void __exit lkm_exit(void) {

	pr_info("Wow! You exited early\n");

}

module_init(lkm_init);
module_exit(lkm_exit);

MODULE_AUTHOR("Vivek Ramachandran");
MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("A Hello World Module");


