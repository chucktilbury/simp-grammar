
TARGET	=	simp
OBJS	=	main.o simple.o
all: $(TARGET)

%.o: %.c
	gcc -c -g $< -o $@

$(TARGET): $(OBJS)
	gcc -g $(OBJS) -o $(TARGET)

main.o: main.c simple.h
simple.o: simple.c
simple.c simple.h: simple.peg
	packcc simple.peg

clean:
	$(RM) $(OBJS) $(TARGET) simple.c simple.h