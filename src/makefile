OBJS := FlyGo.o curlutil.o fly.o qqpostdata.o url.o utils.o timeutil.o
CFLAGS=-I/home/flyzebra/android-curl/include
CURLLIB=/home/flyzebra/android-curl/lib/libcurl.a
flygo-android : $(OBJS)
	gcc $(CFLAGS) -static -o flygo-android $(OBJS) $(LIBS) $(CURLLIB)

.PHONY : clean
clean :
	-rm flygo $(OBJS)
