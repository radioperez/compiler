#include <iostream>
#include <fstream>
#include <string>

class Lexer {
private:
    void number();
    void word();
    void operation();
    bool is_space(char c) {
        switch (c) {
            case ' ':
            case '\n':
            case '\r':
                return true;
            default:
                return false;
        }
    }
public:
    Lexer(const char* beg) : m_begin{beg} {
        while (peek() != '\0') std::cout << get();
        std::cout << *m_begin << std::endl;
    }
    const char* m_begin = nullptr;
    char peek() { return *m_begin; }
    char get() { return *m_begin++; }
};

int main(){
    // Чтение кода из файла, чтобы во время тестирования не нужно было перекомпилировать
    std::string instring, line;
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