/*
    pciscan - a kernel module to enumerate devices on the PCI bus
    Copyright (C) 2013
                                                                                 
    This program is free software; you can redistribute it and/or modify         
    it under the terms of the GNU General Public License as published by         
    the Free Software Foundation; either version 2 of the License, or            
    (at your option) any later version.                                          
                                                                                 
    This program is distributed in the hope that it will be useful,              
    but WITHOUT ANY WARRANTY; without even the implied warranty of               
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                
    GNU General Public License for more details.                                 
                                                                                 
    You should have received a copy of the GNU General Public License along      
    with this program; if not, write to the Free Software Foundation, Inc.,      
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.   
*/

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/list.h>
#include <linux/kobject.h>
#include <linux/sysfs.h>
#include <linux/init.h>
#include <linux/pci.h>
#include <linux/device.h>
#include <linux/slab.h>
 
static int __init init_scan(void)
{
    struct pci_dev *pdev = NULL;
 
    printk("Loading scan\n");
 
    /* Add existing devices */
    for_each_pci_dev(pdev) {
        printk("vendor:0x%08x dev:0x%08x", pdev->vendor, pdev->device);
        if (pdev->driver && pdev->driver->name)
            printk("     name :%s", pdev->driver->name);
        printk("\n");
 
    }
 
    return 0;
}
module_init(init_scan);
 
static void __exit remove_scan(void)
{
    printk("Unloading scan\n");
}
module_exit(remove_scan);
 
MODULE_LICENSE("GPL");
