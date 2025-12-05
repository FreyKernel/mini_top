#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched/signal.h>
#include <linux/mm.h>
#include <linux/swap.h>
#include <linux/sched/loadavg.h> 

extern unsigned long avenrun[];

MODULE_LICENSE("GPL");
MODULE_AUTHOR("FreyKernel");
MODULE_DESCRIPTION("Mini top module for kernel 6.17+");

static int __init mini_top_init(void)
{
    struct task_struct *task;
    unsigned long process_count = 0;

    for_each_process(task)
        process_count++;

    unsigned long div = 1 << FSHIFT;

    struct sysinfo si;
    si_meminfo(&si);

    pr_info("=== mini-top loaded ===\n");
    pr_info("Process count: %lu\n", process_count);

    pr_info("Loadavg: %lu.%02lu %lu.%02lu %lu.%02lu\n",
            (avenrun[0] >> FSHIFT), ((avenrun[0] & (div - 1)) * 100) / div,
            (avenrun[1] >> FSHIFT), ((avenrun[1] & (div - 1)) * 100) / div,
            (avenrun[2] >> FSHIFT), ((avenrun[2] & (div - 1)) * 100) / div);

    pr_info("Free RAM: %lu MB\n",
            (si.freeram * si.mem_unit) >> 20);

    return 0;
}

static void __exit mini_top_exit(void)
{
    pr_info("mini-top unloaded\n");
}

module_init(mini_top_init);
module_exit(mini_top_exit);

