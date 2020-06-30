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

    Attribute* XmlParser::parseAttribute(XMLElement* root, const string& preName, Model* model) {
        cout << "attr " + preName + "_" + root -> Attribute("identifier") << endl;
        return model -> mkAttribute(model -> getUserTypeByName(root -> Attribute("type")),
                                    preName + "_" + root -> Attribute("identifier"));
    }

    Method* XmlParser::parseMethod(XMLElement* root, const string& preName, Model* model) {
        auto method = model -> mkMethod(preName + "_" + root -> Attribute("name"),
                                        model -> getUserTypeByName(root -> Attribute("returnType")), 
                                        root -> Attribute("cryptoSuffix"), "");
        cout << "method: " + method -> getName() << endl;
        if (!(root -> NoChildren())) {
            auto element = root -> FirstChildElement();
            const string& name = method -> getName();
            while (element) {
                auto attr = parseAttribute(element, name, model);
                method -> addParameter(attr);
                element = element -> NextSiblingElement();
            }
        }
        return method;
    }

    CommMethod* XmlParser::parseCommMethod(XMLElement* root, const string& preName, Model* model) {
        auto method = model -> mkCommMethod(preName + "_" + root -> Attribute("name"),
                                            strcmp(root -> Attribute("inOutSuffix"), "In"),
                                            root -> Attribute("commWay"));
        cout << "commMethod: " + method -> getName() << endl;
        if (!(root -> NoChildren())) {
            auto element = root -> FirstChildElement();
            const string& name = method -> getName();
            while (element) {
                auto attr = parseAttribute(element, name, model);
                method -> addParameter(attr);
                element = element -> NextSiblingElement();
            }
        }
        return method;
    }

    void XmlParser::parseUserType(XMLElement* root, Model* model) {
        auto userType = model -> getUserTypeByName(root -> Attribute("name"));
        const string& preName = userType -> getName();
        cout << "userType: " + preName << endl;
        auto base = root -> Attribute("parent");
        if (base) {
            userType -> setBase(model -> getUserTypeByName(base));
        }
        if (!(root -> NoChildren())) {
            auto element = root -> FirstChildElement();
            while (element) {
                if (strcmp(element -> Value(), "Attribute") == 0) {
                    auto attr = parseAttribute(element, preName, model);
                    userType -> addAttribute(attr);
                } else {
                    auto method = parseMethod(element, preName, model);
                    userType -> addMethod(method);
                }
                element = element -> NextSiblingElement();
            }
        }
    }

    void XmlParser::parseProcess(XMLElement* root, Model* model) {
        auto proc = model -> getProcByName(root -> Attribute("name"));
        const string& preName = proc -> getProcName();
        cout << "proc: " + preName << endl;
        if (!(root -> NoChildren())) {
            auto element = root -> FirstChildElement();
            while (element) {
                if (strcmp(element -> Value(), "Attribute") == 0) {
                    auto attr = parseAttribute(element, preName, model);
                    proc -> addAttribute(attr);
                } else if (strcmp(element -> Value(), "Method") == 0) {
                    auto method = parseMethod(element, preName, model);
                    proc -> addMethod(method);
                } else if (strcmp(element -> Value(), "CommMethod") == 0) {
                    auto method = parseCommMethod(element, preName, model);
                    proc -> addCommMethod(method);
                }
                element = element -> NextSiblingElement();
            }
        }
    }

    StateMachine* XmlParser::parseStateMachine(XMLElement* root, Process* proc) {
        auto sm = proc -> mkStateMachine();
    }
}
