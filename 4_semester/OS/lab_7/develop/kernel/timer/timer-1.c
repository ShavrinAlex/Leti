#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/module.h>
#include <linux/printk.h>
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("ALEX");
MODULE_DESCRIPTION("A sample timer interrupt module");
 
#define TIMER_IRQ           0
 
static irqreturn_t timer_isr(int irq, void *dev_id){
   static long long unsigned count = 0;
   if(count < 700){
   	pr_info("Tick %llu handled\n", count++);
   }
   return IRQ_HANDLED;
}
 
static int __init timer_module_init(void){
   int ret;
   pr_info("Timer module is loaded\n");
   
   ret = request_irq(TIMER_IRQ, timer_isr, 0, "timer", NULL);
   if(ret){
      pr_err("Unable to request IRQ: %d\n", ret);
      return ret;
   }
   return 0;
}
 
static void __exit timer_module_cleanup(void){  
   pr_info("Timer module is unloaded\n");
   free_irq(TIMER_IRQ, NULL);
}
 
module_init(timer_module_init);
module_exit(timer_module_cleanup);
