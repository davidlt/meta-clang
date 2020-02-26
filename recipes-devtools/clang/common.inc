FILESEXTRAPATHS =. "${FILE_DIRNAME}/clang:"

LIC_FILES_CHKSUM = "file://llvm/LICENSE.TXT;md5=${LLVMMD5SUM} \
                    file://clang/LICENSE.TXT;md5=${CLANGMD5SUM} \
"
LICENSE = "Apache-2.0-with-LLVM-exception"

BASEURI ??= "${LLVM_GIT}/llvm-project;protocol=${LLVM_GIT_PROTOCOL};branch=${BRANCH}"
SRC_URI = "\
    ${BASEURI} \
    file://0001-lldb-Add-lxml2-to-linker-cmdline-of-xml-is-found.patch \
    file://0002-libcxxabi-Find-libunwind-headers-when-LIBCXXABI_LIBU.patch \
    file://0003-compiler-rt-support-a-new-embedded-linux-target.patch \
    file://0004-compiler-rt-Simplify-cross-compilation.-Don-t-use-na.patch \
    file://0005-compiler-rt-Disable-tsan-on-OE-glibc.patch \
    file://0006-llvm-TargetLibraryInfo-Undefine-libc-functions-if-th.patch \
    file://0007-llvm-allow-env-override-of-exe-path.patch \
    file://0008-clang-driver-Check-sysroot-for-ldso-path.patch \
    file://0009-clang-Driver-tools.cpp-Add-lssp_nonshared-on-musl.patch \
    file://0010-clang-musl-ppc-does-not-support-128-bit-long-double.patch \
    file://0011-clang-Prepend-trailing-to-sysroot.patch \
    file://0012-clang-Look-inside-the-target-sysroot-for-compiler-ru.patch \
    file://0013-clang-Define-releative-gcc-installation-dir.patch \
    file://0014-clang-Fix-ldso-for-musl-on-x86-and-x32-architectures.patch \
    file://0015-clang-scan-view-needs-python-2.x.patch \
    file://0016-clang-Add-lpthread-and-ldl-along-with-lunwind-for-st.patch \
    file://0017-libclang-Use-CMAKE_DL_LIBS-for-deducing-libdl.patch \
    file://0018-Pass-PYTHON_EXECUTABLE-when-cross-compiling-for-nati.patch \
    file://0019-Check-for-atomic-double-intrinsics.patch \
    file://0020-clang-Enable-SSP-and-PIE-by-default.patch \
    file://0021-llvm-Add-lz-to-linker-cmdline-if-enabled.patch \
    file://0022-libcxx-Add-compiler-runtime-library-to-link-step-for.patch \
    file://0023-clang-llvm-cmake-Fix-configure-for-packages-using-fi.patch \
    file://D68899-de1c2877a9ff12899ef50e179ade748fba8ab0c0.patch \
    file://D69003-09856feb3cc141f4f9c8b9edec28602ac4f21575.patch \
    file://D69444-d4a4a32cd94eccbaaa4608b0daac8b820e041214.patch \
    file://f128f442a3d23674bee19ae18e29f92c9dfe40cd.patch \
    file://D69869-1d40c4150630729a9c1ce5119a8027dac93a5b2d.patch \
    file://D68964-cef85193b2cc1817ca43199a0ae9c6f25723997d.patch \
    file://D74399-9816e726e747d72e0c5ac92aa20e652031a10448.patch \
"

# Fallback to no-PIE if not set
GCCPIE ??= ""

S = "${TMPDIR}/work-shared/llvm-project-source-${PV}-${PR}/git"
B = "${WORKDIR}/llvm-project-source-${PV}/build.${HOST_SYS}.${TARGET_SYS}"

# We need to ensure that for the shared work directory, the do_patch signatures match
# The real WORKDIR location isn't a dependency for the shared workdir.
src_patches[vardepsexclude] = "WORKDIR"
should_apply[vardepsexclude] += "PN"
