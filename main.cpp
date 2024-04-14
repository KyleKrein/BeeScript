#include <iostream>
#include "Lexer.hpp"

int main(int argc, char *argv[])
{
    std::string source = "main: () -> int32 { x: int32 = 10; y: int32 = 20; z: int32 = x + y; return z; }";
    BeeScript::Lexer lexer(source);
    auto tokens = lexer.Tokenize();
    for (const auto& token : tokens) {
        std::cout << "Type: " << TokenTypeToString(token.Type) << ", Value: " << token.Value << '\n';
    }    
}