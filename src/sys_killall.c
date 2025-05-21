#include "common.h"
#include "syscall.h"
#include "stdio.h"
#include "libmem.h"
#include <string.h>

// Minimal definitions for demonstration purposes.
struct pcb_t *proc_list = NULL;

static void terminate_proc(struct pcb_t *p) {
    printf("Terminating process %d [%s]\n", p->pid, p->path);
    // Minimal termination: add cleanup logic as needed.
}

int __sys_killall(struct pcb_t *caller, struct sc_regs* regs)
{
    char proc_name[100];
    uint32_t memrg = regs->a1;
    uint32_t data;
    int i = 0;
    
    // Get the process name from the memory region referenced by memrg.
    data = 0;
    while(data != (uint32_t)-1 && i < (int)(sizeof(proc_name) - 1)){
        libread(caller, memrg, i, &data);
        proc_name[i] = (char)data;
        if(data == (uint32_t)-1){
            proc_name[i] = '\0';
            break;
        }
        i++;
    }
    proc_name[i] = '\0';
    
    printf("The procname retrieved from memregionid %d is \"%s\"\n", memrg, proc_name);
    
    // Traverse the process list and terminate processes with matching name.
    int kill_count = 0;
    struct pcb_t *p = proc_list;
    while(p != NULL){
        if(strcmp(p->path, proc_name) == 0){
            terminate_proc(p);
            kill_count++;
        }
        p = p->next;  // Assumes pcb_t contains a 'next' pointer.
    }
    
    printf("Terminated %d processes named \"%s\".\n", kill_count, proc_name);

    return 0; 
}