// Aula 02 PAVIC Progrmação Paralela 2024
/*
PMM
Header
P3 // Format ASCII
250 250 // Image Size
255 // RGB Max
.
.
.
user >> PC = Image.ppm
.
.
.
User << PC

*/
#include <iostream>
#include <fstream> // Ler e escrever imagens

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    std::ofstream image;
    image.open("Image.ppm");
    // Image PPM Header
    image << "P3" << std::endl;
    image << "3 2" << std::endl;
    image << "255" << std::endl;
    image << "255 0 0" << std::endl;
    image << "0 255 0" << std::endl;
    image << "0 0 255" << std::endl;
    image << "255 255 255" << std::endl;
    image << "0 0 0" << std::endl;

    image.close();

    return 0;
}