#include "Model/pragma/InitialKnowledge.hpp"
namespace isadt {
    bool InitialKnowledge::isKeyPair() {
        return (pkKnowledge_ != nullptr);
    }
}
