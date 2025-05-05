#include <iostream>
#include <string>
#include <iomanip>

// XOR encryption/decryption function
std::string xorEncryptDecrypt(const std::string& input, char key) {
    std::string output = input;
    for (size_t i = 0; i < input.size(); i++) {
        output[i] = input[i] ^ key;
    }
    return output;
}

int main() {
    std::string text;
    char key;

    std::cout << "Enter a string (English only): ";
    std::getline(std::cin, text);

    std::cout << "Enter a key (one character): ";
    std::cin >> key;

    std::string encrypted = xorEncryptDecrypt(text, key);
    std::string decrypted = xorEncryptDecrypt(encrypted, key);

    std::cout << "Encrypted (hex): ";
    for (char c : encrypted) {
        std::cout << std::hex << std::uppercase << std::setw(2)
                  << std::setfill('0') << (static_cast<int>(c) & 0xFF) << " ";
    }
    std::cout << std::endl;

    std::cout << "Decrypted: " << decrypted << std::endl;

    return 0;
}
