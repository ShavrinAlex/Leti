#include <asm/io.h>
#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/module.h>
#include <linux/printk.h>
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("ALEX");
MODULE_DESCRIPTION("A sample keyboard driver");
 
#define KBD_IRQ             1
#define KBD_DATA_REG        0x60
#define KBD_SCANCODE_MASK   0x7f
#define KBD_STATUS_MASK     0x80
 
static irqreturn_t kbd2_isr(int irq, void *dev_id){
   char scancode;
   scancode = inb(KBD_DATA_REG);
   pr_info("Scan code %x %s\n", scancode & KBD_SCANCODE_MASK, scancode & KBD_STATUS_MASK ? "released" : "pressed");
   return IRQ_HANDLED;
}
 
static int __init keyboard_module_init(void){
   int ret;
   pr_info("Keyboard module is loaded\n");
   ret = request_irq(KBD_IRQ, kbd2_isr, IRQF_SHARED, "keyboard_stats_irq", (void *)kbd2_isr);
   if(ret){
      pr_err("Unable to request IRQ: %d\n", ret);
      return ret;
   }
   return 0;
}
 
static void __exit keyboard_module_cleanup(void) 
{  pr_info("Keyboard module is unloaded\n");
   free_irq(KBD_IRQ, (void *)kbd2_isr);
}
 
module_init(keyboard_module_init);
module_exit(keyboard_module_cleanup);
