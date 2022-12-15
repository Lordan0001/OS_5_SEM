@ECHO OFF
CHCP 866 > NULL
ECHO -- строка параметров: %*
ECHO -- параметр 1: %1
ECHO -- параметр 2: %2
ECHO -- параметр 3: %3
SET /A C = %1 %3 %2
ECHO результат: %C%
