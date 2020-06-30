#include "Parser/XmlParser/XmlParser.hpp"
#include <iostream>
using std::cout;
using std::endl;
namespace isadt {
    void XmlParser::parse(const char* fileName, Model* model) {
        XMLDocument doc;
        doc.LoadFile(fileName);
        XMLElement* root = doc.RootElement();
        root = root -> FirstChildElement();
        parseClassDiagram(root, model);
    }

    void XmlParser::parseClassDiagram(XMLElement* root, Model* model) {
        if (! (root -> NoChildren())) {
            root = root -> FirstChildElement();
            while (root) {
                if (strcmp(root -> Value(), "UserType") == 0) {
                    parseUserType(root, model);
                } else if (strcmp(root -> Value(), "Process") == 0) {
                    parseProcess(root, model);
                }
                root = root -> NextSiblingElement();
            }
        }
    }

    Attribute* XmlParser::parseAttribute(XMLElement* root, Struct* s, Model* model) {
        cout << root -> Attribute("identifier") << endl;
        return s -> mkAttribute(model -> getUserTypeByName(root -> Attribute("type")),
                                root -> Attribute("identifier"));
    }

    Method* XmlParser::parseMethod(XMLElement* root, Class* s, Model* model) {
        auto method = s -> mkMethod(root -> Attribute("name"),
                                    model -> getUserTypeByName(root -> Attribute("returnType")), 
                                    root -> Attribute("cryptoSuffix"), "");
        cout << "method: " + method -> getName() << endl;
        if (!(root -> NoChildren())) {
            auto element = root -> FirstChildElement();
            while (element) {
                auto attr = parseAttribute(element, method, model);
                element = element -> NextSiblingElement();
            }
        }
        return method;
    }

    CommMethod* XmlParser::parseCommMethod(XMLElement* root, Process* s, Model* model) {
        auto method = s -> mkCommMethod(root -> Attribute("name"), nullptr,
                                        strcmp(root -> Attribute("inOutSuffix"), "In"),
                                        root -> Attribute("commWay"));
        cout << "commMethod: " + method -> getName() << endl;
        if (!(root -> NoChildren())) {
            auto element = root -> FirstChildElement();
            while (element) {
                auto attr = parseAttribute(element, method, model);
                element = element -> NextSiblingElement();
            }
        }
        return method;
    }

    void XmlParser::parseUserType(XMLElement* root, Model* model) {
        auto userType = model -> getUserTypeByName(root -> Attribute("name"));
        cout << "userType: " + userType -> getName() << endl;
        auto base = root -> Attribute("parent");
        if (base) {
            userType -> setBase(model -> getUserTypeByName(base));
        }
        if (!(root -> NoChildren())) {
            auto element = root -> FirstChildElement();
            while (element) {
                if (strcmp(element -> Value(), "Attribute") == 0) {
                    auto attr = parseAttribute(element, userType, model);
                } else {
                    auto method = parseMethod(element, userType, model);
                }
                element = element -> NextSiblingElement();
            }
        }
    }

    void XmlParser::parseProcess(XMLElement* root, Model* model) {
        auto proc = model -> getProcByName(root -> Attribute("name"));
        cout << "proc: " + proc -> getName() << endl;
        if (!(root -> NoChildren())) {
            auto element = root -> FirstChildElement();
            while (element) {
                if (strcmp(element -> Value(), "Attribute") == 0) {
                    auto attr = parseAttribute(element, proc, model);
                } else if (strcmp(element -> Value(), "Method") == 0) {
                    auto method = parseMethod(element, proc, model);
                } else if (strcmp(element -> Value(), "CommMethod") == 0) {
                    auto method = parseCommMethod(element, proc, model);
                }
                element = element -> NextSiblingElement();
            }
        }
    }

    //Edge* XmlParser::parseEdge() {
    //}

    //StateMachine* XmlParser::parseStateMachine(XMLElement* root, Process* proc) {
    //    auto sm = proc -> mkStateMachine();
    //    sm -> mkStartVertex("_init");
    //    if (!(root -> NoChildren())) {
    //        auto element = root -> FirstChildElement();
    //        while (element) {
    //            if (strcmp(element -> Value(), "Transition") == 0) {
    //                auto s = sm -> getVertexByName(element -> Attribute("source"));
    //                auto t = sm -> getVertexByName(element -> Attribute("dest"));
    //                sm -> mkEdge();
    //            } else if (strcmp(element -> Value(), "State") == 0) {
    //            }
    //        }
    //    }
    //}
}
