//
//  Model.hpp
//
//  Created by Jinlong He on 2019/11/14.
//  Copyright © 2019 All rights reserved.
//

#ifndef Parser_C_hpp 
#define Parser_C_hpp
#include <string>
#include <vector>
#include "../../Model/Model.hpp"
using std::string;
using std::vector;
namespace isadt {
    class LParser {
    public:
        static void parse(const vector<string>& text, Model* model);
    };
}
#endif /* Parser_C_hpp */

