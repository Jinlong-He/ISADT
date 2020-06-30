#include "Model/Struct/Struct.hpp"
namespace isadt {
    void Struct::setName(const string& name) {
        name_ = name;
    }

    const string& Struct::getName() const {
        return name_;
    }

    Attribute* Struct::mkAttribute(UserType* type, const string& name) {
        Attribute* attr = new Attribute(type, name);
        attributes_.push_back(attr);
        attributeMap[name] = attr;
        return attr;
    }

    Attribute* Struct::mkAttribute(const string& name) {
        return mkAttribute(nullptr, name);
    }

    Attribute* Struct::getAttributeByName(const string& name) {
        if (attributeMap.count(name) == 0) return mkAttribute(name);
        return attributeMap[name];
    }

    const list<Attribute*>& Struct::getAttributes() const {
        return attributes_;
    }
}
