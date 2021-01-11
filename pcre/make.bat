gcc -I. -DHAVE_CONFIG_H -o dftables dftables.c

.\dftables.exe pcre_chartables.c

gcc -I. -DHAVE_CONFIG_H -c -o pcre_byte_order.o pcre_byte_order.c
gcc -I. -DHAVE_CONFIG_H -c -o pcre_chartables.o pcre_chartables.c
gcc -I. -DHAVE_CONFIG_H -c -o pcre_compile.o pcre_compile.c
gcc -I. -DHAVE_CONFIG_H -c -o pcre_config.o pcre_config.c
gcc -I. -DHAVE_CONFIG_H -c -o pcre_dfa_exec.o pcre_dfa_exec.c
gcc -I. -DHAVE_CONFIG_H -c -o pcre_exec.o pcre_exec.c
gcc -I. -DHAVE_CONFIG_H -c -o pcre_fullinfo.o pcre_fullinfo.c
gcc -I. -DHAVE_CONFIG_H -c -o pcre_get.o pcre_get.c
gcc -I. -DHAVE_CONFIG_H -c -o pcre_globals.o pcre_globals.c
gcc -I. -DHAVE_CONFIG_H -c -o pcre_jit_compile.o pcre_jit_compile.c
gcc -I. -DHAVE_CONFIG_H -c -o pcre_maketables.o pcre_maketables.c
gcc -I. -DHAVE_CONFIG_H -c -o pcre_newline.o pcre_newline.c
gcc -I. -DHAVE_CONFIG_H -c -o pcre_ord2utf8.o pcre_ord2utf8.c
gcc -I. -DHAVE_CONFIG_H -c -o pcre_refcount.o pcre_refcount.c
gcc -I. -DHAVE_CONFIG_H -c -o pcre_string_utils.o pcre_string_utils.c
gcc -I. -DHAVE_CONFIG_H -c -o pcre_study.o pcre_study.c
gcc -I. -DHAVE_CONFIG_H -c -o pcre_tables.o pcre_tables.c
gcc -I. -DHAVE_CONFIG_H -c -o pcre_ucd.o pcre_ucd.c
gcc -I. -DHAVE_CONFIG_H -c -o pcre_valid_utf8.o pcre_valid_utf8.c
gcc -I. -DHAVE_CONFIG_H -c -o pcre_version.o pcre_version.c
gcc -I. -DHAVE_CONFIG_H -c -o pcre_xclass.o pcre_xclass.c

ar rcs libpcre.a pcre_byte_order.o pcre_chartables.o pcre_compile.o pcre_config.o pcre_dfa_exec.o pcre_exec.o pcre_fullinfo.o pcre_get.o pcre_globals.o pcre_jit_compile.o pcre_maketables.o pcre_newline.o pcre_ord2utf8.o pcre_refcount.o pcre_string_utils.o pcre_study.o pcre_tables.o pcre_ucd.o pcre_valid_utf8.o pcre_version.o pcre_xclass.o

copy libpcre.a ..\