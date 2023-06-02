SUBDIRS = src

TESTS_ENVIRONMENT = \
  utftex=$(abs_builddir)/src/utftex
  export utftex;
TESTS=testsuite.sh testeqs.sh testfonts.sh testerrors.sh testtexsymbols.sh

EXTRA_DIST = testsuite.sh testeqs.sh testfonts.sh testerrors.sh testtexsymbols.sh test/testsuite.txt test/testeqs.txt test/testfonts.txt test/test.awk test/README

DISTCLEANFILES = configure~ src/config.h.in~
