#include "Parser/LParser/LParser.hpp"
#include "antlr4-runtime.h"
#include "CLexer.h"
#include "CParser.h"
#include "CBaseVisitor.h"
#include "CBaseListener.h"
#pragma execution_character_set("utf-8")
using namespace antlrcpp;
using namespace antlr4;
using namespace std;
namespace isadt {
    class Visitor : public CBaseVisitor {
    public:
        Any visitInitDeclarator(CParser::InitDeclaratorContext* ctx) override {
            string s = ctx->getText();
            cout << s << endl;
            //string declarator = split(s, "=").at(0);
            //declared.insert(declarator);
            return visitChildren(ctx);
        }

        Any visitAssignmentExpression(CParser::AssignmentExpressionContext* ctx) override {
            string s = ctx->getText();
            cout << s << endl;
            //vector<string> vs = split(ctx->getText(), "=");
            //if (vs.size() > 1) {
            //    string declarator = vs.at(0);
            //    if (declared.find(declarator) == declared.end())
            //    {
            //        cout << "error:" << declarator << " not declared" << endl;
            //    }
            //}
            return visitChildren(ctx);
        }
    private:
        set<string> declared;
    };

    void LParser::parse(const vector<string>& text, Model* model) {
        ANTLRInputStream input("int a; a = 1;");
        CLexer lexer(&input);
        CommonTokenStream tokens(&lexer);

        CParser parser(&tokens);
        tree::ParseTree* tree = parser.compilationUnit();
        Visitor visitor;
        visitor.visit(tree);

        std::wstring s = antlrcpp::s2ws(tree->toStringTree(&parser)) + L"\n";

        //OutputDebugString(s.data()); // Only works properly since VS 2015.
        std::wcout << "Parse Tree: " << s << std::endl; //Unicode output in the console is very limited.
    }
}
