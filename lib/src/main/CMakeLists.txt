cmake_minimum_required(VERSION 3.4)
project(strace-ndk)

set(CMAKE_SHARED_LINKER_FLAGS ${CMAKE_SHARED_LINKER_FLAGS} -Wl,--exclude-libs,ALL -Wl,--gc-sections)
if (NOT CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-Oz -flto)
endif()

set(STRACE_SRC strace)
add_executable(strace
        ${STRACE_SRC}/access.c
        ${STRACE_SRC}/affinity.c
        ${STRACE_SRC}/aio.c
        ${STRACE_SRC}/basic_filters.c
        ${STRACE_SRC}/bind.c
        ${STRACE_SRC}/bjm.c
        ${STRACE_SRC}/block.c
        ${STRACE_SRC}/bpf.c
        ${STRACE_SRC}/bpf_filter.c
        ${STRACE_SRC}/bpf_seccomp_filter.c
        ${STRACE_SRC}/bpf_sock_filter.c
        ${STRACE_SRC}/btrfs.c
        ${STRACE_SRC}/cacheflush.c
        ${STRACE_SRC}/capability.c
        ${STRACE_SRC}/chdir.c
        ${STRACE_SRC}/chmod.c
        ${STRACE_SRC}/clone.c
        ${STRACE_SRC}/copy_file_range.c
        ${STRACE_SRC}/count.c
        ${STRACE_SRC}/delay.c
        ${STRACE_SRC}/desc.c
        ${STRACE_SRC}/dirent.c
        ${STRACE_SRC}/dirent64.c
        ${STRACE_SRC}/dm.c
        ${STRACE_SRC}/dyxlat.c
        ${STRACE_SRC}/epoll.c
        ${STRACE_SRC}/error_prints.c
        ${STRACE_SRC}/evdev.c
        ${STRACE_SRC}/evdev_mpers.c
        ${STRACE_SRC}/eventfd.c
        ${STRACE_SRC}/execve.c
        ${STRACE_SRC}/fadvise.c
        ${STRACE_SRC}/fallocate.c
        ${STRACE_SRC}/fanotify.c
        ${STRACE_SRC}/fchownat.c
        ${STRACE_SRC}/fcntl.c
        ${STRACE_SRC}/fetch_bpf_fprog.c
        ${STRACE_SRC}/fetch_indirect_syscall_args.c
        ${STRACE_SRC}/fetch_struct_flock.c
        ${STRACE_SRC}/fetch_struct_keyctl_kdf_params.c
        ${STRACE_SRC}/fetch_struct_mmsghdr.c
        ${STRACE_SRC}/fetch_struct_msghdr.c
        ${STRACE_SRC}/fetch_struct_stat.c
        ${STRACE_SRC}/fetch_struct_stat64.c
        ${STRACE_SRC}/fetch_struct_statfs.c
        ${STRACE_SRC}/fetch_struct_xfs_quotastat.c
        ${STRACE_SRC}/file_handle.c
        ${STRACE_SRC}/file_ioctl.c
        ${STRACE_SRC}/filter_qualify.c
        ${STRACE_SRC}/flock.c
        ${STRACE_SRC}/fstatfs.c
        ${STRACE_SRC}/fstatfs64.c
        ${STRACE_SRC}/fs_x_ioctl.c
        ${STRACE_SRC}/futex.c
        ${STRACE_SRC}/getcpu.c
        ${STRACE_SRC}/getcwd.c
        ${STRACE_SRC}/getpagesize.c
        ${STRACE_SRC}/getrandom.c
        ${STRACE_SRC}/get_robust_list.c
        ${STRACE_SRC}/hdio.c
        ${STRACE_SRC}/hostname.c
        ${STRACE_SRC}/inotify.c
        ${STRACE_SRC}/inotify_ioctl.c
        ${STRACE_SRC}/io.c
        ${STRACE_SRC}/ioctl.c
        ${STRACE_SRC}/ioperm.c
        ${STRACE_SRC}/iopl.c
        ${STRACE_SRC}/ioprio.c
        ${STRACE_SRC}/ipc.c
        ${STRACE_SRC}/ipc_msg.c
        ${STRACE_SRC}/ipc_msgctl.c
        ${STRACE_SRC}/ipc_sem.c
        ${STRACE_SRC}/ipc_shm.c
        ${STRACE_SRC}/ipc_shmctl.c
        ${STRACE_SRC}/kcmp.c
        ${STRACE_SRC}/kexec.c
        ${STRACE_SRC}/keyctl.c
        ${STRACE_SRC}/kvm.c
        ${STRACE_SRC}/ldt.c
        ${STRACE_SRC}/link.c
        ${STRACE_SRC}/listen.c
        ${STRACE_SRC}/lookup_dcookie.c
        ${STRACE_SRC}/loop.c
        ${STRACE_SRC}/lseek.c
        ${STRACE_SRC}/mem.c
        ${STRACE_SRC}/membarrier.c
        ${STRACE_SRC}/memfd_create.c
        ${STRACE_SRC}/mknod.c
        ${STRACE_SRC}/mmap_cache.c
        ${STRACE_SRC}/mmap_notify.c
        ${STRACE_SRC}/mmsghdr.c
        ${STRACE_SRC}/mount.c
        ${STRACE_SRC}/mq.c
        ${STRACE_SRC}/msghdr.c
        ${STRACE_SRC}/mtd.c
        ${STRACE_SRC}/nbd_ioctl.c
        ${STRACE_SRC}/net.c
        ${STRACE_SRC}/netlink.c
        ${STRACE_SRC}/netlink_crypto.c
        ${STRACE_SRC}/netlink_inet_diag.c
        ${STRACE_SRC}/netlink_kobject_uevent.c
        ${STRACE_SRC}/netlink_netfilter.c
        ${STRACE_SRC}/netlink_netlink_diag.c
        ${STRACE_SRC}/netlink_packet_diag.c
        ${STRACE_SRC}/netlink_route.c
        ${STRACE_SRC}/netlink_selinux.c
        ${STRACE_SRC}/netlink_smc_diag.c
        ${STRACE_SRC}/netlink_sock_diag.c
        ${STRACE_SRC}/netlink_unix_diag.c
        ${STRACE_SRC}/nlattr.c
        ${STRACE_SRC}/nsfs.c
        ${STRACE_SRC}/numa.c
        ${STRACE_SRC}/number_set.c
        ${STRACE_SRC}/oldstat.c
        ${STRACE_SRC}/open.c
        ${STRACE_SRC}/pathtrace.c
        ${STRACE_SRC}/perf.c
        ${STRACE_SRC}/perf_ioctl.c
        ${STRACE_SRC}/personality.c
        ${STRACE_SRC}/pkeys.c
        ${STRACE_SRC}/poll.c
        ${STRACE_SRC}/prctl.c
        ${STRACE_SRC}/print_aio_sigset.c
        ${STRACE_SRC}/print_dev_t.c
        ${STRACE_SRC}/print_group_req.c
        ${STRACE_SRC}/print_ifindex.c
        ${STRACE_SRC}/print_mac.c
        ${STRACE_SRC}/print_mq_attr.c
        ${STRACE_SRC}/print_msgbuf.c
        ${STRACE_SRC}/print_sigevent.c
        ${STRACE_SRC}/print_sg_req_info.c
        ${STRACE_SRC}/print_statfs.c
        ${STRACE_SRC}/print_struct_stat.c
        ${STRACE_SRC}/print_time.c
        ${STRACE_SRC}/print_timespec.c
        ${STRACE_SRC}/print_timeval.c
        ${STRACE_SRC}/print_timex.c
        ${STRACE_SRC}/printmode.c
        ${STRACE_SRC}/printrusage.c
        ${STRACE_SRC}/printsiginfo.c
        ${STRACE_SRC}/process.c
        ${STRACE_SRC}/process_vm.c
        ${STRACE_SRC}/ptp.c
        ${STRACE_SRC}/quota.c
        ${STRACE_SRC}/readahead.c
        ${STRACE_SRC}/readlink.c
        ${STRACE_SRC}/reboot.c
        ${STRACE_SRC}/renameat.c
        ${STRACE_SRC}/resource.c
        ${STRACE_SRC}/retval.c
        ${STRACE_SRC}/riscv.c
        ${STRACE_SRC}/rtc.c
        ${STRACE_SRC}/rtnl_addr.c
        ${STRACE_SRC}/rtnl_addrlabel.c
        ${STRACE_SRC}/rtnl_dcb.c
        ${STRACE_SRC}/rtnl_link.c
        ${STRACE_SRC}/rtnl_mdb.c
        ${STRACE_SRC}/rtnl_neigh.c
        ${STRACE_SRC}/rtnl_neightbl.c
        ${STRACE_SRC}/rtnl_netconf.c
        ${STRACE_SRC}/rtnl_nsid.c
        ${STRACE_SRC}/rtnl_route.c
        ${STRACE_SRC}/rtnl_rule.c
        ${STRACE_SRC}/rtnl_tc.c
        ${STRACE_SRC}/rtnl_tc_action.c
        ${STRACE_SRC}/rt_sigframe.c
        ${STRACE_SRC}/rt_sigreturn.c
        ${STRACE_SRC}/sched.c
        ${STRACE_SRC}/scsi.c
        ${STRACE_SRC}/seccomp.c
        ${STRACE_SRC}/sendfile.c
        ${STRACE_SRC}/sg_io_v3.c
        ${STRACE_SRC}/sg_io_v4.c
        ${STRACE_SRC}/shutdown.c
        ${STRACE_SRC}/sigaltstack.c
        ${STRACE_SRC}/signal.c
        ${STRACE_SRC}/signalfd.c
        ${STRACE_SRC}/sigreturn.c
        ${STRACE_SRC}/sock.c
        ${STRACE_SRC}/sockaddr.c
        ${STRACE_SRC}/socketcall.c
        ${STRACE_SRC}/socketutils.c
        ${STRACE_SRC}/sram_alloc.c
        ${STRACE_SRC}/stat.c
        ${STRACE_SRC}/stat64.c
        ${STRACE_SRC}/statfs.c
        ${STRACE_SRC}/statfs64.c
        ${STRACE_SRC}/statx.c
        ${STRACE_SRC}/strace.c
        ${STRACE_SRC}/string_to_uint.c
        ${STRACE_SRC}/swapon.c
        ${STRACE_SRC}/sync_file_range.c
        ${STRACE_SRC}/sync_file_range2.c
        ${STRACE_SRC}/syscall.c
        ${STRACE_SRC}/sysctl.c
        ${STRACE_SRC}/sysinfo.c
        ${STRACE_SRC}/syslog.c
        ${STRACE_SRC}/sysmips.c
        ${STRACE_SRC}/term.c
        ${STRACE_SRC}/time.c
        ${STRACE_SRC}/times.c
        ${STRACE_SRC}/truncate.c
        ${STRACE_SRC}/ubi.c
        ${STRACE_SRC}/ucopy.c
        ${STRACE_SRC}/uid16.c
        ${STRACE_SRC}/uid.c
        ${STRACE_SRC}/umask.c
        ${STRACE_SRC}/umount.c
        ${STRACE_SRC}/uname.c
        ${STRACE_SRC}/upeek.c
        ${STRACE_SRC}/upoke.c
        ${STRACE_SRC}/userfaultfd.c
        ${STRACE_SRC}/ustat.c
        ${STRACE_SRC}/util.c
        ${STRACE_SRC}/utime.c
        ${STRACE_SRC}/utimes.c
        ${STRACE_SRC}/v4l2.c
        ${STRACE_SRC}/wait.c
        ${STRACE_SRC}/xattr.c
        ${STRACE_SRC}/xlat.c
        ${STRACE_SRC}/xmalloc.c

        ${STRACE_SRC}/unwind.c
        bridge.c
        bridgexx.cpp
)

set(DEFINITIONS -DHAVE_CONFIG_H -DSIZEOF_KERNEL_LONG_T=SIZEOF_LONG -DSIZEOF_OFF_T=SIZEOF_LONG -DENABLE_STACKTRACE -DUSE_UNWINDER=\"libunwindstack\")

target_compile_options(strace PRIVATE
        -Wall
        -Werror
        -Wno-initializer-overrides
        -Wno-missing-field-initializers
        -Wno-nonnull
        -Wno-pointer-arith
        -Wno-unused-parameter
        -Wno-sign-compare
        -fno-strict-aliasing
)

set(HEADERS ${STRACE_SRC} ${STRACE_SRC}/linux)

set(DEFINITIONS_32
        -DSIZEOF_LONG_LONG=8
        -DSIZEOF_LONG=4
        -DSIZEOF_RLIM_T=4
        -DHAVE_STRUCT_STAT64=1
)

set(DEFINITIONS_64
        -DSIZEOF_LONG_LONG=8
        -DSIZEOF_LONG=8
        -DSIZEOF_RLIM_T=8
)

if (${CMAKE_ANDROID_ARCH} STREQUAL "arm")
    set(ARCH "arm")
    set(DEFINITIONS ${DEFINITIONS} ${DEFINITIONS_32} -DARM=1)
elseif (${CMAKE_ANDROID_ARCH} STREQUAL "arm64")
    set(ARCH "aarch64")
    set(DEFINITIONS ${DEFINITIONS} ${DEFINITIONS_64} -DAARCH64=1)
elseif (${CMAKE_ANDROID_ARCH} STREQUAL "x86")
    set(ARCH "i386")
    set(DEFINITIONS ${DEFINITIONS} ${DEFINITIONS_32} -DI386=1 -DHAVE_STRUCT___OLD_KERNEL_STAT=1)
elseif (${CMAKE_ANDROID_ARCH} STREQUAL "x86_64")
    set(ARCH "x86_64")
    set(DEFINITIONS ${DEFINITIONS} ${DEFINITIONS_64} -DX86_64=1)
elseif (${CMAKE_ANDROID_ARCH} STREQUAL "riscv64")
    set(ARCH "riscv")
    set(DEFINITIONS ${DEFINITIONS} ${DEFINITIONS_64} -DRISCV=1)
endif()

target_compile_definitions(strace PRIVATE ${DEFINITIONS})

target_include_directories(strace PRIVATE
        ${STRACE_SRC}/linux/${ARCH} ${HEADERS}
)

target_link_libraries(strace PRIVATE unwindstack log)

if (DEFINED DEBUG_SYMBOLS_PATH)
    add_compile_options(-Oz -flto)
    add_custom_command(TARGET strace POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E make_directory ${DEBUG_SYMBOLS_PATH}/${ANDROID_ABI}
            COMMAND ${CMAKE_OBJCOPY} --only-keep-debug $<TARGET_FILE:strace>
            ${DEBUG_SYMBOLS_PATH}/${ANDROID_ABI}/strace.debug
            COMMAND ${CMAKE_STRIP} --strip-all $<TARGET_FILE:strace>
            COMMAND ${CMAKE_OBJCOPY} --add-gnu-debuglink ${DEBUG_SYMBOLS_PATH}/${ANDROID_ABI}/strace.debug
            $<TARGET_FILE:strace>)
endif()

add_subdirectory(libunwindstack)
