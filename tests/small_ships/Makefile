SOURCES := $(wildcard *.cpp)
HEADERS := $(wildcard *.hpp)
TEST_OBJECTS := $(patsubst %.hpp ,$(PROJECT_DIR)/test_results/small_ships/%.o, $(HEADERS))
SOURCE_OBJECTS := $($(PROJECT_DIR)/obj/shipwar.o)
.PHONY : small_ships




small_ships: $(TEST_OBJECTS) FOLDERS
	$(CXX) -std=c++11 $(SOURCES) $(PROJECT_DIR)/src/shipwar.cpp -I$(PROJECT_DIR)/src/ -o small_ships.exe
	./small_ships.exe >>$(PROJECT_DIR)/test_results/result.txt
	rm small_ships.exe


$(PROJECT_DIR)/test_results/small_ships/%.o: small_ships/%.hpp FOLDERS
	@echo "creating objs"
	 $(CXX) -std=c++11 -c $<  -o $@


FOLDERS:
	mkdir -p $(PROJECT_DIR)/test_results
	mkdir -p  $(PROJECT_DIR)/test_results/small_ships
clean:
	rm -rd $(PROJECT_DIR)/test_results/small_ships
