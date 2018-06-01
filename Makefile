export PROJECT_DIR := $(PWD)
TARGETS := bin/shipwar.exe
SOURCES := $(wildcard src/*.cpp)
HEADERS := $(wildcard  src/*.hpp)
OBJECTS := $(patsubst src/%.cpp, obj/%.o, $(SOURCES))
FOLDERS := obj bin



all: $(OBJECTS) $(HEADERS)
	@echo $(PROJECT_DIR)
#	@echo "Buildnig .exe ..."
	@$(CXX) -std=c++11  $(OBJECTS)  -o $(TARGETS)

obj/%.o : src/%.cpp  $(FOLDERS)
#	@echo "Creating objects..."
	@$(CXX) -std=c++11 -c $<  -o $@
ifndef obj
obj:
	@echo "Creating obj/"
	@mkdir -p obj
endif

ifndef bin
bin:
	@echo "Creating bin/"
	@mkdir -p bin
endif


.PHONY: docs
docs:
	mkdir docs/doxygen
	doxygen config-file
.PHONY: tests
tests:
	cd tests/ && $(MAKE)

.PHONY: clean
clean: 
	@echo "Cleaning..."
	@rm -rf $(FOLDERS) docs/doxygen test_results
	@echo "Done!"
