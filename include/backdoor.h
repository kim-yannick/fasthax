#ifndef __BACKDOOR_H
#define __BACKDOOR_H

#include <3ds.h>

bool backdoor_installed;

/* ASM SVC stubs */
Result svcMyBackdoor(s32 (*callback)(void));
Result svcMyBackdoor2(s32 (*callback)(void));

/* Luma backdoor */
void kmemcpy(void *dst, void *src, u32 len);
void kwriteint(u32 *addr, u32 value);
u32 kreadint(u32 *addr);
bool mybackdoor_installed();
void print_array_wait(char *name, u32 *addr, u32 size);
void *get_object_addr(Handle handle);
/* Used in testing exploit */
void kernel_randomstub(u32 *arg);
bool get_timer_value(Handle timer, u64 *initial, u64 *interval);

/* Real backdoor */
void kwriteint_real(u32 *addr, u32 value);
bool realbackdoor_installed(void);
/* Used in real exploit. */
void install_kernel_backdoor(void);

#endif /* __BACKDOOR_H */
