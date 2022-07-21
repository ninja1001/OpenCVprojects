SOURCE_FILES=$(wildcard *.cpp)
OBJ_FILES=$(patsubst %.o, %.cpp, $(SOURCE_FILES))
EXECUTABLE=project.exe
CC=g++
LDFLAGS=`pkg-config --cflags --libs opencv4`

$(EXECUTABLE) : $(OBJ_FILES)
	$(CC) $^ -o $@ $(LDFLAGS)

%.o : %.cpp
	$(CC) -c $^ -o $@

clear:
	rm -rf *.o
