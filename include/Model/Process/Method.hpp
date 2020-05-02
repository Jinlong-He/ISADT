//
//  Method.hpp
//
//  Created by Jinlong He on 2019/11/14.
//  Copyright © 2019 All rights reserved.
//

#ifndef Model_Method_hpp
#define Model_Method_hpp 
#include <list>
#include "Attribute.hpp"
using std::list;

namespace isadt {
    /// \brief the method of process.
    class Method {
        Method()
            : returnType_(nullptr) {}

        Method(const string& name, 
               Type* returnType, 
               const list<Attribute*>& parameters,
               const string& algorithmId,
               const string& userCode)
            : name_(name),
              returnType_(returnType),
              parameters_(parameters),
              algorithmId_(algorithmId),
              userCode_(userCode) {}

        ~Method() {
            for (auto p : parameters_) {
                delete p;
            }
        }

        const string& getName() const;
        void setName(const string& name) ;

        Type* getReturnType() const ;
        void setReturnType(Type* returnType);

        const list<Attribute*>& getParamters() const;
        void setParameters(const list<Attribute*>& parameters);

        const string& getAlgorithmId() const;
        void setAlgorithmId(const string& algorithmId);

        const string& getUserCode() const;
        void setUserCode(const string& userCode);

    private:
        string name_;                    //< the method name.
        Type* returnType_;               //< the return data type.
        list<Attribute*> parameters_;    //< the parameters.
        string algorithmId_;             //< the algorithm identifier.
        string userCode_;                //< the user insertion code.
    };
}

#endif /* Model_Method_hpp */
