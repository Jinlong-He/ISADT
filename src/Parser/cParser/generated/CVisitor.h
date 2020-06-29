
// Generated from C.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "CParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by CParser.
 */
class  CVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by CParser.
   */
    virtual antlrcpp::Any visitPrimaryExpression(CParser::PrimaryExpressionContext *context) = 0;

    virtual antlrcpp::Any visitGenericSelection(CParser::GenericSelectionContext *context) = 0;

    virtual antlrcpp::Any visitGenericAssocList(CParser::GenericAssocListContext *context) = 0;

    virtual antlrcpp::Any visitGenericAssociation(CParser::GenericAssociationContext *context) = 0;

    virtual antlrcpp::Any visitPostfixExpression(CParser::PostfixExpressionContext *context) = 0;

    virtual antlrcpp::Any visitArgumentExpressionList(CParser::ArgumentExpressionListContext *context) = 0;

    virtual antlrcpp::Any visitUnaryExpression(CParser::UnaryExpressionContext *context) = 0;

    virtual antlrcpp::Any visitUnaryOperator(CParser::UnaryOperatorContext *context) = 0;

    virtual antlrcpp::Any visitCastExpression(CParser::CastExpressionContext *context) = 0;

    virtual antlrcpp::Any visitMultiplicativeExpression(CParser::MultiplicativeExpressionContext *context) = 0;

    virtual antlrcpp::Any visitAdditiveExpression(CParser::AdditiveExpressionContext *context) = 0;

    virtual antlrcpp::Any visitShiftExpression(CParser::ShiftExpressionContext *context) = 0;

    virtual antlrcpp::Any visitRelationalExpression(CParser::RelationalExpressionContext *context) = 0;

    virtual antlrcpp::Any visitEqualityExpression(CParser::EqualityExpressionContext *context) = 0;

    virtual antlrcpp::Any visitAndExpression(CParser::AndExpressionContext *context) = 0;

    virtual antlrcpp::Any visitExclusiveOrExpression(CParser::ExclusiveOrExpressionContext *context) = 0;

    virtual antlrcpp::Any visitInclusiveOrExpression(CParser::InclusiveOrExpressionContext *context) = 0;

    virtual antlrcpp::Any visitLogicalAndExpression(CParser::LogicalAndExpressionContext *context) = 0;

    virtual antlrcpp::Any visitLogicalOrExpression(CParser::LogicalOrExpressionContext *context) = 0;

    virtual antlrcpp::Any visitConditionalExpression(CParser::ConditionalExpressionContext *context) = 0;

    virtual antlrcpp::Any visitAssignmentExpression(CParser::AssignmentExpressionContext *context) = 0;

    virtual antlrcpp::Any visitAssignmentOperator(CParser::AssignmentOperatorContext *context) = 0;

    virtual antlrcpp::Any visitExpression(CParser::ExpressionContext *context) = 0;

    virtual antlrcpp::Any visitConstantExpression(CParser::ConstantExpressionContext *context) = 0;

    virtual antlrcpp::Any visitDeclaration(CParser::DeclarationContext *context) = 0;

    virtual antlrcpp::Any visitDeclarationSpecifiers(CParser::DeclarationSpecifiersContext *context) = 0;

    virtual antlrcpp::Any visitDeclarationSpecifiers2(CParser::DeclarationSpecifiers2Context *context) = 0;

    virtual antlrcpp::Any visitDeclarationSpecifier(CParser::DeclarationSpecifierContext *context) = 0;

    virtual antlrcpp::Any visitInitDeclaratorList(CParser::InitDeclaratorListContext *context) = 0;

    virtual antlrcpp::Any visitInitDeclarator(CParser::InitDeclaratorContext *context) = 0;

    virtual antlrcpp::Any visitStorageClassSpecifier(CParser::StorageClassSpecifierContext *context) = 0;

    virtual antlrcpp::Any visitTypeSpecifier(CParser::TypeSpecifierContext *context) = 0;

    virtual antlrcpp::Any visitStructOrUnionSpecifier(CParser::StructOrUnionSpecifierContext *context) = 0;

    virtual antlrcpp::Any visitStructOrUnion(CParser::StructOrUnionContext *context) = 0;

    virtual antlrcpp::Any visitStructDeclarationList(CParser::StructDeclarationListContext *context) = 0;

    virtual antlrcpp::Any visitStructDeclaration(CParser::StructDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitSpecifierQualifierList(CParser::SpecifierQualifierListContext *context) = 0;

    virtual antlrcpp::Any visitStructDeclaratorList(CParser::StructDeclaratorListContext *context) = 0;

    virtual antlrcpp::Any visitStructDeclarator(CParser::StructDeclaratorContext *context) = 0;

    virtual antlrcpp::Any visitEnumSpecifier(CParser::EnumSpecifierContext *context) = 0;

    virtual antlrcpp::Any visitEnumeratorList(CParser::EnumeratorListContext *context) = 0;

    virtual antlrcpp::Any visitEnumerator(CParser::EnumeratorContext *context) = 0;

    virtual antlrcpp::Any visitEnumerationConstant(CParser::EnumerationConstantContext *context) = 0;

    virtual antlrcpp::Any visitAtomicTypeSpecifier(CParser::AtomicTypeSpecifierContext *context) = 0;

    virtual antlrcpp::Any visitTypeQualifier(CParser::TypeQualifierContext *context) = 0;

    virtual antlrcpp::Any visitFunctionSpecifier(CParser::FunctionSpecifierContext *context) = 0;

    virtual antlrcpp::Any visitAlignmentSpecifier(CParser::AlignmentSpecifierContext *context) = 0;

    virtual antlrcpp::Any visitDeclarator(CParser::DeclaratorContext *context) = 0;

    virtual antlrcpp::Any visitDirectDeclarator(CParser::DirectDeclaratorContext *context) = 0;

    virtual antlrcpp::Any visitGccDeclaratorExtension(CParser::GccDeclaratorExtensionContext *context) = 0;

    virtual antlrcpp::Any visitGccAttributeSpecifier(CParser::GccAttributeSpecifierContext *context) = 0;

    virtual antlrcpp::Any visitGccAttributeList(CParser::GccAttributeListContext *context) = 0;

    virtual antlrcpp::Any visitGccAttribute(CParser::GccAttributeContext *context) = 0;

    virtual antlrcpp::Any visitNestedParenthesesBlock(CParser::NestedParenthesesBlockContext *context) = 0;

    virtual antlrcpp::Any visitPointer(CParser::PointerContext *context) = 0;

    virtual antlrcpp::Any visitTypeQualifierList(CParser::TypeQualifierListContext *context) = 0;

    virtual antlrcpp::Any visitParameterTypeList(CParser::ParameterTypeListContext *context) = 0;

    virtual antlrcpp::Any visitParameterList(CParser::ParameterListContext *context) = 0;

    virtual antlrcpp::Any visitParameterDeclaration(CParser::ParameterDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitIdentifierList(CParser::IdentifierListContext *context) = 0;

    virtual antlrcpp::Any visitTypeName(CParser::TypeNameContext *context) = 0;

    virtual antlrcpp::Any visitAbstractDeclarator(CParser::AbstractDeclaratorContext *context) = 0;

    virtual antlrcpp::Any visitDirectAbstractDeclarator(CParser::DirectAbstractDeclaratorContext *context) = 0;

    virtual antlrcpp::Any visitTypedefName(CParser::TypedefNameContext *context) = 0;

    virtual antlrcpp::Any visitInitializer(CParser::InitializerContext *context) = 0;

    virtual antlrcpp::Any visitInitializerList(CParser::InitializerListContext *context) = 0;

    virtual antlrcpp::Any visitDesignation(CParser::DesignationContext *context) = 0;

    virtual antlrcpp::Any visitDesignatorList(CParser::DesignatorListContext *context) = 0;

    virtual antlrcpp::Any visitDesignator(CParser::DesignatorContext *context) = 0;

    virtual antlrcpp::Any visitStaticAssertDeclaration(CParser::StaticAssertDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitStatement(CParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitLabeledStatement(CParser::LabeledStatementContext *context) = 0;

    virtual antlrcpp::Any visitCompoundStatement(CParser::CompoundStatementContext *context) = 0;

    virtual antlrcpp::Any visitBlockItemList(CParser::BlockItemListContext *context) = 0;

    virtual antlrcpp::Any visitBlockItem(CParser::BlockItemContext *context) = 0;

    virtual antlrcpp::Any visitExpressionStatement(CParser::ExpressionStatementContext *context) = 0;

    virtual antlrcpp::Any visitSelectionStatement(CParser::SelectionStatementContext *context) = 0;

    virtual antlrcpp::Any visitIterationStatement(CParser::IterationStatementContext *context) = 0;

    virtual antlrcpp::Any visitForCondition(CParser::ForConditionContext *context) = 0;

    virtual antlrcpp::Any visitForDeclaration(CParser::ForDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitForExpression(CParser::ForExpressionContext *context) = 0;

    virtual antlrcpp::Any visitJumpStatement(CParser::JumpStatementContext *context) = 0;

    virtual antlrcpp::Any visitCompilationUnit(CParser::CompilationUnitContext *context) = 0;

    virtual antlrcpp::Any visitTranslationUnit(CParser::TranslationUnitContext *context) = 0;

    virtual antlrcpp::Any visitExternalDeclaration(CParser::ExternalDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitFunctionDefinition(CParser::FunctionDefinitionContext *context) = 0;

    virtual antlrcpp::Any visitDeclarationList(CParser::DeclarationListContext *context) = 0;


};

