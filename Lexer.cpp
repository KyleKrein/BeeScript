#include "Lexer.hpp"

namespace BeeScript
{
    std::vector<Token> Lexer::Tokenize()
    {
        std::vector<Token> tokens;
        while (m_Pos < m_Source.size()) {
            const char current = m_Source[m_Pos];

            if (std::isdigit(current)) {
                tokens.push_back(ReadNumber());
                continue;
            } else if (std::isalpha(current)) {
                tokens.push_back(ReadIdentifier());
                continue;
            } else if (current == ';') {
                tokens.push_back({TokenType::Semicolon, ";"});
            } else if (current == '(') {
                tokens.push_back({TokenType::LParen, "("});
            } else if (current == ')') {
                tokens.push_back({TokenType::RParen, ")"});
            } else if (current == '{') {
                tokens.push_back({TokenType::LBrace, "{"});
            } else if (current == '}') {
                tokens.push_back({TokenType::RBrace, "}"});
            } else if (current == '[') {
                tokens.push_back({TokenType::LSquare, "["});
            } else if (current == ']') {
                tokens.push_back({TokenType::RSquare, "]"});
            } else if(current == '-')
            {
                if(m_Pos + 1 < m_Source.size() && m_Source[m_Pos + 1] == '>') {
                    tokens.push_back({TokenType::Arrow, "->"});
                    m_Pos++;
                } else {
                    tokens.push_back({TokenType::Subtract, "-"});
                }
            } else if(current == '+') {
                tokens.push_back({TokenType::Add, "+"});
            } else if(current == '*') {
                tokens.push_back({TokenType::Multiply, "*"});
            } else if(current == '/') {
                tokens.push_back({TokenType::Divide, "/"});
            } else if(current == '=') {
                if(m_Pos + 1 < m_Source.size() && m_Source[m_Pos + 1] == '=') {
                    tokens.push_back({TokenType::Equal, "=="});
                    m_Pos++;
                } else {
                    tokens.push_back({TokenType::Assign, "="});
                }
            } else if(current == '!') {
                if(m_Pos + 1 < m_Source.size() && m_Source[m_Pos + 1] == '=') {
                    tokens.push_back({TokenType::NotEqual, "!="});
                    m_Pos++;
                } else {
                    tokens.push_back({TokenType::Not, "!"});
                }
            } else if(current == '<') {
                if(m_Pos + 1 < m_Source.size() && m_Source[m_Pos + 1] == '=') {
                    tokens.push_back({TokenType::LessEqual, "<="});
                    m_Pos++;
                } else {
                    tokens.push_back({TokenType::Less, "<"});
                }
            } else if(current == '>') {
                if(m_Pos + 1 < m_Source.size() && m_Source[m_Pos + 1] == '=') {
                    tokens.push_back({TokenType::GreaterEqual, ">="});
                    m_Pos++;
                } else {
                    tokens.push_back({TokenType::Greater, ">"});
                }
            } else if(current == '&') {
                tokens.push_back({TokenType::And, "&"});
            } else if(current == '|') {
                tokens.push_back({TokenType::Or, "|"});
            } else if(current == ':') {
                tokens.push_back({TokenType::Colon, ":"});
            }
            m_Pos++;
        }
        tokens.push_back({TokenType::EndOfFile, ""});
        return tokens;
    }

    Token Lexer::ReadNumber()
    {
        std::string number;
        while (m_Pos < m_Source.size() && std::isdigit(m_Source[m_Pos])) {
            number += m_Source[m_Pos++];
        }
        return {TokenType::Number, number};
    }

    Token Lexer::ReadIdentifier()
    {
        size_t start = m_Pos;
        while (m_Pos < m_Source.length() && std::isalnum(m_Source[m_Pos])) {
            m_Pos++;
        }
        std::string text = m_Source.substr(start, m_Pos - start);
        if (text == "void") {
            return {TokenType::Void, text};
        } else if (text == "int32") {
            return {TokenType::Int32, text};
        } else if (text == "int64") {
            return {TokenType::Int64, text};
        } else if (text == "float32") {
            return {TokenType::Float32, text};
        } else if (text == "float64") {
            return {TokenType::Float64, text};
        } else if (text == "byte") {
            return {TokenType::Byte, text};
        } else if (text == "bool") {
            return {TokenType::Bool, text};
        } else if (text == "true") {
            return {TokenType::True, text};
        } else if (text == "false") {
            return {TokenType::False, text};
        } else if (text == "char32" || text == "char") {
            return {TokenType::Char32, text};
        } else if (text == "return") {
            return {TokenType::Return, text};
        }

        return {TokenType::Identifier, text};
    }
}