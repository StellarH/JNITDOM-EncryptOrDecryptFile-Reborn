@ECHO off

IF NOT EXIST "build" (
	MKDIR "build"
)

CD "build"

cmake -S .. -B . -G "MinGW Makefiles"

IF EXIST "Makefile" (
	make
) ELSE (
	ECHO ==============================================================================
	ECHO Build Failed!
)

PAUSE
CD ..
