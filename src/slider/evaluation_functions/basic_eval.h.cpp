//
// @author: jiahong
// @date  : 27/11/17 11:53 PM
//

#include "basic_eval.h"
#include <cmath>

double
count_eval(const Slider &state, size_t depth) {
    auto agent = state.get_agent();
    auto pieces_left = state.get_board().get_piece_positions(agent).size();
    // the LESS pieces left, the better.
    return state.get_board().size() - pieces_left;
}


double
block_eval(const Slider &state, size_t depth) {
    double player_moves_left = state.possible_moves().size();
    double opponent_moves_left = state.possible_moves().size();
    // each piece can go 3 direction AT MOST
    const size_t total_possible_moves = (state.get_board().size() - 1) * 3;
    // number of pieces left of other player (the more the better)
    double c = state.get_board().get_piece_positions(other_player(state.get_player())).size();

    // - log(opponent_moves_left/total_possible_moves) + log(player_moves_left)

    // opponent_moves_left/total_poss => [0, 1] and negative of those values gives an exponential
    // y decrease as it approaches 1. I.e. heavily favours less opponent_moves_left

    // player_moves_left is important, but not linearly important, give it a log increase
    return log(player_moves_left) -
           log((state.get_board().size() - 1) / c * opponent_moves_left / total_possible_moves);
}

double
compound_eval(const Slider &state, size_t depth) {
    // TODO: improve this
//    auto ret_val =
//            (state.get_board().size() - state.get_board().get_piece_positions(state.get_player()).size()) * 2.8797 *
//            count_eval(state) + 2.11 * block_eval(state);
    auto ret_val = count_eval(state, depth);
    return (1 - (depth * 1.0) / (depth + 1)) * ret_val;
}