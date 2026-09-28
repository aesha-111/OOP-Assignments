/*
Faculty of Computers and Artificial Intelligence, Cairo University (FCAI-CU)
Course: CS213 - Object Oriented Programming
Assignment 1 - Image Processing Application

Team Members & Contributions:

1. Rania Adel Kamal Ahmed - ID: 20250222 (Team Leader)
   - Tasks: Program Main Menu, Main Logic Structure, Filter 1 (Grayscale Conversion), Filter 5 (Flip Image)

2. Aesha Osama Abd-elHafeez Abd-elkareem - ID: 20251219
   - Tasks: Filter 4 (Frame Image), Filter 8 (Resize Image)

3. Marwa Sabry Makram Fahmy - ID: 20250808
   - Tasks: Program Main Menu, Main Logic Structure, Filter 3 (Invert Image Colors), Filter 7 (Darken and Lighten Image)

4. Habiba Ibrahim Metwaly Ibrahim - ID: 20250801
   - Tasks: Filter 2 (Black and White Filter), Filter 6 (Rotate Image)
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
    cout << "1. Load New Image\n";
    cout << "2. Grayscale Conversion\n";
    cout << "3. Black and White Filter\n";
    cout << "4. Invert Image Colors\n";
    cout << "5. Frame Image\n";                // تم إضافة كلمة Image
    cout << "6. Flip Image\n";
    cout << "7. Rotate Image\n";
    cout << "8. Darken and Lighten Image\n";
    cout << "9. Resize Image\n";
    cout << "10. Merge Images\n";
    cout << "11. Detect Image Edges\n";
    cout << "12. Crop Image\n";
    cout << "13. Blur Image\n";
    cout << "14. Natural Sunlight Filter\n";
    cout << "15. TV Effect / Noise Filter\n";
    cout << "16. Purple Tint / Wano Night Filter\n";
    cout << "17. Infrared Photography Filter\n";
    cout << "18. Save Current Image\n";
    cout << "19. Exit\n";
    cout << "Enter your choice (1-19): ";
}

void applyGrayscale(Image& img) {
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            int avg = (img(i, j, 0) + img(i, j, 1) + img(i, j, 2)) / 3;
            
            img(i, j, 0) = avg;
            img(i, j, 1) = avg;
            img(i, j, 2) = avg;
        }
    }
}
void applyBlackAndWhite(Image &img){
    for(int i=0;i<img.width;++i){
        for(int j=0;j<img.height;++j){
            int r=img.getPixel(i,j,0);
            int g=img.getPixel(i,j,1);
            int b=img.getPixel(i,j,2);
            int gray=(r+b+g)/3;
            int newValue=(gray>127)?255:0;
            img.setPixel(i,j,0,newValue);
            img.setPixel(i,j,1,newValue);
            img.setPixel(i,j,2,newValue);
        }
    }
}
void applyInvertImageColors(Image& img) {
    for (int y = 0; y < img.height; y++) {
        for (int x = 0; x < img.width; x++) {
            img.pixels[y][x].r = 255 - img.pixels[y][x].r;
            img.pixels[y][x].g = 255 - img.pixels[y][x].g;
            img.pixels[y][x].b = 255 - img.pixels[y][x].b;
        }
    }
}
void applyFlipBoth(Image& img) {
    Image flippedImg(img.width, img.height);
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            for (int c = 0; c < 3; ++c) {
                flippedImg(i, j, c) = img(img.width - 1 - i, img.height - 1 - j, c);
            }
        }
    }

    img = flippedImg;
}
void applyRotate90(Image&img,int angle){
if(angle==360||angle==0)return;
int times=(angle/90)%4;
for(int t=0;t<times;t++){
    Image rotated(img.height,img.width);
    for(int i=0;i<img.width;++i){
        for(int j=0;j<img.height;++j){
            for(int k=0;k<img.channels;++k){
                rotated(j,img.width-1-i,k)=img(i,j,k);
            }
        }
    }
    img=rotated;
}    
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
            while (!isValidExtension(filename)) {
                cout << "INVALID EXTENSION.  ENTER A VALID IMAGE NAME: ";
                cin >> filename;
            }
            img.loadNewImage(filename);
            cout << "IMAGE LOADED SUCCESSFULLY!" << endl;
        }
        else if (number == 2) {
            cout << "-> APPLYING GRAYSCALE FILTER...\n";
         applyGrayscale(img);
        }
        else if (number == 3) {
            cout << "-> APPLYING BLACK AND WHITE FILTER...\n";
         applyBlackAndWhite(img);
        }
        else if (number == 4) {
            cout << "-> APPLYING INVERT COLORS FILTER...\n";
         applyInvertImageColors(img);
        }
        else if (number == 5) {
            cout << "-> APPLYING fRAME IMAGES FILTER...\n";
        }
        else if (number == 6) {
            cout << "-> APPLYING FLIP IMAGE FILTER...\n";
            applyFlipBoth(img);
        }
        else if (number == 7) {
            cout << "-> APPLYING ROTATE IMAGE FILTER...\n";
            int angle;
            cout << "ENTER THE ANGLE TO ROTATE (IN DEGREES): ";
            cin >> angle;
            applyRotate90(img, angle);
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
            askToSaveImage(img);
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
