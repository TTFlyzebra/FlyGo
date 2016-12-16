MAKE = make
#eg:
#GCCROOT = /opt/buildroot-gcc463/usr/bin
#AR = $(GCCROOT)/mipsel-linux-ar
#AS = $(GCCROOT)/mipsel-linux-as
#LD = $(GCCROOT)/mipsel-linux-ld
#RANLIB = $(GCCROOT)/mipsel-linux-ranlib
#CC = $(GCCROOT)/mipsel-linux-gcc
#NM = $(GCCROOT)/mipsel-linux-nm
#LINKER = $(CC)

#INCLUDE_PATH :=-I/opt/buildroot-gcc463/usr/include

CPPFLAGS +=
LDFLAGS :=
LDLIBS :=
LDLIBS_IN:=

cc-option = $(shell if $(CC) $(1) -S -o /dev/null -xc /dev/null \
              > /dev/null 2>&1; then echo "$(1)"; fi ;)

ld-option = $(shell if echo "int main(){return 0;}" | \
		$(CC) $(LDFLAGS) $(CFLAGS) $(1) -o /dev/null -xc - \
		> /dev/null 2>&1; then echo "$(1)"; fi ;)
