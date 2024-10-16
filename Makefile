CC = g++

HEADERS = Constants.h FuncStack.h Struct.h

WINFLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

Stack.exe: main.o FuncStack.o
	$(CC) main.o FuncStack.o -o Stack.exe

main.o: main.cpp $(HEADERS)
	$(CC) -c main.cpp $(WINFLAGS)

FuncStack.o: FuncStack.cpp $(HEADERS)
	$(CC) -c FuncStack.cpp $(WINFLAGS)
