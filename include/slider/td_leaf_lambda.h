//
// @author: jiahong
// @date  : 9/12/17 4:49 AM
//

#ifndef SLIDER_TD_LEAF_LAMBDA_H
#define SLIDER_TD_LEAF_LAMBDA_H

#include <mutex>
#include <vector>

#include "model.h"
#include "Move.h"
#include "commons/ai/agent/Minimax.h"

class TDLeafLambda {
public:
    static constexpr size_t V_INDEX = Minimax<Slider, Move>::V_INDEX;
    static constexpr size_t DEPTH_INDEX = Minimax<Slider, Move>::DEPTH_INDEX;
    static constexpr size_t STATE_INDEX = Minimax<Slider, Move>::STATE_INDEX;
    TDLeafLambda(Model& model, const std::vector<Move>& move_history);
    const Model& update_weights();

private:
    const std::vector<Move>& move_history;
    Model& model;
};


#endif //SLIDER_TD_LEAF_LAMBDA_H
