set CC = g++
set CFLAGS = -std=c++11 -Iinclude -Wall -O2
set PROG = Diary.exe

del src\*.o
start %CC% %FLAG% -o src\Date.o -c src\Date.cpp
start %CC% %FLAG% -o src\Time.o -c src\Time.cpp
start %CC% %FLAG% -o src\Message.o -c src\Message.cpp
start %CC% %FLAG% -o src\Util.o -c src\Util.cpp
start %CC% %FLAG% -o src\Diary.o -c src\Diary.cpp
start %CC% %FLAG% -o src\App.o -c src\App.cpp
start %CC% %FLAG% -o src\main.o -c src\main.cpp

start %CC% %FLAG% -o Diary.exe src\*.o