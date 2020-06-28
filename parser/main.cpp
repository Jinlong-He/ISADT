/* Copyright (c) 2012-2017 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */

//
//  main.cpp
//  antlr4-cpp-demo
//
//  Created by Mike Lischke on 13.03.16.
//

#include <iostream>

#include "antlr4-runtime.h"
#include "TLexer.h"
#include "TParser.h"
#include "TBaseVisitor.h"
#include "TBaseListener.h"

#include <Windows.h>

#pragma execution_character_set("utf-8")

using namespace antlrcpp;
using namespace antlrcpptest;
using namespace antlr4;
using namespace std;


vector<string> split(const string& s, const string& seperator) {
    vector<string> result;
    typedef string::size_type string_size;
    string_size i = 0;

    while (i != s.size()) {
        //找到字符串中首个不等于分隔符的字母；
        int flag = 0;
        while (i != s.size() && flag == 0) {
            flag = 1;
            for (string_size x = 0; x < seperator.size(); ++x)
                if (s[i] == seperator[x]) {
                    ++i;
                    flag = 0;
                    break;
                }
        }

        //找到又一个分隔符，将两个分隔符之间的字符串取出；
        flag = 0;
        string_size j = i;
        while (j != s.size() && flag == 0) {
            for (string_size x = 0; x < seperator.size(); ++x)
                if (s[j] == seperator[x]) {
                    flag = 1;
                    break;
                }
            if (flag == 0)
                ++j;
        }
        if (i != j) {
            result.push_back(s.substr(i, j - i));
            i = j;
        }
    }
    return result;
}

class Visitor : public TBaseVisitor {
    set<string> declared;

public:
    Any visitInitDeclarator(TParser::InitDeclaratorContext* ctx) override {
        string s = ctx->getText();
        string declarator = split(s, "=").at(0);
        declared.insert(declarator);
        return visitChildren(ctx);
    }

    Any visitAssignmentExpression(TParser::AssignmentExpressionContext* ctx) override {
        vector<string> vs = split(ctx->getText(), "=");
        if (vs.size() > 1) {
            string declarator = vs.at(0);
            if (declared.find(declarator) == declared.end())
            {
                cout << "error:" << declarator << " not declared" << endl;
            }
        }
        return visitChildren(ctx);
    }
};


int main(int argc, const char * argv[]) {

  ANTLRInputStream input("struct Head {int version; int msgType; int seq;};");
  TLexer lexer(&input);
  CommonTokenStream tokens(&lexer);

  TParser parser(&tokens);
  tree::ParseTree* tree = parser.compilationUnit();
  Visitor visitor;
  visitor.visit(tree);

  
  

  std::wstring s = antlrcpp::s2ws(tree->toStringTree(&parser)) + L"\n";

  OutputDebugString(s.data()); // Only works properly since VS 2015.
  //std::wcout << "Parse Tree: " << s << std::endl; Unicode output in the console is very limited.

  return 0;
}


