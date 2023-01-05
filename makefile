CC := gcc
#CFLAGS  := -std=gnu99 -ggdb -ffunction-sections # -w:关闭所有告警
CFLAGS := -g -I. $(CCFLAGS)
SRCS   := $(wildcard *.c) # 当前目录下的所有的.c文件 
OBJS   := $(SRCS:.c=.o)   # 将所有的.c文件名替换为.o
LIB	   := lib.a

all:$(LIB) gccmy

# ***************************************************************
# C compilations
genlib.o: genlib.c genlib.h
	$(CC) $(CFLAGS) -c genlib.c

$(LIB):$(OBJS)
	-rm -f $(LIB)
	ar cr $(LIB) $(OBJS)
	ranlib $(LIB)

# ***************************************************************
# Entry to reconstruct the gccmy script

gccmy: makefile
	@echo '#!/bin/bash' > gccmy
	@echo 'INCLUDE='\"`pwd`\" >> gccmy
	@echo 'LIB="$$INCLUDE/$(LIB)"' >> gccmy
	@echo 'LIBRARIES="$$LIB"' >> gccmy
	@echo 'gcc -g -I$$INCLUDE $$* $$LIBRARIES' >> gccmy
	@chmod a+x gccmy
	@echo '[gccmy script created]'

clean:
	rm -f *.o
	rm -f $(BINS)
	rm -f $(LIB)
	rm -f gccmy
