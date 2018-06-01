#include "assert.h"
#include <csignal>
#include <iostream>
#include <cstdlib>
#include <cstddef>      //NULL
#include "shipwar.hpp"
#include <stdio.h>

void test_medium_ships(){
        Shipwar *game = new Shipwar();
        if ( NULL == game) {
                std::abort();
        } 
        game->fill_medium_ships();
        int r = 0;
        for(int i = 0; i < 100; i++){
                r += game->current_sea[i];
        }
        FILE * pFile;
        pFile = fopen ("/home/student/Documents/testthegit/shipwar_project/test_results/medium_ships/results.txt","w");         
        if(8 == r) {
                if (pFile!=NULL) {
                        fputs ("medium ships - pass",pFile);
                        fclose (pFile);
                }
        } else {
                if (pFile!=NULL) {
                        fputs ("medium ships - fail",pFile);
                        fclose (pFile);
                }
        }
}

