@echo off
@copy x64\Debug\AdventOfCode.exe AdventOfCode\ >nul
@cd /d %~dp0
@cd AdventOfCode\
@del AdventOfCode
@copy AdventOfCode.exe AdventOfCode >nul
@cmd.exe
prompt $g