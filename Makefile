







CXX      = g++
CXXFLAGS = -std=c++17 -Wall

TARGET = AirlineSystem

SRCS = src/main.cpp \
       src/menus.cpp

OBJS = src/main.o \
       src/menus.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
	@echo "Build successful ! Run with: ./$(TARGET)"

src/main.o: src/main.cpp src/menus.h \
            include/Passenger.h \
            include/BookingOffice.h \
            include/Ticket.h \
            include/Flight.h \
            data_structures/LinkedList.h \
            data_structures/Stack.h \
            data_structures/Queue.h
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o src/main.o

src/menus.o: src/menus.cpp src/menus.h \
             include/Passenger.h \
             include/BookingOffice.h \
             include/Ticket.h \
             include/Flight.h \
             data_structures/LinkedList.h \
             data_structures/Stack.h \
             data_structures/Queue.h
	$(CXX) $(CXXFLAGS) -c src/menus.cpp -o src/menus.o

clean:
	rm -f src/main.o src/menus.o $(TARGET)
	@echo "Cleaned successfully !"
