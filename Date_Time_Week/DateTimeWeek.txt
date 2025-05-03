@echo off

::Year
set Year=%date:~10,4%
echo Year: %year%

::Date
echo Date: %date%

::Month
set Month=%date:~4,2%
echo Month: %month%

::Time
echo Time: %time%

::Week
for /f "skip=1 tokens=1,2 delims=," %%A in ('wmic path Win32_LocalTime get DayOfWeek /format:csv') do if not "%%A"=="" set Day=%%B
if "%Day%"=="0" set DayName=Sunday
if "%Day%"=="1" set DayName=Monday
if "%Day%"=="2" set DayName=Tuesday
if "%Day%"=="3" set DayName=Wednesday
if "%Day%"=="4" set DayName=Thursday
if "%Day%"=="5" set DayName=Friday
if "%Day%"=="6" set DayName=Saturday
echo Day of the Week: %DayName%

::Month Name
if "%Month%"=="01" set MonthName=January
if "%Month%"=="02" set MonthName=February
if "%Month%"=="03" set MonthName=March
if "%Month%"=="04" set MonthName=April
if "%Month%"=="05" set MonthName=May
if "%Month%"=="06" set MonthName=June
if "%Month%"=="07" set MonthName=July
if "%Month%"=="08" set MonthName=August
if "%Month%"=="09" set MonthName=September
if "%Month%"=="10" set MonthName=October
if "%Month%"=="11" set MonthName=November
if "%Month%"=="12" set MonthName=December
echo Month Name: %MonthName%

pause