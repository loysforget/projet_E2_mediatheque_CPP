EXE = all
CPP = g++
CPP_FLAGS = -std=c++11 -O3
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
SRCS = $(wildcard $(SRC_DIR)/*.c*)
OBJS = $(addprefix $(OBJ_DIR)/,$(addsuffix .o,$(notdir $(basename $(SRCS)))))


# Link c++ compiled object files to target executable:
$(EXE): $(OBJS)
	$(CPP) $(CPP_FLAGS) $(OBJS) -o $@ -I./$(INC_DIR)

# Compile main .cpp file to object files:
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CPP) $(CPP_FLAGS) $(PY_BIND) -c $< -o $@ -I./$(INC_DIR)

# Compile C++ source files to object files:
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INC_DIR)/%.h
	$(CPP) $(CPP_FLAGS) $(PY_BIND) -c $< -o $@ -I./$(INC_DIR)

clean:
	rm -f $(OBJ_DIR)/*

veryclean: clean
	rm -f $(EXE)
