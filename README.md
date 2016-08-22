# Kernel Scanning tools

## About

In this repository are two kernel modules which can be built and used to
enumerate information on devices on the I²C and PCI kernel busses. They were not
written by me, but unfortunately the original author has taken some effort to
stay anonymous.  Links to the original sources are left under the respective
module descriptions.

## Building

To build the modules for your running kernel simply run the command:

```
$ make
```

This will output the files `i2cscan.ko` and `pciscan.ko`, which can be loaded.

In the event that you do not wish to run them against your running kernel, but
another set of sources within the path `/lib/modules/$(KERNELVER)/build`
you may run:

```
$ make KERNELVER=3.9.6
```

Replacing `3.9.6` with your desired kernel version.

Finally, if you wish to specify an arbitrary path (as the author of this
README.md does) extract the desired kernel version to the path `/some/path/here`
and then run the command:

```
$ make KERNELHEADERS=/some/path/here
```

This is especially useful when you are trying to compile these modules for a
remote device and you are only able to identify the running version with
`uname -r`.

In addition, if you have done a raw checkout/untar of sources from 
[Kernel.org](https://kernel.org) there may be additional steps that you have to
take.  Some old kernels will be missing files, but can be solved very easily.
Refer to [Various Errors/Errata] for more information.

## Modules

### i2cscan

i2cscan is a Linux kernel module originally appearing on the blog 
[godandme](https://godandme.wordpress.com/2013/01/31/i2c-scanning-from-linux-kernel/)
designed to scan the I²C bus and enumerate devices.

### pciscan

pciscan is a Linux kernel module originally appearing on the blog 
[godandme](https://godandme.wordpress.com/2013/01/30/pci-scan-code-for-linux-kernel/)
designed to scan the PCI bus and enumerate devices.

## Various Errors/Errata:

### GCC
```
include/linux/compiler-gcc.h:103:30: fatal error: linux/compiler-gcc5.h: No such file or directory
compilation terminated.
```

It means that the kernel did not ship with headers knowledgeable about the
various capabilities of GCC Version 5.   In this case, GCC can operate in a
backwards compatible manner, but we will need to redirect these calls.  In the
source kernel source tree run:

```
echo "#include <linux/compiler-gcc4.h>" > include/linux/compiler-gcc5.h
```

### Missing config / prepare 

```
     ERROR: Kernel configuration is invalid.
         include/generated/autoconf.h or include/config/auto.conf are missing.
         Run 'make oldconfig && make prepare' on kernel src to fix it.
```

You'll need to put in a sample config (if you don't have a default kernel config)
and prep the tree to be built.  In the kernel source tree run:

```
make oldconfig && make prepare
```

### Missing files in `/scripts` 

```
/bin/sh: /home/user/Projects/linux-3.9.6/scripts/recordmcount: No such file or directory
```

The kernel includes many helper scripts to identify the location of
system/toolchain components.  These need to be generated via the `Makefile`.
In the kernel source tree run:

```
make scripts
```
