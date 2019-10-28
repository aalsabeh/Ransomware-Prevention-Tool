##############################################################################
##
##  Makefile for Detours Test Programs.
##
##  Microsoft Research Detours Package, Version 3.0.
##
##  Copyright (c) Microsoft Corporation.  All rights reserved.
##
##  Note:
##    syelog, setdll, and withdll must be built first because a number of the
##    other samples depend on them.
##

ROOT=..
!include .\common.mak

##############################################################################

all:
    cd "$(MAKEDIR)\syelog"
    @$(MAKE) /NOLOGO /$(MAKEFLAGS)
    cd "$(MAKEDIR)\setdll"
    @$(MAKE) /NOLOGO /$(MAKEFLAGS)
    cd "$(MAKEDIR)\withdll"
    @$(MAKE) /NOLOGO /$(MAKEFLAGS)

    cd "$(MAKEDIR)\traceapi"
    @$(MAKE) /NOLOGO /$(MAKEFLAGS)

clean:
    cd "$(MAKEDIR)\syelog"
    @$(MAKE) /NOLOGO /$(MAKEFLAGS) clean
    cd "$(MAKEDIR)\setdll"
    @$(MAKE) /NOLOGO /$(MAKEFLAGS) clean
    cd "$(MAKEDIR)\withdll"
    @$(MAKE) /NOLOGO /$(MAKEFLAGS) clean
    cd "$(MAKEDIR)\traceapi"
    @$(MAKE) /NOLOGO /$(MAKEFLAGS) clean
    -rmdir lib32 2>nul
    -rmdir lib64 2>nul
    -rmdir include 2>nul

realclean:
    cd "$(MAKEDIR)\syelog"
    @$(MAKE) /NOLOGO /$(MAKEFLAGS) realclean
    cd "$(MAKEDIR)\setdll"
    @$(MAKE) /NOLOGO /$(MAKEFLAGS) realclean
    cd "$(MAKEDIR)\withdll"
    @$(MAKE) /NOLOGO /$(MAKEFLAGS) realclean
    cd "$(MAKEDIR)\traceapi"
    @$(MAKE) /NOLOGO /$(MAKEFLAGS) realclean
    -rmdir lib32 2>nul
    -rmdir lib64 2>nul
    -rmdir include 2>nul

test:
     cd "$(MAKEDIR)\traceapi"
     @$(MAKE) /NOLOGO /$(MAKEFLAGS) test

##
################################################################# End of File.
