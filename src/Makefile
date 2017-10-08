CXX = clang++
CXXFLAGS = -c -O3
LDFLAGS = -o
OBJ_DIR = ../obj
OBJS = $(OBJ_DIR)/file_parser.o
BIN_DIR = ../bin


$(BIN_DIR)/file_parser: $(OBJ_DIR)/file_parser.o
	$(CXX) $(OBJS) $(LDFLAGS) $(BIN_DIR)/file_parser

$(OBJ_DIR)/file_parser.o: file_parser.cpp
	$(CXX) $(CXXFLAGS) file_parser.cpp $(LDFLAGS) $(OBJ_DIR)/file_parser.o

clean:
	rm -f $(OBJ_DIR)/*.o; rm -f $(BIN_DIR)/file_parser