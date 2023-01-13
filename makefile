CC  := gcc
CFLAGS  := -g -I. $(CCFLAGS) -O0 -std=c89
SRCS    := $(wildcard *.c) # 当前目录下的所有的.c文件 
OBJS    := $(SRCS:.c=.o) # 将所有的.c文件名替换为.o
LIB 	:= libm.a

all:$(LIB) gccm

# ***************************************************************
# C compilations
genlib.o: genlib.c genlib.h
	$(CC) $(CFLAGS) -c genlib.c

strlib.o: strlib.c strlib.h genlib.h
	$(CC) $(CFLAGS) -c strlib.c

$(LIB):$(OBJS)
	-rm -f $(LIB)
	ar cr $(LIB) $(OBJS)
	ranlib $(LIB)

# ***************************************************************
# Entry to reconstruct the gccm script

gccm: makefile
	@echo '#!/bin/bash' > gccm
	@echo 'INCLUDE='\"`pwd`\" >> gccm
	@echo 'LIB="$$INCLUDE/$(LIB)"' >> gccm
	@echo 'LIBRARIES="$$LIB"' >> gccm
	@echo 'gcc -g -I$$INCLUDE $$* $$LIBRARIES' >> gccm
	@chmod a+x gccm
	@echo '[gccm script created]'

clean:
	rm -f *.o *.a
	rm -f gccm
