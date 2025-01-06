# strace-NDK

Build [strace][strace] from [AOSP][AOSP-strace] integrated with [libunwindstack][libunwindstack] ([non-official][libunwindstack-unofficial])

## Build

```shell
gradlew assembleDebug
gradlew assembleRelease
```

You can find executables under lib/build/intermediates/cmake/TYPE/obj/ABI/strace .

## Requirement

Android API >= 28

ABI: arm64-v8a, armeabi-v7a, x86, x86_64, riscv64

[strace]: https://github.com/strace/strace
[AOSP-strace]: https://cs.android.com/android/platform/superproject/main/+/main:external/strace
[libunwindstack]: https://cs.android.com/android/platform/superproject/main/+/main:system/unwinding/libunwindstack/
[libunwindstack-unofficial]: https://github.com/cinit/libunwindstack
