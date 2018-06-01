SOURCES := $(wildcard *.cpp)
HEADERS := $(wildcard *.hpp)
TEST_OBJECTS := $(patsubst %.hpp ,$(PROJECT_DIR)/test_results/big_ships/%.o, $(HEADERS))
SOURCE_OBJECTS := $($(PROJECT_DIR)/obj/shipwar.o)
.PHONY : big_ships

#all:
#	@echo "sources"
#	@echo $(SOURCES)
#	@echo "headers"
#	@echo $(HEADERS)
#	@echo "test objects"
#	@echo $(TEST_OBJECTS)
#	@echo "source objects"
#	@echo $(SOURCE_OBJECTS)
#


big_ships: $(TEST_OBJECTS) FOLDERS
	$(CXX) -std=c++11 $(SOURCES) $(PROJECT_DIR)/src/shipwar.cpp -I$(PROJECT_DIR)/src/ -o big_ships.exe
	./big_ships.exe
	rm big_ships.exe


$(PROJECT_DIR)/test_results/big_ships/%.o: %.hpp FOLDERS
	@echo "creating objs"
	 $(CXX) -std=c++11 -c $<  -o $@


FOLDERS:
	mkdir -p $(PROJECT_DIR)/test_results
	mkdir -p  $(PROJECT_DIR)/test_results/big_ships
clean:
	rm -rd $(PROJECT_DIR)/test_results/big_ships
