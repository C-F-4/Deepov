#include "catch.hpp"
#include "Board.hpp"
#include "Move.hpp"
#include "MoveGen.hpp"
#include "MoveOrdering.hpp"
#include "Eval.hpp"


TEST_CASE( "Test move rating", "[moveordering]" )
{
	MagicMoves::initmagicmoves();
	Tables::init();

	std::shared_ptr<Board> sp = std::shared_ptr<Board>(new Board("8/8/3k4/4b3/2nnn3/2nQn3/2nnn3/7K w - - 0 1"));
	MoveGen moveGen(*sp);

    std::vector<Move> moveList = moveGen.generateMoves();
    MoveOrdering::rateMoves(moveList);

//    for (auto it=moveList.begin(); it<moveList.end(); it++)
//    {
//        REQUIRE(it->getMoveRating() == Piece::KNIGHT_VALUE);
//    }
}


TEST_CASE( "Compare sort methods", "[moveordering]" )
{
	MagicMoves::initmagicmoves();
	Tables::init();

	std::shared_ptr<Board> sp = std::shared_ptr<Board>(new Board("r4rk1/ppp1nppp/2n2q2/4p1B1/1b1pP3/2NP1NPb/PPP1QPBP/2KR3R w - - 3 11"));
	MoveGen moveGen(*sp);

    std::vector<Move> moveList0 = moveGen.generateMoves();
    MoveOrdering::rateMoves(moveList0);
    std::cout << "MoveOrdering::getBestCandidate" << std::endl;


    std::cout << *MoveOrdering::getBestCandidate(moveList0) << std::endl;
//    std::cout << MoveOrdering::getBestCandidate(moveList0) << std::endl;
    

	std::vector<Move> moveList1 = moveGen.generateMoves();

    MoveOrdering::rateMoves(moveList1);
    MoveOrdering::sortMoves(moveList1);

    std::cout << "MoveOrdering::sortMoves" << std::endl;
    for (auto it=moveList1.begin(); it<moveList1.begin()+5; it++)
    {
        std::cout << *it << std::endl;
        std::cout << it->getMoveRating() << std::endl;
    }

    std::begin(moveList1)->setMoveRating(100);
    std::cout << *std::begin(moveList1) << std::endl;
    std::cout << std::begin(moveList1)->getMoveRating() << std::endl;

	std::vector<Move> moveList2 = moveGen.generateMoves();
    Eval::sortMoveList(moveList2);
    Move bestMove=*std::begin(moveList2);
    std::cout << "Eval::sortMoveList" << std::endl;
    for (auto it=moveList2.begin(); it<moveList2.begin()+5; it++)
    {       
        std::cout << *it << std::endl;
        std::cout << it->getMoveRating() << std::endl;
    }

    REQUIRE(bestMove.toShortString() == "g5f6");

}
