TARGETS = bin/shipwar.exe
SOURCES = $(wildcard src/*.cpp)
HEADERS = $(wildcard  src/*.hpp)
OBJECTS = $(patsubst src/%.cpp, obj/%.o, $(SOURCES))
FOLDERS = obj bin


all: $(OBJECTS) $(FOLDERS)
	$(CXX) -std=c++11  $(OBJECTS)  -o $(TARGETS)

obj/%.o : src/%.cpp $(FOLDERS)
	$(CXX) -std=c++11 -c $<  -o $@
obj:
	mkdir -p obj   
bin: 
	mkdir -p bin

.PHONY: docs
docs:
	mkdir docs/doxygen
	doxygen config-file

.PHONY: clean
clean: 
	@echo "Cleaning..."
	@rm -rf $(FOLDERS) docs/doxygen
	@echo "Done!"
