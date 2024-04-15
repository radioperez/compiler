#include <iostream>
#include <fstream>
#include <string>

class Lexer {
private:
    bool is_space(char c) {
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
    bool is_number(char c) {
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
    bool is_word(char c) {
        return false;
    }
    void number() {
        std::cout << get();
    }
    void word() {
        get();
    }
    void operation() {
        get();
    };
    void analyse() {
        while (peek() != '\0') {
            if (is_space(peek())) get();
            else if (is_number(peek())) number();
            else if (is_word(peek())) word();
            else get();
        }
    }
public:
    Lexer(const char* beg) : m_begin{beg} {
        while (peek() != '\0') {
            if (is_number(peek())) std::cout << get();
            else get();
        }
    }
    const char* m_begin = nullptr;
    char peek() { return *m_begin; }
    char get() { return *m_begin++; }
};

int main(){
    // Чтение кода из файла, чтобы во время тестирования не нужно было перекомпилировать
    std::string instring;
    std::fstream infile;
    infile.open("input.txt");
    if (infile.is_open()) {
        for (std::string line; getline(infile, line);) {
            instring += line;
        }
        infile.close();
    }

    Lexer lex(&instring[0]);
    return 0;
    /*
    if (infile.is_open()) {
        while (infile.read(ch,1)) {

            if (*ch < 'z' || *ch > 'a') {
                // функция чтения слова
                // seekg
                std::cout << ch;
            } 
            else if (*ch < '0' || *ch > '9') {
                // функция чтения числа
                // seekg 
            }
            else if ("<>:!") {
                // функция чтения особых знаков
            }
            else if (Все односимвольные) {
                //обработка односимвольных
            }
            else if (" " || "\n") {
                infile.seekg(1);
            }
            else {
                //Ошибка в чтении символа
            }
        }
    }
    return 0;
    */
}