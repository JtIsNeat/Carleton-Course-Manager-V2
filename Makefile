CC = g++
CFLAGS = -g
CM: main.o Course.o MainControl.o CourseList.o UserInterface.o WebScraper.o
	$(CC) $(CFLAGS) -o CM main.o Course.o MainControl.o CourseList.o UserInterface.o WebScraper.o

main.o: main.cc
	$(CC) $(CFLAGS) -c main.cc

Course.o: Course.cc Course.h Credit.h Grade.h
	$(CC) $(CFLAGS) -c Course.cc

MainControl.o: MainControl.cc MainControl.h
	$(CC) $(CFLAGS) -c MainControl.cc

CourseList.o: CourseList.cc CourseList.h
	$(CC) $(CFLAGS) -c CourseList.cc

UserInterface.o: UserInterface.cc UserInterface.h
	$(CC) $(CFLAGS) -c UserInterface.cc

WebScraper.o: WebScraper.cc WebScraper.h
	$(CC) $(CFLAGS) -c WebScraper.cc

winclean:
	del -f *.o CM.exe

clean:
	rm -f *.o CM