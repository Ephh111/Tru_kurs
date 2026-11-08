CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -I.
LIBS = -lcryptopp

COMMON_SRCS = base.cpp calc.cpp communicator.cpp interface.cpp logger.cpp
COMMON_OBJS = $(COMMON_SRCS:.cpp=.o)

TARGET = server_kurs
MAIN_SRC = main.cpp
MAIN_OBJ = main.o

TEST_TARGET = run_tests
TEST_SRC = tests/test_all.cpp
TEST_OBJ = tests/test_all.o
TEST_LIBS = -lUnitTest++ -pthread

all: $(TARGET)

$(TARGET): $(MAIN_OBJ) $(COMMON_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

$(TEST_TARGET): $(TEST_OBJ) $(COMMON_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS) $(TEST_LIBS)
	
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

tests/%.o: tests/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	rm -f *.o $(TARGET) $(TEST_TARGET) tests/*.o

.PHONY: all clean test
