@echo off
echo --Parameters: %1 %2
echo --Mode: %1
echo --File: %2

if "%1" EQU "" goto error
if /I "%1" EQU "create" goto create
if /I "%1" EQU "delete" goto delete
if "%1" NEQ "delete" goto error1
if "%1" NEQ "create" goto error1

:create
	if "%2" NEQ "" goto checkFileToCreate
	echo --no filename
	goto exit

:checkFileToCreate
	if exist %2 (goto existFile)
	copy NUL %2
	echo --file %2 created
	goto exit

:existFile
	echo --file %2 already exist
	goto exit

:delete
	if "%2" NEQ "" goto checkFileToDelete
	echo --no filename
	goto exit

:checkFileToDelete
	if not exist %2 (goto notFoundFile)
	del %2
	echo --file %2 deleted
	goto exit

:notFoundFile
	echo --file %2 not found
	goto exit

:error
	echo --%0 mode file
	echo --mode = {create, delete}
	echo --file = filename
	goto exit

:error1
	echo --mode is incorrect
	goto exit

:exit