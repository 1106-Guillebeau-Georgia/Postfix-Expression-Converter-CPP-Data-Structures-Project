parser: driver.o
	g++ -std=c++11 driver.o -o driver
driver.o: driver.cpp linkedStack.h arrayStack.h node.h
	g++ -std=c++11 -c driver.cpp

clean:
	rm *.o driver