#pragma once
#include <string>
#include <vector>
namespace BeeScript
{
    enum class TokenType
    {
        Identifier,
        Int32,
        Int64,
        Float32,
        Float64,
        Void,
        Byte,
        Bool,
        True,
        False,
        Char32,
        Return,
        Assign, // =
        Multiply, // *
        Divide, // /
        Add, // +
        Subtract, // -
        Equal, // ==
        NotEqual, // !=
        Less, // <
        LessEqual, // <=
        Greater, // >
        GreaterEqual, // >=
        And, // and
        Or, // or
        Not, // not
        Colon, // :
        Arrow, // ->
        Number,
        String,
        Operator,
        Keyword,
        LParen, // (
        RParen, // )
        LSquare, // [
        RSquare, // ]
        LBrace, // {
        RBrace, // }
        Semicolon,
        EndOfFile
    };
    inline auto TokenTypeToString(TokenType type) -> const char*
    {
        switch (type)
        {
            case TokenType::Identifier: return "Identifier";
            case TokenType::Int32: return "Int32";
            case TokenType::Int64: return "Int64";
            case TokenType::Float32: return "Float32";
            case TokenType::Float64: return "Float64";
            case TokenType::Void: return "Void";
            case TokenType::Byte: return "Byte";
            case TokenType::Bool: return "Bool";
            case TokenType::True: return "True";
            case TokenType::False: return "False";
            case TokenType::Char32: return "Char32";
            case TokenType::Return: return "Return";
            case TokenType::Assign: return "Assign";
            case TokenType::Multiply: return "Multiply";
            case TokenType::Divide: return "Divide";
            case TokenType::Add: return "Add";
            case TokenType::Subtract: return "Subtract";
            case TokenType::Equal: return "Equal";
            case TokenType::NotEqual: return "NotEqual";
            case TokenType::Less: return "Less";
            case TokenType::LessEqual: return "LessEqual";
            case TokenType::Greater: return "Greater";
            case TokenType::GreaterEqual: return "GreaterEqual";
            case TokenType::And: return "And";
            case TokenType::Or: return "Or";
            case TokenType::Not: return "Not";
            case TokenType::Colon: return "Colon";
            case TokenType::Arrow: return "Arrow";
            case TokenType::Number: return "Number";
            case TokenType::String: return "String";
            case TokenType::Operator: return "Operator";
            case TokenType::Keyword: return "Keyword";
            case TokenType::LParen: return "LParen";
            case TokenType::RParen: return "RParen";
            case TokenType::LSquare: return "LSquare";
            case TokenType::RSquare: return "RSquare";
            case TokenType::LBrace: return "LBrace";
            case TokenType::RBrace: return "RBrace";
            case TokenType::Semicolon: return "Semicolon";
            case TokenType::EndOfFile: return "EndOfFile";
        }
        return "Unknown";
    }
    struct Token
    {
        TokenType Type;
        std::string Value;
    };

    class Lexer
    {
        public:
        explicit Lexer(const std::string& source) : m_Source(source), m_Pos(0) {}
        std::vector<Token> Tokenize();

        private:
        Token ReadNumber();

        Token ReadIdentifier();

        private:
        std::string m_Source;
        size_t m_Pos;
    };
}