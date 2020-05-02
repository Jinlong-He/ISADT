//
//  UserType.hpp
//
//  Created by Jinlong He on 2019/11/14.
//  Copyright © 2019 All rights reserved.
//

#ifndef Model_UserType_hpp
#define Model_UserType_hpp 
#include <list>
#include "Type.hpp"
#include "../Process/Attribute.hpp"

using std::list;

namespace isadt {
    /// \brief the user defined data type of process.
    class UserType : public Type {
    public:
        UserType();

        UserType(const string& name, 
                 const list<Attribute*>& parameters, 
                 UserType* base = nullptr) :
            name_(name),
            parameters_(parameters),
            base_(base) {}

        const list<Attribute*>& getParameters() const;
        void setParameters(const list<Attribute*>& _parameters);
        void addParameter(Attribute* attr);

    private:
        string name_;                     //< the name of this type.
        list<Attribute*> parameters_;     //< the parameter list of this type.
        UserType* base_;                  //< the base type of this type.
    };
}

#endif /* Model_UserType_hpp */
