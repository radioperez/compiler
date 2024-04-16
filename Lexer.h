#include <string>
#include <iostream>

class Lexer {
private:
    bool is_space(char c);
    bool is_number(char c);
    bool is_letter(char c);
    bool is_operation(char c);

    void number();
    float fraction();
    void word();
    void operation();
    void comment();
    void analyse();
public:
    Lexer(const char* beg) : m_begin{beg} {
        analyse();
    }
    const char* m_begin = nullptr;
    char peek() { return *m_begin; }
    char get() { return *m_begin++; }
};

inline bool Lexer::is_space(char c) {
    switch (c) {
        case ' ':
        case '\n':
        case '\r':
        case '\t':
            return true;
        default:
            return false;
    }
}
inline bool Lexer::is_number(char c) {
    switch (c) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return true;
        default:
            return false;
    }
}
inline bool Lexer::is_letter(char c) {
    switch (c) {
        case 'a':
        case 'b':
        case 'c':
        case 'd':
        case 'e':
        case 'f':
        case 'g':
        case 'h':
        case 'i':
        case 'j':
        case 'k':
        case 'l':
        case 'm':
        case 'n':
        case 'o':
        case 'p':
        case 'q':
        case 'r':
        case 's':
        case 't':
        case 'u':
        case 'v':
        case 'w':
        case 'x':
        case 'y':
        case 'z':
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case 'E':
        case 'F':
        case 'G':
        case 'H':
        case 'I':
        case 'J':
        case 'K':
        case 'L':
        case 'M':
        case 'N':
            return true;
        default:
            return false;
    }
}
inline bool Lexer::is_operation(char c) {
    switch (c) {
        case ':':
        case '=':
        case '+':
        case '-':
        case '*':
        case '/':
        case '(':
        case ')':
        case '[':
        case ']':
        case '{':
        case '}':
        case '!':
        case '<':
        case '>':
            return true;
        default:
            return false;
    }
}
inline void Lexer::number() {
    int number = 0;
    while (is_number(peek())) {
        number *= 10;
        number += get() - '0';
    }
    if (peek() == '.') {
        get();
        float frac = fraction() + number;
        std::cout << "Got fractial number: " << frac << std::endl;
        return;
    }
    std::cout << "Got number: " << number << std::endl;
}
inline float Lexer::fraction() {
    float fraction = 0;
    float power = 1;
    while (is_number(peek())) {
        power /= 10;
        fraction += (get() - '0')*power;
    }
    return fraction;
}
inline void Lexer::word() {
    std::string word = "";
    while (is_letter(peek()) || is_number(peek()) || peek() == '_') {
        word += get();
    }
    std::cout << "Got word: " << word << std::endl;
}
inline void Lexer::operation() {
    std::cout << "Got operation" << std::endl;
    get();
};
inline void Lexer::comment() {
    get();
    std::string comment = "";
    while (peek() != '?') {
        comment += get();
    }
    std::cout << "Got comment: " << comment << std::endl;
    get();
}
inline void Lexer::analyse() {
    while (peek() != '\0') {
        if (is_space(peek())) get();
        else if (is_number(peek())) number();
        else if (is_letter(peek())) word();
        else if (is_operation(peek())) operation();
        else if (peek() == '?') comment();
        else get();
    }
}