#include "strace/unwind.h"

void *android_unwinder_init(int pid, void (*on_error)(const char*, ...));

void android_unwinder_fini(void* data);

void android_unwinder_walk(void* unwind_p, int pid,
                                  unwind_call_action_fn call_action,
                                  unwind_error_action_fn error_action,
                                  void *data);

static void init() {}

static void* tcb_init(struct tcb* tcp) {
    return android_unwinder_init(tcp->pid, perror_msg_and_die);
}

static void tcb_fin(struct tcb* tcp) {
    android_unwinder_fini(tcp->unwind_ctx);
}

static void tcb_walk(struct tcb* tcp, unwind_call_action_fn call_action,
                     unwind_error_action_fn error_action,
                     void *data) {
    android_unwinder_walk(tcp->unwind_ctx, tcp->pid, call_action, error_action, data);
}

const struct unwind_unwinder_t unwinder = {
        .name = "libunwind",
        .init = init,
        .tcb_init = tcb_init,
        .tcb_fin = tcb_fin,
        .tcb_walk = tcb_walk,
};
