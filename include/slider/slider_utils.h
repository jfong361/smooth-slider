//
// @author: jiahong
// @date  : 18/11/17 11:00 PM
//

#ifndef SLIDER_SLIDER_UTILS_H
#define SLIDER_SLIDER_UTILS_H

enum class SliderMove : char {
    Up, Down, Left, Right
};

enum class SliderPiece : char {
    Vertical, Horizontal, Blank, Block
};

enum class SliderPlayer : char {
    Vertical, Horizontal
};

inline const char*
get_cstr(SliderPlayer player) {
    return player == SliderPlayer::Horizontal
           ? "Horizontal"
           : "Vertical";
}

#endif //SLIDER_SLIDER_UTILS_H

