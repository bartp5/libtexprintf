ACLOCAL_AMFLAGS = -I m4
AM_CFLAGS = -Wall

# -- Top-level Makefile.am --
lib_LTLIBRARIES = libtexprintf.la
libtexprintf_la_SOURCES = boxes.c  drawbox.c  texprintf.c parser.c lexer.c boxes.h error.c drawbox.h  texprintf.h stringutils.h  unicodeblocks.h parser.h lexer.h parsedef.h mapunicode.h error.h gen_errorflags.sh texprintfsymbols texprintf.3
nodist_libtexprintf_la_SOURCES = errorflags.h errormessages.h
CLEANFILES = errorflags.h errormessages.h
libtexprintf_la_LIBADD = libstringutils.la
libtexprintf_la_LDFLAGS = -export-symbols ${srcdir}/texprintfsymbols -version-info 1:0:0 
man3_MANS = texprintf.3 
include_HEADERS = texprintf.h

# -- libstringutils/Makefile.am --
noinst_LTLIBRARIES = libstringutils.la
libstringutils_la_SOURCES = stringutils.c


bin_PROGRAMS = utftex utfstringinfo
utftex_SOURCES = main.c testfonts.c testfonts.h
utftex_LDADD = libtexprintf.la boxes.o error.o stringutils.o drawbox.o lexer.o parser.o
utfstringinfo_SOURCES = stringutils.h unicodeblocks.h utf2unicode.c parsedef.h
utfstringinfo_LDADD = libstringutils.la
man1_MANS = utftex.1 utfstringinfo.1 
EXTRA_DIST = utftex.1 utfstringinfo.1


BUILT_SOURCES = errorflags.h gen_errorflags.sh

errorflags.h errormessages.h: gen_errorflags.sh boxes.c drawbox.c lexer.c parser.c
	${SHELL} ${srcdir}/gen_errorflags.sh ${srcdir}/boxes.c ${srcdir}/drawbox.c ${srcdir}/lexer.c ${srcdir}/parser.c

