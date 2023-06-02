SUBDIRS = src

TESTS_ENVIRONMENT = \
  utftex=$(abs_builddir)/src/utftex
  export utftex;
TESTS=testsuite.sh testerrors.sh testtexsymbols.sh

EXTRA_DIST = testsuite.sh testerrors.sh testtexsymbols.sh test/testsuite.txt test/test.awk test/README

DISTCLEANFILES = configure~ src/config.h.in~
