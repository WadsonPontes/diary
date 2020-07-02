CC = g++
CFLAGS = -std=c++11 -Iinclude -Wall -O2
PROG = Diary

$(PROG): clean main.o App.o Diary.o Message.o Date.o Time.o Util.o
	$(CC) $(CFLAGS) -o build/Diary *.o

test: clean test.o App.o Diary.o Message.o Date.o Time.o Util.o
	$(CC) $(CFLAGS) -o build/Test *.o

clean:
	rm -f src/*.o
	rm -f *.o
	rm -f build/Diary
	rm -f build/Diary.exe

main.o: src/main.cpp
	$(CC) $(CFLAGS) -c src/main.cpp

test.o: src/test.cpp
	$(CC) $(CFLAGS) -c src/test.cpp

App.o: src/App.cpp include/App.h
	$(CC) $(CFLAGS) -c src/App.cpp

Diary.o: src/Diary.cpp include/Diary.h
	$(CC) $(CFLAGS) -c src/Diary.cpp

Message.o: src/Message.cpp include/Message.h
	$(CC) $(CFLAGS) -c src/Message.cpp

Date.o: src/Date.cpp include/Date.h
	$(CC) $(CFLAGS) -c src/Date.cpp

Time.o: src/Time.cpp include/Time.h
	$(CC) $(CFLAGS) -c src/Time.cpp

Util.o: src/Util.cpp include/Util.h
	$(CC) $(CFLAGS) -c src/Util.cpp