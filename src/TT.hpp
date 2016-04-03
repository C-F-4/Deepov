#ifndef TT_HPP_
#define TT_HPP_

#include "Move.hpp"
#include "Types.hpp"
#include "TTEntry.hpp"

class TT {

public:

    const static int TT_SIZE = 1048576;

	TT()
    {
    }

    void setTTEntry(Zkey zkey, int depth, int score, NodeType node, Move bestMove);
    TTEntry* probeTT(Zkey zkey, int depth);

private:
    TTEntry myTTable[TT_SIZE];


};

inline std::ostream& operator<<(std::ostream &strm, const TT &tt) {

	for(int entry = 0; rank < TT_SIZE ; entry++)
	{
        if (tt[entry] != NodeType::NONE)
        {
		    strm << entry << " > ";
            strm << tt[entry].getNodeType() << " ";
		    strm << "Depth " tt[entry].getDepth() << " ";
		    strm << "Score " tt[entry].getScore() << " ";
		    strm << "Best move " tt[entry].getBestmove() << " ";
        }

		strm << std::endl;
	}


	return strm;
}


#endif /* TT_HPP_ */