#include <stack>
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
        Visitor(Model* model, Process* proc, Edge* edge)
            : model_(model),
              proc_(proc),
              edge_(edge) {}

        Any visitAndExpression(CParser::AndExpressionContext* ctx) override {
            return visitChildren(ctx);
        }

        Any visitInclusiveOrExpression(CParser::InclusiveOrExpressionContext* ctx) override {
            return visitChildren(ctx);
        }
        Any visitAdditiveExpression(CParser::AdditiveExpressionContext* ctx) override {
            cout << "+" << endl;
            if (ctx -> additiveExpression())
                cout << "add" << ctx -> additiveExpression() ->getText() <<endl;
            if (ctx -> multiplicativeExpression())
                cout << "mul" << ctx -> multiplicativeExpression() -> getText() <<endl;
            return visitChildren(ctx);
        }

        Any visitMultiplicativeExpression(CParser::MultiplicativeExpressionContext* ctx) override {
            cout << "*" << endl;
            if (ctx -> castExpression())
            cout << "cast" << ctx -> castExpression()-> getText() <<endl;
            if (ctx -> multiplicativeExpression())
            cout << "mul" << ctx -> multiplicativeExpression()-> getText() <<endl;
            return visitChildren(ctx);
        }


        Any visitDeclaration(CParser::DeclarationContext* ctx) override {
            cout << 333 << endl;
            string typeStr = ctx -> declarationSpecifiers() -> getText();
            string identifier = ctx -> initDeclaratorList() -> getText();
            cout << typeStr << identifier << endl;
            //cout << identifier << endl;
            UserType* type = model_ -> getUserTypeByName(typeStr);
            auto attr = proc_ -> mkAttribute(type, identifier);
            edge_ -> mkDeclarationAction(attr, identifier);
            return visitChildren(ctx);
        }
        //Any visitDeclarator(CParser::DeclaratorContext* ctx) override {
        //    cout << 111 << endl;
        //    return visitChildren(ctx);
        //}

        Any visitExpression(CParser::ExpressionContext* ctx) override {
            cout << 444 << endl;
            cout << ctx ->  assignmentExpression() -> getText() << endl;
            //cout << ctx ->  expression();
            return visitChildren(ctx);
        }

        Any visitAssignmentExpression(CParser::AssignmentExpressionContext* ctx) override {
            cout << 222 << endl;
            auto ce = ctx -> conditionalExpression();
            //size_t pos = ce -> getText().find("(");
            //if (pos != string::npos) {
            //    string name = ce -> getText().substr(0,pos);
            //    if (proc_ -> hasMethod(name)) {
            //        //auto methodTerm
            //    } else {
            //        cout << name << " is not declared!" << endl;
            //    }
            //}
            //cout << ctx -> assignmentOperator() -> getText() << endl;;
            //cout << ctx -> conditionalExpression() -> getText() << endl;
            //cout << ctx -> unaryExpression();
            //cout << ctx -> assignmentOperator();
            //cout << ctx -> assignmentExpression();
            //cout << ctx -> DigitSequence();
            return visitChildren(ctx);
        }
    private:
        Model* model_;
        Process* proc_;
        Edge* edge_;
        stack<MethodTerm*> methodTermStack_;
    };

    void LParser::parse(const vector<string>& text, Model* model, Process* proc, Edge* edge) {
        ANTLRInputStream input("main() {int a; a = get(a) + 1;}");
        //ANTLRInputStream input("if(ba==1||b>1)&&a==2;");
        CLexer lexer(&input);
        CommonTokenStream tokens(&lexer);
        CParser parser(&tokens);
        tree::ParseTree* tree = parser.compilationUnit();
        Visitor visitor(model, proc, edge);
        visitor.visit(tree);

        std::wstring s = antlrcpp::s2ws(tree->toStringTree(&parser)) + L"\n";

        //OutputDebugString(s.data()); // Only works properly since VS 2015.
        std::wcout << "Parse Tree: " << s << std::endl; //Unicode output in the console is very limited.
    }
}
