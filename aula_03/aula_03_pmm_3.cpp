// Aula 03 PAVIC Progrmação Paralela 2024

#include <iostream>
#include <fstream> // Ler e escrever imagens
#include <chrono>
#include <sstream>

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    // Header
    std::string type = "";
    std::string width = "";
    std::string height = "";
    std::string RGB = "";

    std::ifstream old_image; // Ler arquivo
    std::ofstream new_image; // Escrever arquivo

    old_image.open("Image_2.ppm");
    new_image.open("Image_3.ppm");

    // Copiar do arquivo antigo para a memória
    old_image >> type;
    old_image >> width;
    old_image >> height;
    old_image >> RGB;

    // Copiar da memória para o novo arquivo
    new_image << type << std::endl;
    new_image << width << " " << height << std::endl;
    new_image << RGB << std::endl;

    // copy from body old file(image) to memory
    std::string red = "";
    std::string green = "";
    std::string blue="";
    int intred = 0;
    int intgreen = 0;
    int intblue = 0;

    //Timer
    auto start_single_thread = std::chrono::high_resolution_clock::now();
    std::cout << "início do processo" << std::endl;

    // Ler cada pixel
    while (!old_image.eof()){

        old_image >> red;
        old_image >> green;
        old_image >> blue;

        /*
        Syntax:

        int stoi (string s, size_t* position = 0, int base = 10)
        Parameters:

        The string which has to be transformed is the first parameter.
        Location of an integer used to track how many characters were read. In that scenario, it is not used if this parameter is a null pointer.
        The third and last parameter is base. The sequence’s format determines the base used if this is 0. It uses base 10(decimal) if no argument is passed
       
        */

        // Converter string para números
        intred = std::stoi(red, nullptr);
        intgreen = std::stoi(green, nullptr);
        intblue = std::stoi(blue, nullptr);

        // Filtro azul
        intblue = intblue + 100;

        if (intblue > 249) {
            intblue = 255;
        }

        // Copiar pixels
        new_image << red << " " << green << " " << intblue << std::endl;

    }

    // Parar o timer
    auto stop_single_thread = std::chrono::high_resolution_clock::now();
    std::cout << "Processo finalizado" << std::endl;

    //Salvar tempo de execução
    auto duration_single_thread = std::chrono::duration_cast<std::chrono::milliseconds>(stop_single_thread - start_single_thread);

    //Mostrar tempo de execução
    std::cout << "Tempo de processamento: " << duration_single_thread.count() << " ms" << std::endl;

    new_image.close();
    old_image.close();

    return 0;
}