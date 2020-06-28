//
//  Attribute.hpp
//
//  Created by Jinlong He on 2019/11/14.
//  Copyright © 2019 All rights reserved.
//

#ifndef Model_Attribute_hpp
#define Model_Attribute_hpp 
#include "../Type/Type.hpp"
namespace isadt {
    /// \brief the attribute of process.
    class Attribute {
    public:
        Attribute()
            : type_(nullptr) {}

        Attribute(Type* type, const string& identifier) 
            : type_(type),
              identifier_(identifier) {}

        ~Attribute() {}

        Type* getType() const;
        void setType(Type* type);
        const string& getIdentifier() const;
        void setIdentifier(const string& identifier);
        const string toString() const;

    private:
        Type* type_;
        string identifier_;
    };
}

#endif /* Model_Attribute_hpp */
