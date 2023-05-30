SUBDIRS = src

TESTS_ENVIRONMENT = \
  utftex=$(abs_builddir)/src/utftex
  export utftex;
TESTS=runtest.sh testfont.sh testascii.sh testerrors.sh testsprintf.sh testtexsymbols.sh

EXTRA_DIST = runtest.sh testfont.sh  testascii.sh testerrors.sh testsprintf.sh testtexsymbols.sh test/eq1.tex \
			 test/eq2.tex test/eq3.tex test/eq4.tex test/eq5.tex test/eq6.tex test/eq7.tex test/eq8.tex \
			 test/eq9.tex test/eq10.tex test/eq11.tex test/eq12.tex test/eq13.tex test/eq14.tex test/eq15.tex \
			 test/eq16.tex test/eq17.tex test/eq18.tex test/eq19.tex test/eq20.tex test/mathjax_examples.tex test/font.tex \
             test/eq1.ref test/eq2.ref test/eq3.ref test/eq4.ref test/eq5.ref test/eq6.ref test/eq7.ref \
             test/eq8.ref test/eq9.ref test/eq10.ref test/eq11.ref test/eq12.ref test/eq13.ref test/eq14.ref \
             test/eq15.ref test/eq16.ref test/eq17.ref test/eq18.ref test/eq19.ref test/eq20.ref test/eq21.ref test/mathjax_examples.ref test/font.ref \
             test/eq1-A.ref test/eq2-A.ref test/eq3-A.ref test/eq4-A.ref test/eq5-A.ref test/eq6-A.ref test/eq7-A.ref \
             test/eq8-A.ref test/eq9-A.ref test/eq10-A.ref test/eq11-A.ref test/eq12-A.ref test/eq13-A.ref test/eq14-A.ref \
             test/eq15-A.ref test/eq16-A.ref test/eq17-A.ref test/eq18-A.ref  test/eq19-A.ref test/eq20-A.ref test/eq21-A.ref \
             test/mathjax_examples-A.ref test/font.ref \
             test/fontmathbb.ref test/fontmathbf.ref test/fontmathbfit.ref test/fontmathcal.ref \
             test/fontmathfrak.ref test/fontmathnormal.ref test/fontmathscr.ref test/fontmathsf.ref \
             test/fontmathsfbf.ref test/fontmathsfbfit.ref test/fontmathsfit.ref test/fontmathtt.ref \
             test/fonttext.ref test/README

CLEANFILES = test/eq1-A.new test/eq1.new test/eq10-A.new test/eq10.new test/eq11-A.new test/eq11.new test/eq12-A.new test/eq12.new \
             test/eq13-A.new test/eq13.new test/eq14-A.new test/eq14.new test/eq15-A.new test/eq15.new test/eq16-A.new test/eq16.new \
             test/eq17-A.new test/eq17.new test/eq18-A.new test/eq18.new test/eq19-A.new test/eq19.new test/eq20-A.new test/eq20.new \
             test/eq21-A.new test/eq21.new test/eq2-A.new test/eq2.new test/eq3-A.new test/eq3.new test/eq4-A.new test/eq4.new test/eq5-A.new test/eq5.new \
			 test/eq6-A.new test/eq6.new test/eq7-A.new test/eq7.new test/eq8-A.new test/eq8.new test/eq9-A.new test/eq9.new \
			 test/font-A.new test/font.new test/fontmathbb.new test/fontmathbf.new test/fontmathbfit.new test/fontmathcal.new \
			 test/fontmathfrak.new test/fontmathnormal.new test/fontmathscr.new test/fontmathsf.new test/fontmathsfbf.new \
			 test/fontmathsfbfit.new test/fontmathsfit.new test/fontmathtt.new test/fonttext.new test/mathjax_examples-A.new \
			 test/mathjax_examples.new
DISTCLEANFILES = configure~ src/config.h.in~
