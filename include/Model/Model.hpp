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
#include "Pragma/Axiom.hpp"
#include "Channel/Channel.hpp"
namespace isadt {
    /// \brief the model in isadt.
    class Model {
    public:
        Model();
        ~Model();

        Process* mkProcess();
        Process* mkProcess(std::string procName);

        ConfidentialProperty*
        mkConfidentialProperty(Process* process, Attribute* attribute);

        AuthenticityProperty* 
        mkAuthenticityProperty(Process* process1, Vertex* vertex1, Attribute* attribute1,
                               Process* process2, Vertex* vertex2, Attribute* attribute2);

        InitialKnowledge* 
        mkInitialKnowledge(Process* process, Attribute* attribute);
        
        const list<Process*>& getProcesses() const;

        list<UserType*> getUserTypes();
    private:
        list<Process*> processes_;
        list<Property*> properties_;
        list<InitialKnowledge*> initialKnowledges_;
        list<UserType*> userTypes_;
        //list<SequenceDiagram*> sd_;
        list<Axiom*> axioms;
        list<Channel*> channels;
        // ProcMethodPair * 2, bool privacy

    };
}

#endif /* Model_Model_hpp */
