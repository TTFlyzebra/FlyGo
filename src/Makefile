include utils.mk
include config.mk
EXECTARGET = flygo
LIBTARGET = libflygo.a
#save external LDLIBS
LDLIBS_IN := $(LDLIBS)

LINKER = $(CC)
STATIC ?= 0
DEBUG ?= 1

CURL_PREFIX=$(HOME)/curl_install/$(ARCH)
CURL_INCLUDE_DIR=$(CURL_PREFIX)/include
CURL_LIB_DIR=$(CURL_PREFIX)/lib
INCLUDE_PATH += -I$(CURL_INCLUDE_DIR)

OPENSSL_PREFIX=$(HOME)/openssl-install/$(ARCH)
OPENSSL_INCLUDE_DIR=$(OPENSSL_PREFIX)/include
OPENSSL_LIB_DIR=$(OPENSSL_PREFIX)/lib
INCLUDE_PATH += -I$(OPENSSL_INCLUDE_DIR)

ifdef DEBUG
CFLAGS += -g -O0
CPPFLAGS += -DDEBUG
LDFLAGS += -g
endif
LDFLAGS += -L$(CURL_LIB_DIR)
LDFLAGS += -L$(OPENSSL_LIB_DIR)
LDLIBS += 
LIBFILES += $(addprefix $(CURL_LIB_DIR)/,libcurl.a)
LIBFILES += $(addprefix $(OPENSSL_LIB_DIR)/,libssl.a)
LIBFILES += $(addprefix $(OPENSSL_LIB_DIR)/,libcrypto.a)

LDFLAGS += $(LIB_PATH)
#LDFLAGS += -L./lib/ 
LDLIBS += 
#LIBFILES += ./lib/$(ARCH)/libcurl.a
#LIBFILES += $(addprefix ./lib/$(ARCH)/,libcurl.a)  


CPPFLAGS +=$(CFLAGS)

CPPFLAGS += $(INCLUDE_PATH)
OBJS =
OBJS += curl/curlsend.o \
			tool/tool_utils.o \
			tool/tool_url.o \
			tool/tool_sleep.o \
			tool/tool_string.o \
			tool/cJSON.o \
			tool/tool_file.o \
			tool/tool_rand.o \
			tool/tool_time.o \
			log/flylog.o \
			livemsg_getadlist.o \
			httpdata.o \
			kvcollect.o \
			kvcollectdata1.o

ifeq ($(STATIC), 1)
EXECTARGET := $(EXECTARGET)-halfstatic
LDFLAGS += -Wl,-static
LDFLAGSPOST += -Wl,-Bdynamic
endif
ifeq ($(STATIC), 2)
EXECTARGET := $(EXECTARGET)-static
LDFLAGS += -static
endif

ifdef DEBUG
EXECTARGET := $(EXECTARGET)-debug
endif

ifdef RELEASE
EXECTARGET := $(EXECTARGET)-release
endif

#apply external LDLIBS at the end as well to resolve lining order problems
LDLIBS += $(LDLIBS_IN)
#lm might be needed again at the end
LDLIBS += $(call ld-option, -lm)
LDLIBS += $(call ld-option, -lz)
LDLIBS +=-ldl
ifeq ($(ARCH), x86)
LDLIBS +=-lpthread
endif

.PHONY: clean distclean

all: $(LIBTARGET) $(EXECTARGET)

$(EXECTARGET): FlyGo.o $(LIBTARGET)
	$(CC) $(LDFLAGS) -Wl,--start-group $^ $(LIBFILES) $(LOADLIBES) $(LDLIBS) -Wl,--end-group $(LDFLAGSPOST) -o $@ -Wl,-Map,$@.map

$(LIBTARGET):$(OBJS)
	$(AR) cru $@ $^
	$(RANLIB) $@

#ar cru $ALLLIB *.o
#ranlib $ALLLIB
#mipsel-linux-ar cru libxxx.a  libcurl_la-file.o libcurl_la-timeval.o 
#mipsel-linux-ranlib libxxx.a
#mipsel-linux-gcc -O2 -Wno-system-headers -o curl curl-slist_wc.o curl-tool_binmode.o curl-tool_bname.o curl-tool_cb_dbg.o curl-tool_cb_hdr.o curl-tool_cb_prg.o curl-tool_cb_rea.o curl-tool_cb_see.o curl-tool_cb_wrt.o curl-tool_cfgable.o curl-tool_convert.o curl-tool_dirhie.o curl-tool_doswin.o curl-tool_easysrc.o curl-tool_formparse.o curl-tool_getparam.o curl-tool_getpass.o curl-tool_help.o curl-tool_helpers.o curl-tool_homedir.o curl-tool_hugehelp.o curl-tool_libinfo.o curl-tool_main.o curl-tool_metalink.o curl-tool_mfiles.o curl-tool_msgs.o curl-tool_operate.o curl-tool_operhlp.o curl-tool_panykey.o curl-tool_paramhlp.o curl-tool_parsecfg.o curl-tool_strdup.o curl-tool_setopt.o curl-tool_sleep.o curl-tool_urlglob.o curl-tool_util.o curl-tool_vms.o curl-tool_writeenv.o curl-tool_writeout.o curl-tool_xattr.o ../lib/curl-strtoofft.o ../lib/curl-nonblock.o ../lib/curl-warnless.o  ../lib/.libs/libcurl.a

version.h: config.mk
	./version.sh

version.d: version.h

clean:
	rm -f $(LIBTARGET)
	rm -f $(EXECTARGET)
	rm -f $(EXECTARGET)-*
	rm -f $(OBJS)
	rm -f version.h
	rm -f *.a
	rm -f *.map
	rm -f *.o
	
distclean: clean
%.o:%.c %.cpp
	$(CC) $(CPPFLAGS) -c -o $@ $<
    
### Automatic generation of headers dependencies ###
#%.d:%.c
#	$(CC) $(CPPFLAGS) -MM -MF $@ $<
#%.o:%.d

#-include $(OBJS:.o=.d)
# version.d
