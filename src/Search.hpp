#ifndef SEARCH_H_INCLUDED
#define SEARCH_H_INCLUDED
#include <unordered_map>

#include "Board.hpp"
#include "MoveGen.hpp"
#include "Eval.hpp"
#include "TTEntry.hpp"


class Search
{
public:
	constexpr static int MAX_DEPTH = 64;

	Search(std::shared_ptr<Board> boardPtr);

    int negaMaxRoot(const int depth);
    int negaMaxRootIterativeDeepening(const int timeSec);
    inline int getCurrentScore() {return myEval.evaluate();};
    Move myBestMove;

private:

    std::shared_ptr<Board> myBoard;
    Eval myEval;

    int negaMax(const int depth, int alpha, const int beta);
    int evaluate();
    int qSearch(int alpha, const int beta);
    std::unordered_map <int, TTEntry> tt;

    Move pvTable[MAX_DEPTH][MAX_DEPTH]; //pvtable[ply][depth] Quadratic PV-Table
};

#endif // SEARCH_H_INCLUDED
