#ifndef EVALTABLES_H_INCLUDED
#define EVALTABLES_H_INCLUDED

namespace EvalTables
{
    /* Piece square tables */

    // All constants are for white, need to flip to get the little-endian ...

    /*
    [0][][] is for white, [1][][] is for black
    [][1][6] is for midgame
    [][1][6] is for endgame

    Last dimension : same as for moves
    0 Pawn, 1 Knight, 2 Bishop, 3 Rook, 4 Queen, 5 King
    */

    extern const int AllPSQT[2][2][6][64];

    /* Mobility tables */
    extern const int MobilityScaling[2][6];
}

#endif // EVALTABLES_H_INCLUDED
