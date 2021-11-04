#ifndef SEARCH_H
#define SEARCH_H

#include "board.h"
#include "move.h"

// Declare any data that your engine needs across moves here
typedef struct {
    // input
    int uci;
    int use_book;
    double duration;
    // output
    Move move;
    // control
    int stop;
    // internal
    int nodes;
} Search;

int do_search(Search *search, Board *board);

#endif
