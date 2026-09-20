





CXX      = g++
CXXFLAGS = -std=c++17 -Wall -I.

TARGET = air

SRCS = src/main.cpp \
       src/tui/menus.cpp

OBJS = src/main.o \
       src/tui/menus.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
	@echo "Build successful ! Run with: ./$(TARGET)"

src/main.o: src/main.cpp src/tui/menus.h core/Core.h
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o src/main.o

src/tui/menus.o: src/tui/menus.cpp src/tui/menus.h core/Core.h
	$(CXX) $(CXXFLAGS) -c src/tui/menus.cpp -o src/tui/menus.o

clean:
	rm -f src/main.o src/tui/menus.o $(TARGET)
	@echo "Cleaned successfully !"