
obj-m += i2cscan.o
obj-m += pciscan.o

KERNELVER = $(shell uname -r)
KERNELHEADERS = /lib/modules/$(KERNELVER)/build

all:
		make -C $(KERNELHEADERS) M=$(PWD) modules

clean:
		make -C $(KERNELHEADERS) M=$(PWD) clean
