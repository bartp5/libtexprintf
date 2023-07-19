AC_INIT([libtexprintf],[1.25])
AC_CONFIG_MACRO_DIRS([m4])
LT_INIT([])
AC_ENABLE_SHARED
AC_ENABLE_SHARED([])
LT_INIT()
AM_INIT_AUTOMAKE()
AC_PROG_CC
AC_CHECK_HEADER([getopt.h],
    [AC_DEFINE([HAVE_GETOPT_H], 1, [Define to 1 if you have <getopt.h>.])],
        [AC_MSG_ERROR([utftex needs getopt support to run. Please install it.])])
AC_MSG_CHECKING([if libtool needs -no-undefined flag to build shared libraries])
case "$host_os" in
  cygwin*|msys*|mingw*)
    ## Add in the -no-undefined flag to LDFLAGS for libtool.
    AC_MSG_RESULT([yes])
    LDFLAGS="$LDFLAGS -no-undefined"
    ;;
  *)
    ## Don't add in anything.
    AC_MSG_RESULT([no])
    ;;
esac
AC_DEFINE([UTFTEXVERSION], ["1.16"], [utftex version string])
AC_CONFIG_SRCDIR([src/boxes.c])
AC_CONFIG_HEADERS([src/config.h])
AC_CHECK_LIB([m],[cos])
AC_CONFIG_FILES([
 Makefile src/Makefile
])
AC_OUTPUT
