/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.28 from the
 * contents of unix.xs. Do not edit this file, edit unix.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "src/auto/XSTools/unix/unix.xs"
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <string.h>
#include "consoleui.h"

#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

#ifdef TIOCGWINSZ
	#define WINSIZE(name) struct winsize name
#else
	#define TIOCGWINSZ 0
	#define WINSIZE(name) struct { int ws_col, ws_row; } name
	#define ioctl(a, b, c) 0
#endif

#line 29 "src/auto/XSTools/unix/unix.c"
#ifndef PERL_UNUSED_VAR
#  define PERL_UNUSED_VAR(var) if (0) var = var
#endif

#ifndef dVAR
#  define dVAR		dNOOP
#endif


/* This stuff is not part of the API! You have been warned. */
#ifndef PERL_VERSION_DECIMAL
#  define PERL_VERSION_DECIMAL(r,v,s) (r*1000000 + v*1000 + s)
#endif
#ifndef PERL_DECIMAL_VERSION
#  define PERL_DECIMAL_VERSION \
	  PERL_VERSION_DECIMAL(PERL_REVISION,PERL_VERSION,PERL_SUBVERSION)
#endif
#ifndef PERL_VERSION_GE
#  define PERL_VERSION_GE(r,v,s) \
	  (PERL_DECIMAL_VERSION >= PERL_VERSION_DECIMAL(r,v,s))
#endif
#ifndef PERL_VERSION_LE
#  define PERL_VERSION_LE(r,v,s) \
	  (PERL_DECIMAL_VERSION <= PERL_VERSION_DECIMAL(r,v,s))
#endif

/* XS_INTERNAL is the explicit static-linkage variant of the default
 * XS macro.
 *
 * XS_EXTERNAL is the same as XS_INTERNAL except it does not include
 * "STATIC", ie. it exports XSUB symbols. You probably don't want that
 * for anything but the BOOT XSUB.
 *
 * See XSUB.h in core!
 */


/* TODO: This might be compatible further back than 5.10.0. */
#if PERL_VERSION_GE(5, 10, 0) && PERL_VERSION_LE(5, 15, 1)
#  undef XS_EXTERNAL
#  undef XS_INTERNAL
#  if defined(__CYGWIN__) && defined(USE_DYNAMIC_LOADING)
#    define XS_EXTERNAL(name) __declspec(dllexport) XSPROTO(name)
#    define XS_INTERNAL(name) STATIC XSPROTO(name)
#  endif
#  if defined(__SYMBIAN32__)
#    define XS_EXTERNAL(name) EXPORT_C XSPROTO(name)
#    define XS_INTERNAL(name) EXPORT_C STATIC XSPROTO(name)
#  endif
#  ifndef XS_EXTERNAL
#    if defined(HASATTRIBUTE_UNUSED) && !defined(__cplusplus)
#      define XS_EXTERNAL(name) void name(pTHX_ CV* cv __attribute__unused__)
#      define XS_INTERNAL(name) STATIC void name(pTHX_ CV* cv __attribute__unused__)
#    else
#      ifdef __cplusplus
#        define XS_EXTERNAL(name) extern "C" XSPROTO(name)
#        define XS_INTERNAL(name) static XSPROTO(name)
#      else
#        define XS_EXTERNAL(name) XSPROTO(name)
#        define XS_INTERNAL(name) STATIC XSPROTO(name)
#      endif
#    endif
#  endif
#endif

/* perl >= 5.10.0 && perl <= 5.15.1 */


/* The XS_EXTERNAL macro is used for functions that must not be static
 * like the boot XSUB of a module. If perl didn't have an XS_EXTERNAL
 * macro defined, the best we can do is assume XS is the same.
 * Dito for XS_INTERNAL.
 */
#ifndef XS_EXTERNAL
#  define XS_EXTERNAL(name) XS(name)
#endif
#ifndef XS_INTERNAL
#  define XS_INTERNAL(name) XS(name)
#endif

/* Now, finally, after all this mess, we want an ExtUtils::ParseXS
 * internal macro that we're free to redefine for varying linkage due
 * to the EXPORT_XSUB_SYMBOLS XS keyword. This is internal, use
 * XS_EXTERNAL(name) or XS_INTERNAL(name) in your code if you need to!
 */

#undef XS_EUPXS
#if defined(PERL_EUPXS_ALWAYS_EXPORT)
#  define XS_EUPXS(name) XS_EXTERNAL(name)
#else
   /* default to internal */
#  define XS_EUPXS(name) XS_INTERNAL(name)
#endif

#ifndef PERL_ARGS_ASSERT_CROAK_XS_USAGE
#define PERL_ARGS_ASSERT_CROAK_XS_USAGE assert(cv); assert(params)

/* prototype to pass -Wmissing-prototypes */
STATIC void
S_croak_xs_usage(const CV *const cv, const char *const params);

STATIC void
S_croak_xs_usage(const CV *const cv, const char *const params)
{
    const GV *const gv = CvGV(cv);

    PERL_ARGS_ASSERT_CROAK_XS_USAGE;

    if (gv) {
        const char *const gvname = GvNAME(gv);
        const HV *const stash = GvSTASH(gv);
        const char *const hvname = stash ? HvNAME(stash) : NULL;

        if (hvname)
	    Perl_croak_nocontext("Usage: %s::%s(%s)", hvname, gvname, params);
        else
	    Perl_croak_nocontext("Usage: %s(%s)", gvname, params);
    } else {
        /* Pants. I don't think that it should be possible to get here. */
	Perl_croak_nocontext("Usage: CODE(0x%"UVxf")(%s)", PTR2UV(cv), params);
    }
}
#undef  PERL_ARGS_ASSERT_CROAK_XS_USAGE

#define croak_xs_usage        S_croak_xs_usage

#endif

/* NOTE: the prototype of newXSproto() is different in versions of perls,
 * so we define a portable version of newXSproto()
 */
#ifdef newXS_flags
#define newXSproto_portable(name, c_impl, file, proto) newXS_flags(name, c_impl, file, proto, 0)
#else
#define newXSproto_portable(name, c_impl, file, proto) (PL_Sv=(SV*)newXS(name, c_impl, file), sv_setpv(PL_Sv, proto), (CV*)PL_Sv)
#endif /* !defined(newXS_flags) */

#if PERL_VERSION_LE(5, 21, 5)
#  define newXS_deffile(a,b) Perl_newXS(aTHX_ a,b,file)
#else
#  define newXS_deffile(a,b) Perl_newXS_deffile(aTHX_ a,b)
#endif

#line 173 "src/auto/XSTools/unix/unix.c"

XS_EUPXS(XS_Utils__Unix_getTerminalSize); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Utils__Unix_getTerminalSize)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
#line 26 "src/auto/XSTools/unix/unix.xs"
		WINSIZE(size);
#line 186 "src/auto/XSTools/unix/unix.c"
#line 28 "src/auto/XSTools/unix/unix.xs"
		if (ioctl (1, TIOCGWINSZ, &size) != 0) {
			size.ws_col = 80;
			size.ws_row = 24;
		}
		XPUSHs (sv_2mortal (newSVnv (size.ws_col)));
		XPUSHs (sv_2mortal (newSVnv (size.ws_row)));
#line 194 "src/auto/XSTools/unix/unix.c"
	PUTBACK;
	return;
    }
}


/* INCLUDE:  Including 'consoleui-perl.xs' from 'unix.xs' */


XS_EUPXS(XS_Utils__Unix__ConsoleUI_start); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Utils__Unix__ConsoleUI_start)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    {
#line 6 "src/auto/XSTools/unix/consoleui-perl.xs"
	// Initialize singleton.
	ConsoleUI::getInstance()->start();
#line 214 "src/auto/XSTools/unix/unix.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Utils__Unix__ConsoleUI_stop); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Utils__Unix__ConsoleUI_stop)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    {
#line 12 "src/auto/XSTools/unix/consoleui-perl.xs"
	ConsoleUI::getInstance()->stop();
#line 229 "src/auto/XSTools/unix/unix.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Utils__Unix__ConsoleUI_getInput); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Utils__Unix__ConsoleUI_getInput)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    {
	SV *	RETVAL;
#line 17 "src/auto/XSTools/unix/consoleui-perl.xs"
	char *line;
#line 245 "src/auto/XSTools/unix/unix.c"
#line 19 "src/auto/XSTools/unix/consoleui-perl.xs"
	line = ConsoleUI::getInstance()->getInput();
	if (line == NULL) {
		XSRETURN_UNDEF;
	} else {
		RETVAL = newSVpv(line, strlen(line));
		free(line);
	}
#line 254 "src/auto/XSTools/unix/unix.c"
	RETVAL = sv_2mortal(RETVAL);
	ST(0) = RETVAL;
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Utils__Unix__ConsoleUI_print); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Utils__Unix__ConsoleUI_print)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "msg");
    {
	char *	msg = (char *)SvPV_nolen(ST(0))
;
#line 33 "src/auto/XSTools/unix/consoleui-perl.xs"
	ConsoleUI::getInstance()->print(msg);
#line 273 "src/auto/XSTools/unix/unix.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Utils__Unix__ConsoleUI_waitUntilPrinted); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Utils__Unix__ConsoleUI_waitUntilPrinted)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    {
#line 38 "src/auto/XSTools/unix/consoleui-perl.xs"
	ConsoleUI::getInstance()->waitUntilPrinted();
#line 288 "src/auto/XSTools/unix/unix.c"
    }
    XSRETURN_EMPTY;
}


/* INCLUDE: Returning to 'unix.xs' from 'consoleui-perl.xs' */

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Utils__Unix); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Utils__Unix)
{
#if PERL_VERSION_LE(5, 21, 5)
    dVAR; dXSARGS;
#else
    dVAR; dXSBOOTARGSXSAPIVERCHK;
#endif
#if (PERL_REVISION == 5 && PERL_VERSION < 9)
    char* file = __FILE__;
#else
    const char* file = __FILE__;
#endif

    PERL_UNUSED_VAR(file);

    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(items); /* -W */
#if PERL_VERSION_LE(5, 21, 5)
    XS_VERSION_BOOTCHECK;
#  ifdef XS_APIVERSION_BOOTCHECK
    XS_APIVERSION_BOOTCHECK;
#  endif
#endif

        (void)newXSproto_portable("Utils::Unix::getTerminalSize", XS_Utils__Unix_getTerminalSize, file, "");
        (void)newXSproto_portable("Utils::Unix::ConsoleUI::start", XS_Utils__Unix__ConsoleUI_start, file, "");
        (void)newXSproto_portable("Utils::Unix::ConsoleUI::stop", XS_Utils__Unix__ConsoleUI_stop, file, "");
        (void)newXSproto_portable("Utils::Unix::ConsoleUI::getInput", XS_Utils__Unix__ConsoleUI_getInput, file, "");
        (void)newXSproto_portable("Utils::Unix::ConsoleUI::print", XS_Utils__Unix__ConsoleUI_print, file, "$");
        (void)newXSproto_portable("Utils::Unix::ConsoleUI::waitUntilPrinted", XS_Utils__Unix__ConsoleUI_waitUntilPrinted, file, "");
#if PERL_VERSION_LE(5, 21, 5)
#  if PERL_VERSION_GE(5, 9, 0)
    if (PL_unitcheckav)
        call_list(PL_scopestack_ix, PL_unitcheckav);
#  endif
    XSRETURN_YES;
#else
    Perl_xs_boot_epilog(aTHX_ ax);
#endif
}

