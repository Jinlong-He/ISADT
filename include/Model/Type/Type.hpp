//
//  Type.hpp
//
//  Created by Jinlong He on 2019/11/14.
//  Copyright © 2019 All rights reserved.
//

#ifndef Model_Type_hpp
#define Model_Type_hpp 
#include <string>
using std::string;

namespace isadt {
    /// \brief the data type.
    class Type {
    public:
        Type() : name("") {}

        Type(const string& _name) : name(_name) {}

        /// \brief Gets the name of type.
        /// \return the const reference of string.
        const string& getName() const;

        /// \brief Sets the name of type.
        /// \param _name.
        void setName(const string& _name);

    private:
        string name;
    };

    /// \brief the bool data type.
    class BoolType : public Type {
    public:
        BoolType() : Type("Bool") {}

        BoolType(const string& _name) : Type(_name) {}
    };

    /// \brief the int data type.
    class IntType : public Type {
    public:
        IntType() : Type("Int") {}

        IntType(const string& _name) : Type(_name) {}
    };
}

#endif /* Model_Type_hpp */
