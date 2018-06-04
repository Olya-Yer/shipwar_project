SOURCES := $(wildcard *.cpp)
HEADERS := $(wildcard *.hpp)
TEST_OBJECTS := $(patsubst %.hpp ,../../test_results/medium_ships/%.o, $(HEADERS))
SOURCE_OBJECTS := $(../obj/shipwar.o)
.PHONY : medium_ships


medium_ships: $(TEST_OBJECTS) FOLDERS
	g++ -std=c++11 $(SOURCES) $(PROJECT_DIR)/src/shipwar.cpp -I$(PROJECT_DIR)/src/ -o medium_ships.exe
	./medium_ships.exe >>$(PROJECT_DIR)/test_results/result.txt
	rm medium_ships.exe


$(PROJECT_DIR)/test_results/medium_ships/%.o: %.hpp FOLDERS
	@echo "creating objs"
	 $(CXX) -std=c++11 -c $<  -o $@


FOLDERS:
	mkdir -p $(PROJECT_DIR)/test_results
	mkdir -p  $(PROJECT_DIR)/test_results/medium_ships
clean:
	rm -rd $(PROJECT_DIR)/test_results/medium_ships
