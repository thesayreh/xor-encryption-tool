#include <iostream>
#include <string>
#include <iomanip>

//������� ���������� � ������������ XOR
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

    std::cout << "������� ������(������ �� ����������): ";
    std::getline(std::cin, text);

    std::cout << "������� ����(������): ";
    std::cin >> key;

    std::string encrypted = xorEncryptDecrypt(text, key); 
    std::string decrypted = xorEncryptDecrypt(encrypted, key);

    std::cout << "����������� (hex): ";
    for (char c : encrypted) {
        std::cout << std::hex << std::uppercase << std::setw(2) << std::setfill('0') << (static_cast<int>(c) & 0xFF) << " "; //�������� �����, �� ����� ���������� ������ ������, ������ ��� �������� ��� ����
    }
    std::cout << std::endl;

    std::cout << "������������: " << decrypted << std::endl;

    return 0;
} 