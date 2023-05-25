ACLOCAL_AMFLAGS = -I m4
AM_CFLAGS = -Wall

# -- Top-level Makefile.am --
lib_LTLIBRARIES = libtexprintf.la
libtexprintf_la_SOURCES = boxes.c  drawbox.c  texprintf.c parser.c lexer.c boxes.h error.c drawbox.h drawchars.h texprintf.h stringutils.h  unicodeblocks.h parser.h lexer.h parsedef.h mapunicode.h error.h gen_errorflags.sh texprintfsymbols texprintf.3
nodist_libtexprintf_la_SOURCES = errorflags.h errormessages.h texprintfsymbols
CLEANFILES = errorflags.h errormessages.h texprintfsymbols
libtexprintf_la_LIBADD = libstringutils.la
libtexprintf_la_LDFLAGS = -export-symbols ${srcdir}/texprintfsymbols -version-info 1:0:0
man3_MANS = texprintf.3
include_HEADERS = texprintf.h

# -- libstringutils/Makefile.am --
noinst_LTLIBRARIES = libstringutils.la
libstringutils_la_SOURCES = stringutils.c


bin_PROGRAMS = utftex utfstringinfo
utftex_SOURCES = main.c testfonts.c testfonts.h boxes.c error.c stringutils.c drawbox.c lexer.c parser.c
utftex_LDADD = libtexprintf.la
utftex_CFLAGS = $(AM_CFLAGS) # see https://www.gnu.org/software/automake/manual/html_node/Objects-created-both-with-libtool-and-without.html
utfstringinfo_SOURCES = stringutils.h unicodeblocks.h utf2unicode.c parsedef.h
utfstringinfo_LDADD = libstringutils.la
man1_MANS = utftex.1 utfstringinfo.1

EXTRA_DIST = utftex.1 utfstringinfo.1 gen_errorflags.sh gentexprintfsymbols.sh

BUILT_SOURCES = errorflags.h errormessages.h texprintfsymbols

errorflags.h: gen_errorflags.sh boxes.c drawbox.c lexer.c parser.c
	${SHELL} ${srcdir}/gen_errorflags.sh ${srcdir}/boxes.c ${srcdir}/drawbox.c ${srcdir}/lexer.c ${srcdir}/parser.c

# see https://www.gnu.org/software/automake/manual/html_node/Multiple-Outputs.html
errormessages.h: errorflags.h
	@test -f $@ || rm -f errorflags.h
	@test -f $@ || $(MAKE) $(AM_MAKEFLAGS) errorflags.h

texprintfsymbols: gentexprintfsymbols.sh texprintf.h
	${SHELL} ${srcdir}/gentexprintfsymbols.sh
