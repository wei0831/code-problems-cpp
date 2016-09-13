# Objects
OUTPUT_FOLDER=bin
DRIVER=main.cpp
OBJS=algorithm.cpp

# Compilers
GCC=g++-6
GCC_FLAGS=-g -pedantic -Wall -Wextra -Weffc++ -Wold-style-cast -Woverloaded-virtual -Wsign-promo -Wnon-virtual-dtor -Wctor-dtor-privacy -Wreorder
GCC_OUTPUT=gcc0

CLANG=clang++-3.8
CLANG_FLAGS=-g -pedantic -Werror -Wall -Wextra
CLANG_ASAN=-fsanitize=address
CLANG_OUTPUT=clang0

# Mem Check
VALGRIND=valgrind
VALGRIND_FLAGS=--tool=memcheck --leak-check=full

# Tasks
gcc:
	mkdir -p $(OUTPUT_FOLDER)
	$(GCC) -o $(OUTPUT_FOLDER)/$(GCC_OUTPUT) $(DRIVER) $(OBJS) $(GCC_FLAGS)
gccrun:
	./$(OUTPUT_FOLDER)/$(GCC_OUTPUT)
	
clang:
	mkdir -p $(OUTPUT_FOLDER)
	$(CLANG) -o $(OUTPUT_FOLDER)/$(CLANG_OUTPUT) $(DRIVER) $(OBJS) $(CLANG_FLAGS)
clangrun:
	./$(OUTPUT_FOLDER)/$(CLANG_OUTPUT)
	
gccmem:
	mkdir -p $(OUTPUT_FOLDER)
	$(GCC) -o $(OUTPUT_FOLDER)/$(GCC_OUTPUT) $(DRIVER) $(OBJS) $(GCC_FLAGS)
	$(VALGRIND) $(OUTPUT_FOLDER)/$(GCC_OUTPUT) $(VALGRIND_FLAGS)
clangmem:
	mkdir -p $(OUTPUT_FOLDER)
	$(CLANG) -o $(OUTPUT_FOLDER)/$(CLANG_OUTPUT)_asan $(DRIVER) $(OBJS) $(CLANG_FLAGS) $(CLANG_ASAN)
	./$(OUTPUT_FOLDER)/$(CLANG_OUTPUT)_asan

clean:
	rm -rf $(OUTPUT_FOLDER)
