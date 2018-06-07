#include "bowling.h"

#include <numeric>

#define MAX_FRAME_SCORE 10

bool is_strike(const Frame& frame) {
  return frame[0] == MAX_FRAME_SCORE;
}

bool is_spare(const Frame& frame) {
  return frame[0] != MAX_FRAME_SCORE && (frame[0] + frame[1]) == MAX_FRAME_SCORE;
}

std::tuple<int, bool, bool> calculate_frame(const Frame& frame) {
  auto frame_result = std::accumulate(frame.cbegin(), frame.cend(), 0);
  auto strike = is_strike(frame);
  auto spare = is_spare(frame);

  return std::make_tuple(frame_result, spare, strike);
}

int calculate_spare(bool spare, const Frame& frame) {
  return spare == true ? frame[0] : 0;
}

bool is_last_frame(int frame_cnt) {
  return frame_cnt == 9;
}

int calculate_strike(int& strikes_rolls, const Frame& frame, bool last_frame) {
  int strike_result = 0;

  if (strikes_rolls > 0) {
    strike_result += (strikes_rolls + 1) / 2 * frame[0];
    strikes_rolls -= (strikes_rolls + 1) / 2;
  }

  if (strikes_rolls > 0 && (is_strike(frame) == false || last_frame == true)) {
    strike_result += (strikes_rolls + 1) / 2 * frame[1];
    strikes_rolls -= (strikes_rolls + 1) / 2;
  }

  return strike_result;
}

int calculate_game(Game&& game) {
  bool spare, strike, last_spare;
  int frame_result;
  int game_result = 0;
  int frame_cnt = 0;
  int strikes_rolls = 0;

  for (const auto& frame : game) {
    std::tie(frame_result, spare, strike) = calculate_frame(frame);
    game_result += frame_result;
    if (frame_cnt > 0) {
      game_result += calculate_spare(last_spare, frame);
      game_result += calculate_strike(strikes_rolls, frame, frame_cnt);
    }
    last_spare = spare;
    strikes_rolls += strike == true ? 2 : 0;
    frame_cnt++;
  }

  return game_result;
}
