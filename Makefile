TARGET = Rational
CC = g++

SRC = $(wildcard *.cpp)
OBG = $(patsubst %.cpp, %.o, $(SRC))

$(TARGET) : $(OBG)
	$(CC) $(OBG) -o $(TARGET)

%.o : %.cpp
	$(CC) -c $< -o $@


