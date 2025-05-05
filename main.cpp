#include <iostream>
#include <string>
#include <iomanip>

//Функция шифрования и дешифрования XOR
std::string xorEncryptDecrypt(const std::string& input, char key) {
	std::string output = input;
	for (size_t i = 0; i < input.size(); i++) {
		output[i] = input[i] ^ key;
	}
	return output;
}
int main() { 
    setlocale(LC_ALL, "RU"); 
    std::string text;
    char key;

    std::cout << "Введите строку(только на английском): ";
    std::getline(std::cin, text);

    std::cout << "Введите ключ(символ): ";
    std::cin >> key;

    std::string encrypted = xorEncryptDecrypt(text, key); 
    std::string decrypted = xorEncryptDecrypt(encrypted, key);

    std::cout << "Зашифровано (hex): ";
    for (char c : encrypted) {
        std::cout << std::hex << std::uppercase << std::setw(2) << std::setfill('0') << (static_cast<int>(c) & 0xFF) << " "; //Пофиксил вывод, до этого выводилась пустая строка, сейчас все работает как надо
    }
    std::cout << std::endl;

    std::cout << "Расшифровано: " << decrypted << std::endl;

    return 0;
} 