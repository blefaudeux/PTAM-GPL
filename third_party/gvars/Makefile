# Makefile.  Generated from Makefile.in by configure.

SHELL = /bin/sh
srcdir = .
top_srcdir = .

prefix = /usr/local
exec_prefix = ${prefix}
bindir = ${exec_prefix}/bin
sbindir = ${exec_prefix}/sbin
libexecdir = ${exec_prefix}/libexec
datadir = ${datarootdir}
datarootdir = ${prefix}/share
sysconfdir = ${prefix}/etc
sharedstatedir = ${prefix}/com
localstatedir = ${prefix}/var
libdir = ${exec_prefix}/lib
infodir = ${datarootdir}/info
mandir = ${datarootdir}/man
includedir = ${prefix}/include
oldincludedir = /usr/include
arch= x86_64


CC = @CC@
CXX=g++
CPPFLAGS = -I.  -INONE/include
CFLAGS = $(CPPFLAGS) @CFLAGS@
CXXFLAGS = $(CPPFLAGS) -g -O2 -Wall -Wextra -pthread
OFLAGS=@OFLAGS@
LDFLAGS = 
LIBS =  -lm 
HLIBS =  -lm 
INSTALL = @INSTALL@
AR=ar

ifneq "$(DESTDIR)" ""
DESTDIR+=/
endif


pkgdatadir = $(datadir)/@PACKAGE@
pkglibdir = $(libdir)/@PACKAGE@
pkgincludedir = $(includedir)/@PACKAGE@

top_builddir = .

ACLOCAL = @ACLOCAL@
AUTOCONF = @AUTOCONF@
AUTOMAKE = @AUTOMAKE@
AUTOHEADER = @AUTOHEADER@

INSTALL = @INSTALL@
INSTALL_PROGRAM = @INSTALL_PROGRAM@ $(AM_INSTALL_PROGRAM_FLAGS)
INSTALL_DATA = @INSTALL_DATA@
INSTALL_SCRIPT = @INSTALL_SCRIPT@
transform = s,x,x,

NORMAL_INSTALL = :
PRE_INSTALL = :
POST_INSTALL = :
NORMAL_UNINSTALL = :
PRE_UNINSTALL = :
POST_UNINSTALL = :
MAKEINFO = @MAKEINFO@
PACKAGE = @PACKAGE@
VERSION = @VERSION@

SUBDIRS =
ACLOCAL_M4 = $(top_srcdir)/aclocal.m4
mkinstalldirs = $(SHELL) $(top_srcdir)/mkinstalldirs
CONFIG_CLEAN_FILES =
DIST_COMMON =  README ChangeLog Makefile.am \
Makefile.in aclocal.m4 configure configure.ac install-sh missing \
mkinstalldirs


DISTFILES = $(DIST_COMMON) $(SOURCES) $(HEADERS) $(TEXINFOS) $(EXTRA_DIST)

TAR = gtar
GZIP_ENV = --best

optional_objs=
ifeq (,yes)
	optional_objs+=src/GUI_language.o
else
	optional_objs+=src/GUI_no_language.o
endif

HEADLESSOBJS=\
	src/gvars3.o			\
	src/GUI.o				\
	src/GStringUtil.o		\
	src/gvars2.o			\
	src/serialize.o			\
	src/GUI_none.o			\
	src/GUI_impl_headless.o\
	src/inst.o				\
	$(optional_objs)

OBJS=\
	src/gvars3.o			\
	src/GUI.o				\
	src/GStringUtil.o		\
	src/gvars2.o			\
	src/serialize.o			\
	src/GUI_none.o          \
	src/GUI_non_readline.o	\
	src/inst.o\
	$(optional_objs)

ifeq (,yes)
	OBJS+=src/GUI_readline.o
	OBJS+=src/GUI_impl_readline.o
	CPPFLAGS+=-DGUI_HAVE_READLINE
else
	OBJS+=src/GUI_impl_noreadline.o
endif

	#src/@readlineobj@.o     \
#G++ seems to run constructors in the reverse order
#so inst needs to be last.

DEBUG_OBJS=$(OBJS:src%=debug/%)
DEBUG_HEADLESS_OBJS=$(HEADLESSOBJS:src%=debug/%)


ifeq (x86_64,x86_64)
    CPPFLAGS+=-fPIC
endif


ifeq (,yes)

	dhsoname=libGVars3_debug_headless.dylib
	dhsoname1=libGVars3_debug_headless-0.dylib
	dhsoname2=libGVars3_debug_headless-0.6.dylib
	 
	dsoname=libGVars3_debug.dylib
	dsoname1=libGVars3_debug-0.dylib
	dsoname2=libGVars3_debug-0.6.dylib

	hsoname=libGVars3_headless.dylib
	hsoname1=libGVars3_headless-0.dylib
	hsoname2=libGVars3_headless-0.6.dylib
	 
	soname=libGVars3.dylib
	soname1=libGVars3-0.dylib
	soname2=libGVars3-0.6.dylib
	shared=-dynamiclib
else
	dhsoname=libGVars3_debug_headless.so
	dhsoname1=libGVars3_debug_headless.so.0
	dhsoname2=libGVars3_debug_headless.so.0.6

	dsoname=libGVars3_debug.so
	dsoname1=libGVars3_debug.so.0
	dsoname2=libGVars3_debug.so.0.6

	hsoname=libGVars3_headless.so
	hsoname1=libGVars3_headless.so.0
	hsoname2=libGVars3_headless.so.0.6

	soname=libGVars3.so
	soname1=libGVars3.so.0
	soname2=libGVars3.so.0.6
	shared=-shared
endif

archive=libGVars3.a
harchive=libGVars3_headless.a
darchive=libGVars3_debug.a
dharchive=libGVars3_debug_headless.a

sos=   $(soname)   $(soname1)   $(soname2)
hsos=  $(hsoname)  $(hsoname1)  $(hsoname2)
dsos=  $(dsoname)  $(dsoname1)  $(dsoname2)
dhsos= $(dhsoname) $(dhsoname1) $(dhsoname2)

install_shared=

ifneq (,no)
	NORMAL=$(archive) $(snoame)
	install_shared+=install-shared-normal
	Narchive=$(archive)
endif

ifeq (yes,yes)
	HEADLESS=$(harchive) $(hsoname)
	Harchive=$(harchive)
	install_shared+=install-shared-headless
endif

ifeq (,yes)
	DEBUG=$(darchive) $(dsoname)
	Darchive=$(darchive)
	install_shared+=install-shared-debug
endif

ifeq (yes,yesyes)
	DEBUG_HEADLESS=$(dharchive) $(dhsoname)
	DHarchive=$(dharchive)
	install_shared+=install-shared-debug-headless
endif


all: $(NORMAL) $(HEADLESS) $(DEBUG) $(DEBUG_HEADLESS)

$(dhsoname): $(DEBUG_HEADLESS_OBJS)
	rm -f $(dhsos)
	$(CXX) $(shared) -o $(dhsoname2) $(DEBUG_HEADLESS_OBJS) $(LIBS)
	ln -s $(dhsoname2) $(dhsoname1)
	ln -s $(dhsoname1) $(dhsoname)

$(dsoname): $(DEBUG_OBJS)
	rm -f $(dsos)
	$(CXX) $(shared) -o $(dsoname2) $(DEBUG_OBJS) $(LIBS)
	ln -s $(dsoname2) $(dsoname1)
	ln -s $(dsoname1) $(dsoname)


$(hsoname): $(HEADLESSOBJS)
	rm -f $(hsos)
	$(CXX) $(shared) -o $(hsoname2) $(HEADLESSOBJS) $(HLIBS)
	ln -s $(hsoname2) $(hsoname1)
	ln -s $(hsoname1) $(hsoname)

$(soname): $(OBJS)
	rm -f $(sos)
	$(CXX) $(shared) -o $(soname2) $(OBJS) $(LIBS)
	ln -s $(soname2) $(soname1)
	ln -s $(soname1) $(soname)

.PHONY: install-static install-headers install-shared-normal install-shared-headless

install:install-static $(install_shared) install-headers

install-static: $(Narchive) $(Harchive) $(DHarchive) $(Darchive) 
	mkdir -p $(DESTDIR)$(libdir)
	cp $(Narchive) $(Harchive) $(DHarchive) $(Darchive) $(DESTDIR)$(libdir)

install-shared-normal: $(soname) 
	mkdir -p $(DESTDIR)$(libdir)
	cp $(soname2) $(DESTDIR)$(libdir)
	ln -fs  ./$(soname2) $(DESTDIR)$(libdir)/$(soname1)
	ln -fs  ./$(soname1) $(DESTDIR)$(libdir)/$(soname)
	
install-shared-headless: $(hsoname) 
	mkdir -p $(DESTDIR)$(libdir)
	cp $(hsoname2) $(DESTDIR)$(libdir)
	ln -fs  ./$(hsoname2) $(DESTDIR)$(libdir)/$(hsoname1)
	ln -fs  ./$(hsoname1) $(DESTDIR)$(libdir)/$(hsoname)
	
install-shared-debug: $(dsoname) 
	mkdir -p $(DESTDIR)$(libdir)
	cp $(dsoname2) $(DESTDIR)$(libdir)
	ln -fs  ./$(dsoname2) $(DESTDIR)$(libdir)/$(dsoname1)
	ln -fs  ./$(dsoname1) $(DESTDIR)$(libdir)/$(dsoname)

install-shared-debug-headless: $(dhsoname) 
	mkdir -p $(DESTDIR)$(libdir)
	cp $(dhsoname2) $(DESTDIR)$(libdir)
	ln -fs  ./$(dhsoname2) $(DESTDIR)$(libdir)/$(dhsoname1)
	ln -fs  ./$(dhsoname1) $(DESTDIR)$(libdir)/$(dhsoname)
	
	
install-headers:
	mkdir -p $(DESTDIR)$(includedir)
	cp -r gvars3 $(DESTDIR)$(includedir)
	
$(darchive): $(DEBUG_OBJS)
	$(AR) crvs $@ $^

$(harchive): $(HEADLESSOBJS)
	$(AR) crvs $@ $^

$(dharchive): $(DEBUG_HEADLESS_OBJS)
	$(AR) crvs $@ $^

$(archive): $(OBJS)
	$(AR) crvs $@ $^

debug: debug/foo
	
debug/foo:
	mkdir -p debug
	touch debug/foo

debug/%.o : src/%.cc debug/foo
	$(CXX) -I. $(CPPFLAGS) $(CXXFLAGS) -O0 -D_GLIBCXX_DEBUG -c $< -o $@

clean:
	rm -f *.a src/*.o *.so *.so.? test *.o *.so.?.? main debug/*

main:  main.cc
	$(CXX) $(CXXFLAGS) -o main -lGVars3 main.cc
