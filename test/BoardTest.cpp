/*
	Deepov, a UCI chess playing engine.

	Copyright (c) 20014-2016 Romain Goussault, Navid Hedjazian

    Deepov is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Deepov is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Deepov.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "catch.hpp"
#include "Board.hpp"
#include "BitBoardUtils.hpp"
#include "MagicMoves.hpp"
#include "Tables.hpp"
#include "MoveGen.hpp"


TEST_CASE( "is bit Set method" )
{
	//whitePawnStartingPosition
	U64 whitePawns(0LL | 0xFFLL << 8 );

	REQUIRE(BitBoardUtils::isBitSet(0, 5, 5) == false);
	REQUIRE(BitBoardUtils::isBitSet(whitePawns, 0, 0) == false);
	REQUIRE(BitBoardUtils::isBitSet(whitePawns, 5, 0) == false);
	REQUIRE(BitBoardUtils::isBitSet(whitePawns, 5, 5) == false);
	REQUIRE(BitBoardUtils::isBitSet(whitePawns, 7, 5) == false);
	REQUIRE(BitBoardUtils::isBitSet(whitePawns, 1, 5) == false);
	REQUIRE(BitBoardUtils::isBitSet(whitePawns, 5, 1) == true);
	REQUIRE(BitBoardUtils::isBitSet(whitePawns, 0, 1) == true);
	REQUIRE(BitBoardUtils::isBitSet(whitePawns, 7, 1) == true);
	REQUIRE(BitBoardUtils::isBitSet(whitePawns, 2, 1) == true);
	REQUIRE(BitBoardUtils::isBitSet(whitePawns, 2, 2) == false);
	REQUIRE(BitBoardUtils::isBitSet(whitePawns, 2, 7) == false);
}

TEST_CASE( "AtkFr" )
{
	MagicMoves::initmagicmoves();
	Tables::init();

	std::shared_ptr<Board> sp = std::shared_ptr<Board>(new Board());
    sp->updateAtkFr();
	REQUIRE(sp->getAtkFr(SQ_C5) == 0LL);
	REQUIRE(popcount(sp->getAtkFr(SQ_B1)) == 2);//Knight
	REQUIRE(popcount(sp->getAtkFr(SQ_C1)) == 0);//Bishop
	REQUIRE(popcount(sp->getAtkFr(SQ_A1)) == 0);//Rook
	REQUIRE(popcount(sp->getAtkFr(SQ_D1)) == 0);//Queen
	REQUIRE(popcount(sp->getAtkFr(SQ_E1)) == 0);//King

	REQUIRE(popcount(sp->getAtkFr(SQ_A2)) == 1); //Pawn
	REQUIRE(popcount(sp->getAtkFr(SQ_B2)) == 2); //Pawn

	REQUIRE(popcount(sp->getAtkFr(SQ_C7)) == 2); //Black Pawn

	sp = std::shared_ptr<Board>(new Board("r1b1k2r/p1pQ1p1p/np2pn2/4b2K/8/P1P3q1/4NPPP/3R1pNR w kq -"));
    sp->updateAtkFr();
	REQUIRE(popcount(sp->getAtkFr(SQ_E5)) == 4); //Bishop
	REQUIRE(popcount(sp->getAtkFr(SQ_D1)) == 10); //Rook
	REQUIRE(popcount(sp->getAtkFr(SQ_D7)) == 15); //Queen
	REQUIRE(popcount(sp->getAtkFr(SQ_E8)) == 4); //King
}


TEST_CASE( "EP squares" )
{
	std::shared_ptr<Board> sp = std::shared_ptr<Board>(new Board("rnbqkb1r/pp1ppppp/5n2/2pP4/8/8/PPP1PPPP/RNBQKBNR w KQkq c6 0 3"));
    REQUIRE(sp->getLastEpSquare() == SQ_C6);

    Move move1(SQ_E2,SQ_E3,Move::QUIET_FLAG,Piece::PAWN);
    Move move2(SQ_E2, SQ_E4, Move::DOUBLE_PAWN_PUSH_FLAG, Piece::PAWN);

	sp->executeMove(move1);
    REQUIRE(sp->getLastEpSquare() == SQ_NONE);

    sp->undoMove(move1);
    REQUIRE(sp->getLastEpSquare() == SQ_C6);

	sp->executeMove(move2);
    REQUIRE(sp->getLastEpSquare() == SQ_E3);

    sp->undoMove(move2);
    REQUIRE(sp->getLastEpSquare() == SQ_C6);
}



