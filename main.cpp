#include <iostream>
#include <filesystem>
#include <windows.h>

using namespace std;
namespace fs = std::filesystem;

int main() {
    // Obtener la ruta de la carpeta del usuario
    string folderPath;
    cout << "Ingrese la ruta de la carpeta: ";
    getline(cin, folderPath);

    try {
        // Iterar sobre los archivos en la carpeta
        for (const auto& file : fs::directory_iterator(folderPath)) {
            // Mostrar el nombre del archivo
            cout << file.path().filename() << endl;
        }
    }
    catch (const fs::filesystem_error& ex) {
        cout << "Error: " << ex.what() << endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
