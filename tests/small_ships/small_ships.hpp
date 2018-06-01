#include "assert.h"
#include <csignal>
#include <iostream>
#include <cstdlib>
#include <cstddef>      //NULL
#include "shipwar.hpp"
#include <stdio.h>

void test_small_ships(){
        Shipwar *game = new Shipwar();
        if ( NULL == game) {
                std::abort();
        } 
        game->fill_small_ships();
        int r = 0;
        for(int i = 0; i < 100; i++){
                r += game->current_sea[i];
        }
        assert(6 == r);
        FILE * pFile;
        pFile = fopen ("/home/student/Documents/testthegit/shipwar_project/test_results/small_ships/results.txt","w");
        if (pFile!=NULL) {
                fputs ("small_ships - pass",pFile);
                fclose (pFile);
        }
}

