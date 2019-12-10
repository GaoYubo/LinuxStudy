#定义变量
#ARCH 默认为x86，使用gcc 编译器，
#否则使用arm 编译器
ARCH ?= x86
TARGET = hello_main
CFLAGS = -I .
DEPS = func.h
OBJS = hello.o func.o

#根据输入的ARCH 变量来选择编译器
#ARCH=x86，使用gcc
#ARCH=arm，使用arm-gcc
ifeq ($(ARCH),x86)
	CC = gcc
else
	CC = arm-linux-gnueabihf-gcc
endif

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY:clean
clean:
	rm -f *.o hello_main