# Simplest possible makefile 

obj-m +=  helloworld-fmt.o



modules:
	@$(MAKE) -C $(KERNEL_ROOT) M=$(shell pwd) modules

clean: 
	@$(MAKE) -C $(KERNEL_ROOT) M=$(shell pwd) clean
