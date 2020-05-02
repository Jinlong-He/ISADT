//
//  Model.hpp
//
//  Created by Jinlong He on 2019/11/14.
//  Copyright © 2019 All rights reserved.
//

#ifndef Model_Model_hpp
#define Model_Model_hpp 
#include "Type/UserType.hpp"
#include "Process/Process.hpp"
#include "Pragma/Property.hpp"
#include "Pragma/InitialKnowledge.hpp"
#include "SequenceDiagram/SequenceDiagram.hpp"

namespace isadt {
    /// \brief the model in isadt.
    class Model {
    public:
        Model();
        ~Model() {
            //delete processes, properties, initialknowledges.
        }

        Process* mkProcess();

        ConfidentialProperty*
        mkConfidentialProperty(Process* process, Attribute* attribute);

        AuthenticityProperty* 
        mkAuthenticityProperty(Process* process1, Vertex* vertex1, Attribute* attribute1,
                               Process* process2, Vertex* vertex2, Attribute* attribute2);

        InitialKnowledge* 
        mkInitialKnowledge(Process* process, Attribute* attribute);
    private:
        list<Process*> processes_;
        list<Property*> properties_;
        list<InitialKnowledge*> initialKnowledges_;
        list<UserType*> userTypes_;
        SequenceDiagram* sd_;
    };
}

#endif /* Model_Model_hpp */
