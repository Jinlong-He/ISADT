#include "Parser/XmlParser/XmlParser.hpp"
#include <iostream>
using std::cout;
using std::endl;
namespace isadt {
    void XmlParser::parse(const char* fileName, Model* model) {
        XMLDocument doc;
        doc.LoadFile(fileName);
        XMLElement* root = doc.RootElement();
        root = root -> FirstChildElement() -> FirstChildElement();
        while (root) {
            if (strcmp(root -> Value(), "UserType_VM") == 0) {
                parseUserType(root, model);
            }
            root = root -> NextSiblingElement();
        }
    }

    Attribute* XmlParser::parseAttribute(XMLElement* root, const string& preName, Model* model) {
        return model -> mkAttribute(model -> getUserTypeById(root -> Attribute("type_ref")),
                                    preName + "_" + root -> Attribute("identifier"));
    }

    Method* XmlParser::parseMethod(XMLElement* root, const string& preName, Model* model) {
        auto method = model -> mkMethod(preName + "_" + root -> Attribute("name"),
                                        model -> getUserTypeById(root -> Attribute("type_ref")), "","");
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
        UserType* userType = model -> mkUserType(root -> Attribute("name"));
        const string& preName = userType -> getName();
        auto base = root -> Attribute("parent_ref");
        if (base) {
            userType -> setBase(model -> getUserTypeById(base));
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
}
