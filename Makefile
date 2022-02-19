INC=/usr/include/python3.8
LIB=python3.8
SRC=python3call.c
TARGET=python3call

all:
	gcc -g -o $(TARGET) $(SRC) -I$(INC) -l$(LIB)

clean:
	rm -rf $(TARGET) __pycache__