AC_INIT([libtexprintf], [1.13])
AC_CONFIG_MACRO_DIRS([m4])
AC_PROG_LIBTOOL()
AC_ENABLE_SHARED
AM_ENABLE_SHARED
LT_INIT()
AM_INIT_AUTOMAKE()
AC_PROG_CC
AC_CHECK_HEADER([getopt.h],
    [AC_DEFINE([HAVE_GETOPT_H], 1, [Define to 1 if you have <getopt.h>.])],
		[AC_MSG_ERROR([utftex needs getopt support to run. Please install it.])])
AC_DEFINE([UTFTEXVERSION], ["1.11"], [utftex version string])
AC_CONFIG_SRCDIR([src/boxes.c])
AC_CONFIG_HEADERS([src/config.h])
AC_CONFIG_FILES([
 Makefile src/Makefile
])
AC_OUTPUT
