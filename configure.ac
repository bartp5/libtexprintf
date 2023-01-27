AC_INIT([libtexprintf], [1.14])
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
AC_DEFINE([UTFTEXVERSION], ["1.11"], [utftex version string])
AC_CONFIG_SRCDIR([src/boxes.c])
AC_CONFIG_HEADERS([src/config.h])
AC_CONFIG_LINKS([test/eq1.tex:test/eq1.tex])
AC_CONFIG_LINKS([test/eq2.tex:test/eq2.tex])
AC_CONFIG_LINKS([test/eq3.tex:test/eq3.tex])
AC_CONFIG_LINKS([test/eq4.tex:test/eq4.tex])
AC_CONFIG_LINKS([test/eq5.tex:test/eq5.tex])
AC_CONFIG_LINKS([test/eq6.tex:test/eq6.tex])
AC_CONFIG_LINKS([test/eq7.tex:test/eq7.tex])
AC_CONFIG_LINKS([test/eq8.tex:test/eq8.tex])
AC_CONFIG_LINKS([test/eq9.tex:test/eq9.tex])
AC_CONFIG_LINKS([test/eq10.tex:test/eq10.tex])
AC_CONFIG_LINKS([test/eq11.tex:test/eq11.tex])
AC_CONFIG_LINKS([test/eq12.tex:test/eq12.tex])
AC_CONFIG_LINKS([test/eq13.tex:test/eq13.tex])
AC_CONFIG_LINKS([test/eq14.tex:test/eq14.tex])
AC_CONFIG_LINKS([test/eq15.tex:test/eq15.tex])
AC_CONFIG_LINKS([test/eq16.tex:test/eq16.tex])
AC_CONFIG_LINKS([test/eq17.tex:test/eq17.tex])
AC_CONFIG_LINKS([test/eq18.tex:test/eq18.tex])

AC_CONFIG_LINKS([test/eq1.ref:test/eq1.ref])
AC_CONFIG_LINKS([test/eq2.ref:test/eq2.ref])
AC_CONFIG_LINKS([test/eq3.ref:test/eq3.ref])
AC_CONFIG_LINKS([test/eq4.ref:test/eq4.ref])
AC_CONFIG_LINKS([test/eq5.ref:test/eq5.ref])
AC_CONFIG_LINKS([test/eq6.ref:test/eq6.ref])
AC_CONFIG_LINKS([test/eq7.ref:test/eq7.ref])
AC_CONFIG_LINKS([test/eq8.ref:test/eq8.ref])
AC_CONFIG_LINKS([test/eq9.ref:test/eq9.ref])
AC_CONFIG_LINKS([test/eq10.ref:test/eq10.ref])
AC_CONFIG_LINKS([test/eq11.ref:test/eq11.ref])
AC_CONFIG_LINKS([test/eq12.ref:test/eq12.ref])
AC_CONFIG_LINKS([test/eq13.ref:test/eq13.ref])
AC_CONFIG_LINKS([test/eq14.ref:test/eq14.ref])
AC_CONFIG_LINKS([test/eq15.ref:test/eq15.ref])
AC_CONFIG_LINKS([test/eq16.ref:test/eq16.ref])
AC_CONFIG_LINKS([test/eq17.ref:test/eq17.ref])
AC_CONFIG_LINKS([test/eq18.ref:test/eq18.ref])
AC_CONFIG_LINKS([test/font.ref:test/font.ref])

AC_CONFIG_LINKS([runtest.sh:runtest.sh])
AC_CONFIG_LINKS([testfont.sh:testfont.sh])
AC_CONFIG_FILES([
 Makefile src/Makefile
])
AC_OUTPUT
