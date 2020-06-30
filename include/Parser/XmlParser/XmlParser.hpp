//
//  Model.hpp
//
//  Created by Jinlong He on 2019/11/14.
//  Copyright © 2019 All rights reserved.
//

#ifndef Parser_XML_hpp 
#define Parser_XML_hpp
#include "tinyxml2.h"
#include "../../Model/Model.hpp"
using namespace tinyxml2;
namespace isadt {
    class XmlParser {
    public:
        static void parse(const char* fileName, Model* model);
        static void parseClassDiagram(XMLElement* root, Model* model);
        static void parseUserType(XMLElement* root, Model* model);
        static void parseProcess(XMLElement* root, Model* model);
        static Attribute* parseAttribute(XMLElement* root, const string& preName, Model* model);
        static Method* parseMethod(XMLElement* root, const string& preName, Model* model);
        static CommMethod* parseCommMethod(XMLElement* root, const string& preName, Model* model);
        static StateMachine* parseStateMachine(XMLElement* root, Process* proc);
    };
}

#endif /* Parser_XML_hpp */
