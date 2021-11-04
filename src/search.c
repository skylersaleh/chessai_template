#include <stdio.h>
#include <string.h>
#include "search.h"
#include "gen.h"
#include "move.h"
#include <stdlib.h>
// Call this function to commit to making a move and send it to the chess client. 
void execute_move(Move* move){
    char move_string[16];
    move_to_string(move, move_string);
    printf("bestmove %s\n", move_string);
}
// This function is the core entry point of your Chess AI.
// It is called everytime the chess client wants your AI to make a move.
// The return value indicates a score for how good the move made was. It can be used to implement AIs that 
// play against themselves using recursion. 

// This example implements a very basic AI that tries to check the opponent, take the most valuable peice it can or move at random. 
int do_search(Search *search, Board *board) {
    Move moves[MAX_MOVES];
    // This function returns the total number of legal moves that results in a check
    // for the current board. It populates each of these legal moves in the 'moves' array. 
    int check_moves = gen_checks(board, moves);
    if(check_moves){
        // If there is a move execute a random one from the set
        execute_move(&moves[rand()%check_moves]);
        return 2;
    }
    // This function returns the total number of legal moves that will attack an oponents piece
    // for the current board. It populates each of these legal moves in the 'moves' array. 
    int attack_moves = gen_attacks(board, moves);
    if(attack_moves){
        int best_move = 0; 
        int best_piece_taken = PAWN; 
        //Look for the best attack
        for(int m =0;m<attack_moves;++m){
            char rank = moves[m].dst / 8;
            char file = moves[m].dst % 8;
            /*
            The data stored in each square is one of the following
            #define WHITE_PAWN 0x01
            #define WHITE_KNIGHT 0x02
            #define WHITE_BISHOP 0x03
            #define WHITE_ROOK 0x04
            #define WHITE_QUEEN 0x05
            #define WHITE_KING 0x06

            #define BLACK_PAWN 0x11
            #define BLACK_KNIGHT 0x12
            #define BLACK_BISHOP 0x13
            #define BLACK_ROOK 0x14
            #define BLACK_QUEEN 0x15
            #define BLACK_KING 0x16
            */
            char opponent_piece = board->squares[RF(rank,file)];
            // The lower nibble tells us what kind of piece it is, with higher values being more valuable. 
            opponent_piece&=0xf;
            // Latch the best move found 
            if(opponent_piece>best_piece_taken){
                best_move=m;
                best_piece_taken=opponent_piece;
            }

        }
        // If there is a move execute a random one from the set
        execute_move(&moves[best_move]);
        return 1;
    }
    // This function returns the total number of legal moves
    // for the current board. It populates each of these legal moves in the 'moves' array.
    int legal_moves = gen_legal_moves(board, moves);
    if(legal_moves){
        // If there is a move execute a random one from the set
        execute_move(&moves[rand()%legal_moves]);
        return 0; 
    }
    return -1;
}
