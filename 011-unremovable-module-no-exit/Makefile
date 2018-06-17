# Simplest possible makefile 

obj-m +=  unremovable-module-no-exit.o

modules:
	@$(MAKE) -C $(KERNEL_ROOT) M=$(shell pwd) modules

clean: 
	@$(MAKE) -C $(KERNEL_ROOT) M=$(shell pwd) clean
