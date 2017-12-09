//
// @author: jiahong
// @date  : 9/12/17 4:53 AM
//

#ifndef SLIDER_MODEL_H
#define SLIDER_MODEL_H

#include <vector>
#include <string>
#include <slider/evaluation_functions/basic_eval.h>

class Slider;

class Model {
public:
    Model() = default;
    Model(const std::string& model_file);
    typedef double evalf (const Slider&, std::size_t);
    typedef std::vector<double>::size_type size_type;
    double& operator[](size_type i) { return weights[i]; };
    size_type size() const { return weights.size(); }


public:
    std::vector<evalf*> phi{count_eval/*, block_eval*/};
private:
    std::vector<double> weights{1/*, 0*/};
};


#endif //SLIDER_MODEL_H
