 /*
Faculty of Computers and Artificial Intelligence, Cairo University (FCAI-CU)
Course: CS213 - Object Oriented Programming
Assignment 1 - Image Processing Application

Team Members:
1. Rania Adel Kamal Ahmed - ID: 20250222 (Team Leader)
2. Aesha Osama Abd-elHafeez Abd-elkareem - ID: 20251219
3. Marwa Sabry Makram Fahmy - ID: 20250808
4. Habiba Ibrahim Metwaly Ibrahim - ID: 20250801
*/
#include <iostream>
#include <string>
#include "Image_Class.h"


using namespace std;

bool isValidExtension(const string& filename) {
    size_t dotPos = filename.find_last_of(".");
    if (dotPos != string::npos) {
        string ext = filename.substr(dotPos);
        return (ext == ".jpg" || ext == ".jpeg" || ext == ".png" || ext == ".bmp");
    }
    return false;
}

void loadImage(string& currentFilename, Image& currentImage, bool& isImageLoaded) {
    cout << "Enter image filename to load (.jpg, .png, .bmp): ";
    cin >> currentFilename;

    while (!isValidExtension(currentFilename)) {
        cout << "Invalid extension! Enter a valid image: ";
        cin >> currentFilename;
    }

    currentImage.loadNewImage(currentFilename);
    isImageLoaded = true;
    cout << "Image '" << currentFilename << "' loaded successfully!\n";
}

void showMenu() {
    cout << "\n--- Image Processing Menu ---\n";
    cout << "1.  Load New Image\n";
    cout << "2.  Grayscale Conversion\n";
    cout << "3.  Black and White Filter\n";
    cout << "4.  Invert Image Colors\n";
    cout << "5.  Merge Images\n";
    cout << "6.  Flip Image\n";
    cout << "7.  Rotate Image\n";
    cout << "8.  Darken and Lighten Image\n";
    cout << "9.  Resize Image\n";
    cout << "10. Detect Image Edges\n";
    cout << "11. Crop Image\n";
    cout << "12. Blur Image\n";
    cout << "13. Natural Sunlight Filter\n";
    cout << "14. TV Effect / Noise Filter\n";
    cout << "15. Purple Tint / Wano Night Filter\n";
    cout << "16. Infrared Photography Filter\n";
    cout << "17. Save Current Image\n";
    cout << "18. Exit\n";
    cout << "Enter your choice (1-18): ";
}





}




