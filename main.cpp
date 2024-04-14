#include <iostream>
#include <fstream>
#include <string>

int main(){
    char *ch = new char[1];
    std::fstream infile;
    infile.open("input.txt");
    if (infile.is_open()) {
        while (infile.read(ch,1)) {

            /*
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
            */
        }
    }
    return 0;
}