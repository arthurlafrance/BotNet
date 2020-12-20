#include <vector>
#include <stdexcept>

#include <gtest/gtest.h>

#include "Board.hpp"
#include "GameOutcome.hpp"


class BoardTests : public testing::Test {
public:
    mancala::Board board;
    unsigned int empty_board[2][6]{
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}
    };

    
    void SetUp() override {
        board = mancala::Board();
    }
};


TEST_F(BoardTests, StoresAreInitiallyEmpty) {
    ASSERT_EQ(board.store(0), 0);
    ASSERT_EQ(board.store(1), 0);
}


TEST_F(BoardTests, PitsInitiallyContain3Pieces) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < mancala::Board::PITS; ++j) {
            ASSERT_EQ(board.pit(i, j), 3);
        }
    }
}


TEST_F(BoardTests, SowPlayerTooLargeThrowsException) {
    ASSERT_THROW(board.sow(2, 0), std::out_of_range);
}


TEST_F(BoardTests, SowPlayerTooSmallThrowsException) {
    ASSERT_THROW(board.sow(-1, 0), std::out_of_range);
}


TEST_F(BoardTests, SowPitTooLargeThrowsException) {
    ASSERT_THROW(board.sow(0, 10), std::out_of_range);
}


TEST_F(BoardTests, SowPitTooSmallThrowsException) {
    ASSERT_THROW(board.sow(0, -1), std::out_of_range);
}


TEST_F(BoardTests, SowStaysInSameRowCorrectly) {
    board.sow(0, 4);
    board.sow(1, 4);

    ASSERT_EQ(board.pit(0, 4), 0);
    ASSERT_EQ(board.pit(1, 4), 0);

    for (unsigned int i = 3; i > 0; --i) {
        ASSERT_EQ(board.pit(0, i), 4);
        ASSERT_EQ(board.pit(1, i), 4);
    }
}


TEST_F(BoardTests, SowSpillsOverToNextRowCorrectly) {
    board.sow(0, 1);
    board.sow(1, 1);

    ASSERT_EQ(board.pit(0, 1), 0);
    ASSERT_EQ(board.pit(1, 1), 0);

    ASSERT_EQ(board.store(0), 1);
    ASSERT_EQ(board.store(1), 1);

    ASSERT_EQ(board.pit(0, 0), 4);
    ASSERT_EQ(board.pit(1, 0), 4);

    ASSERT_EQ(board.pit(0, 5), 4);
    ASSERT_EQ(board.pit(1, 5), 4);
}


TEST_F(BoardTests, AllMovesReturnedWhenAllLegal) {
    std::vector<unsigned int> expected{0, 1, 2, 3, 4, 5};

    ASSERT_EQ(board.legal_moves(0), expected);
    ASSERT_EQ(board.legal_moves(1), expected);
}


TEST_F(BoardTests, NoMovesReturnedWhenNoneAreLegal) {
    unsigned int empty_stores[2]{0, 0};
    board = mancala::Board(empty_stores, empty_board);

    ASSERT_EQ(board.legal_moves(0).size(), 0);
    ASSERT_EQ(board.legal_moves(1).size(), 0);
}


TEST_F(BoardTests, AppropriateLegalMovesReturned) {
    unsigned int empty_stores[2]{0, 0};
    unsigned int partial_board[2][6]{
        {0, 1, 1, 0, 1, 0},
        {1, 0, 0, 1, 0, 1}
    };

    board = mancala::Board(empty_stores, partial_board);

    std::vector<unsigned int> expected_p1{1, 2, 4};
    std::vector<unsigned int> expected_p2{0, 3, 5};

    ASSERT_EQ(board.legal_moves(0), expected_p1);
    ASSERT_EQ(board.legal_moves(1), expected_p2);
}


TEST_F(BoardTests, ContinuingReturnedWhenGameNotOver) {
    ASSERT_EQ(board.game_over(), mancala::GameOutcome::CONTINUING);
}


TEST_F(BoardTests, DrawCorrectlyReturned) {
    unsigned int equal_stores[2]{3, 3};
    board = mancala::Board(equal_stores, empty_board);

    ASSERT_EQ(board.game_over(), mancala::GameOutcome::DRAW);
}


TEST_F(BoardTests, Player1WinCorrectlyReturned) {
    unsigned int stores[2]{3, 2};
    board = mancala::Board(stores, empty_board);

    ASSERT_EQ(board.game_over(), mancala::GameOutcome::P1_WIN);
}


TEST_F(BoardTests, Player2WinCorrectlyReturned) {
    unsigned int stores[2]{2, 3};
    board = mancala::Board(stores, empty_board);

    ASSERT_EQ(board.game_over(), mancala::GameOutcome::P2_WIN);
}
