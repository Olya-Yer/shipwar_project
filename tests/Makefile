HEADERS := $(wildcard small_ships/*.hpp)
TEST_OBJECTS := $(patsubst small_ships/%.cpp ,../test_results/small_ships/%.o, $(HEADERS))
SOURCE_OBJECTS := $(../obj/shipwar.o)

#try: 
#	@echo $(PROJECT_DIR)

all: small_ships medium_ships big_ships

.PHONY : small_ships
small_ships:
	cd  small_ships/ && $(MAKE)
.PHONY : medium_ships
medium_ships:
	cd  medium_ships/ && $(MAKE)
.PHONY : big_ships
big_ships:
	cd  big_ships/ && $(MAKE)




