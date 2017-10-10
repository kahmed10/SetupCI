CXX = clang++
CXXFLAGS = -c -O3 -std=c++11
LDFLAGS = -o
OBJ_DIR = ../obj
OBJS = $(OBJ_DIR)/file_parser.o $(OBJ_DIR)/ci_calls.o
BIN_DIR = ../bin


$(BIN_DIR)/file_parser: $(OBJ_DIR)/file_parser.o $(OBJ_DIR)/ci_calls.o
	$(CXX) $(OBJS) $(LDFLAGS) $(BIN_DIR)/file_parser

$(OBJ_DIR)/file_parser.o: file_parser.cpp ci_calls.cpp
	$(CXX) $(CXXFLAGS) file_parser.cpp $(LDFLAGS) $(OBJ_DIR)/file_parser.o

$(OBJ_DIR)/ci_calls.o: ci_calls.cpp ci_calls.h
	$(CXX) $(CXXFLAGS) ci_calls.cpp $(LDFLAGS) $(OBJ_DIR)/ci_calls.o

clean:
	rm -f $(OBJ_DIR)/*.o; rm -f $(BIN_DIR)/file_parser
