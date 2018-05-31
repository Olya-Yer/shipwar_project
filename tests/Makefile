SOURCES := $(wildcard small_ships/*.cpp)
HEADERS := $(wildcard small_ships/*.hpp)
TEST_OBJECTS := $(patsubst small_ships/%.cpp ,../test_results/small_ships/%.o, $(HEADERS))
SOURCE_OBJECTS := $(../obj/shipwar.o)
.PHONY : small_ships

small_ships:
	mkdir -p ../test_results
	mkdir -p  ../test_results/small_ships
	g++ -std=c++11 small_ships/main.cpp ./../src/shipwar.cpp -I./../src/ -o small_ships/small_ships.exe
	./small_ships/small_ships.exe
	rm small_ships/small_ships.exe

clean:
	rm -rd ../test_results
