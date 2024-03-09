#include "lab_func.hpp"

std::string lab_func(const std::string &inp_stirng) {
    std::string res_string = "";
    for (size_t i = 0; i < inp_stirng.size(); ++i) {
        if (inp_stirng[i] == 'b') {
            res_string += 'a';
        } else if (inp_stirng[i] == 'a') {
            res_string += 'b';
        } else {
            res_string += inp_stirng[i];
        }
    }
    return res_string;
}
