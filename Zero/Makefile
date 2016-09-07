# Objects
OUTPUT_FOLDER=bin
DRIVER=zero.cpp

# Compilers
GCC=g++-6
GCC_FLAGS=-g -pedantic -Wall -Wextra -Weffc++ -Wold-style-cast -Woverloaded-virtual -Wsign-promo -Wnon-virtual-dtor -Wctor-dtor-privacy -Wreorder
GCC_OUTPUT=zero_gcc

CLANG=clang++-3.8
CLANG_FLAGS=-g -pedantic -Werror -Wall -Wextra
CLANG_ASAN=-fsanitize=address
CLANG_OUTPUT=zero_clang

# Mem Check
VALGRIND=valgrind
VALGRIND_FLAGS=--tool=memcheck --leak-check=full --show-reachable=yes

# Tasks
gcc:
	mkdir -p $(OUTPUT_FOLDER)
	$(GCC) -o $(OUTPUT_FOLDER)/$(GCC_OUTPUT) $(DRIVER) $(GCC_FLAGS)
rungcc:
	./$(OUTPUT_FOLDER)/$(GCC_OUTPUT)
	
clang:
	mkdir -p $(OUTPUT_FOLDER)
	$(CLANG) -o $(OUTPUT_FOLDER)/$(CLANG_OUTPUT) $(DRIVER) $(CLANG_FLAGS)
runclang:
	./$(OUTPUT_FOLDER)/$(CLANG_OUTPUT)
	
mem_gcc:
	mkdir -p $(OUTPUT_FOLDER)
	$(GCC) -o $(OUTPUT_FOLDER)/$(GCC_OUTPUT) $(DRIVER) $(GCC_FLAGS)
	$(VALGRIND) $(OUTPUT_FOLDER)/$(GCC_OUTPUT) $(VALGRIND_FLAGS)
mem_clang:
	mkdir -p $(OUTPUT_FOLDER)
	$(CLANG) -o $(OUTPUT_FOLDER)/$(CLANG_OUTPUT)_asan $(DRIVER) $(CLANG_FLAGS) $(CLANG_ASAN)
	./$(OUTPUT_FOLDER)/$(CLANG_OUTPUT)_asan

clean:
	rm -rf $(OUTPUT_FOLDER)
