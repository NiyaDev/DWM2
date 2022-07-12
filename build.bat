@echo off

cls

for /f "tokens=2 delims==" %%a in ('wmic OS Get localdatetime /value') do set "dt=%%a"
set "date=%dt:~0,4%_%dt:~4,2%_%dt:~6,2%"

ROBOCOPY "src" "target\debug\%date%\source\src" /mir /nfl /ndl /njh /njs /np /ns /nc > nul


rgbasm  -L -o target\debug\%date%\DWM2C.o   src\entry.asm
rgblink -o    target\debug\%date%\DWM2C.gbc target\debug\%date%\DWM2C.o
rgbfix  target\debug\%date%\DWM2C.gbc -c -i BQLE -j -k B4 -l $33 -m $1B -r 03 -s -t DWM2-C -v


del compared.txt
fc /b ROM\Cobi.gbc target\debug\%date%\DWM2C.gbc >> compared.txt