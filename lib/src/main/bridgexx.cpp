#include "unwindstack/AndroidUnwinder.h"
#include <string>

using namespace unwindstack;

typedef unsigned long unwind_function_offset_t;

typedef void (*unwind_call_action_fn)(void *data,
                                      const char *binary_filename,
                                      const char *symbol_name,
                                      unwind_function_offset_t function_offset,
                                      unsigned long true_offset);
typedef void (*unwind_error_action_fn)(void *data,
                                       const char *error,
                                       unsigned long true_offset);

extern "C" {
void *android_unwinder_init(int pid, void (*on_error)(const char*, ...)) {
    auto p = new AndroidRemoteUnwinder(pid);
    if (!p) {
        on_error("AndroidRemoteUnwinder init");
        return nullptr;
    }
    return p;
}

void android_unwinder_fini(void* data) {
    delete reinterpret_cast<AndroidRemoteUnwinder *>(data);
}

void android_unwinder_walk(void* unwind_p, int pid,
                     unwind_call_action_fn call_action,
                     unwind_error_action_fn error_action,
                     void *data) {
    auto unwind = reinterpret_cast<AndroidRemoteUnwinder *>(unwind_p);

    unwindstack::AndroidUnwinderData unwind_data;
    auto regs = unwindstack::Regs::RemoteGet(pid);
    if (regs == nullptr) {
        error_action(data, "failed to get regs", 0);
        return;
    }

    unwindstack::ErrorData error_data{};
    if (!unwind->Initialize(error_data)) {
        error_action(data, (std::string{"unwinder initialize: "} + unwindstack::GetErrorCodeString(error_data.code)).c_str(), 0);
        return;
    }
    if (!unwind->Unwind(regs, unwind_data)) {
        error_action(data, ("failed to unwind: " + unwind_data.GetErrorString()).c_str(), 0);
        return;
    }

    for (const auto &frame: unwind_data.frames) {
        auto file = frame.map_info ? &frame.map_info->name() : nullptr;
        auto &func = frame.function_name;
        call_action(data, file ? (file->is_null() ? "(null)" : file->c_str()) : "(null frame)", func.is_null() ? "(null)" : func.c_str(),
                    frame.function_offset, frame.rel_pc);
    }
}

}
