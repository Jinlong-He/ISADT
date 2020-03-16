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
            : type(nullptr) {}

        Attribute(Type* _type, const string& _identifier) 
            : type(_type),
              identifier(_identifier) {}

        ~Attribute() {}

        Type* getType() const;
        void setType(Type* _type);
        const string& getIdentifier() const;
        void setIdentifier(const string& _identifier);
        const string toString() const;

    private:
        Type* type;
        string identifier;
    };
}

#endif /* Model_Attribute_hpp */
