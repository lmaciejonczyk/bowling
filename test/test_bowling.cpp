#include <gtest/gtest.h>

#include "../src/bowling.h"

TEST(FrameTest, strike) {
  EXPECT_EQ(false, is_strike(Frame{3, 5}));
  EXPECT_EQ(true, is_strike(Frame{10, 0}));
  EXPECT_EQ(false, is_strike(Frame{9, 1}));
}

TEST(FrameTest, spare) {
  EXPECT_EQ(false, is_spare(Frame{0, 0}));
  EXPECT_EQ(false, is_spare(Frame{10, 0}));
  EXPECT_EQ(true, is_spare(Frame{2, 8}));
}

TEST(FrameTest, calculate_spare) {
  EXPECT_EQ(0, calculate_spare(false, Frame{3, 4}));
  EXPECT_EQ(3, calculate_spare(true, Frame{3, 4}));
}

TEST(FrameTest, calculate_strike) {
  int active_strikes = 0;
  EXPECT_EQ(0, calculate_strike(active_strikes, Frame({4, 5}), false));

  active_strikes = 1;
  EXPECT_EQ(4, calculate_strike(active_strikes, Frame({4, 5}), false));

  active_strikes = 2;
  EXPECT_EQ(9, calculate_strike(active_strikes, Frame({4, 5}), false));

  active_strikes = 3;
  EXPECT_EQ(13, calculate_strike(active_strikes, Frame({4, 5}), false));

  active_strikes = 3;
  EXPECT_EQ(13, calculate_strike(active_strikes, Frame({4, 5, 0}), true));

  active_strikes = 3;
  EXPECT_EQ(20, calculate_strike(active_strikes, Frame({10, 0}), false));
}

TEST(FrameTest, calculate) {
  EXPECT_EQ(std::make_tuple(0, false, false), calculate_frame(Frame{0, 0}));
  EXPECT_EQ(std::make_tuple(7, false, false), calculate_frame(Frame{3, 4}));
  EXPECT_EQ(std::make_tuple(10, true, false), calculate_frame(Frame{3, 7}));
  EXPECT_EQ(std::make_tuple(10, true, false), calculate_frame(Frame{0, 10}));
  EXPECT_EQ(std::make_tuple(10, false, true), calculate_frame(Frame{10, 0}));
}

TEST(GameTest, calculate) {
  EXPECT_EQ(0,
            calculate_game(Game{
                Frame{0, 0},
                Frame{0, 0},
                Frame{0, 0},
                Frame{0, 0},
                Frame{0, 0},
                Frame{0, 0},
                Frame{0, 0},
                Frame{0, 0},
                Frame{0, 0},
                Frame{0, 0},
            }));

  EXPECT_EQ(60,
            calculate_game(Game{
                Frame{3, 3},
                Frame{3, 3},
                Frame{3, 3},
                Frame{3, 3},
                Frame{3, 3},
                Frame{3, 3},
                Frame{3, 3},
                Frame{3, 3},
                Frame{3, 3},
                Frame{3, 3},
            }));

  EXPECT_EQ(140,
            calculate_game(Game{
                Frame{4, 6},
                Frame{4, 6},
                Frame{4, 6},
                Frame{4, 6},
                Frame{4, 6},
                Frame{4, 6},
                Frame{4, 6},
                Frame{4, 6},
                Frame{4, 6},
                Frame{4, 6, 4},
            }));

  EXPECT_EQ(240,
            calculate_game(Game{
                Frame{10, 0},
                Frame{10, 0},
                Frame{10, 0},
                Frame{10, 0},
                Frame{10, 0},
                Frame{10, 0},
                Frame{10, 0},
                Frame{10, 0},
                Frame{10, 0},
                Frame{0, 0},
            }));

  EXPECT_EQ(300,
            calculate_game(Game{
                Frame{10, 0},
                Frame{10, 0},
                Frame{10, 0},
                Frame{10, 0},
                Frame{10, 0},
                Frame{10, 0},
                Frame{10, 0},
                Frame{10, 0},
                Frame{10, 0},
                Frame{10, 10, 10},
            }));
}
