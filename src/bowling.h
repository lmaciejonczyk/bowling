#pragma once

#include <tuple>
#include <vector>

using Frame = std::vector<int>;
using Game = std::vector<Frame>;

bool is_spare(const Frame&);
bool is_strike(const Frame&);
int calculate_spare(bool spare, const Frame& frame);
int calculate_strike(int& active_strikes, const Frame& frame, bool last_frame);
std::tuple<int, bool, bool> calculate_frame(const Frame& frame);
int calculate_game(Game&& game);
