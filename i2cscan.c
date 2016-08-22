/*
    i2cscan - A kernel module to enumerate devices on the I2C bus
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
#include <linux/i2c.h>
#include <linux/device.h>
#include <linux/slab.h>
static void sib_i2c_scan(struct device *dev, void *dummy)
{
    struct i2c_adapter *adap;
    struct i2c_dev *i2c_dev;
 
    if (dev->type != &i2c_adapter_type)
        return 0;
     
    adap = to_i2c_adapter(dev);
#if 0
    i2c_dev = get_free_i2c_dev(adap);
    if (IS_ERR(i2c_dev))
        return PTR_ERR(i2c_dev);
#endif
    printk("adapter_name:%s dev_name:%s\n", 
            adap->name, NULL /*i2c_dev->device->init_name*/);
 
}
 
static int __init init_i2c_scan(void)
{
    struct i2c_adapter *adap = NULL;
    struct i2c_dev *i2c_dev = NULL;
 
    printk("Loading i2c scan\n");
    i2c_for_each_dev(NULL, sib_i2c_scan);
 
    return 0;
}
module_init(init_i2c_scan);
 
static void __exit remove_i2c_scan(void)
{
    printk("Unloading i2c scan\n");
}
module_exit(remove_i2c_scan);
 
MODULE_LICENSE("GPL");
