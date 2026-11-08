CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
TARGET = server_kurs

SRCS = main.cpp base.cpp calc.cpp communicator.cpp interface.cpp logger.cpp

OBJS = $(SRCS:.cpp=.o)

LIBS = -lcryptopp -lboost_program_options

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
