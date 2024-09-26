// Aula 03 PAVIC Progrmação Paralela 2024

#include <iostream>
#include <fstream> // Ler e escrever imagens
#include <chrono>

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    std::ofstream image;
    image.open("Image_2.ppm");
    // Image PPM Header
    image << "P3" << std::endl;
    image << "250 250" << std::endl;
    image << "255" << std::endl;

    //Image PPM Body
    auto start_single_thread = std::chrono::high_resolution_clock::now();
    for (int y = 0; y < 250; y++) {
        for (int x = 0; x < 250; x++) {
            // Pixel RGB (0->> 255) 8 bits
            // image << "R" << " " << "G" << " " << "B" << std::endl;
            image << x << " " << 0 << " " << y << std::endl;
            
        }
    }
    auto stop_single_thread = std::chrono::high_resolution_clock::now();

    //Cronometra o tempo de execução
    auto duration_single_thread = std::chrono::duration_cast<std::chrono::milliseconds>(stop_single_thread - start_single_thread);

    //Mostrar tempo de execução
    std::cout << "Single Threaded image processing time: " << duration_single_thread.count() << " ms" << std::endl;

    image.close();

    return 0;
}