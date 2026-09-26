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
void saveImage(Image& img) {
    cout << "ENTER THE NAME OF THE IMAGE TO SAVE (example: output.jpg): ";
    string outName;
    cin >> outName;
    while (!isValidExtension(outName)) {
        cout << "INVALID EXTENSION. ENTER A VALID IMAGE NAME: ";
        cin >> outName;
    }
    img.saveImage(outName);
    cout << "IMAGE SAVED AS " << outName << endl;
}

void askToSaveImage(Image& img) {
    char choice;
    cout << "DO YOU WANT TO SAVE THE IMAGE? (Y/N): ";
    cin >> choice;
    if (choice == 'Y' || choice == 'y') {
        saveImage(img);
    } else {
        cout << "IMAGE NOT SAVED.\n";
    }
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
int main() {
    Image img;
    int number = 0; 
    while (number != 18) {
        showMenu();
        cin >> number;
        if (number == 1) {
            string filename;
            cout << "ENTER THE IMAGE FILE NAME : ";
            cin >> filename;
            while (!isvalidExtension(filename)) {
                cout << "INVALID EXTENSION.  ENTER A VALID IMAGE NAME: ";
                cin >> filename;
            }
            img.loadRaw(filename);
            cout << "IMAGE LOADED SUCCESSFULLY!" << endl;
        }
        else if (number == 2) {
            cout << "-> APPLYING GRAYSCALE FILTER...\n";
        }
        else if (number == 3) {
            cout << "-> APPLYING BLACK AND WHITE FILTER...\n";
        }
        else if (number == 4) {
            cout << "-> APPLYING INVERT COLORS FILTER...\n";
        }
        else if (number == 5) {
            cout << "-> APPLYING MERGE IMAGES FILTER...\n";
        }
        else if (number == 6) {
            cout << "-> APPLYING FLIP IMAGE FILTER...\n";
        }
        else if (number == 7) {
            cout << "-> APPLYING ROTATE IMAGE FILTER...\n";
        }
        else if (number == 8) {
            cout << "-> APPLYING DARKEN/LIGHTEN FILTER...\n";
        }
        else if (number == 9) {
            cout << "-> APPLYING RESIZE FILTER...\n";
        }
        else if (number == 10) {
            cout << "-> APPLYING DETECT EDGES FILTER...\n";
        }
        else if (number == 11) {
            cout << "-> APPLYING CROP IMAGE FILTER...\n";
        }
        else if (number == 12) {
            cout << "-> APPLYING BLUR IMAGE FILTER...\n";
        }
        else if (number == 13) {
            cout << "-> APPLYING NATURAL SUNLIGHT FILTER...\n";
        }
        else if (number == 14) {
            cout << "-> APPLYING TV EFFECT / NOISE FILTER...\n";
        }
        else if (number == 15) {
            cout << "-> APPLYING PURPLE TINT / WANO NIGHT FILTER...\n";
        }
        else if (number == 16) {
            cout << "-> APPLYING INFRARED PHOTOGRAPHY FILTER...\n";
        }
        else if (number == 17) {
            AsktosaveImage(img);
        }
        else if (number == 18) {
            cout << "THANK YOU FOR USING THE PROGRAM. GOODBYE!\n";
            break;
        }
        else {
            cout << "INVALID CHOICE. PLEASE ENTER A NUMBER BETWEEN 1 AND 18.\n";
        }
    }
    return 0;
}










