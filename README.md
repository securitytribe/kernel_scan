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

In the event that you do not wish to run them against your running kernel,
extract the desired kernel version to the path `/some/path/here` and then run the
command:

```
$ make KERNELVER=3.9.6
```

Replacing `3.9.6` with your desired kernel version.

## Modules

### i2cscan

i2cscan is a Linux kernel module originally appearing on the blog 
[godandme](https://godandme.wordpress.com/2013/01/31/i2c-scanning-from-linux-kernel/)
designed to scan the I²C bus and enumerate devices.

### pciscan

pciscan is a Linux kernel module originally appearing on the blog 
[godandme](https://godandme.wordpress.com/2013/01/30/pci-scan-code-for-linux-kernel/)
designed to scan the PCI bus and enumerate devices.
