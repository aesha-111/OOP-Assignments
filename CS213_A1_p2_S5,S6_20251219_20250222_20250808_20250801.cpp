/*
Faculty of Computers and Artificial Intelligence, Cairo University (FCAI-CU)
Course: CS213 - Object Oriented Programming
Assignment 1 - Image Processing Application
Section: S5,6
Team Members & Contributions:

1. Rania Adel Kamal Ahmed - ID: 20250222 (Team Leader)
   - Tasks: Program Main Menu, Main Logic Structure, Filter 1 (Grayscale Conversion), Filter 5 (Flip Image),Filter 9 (Merge Images), Filter 13 (Sunlight Filter)

2. Aesha Osama Abd-elHafeez Abd-elkareem - ID: 20251219
   - Tasks: Filter 4 (Frame Image), Filter 8 (Resize Image),Filter 12(Blur Image),Filter 16(Infrared Image)

3. Marwa Sabry Makram Fahmy - ID: 20250808
   - Tasks: Program Main Menu, Main Logic Structure, Filter 3 (Invert Image Colors), Filter 7 (Darken and Lighten Image),Filter 11 (Crop Images) ,Filter 12 (Purple filter)

4. Habiba Ibrahim Metwaly Ibrahim - ID: 20250801
   - Tasks: Filter 2 (Black and White Filter), Filter 6 (Rotate Image), Filter 10 (Detect Image Edges), Filter 14 (TV Effect)
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
    cout << "5. Frame Image\n";                
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
void applyInvertColors(Image& img) {
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            for (int c = 0; c < 3; ++c) {
                img(i, j, c) = 255 - img(i, j, c);
            }
        }
    }
}
void applyBorderFilter(Image &img) {
 int borderSize=20;
 for (int y =0 ;y < img.height ; ++y){
    for (int x =0 ; x<img.width; ++x){
        if(x<borderSize || x>=img.width-borderSize||
            y<borderSize || y>=img.height-borderSize){
                img.setPixel(x,y,0,255);
                img.setPixel(x,y,1,255);
                img.setPixel(x,y,2,255);
       }
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
void applyDarkenandLighten(Image& img, float factor) {
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            for (int c = 0; c < 3; ++c) {
                int newValue =img(i, j, c) * factor;
                if (newValue > 255) newValue = 255;
                if (newValue < 0) newValue = 0;
                img(i, j, c) = newValue;
            }
        }
    }
}

void resizeImage(Image& img) {
    int newWidth, newHeight;
    cout << "Enter new width and new height: ";
    cin >> newWidth >> newHeight;

    Image resizedImage(newWidth, newHeight);

    float scalex = (float)img.width / newWidth;
    float scaley = (float)img.height / newHeight;

    for (int y2 = 0; y2 < newHeight; y2++) {
        for (int x2 = 0; x2 < newWidth; x2++) {
            
            int x1 = (int)(x2 * scalex);
            int y1 = (int)(y2 * scaley);

            for (int c = 0; c < 3; c++) {
                resizedImage.setPixel(x2, y2, c, img.getPixel(x1, y1, c));
            }
        }
    }

    img = resizedImage;
}
void mergeImages(Image img1, Image img2, Image& result) {
    int w, h, choice = 1;
    
    if (img1.width != img2.width || img1.height != img2.height) {
        cout << "1. Max Size (Resize)\n2. Min Size (Crop)\nChoice: ";
        cin >> choice;
    }

    if (choice == 1) {
        w = max(img1.width, img2.width);
        h = max(img1.height, img2.height);
    } else {
        w = min(img1.width, img2.width);
        h = min(img1.height, img2.height);
    }

    result = Image(w, h);

    for (int x = 0; x < w; ++x) {
        for (int y = 0; y < h; ++y) {
            for (int c = 0; c < 3; ++c) {
                int p1 = img1(x * img1.width / w, y * img1.height / h, c);
                int p2 = img2(x * img2.width / w, y * img2.height / h, c);
                result(x, y, c) = (p1 + p2) / 2;
            }
        }
    }
}
void detectEdges (Image&img){
    for(int i=0;i<img.height-1;i++){
        for(int j=0;j<img.width-1;j++){
            if(img.getPixel(i,j,0)!=img.getPixel(i,j+1,0)){
                img.setPixel(i,j,0,0);
                img.setPixel(i,j,1,0);
                img.setPixel(i,j,2,0);
            }else{
                img.setPixel(i,j,0,225);
                img.setPixel(i,j,1,225);
                img.setPixel(i,j,2,225);
            }
        }
    }
void applyCrop(Image& img, int x, int y, int width, int height) {
    Image cropped(width, height);
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            for (int c = 0; c < 3; ++c) {
                cropped(i, j, c) = img(x + i, y + j, c);
            }
        }
    }
    img = cropped;
}
void applyBlurFilter(Image& image)
{
    int width = image.width;
    int height = image.height;
    Image blurredImage(width, height);
    int boxSize = 15;
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            int sumR = 0, sumG = 0, sumB = 0;
            int count = 0;

            for (int dy = -boxSize / 2; dy <= boxSize / 2; ++dy)
            {
                for (int dx = -boxSize / 2; dx <= boxSize / 2; ++dx)
                {
                    int newY = y + dy;
                    int newX = x + dx;

                    if (newY >= 0 && newY < height && newX >= 0 && newX < width)
                    {
                        sumR +=image(newX, newY, 0);
                        sumG += image(newX, newY, 1);
                        sumB += image(newX, newY, 2);
                        count++;
                    }
                }
            }

            blurredImage(x, y, 0) = sumR / count;
            blurredImage(x, y, 1) = sumG / count;   
            blurredImage(x, y, 2) = sumB / count;

        }
    }
    image = blurredImage;
}
void filter13_sunlight(Image img, Image& result) {
    result = Image(img.width, img.height);

    for (int x = 0; x < img.width; ++x) {
        for (int y = 0; y < img.height; ++y) {
            int r = img(x, y, 0) + 40;
            int g = img(x, y, 1) + 30;
            int b = img(x, y, 2) + 10;

            result(x, y, 0) = min(255, r);
            result(x, y, 1) = min(255, g);
            result(x, y, 2) = min(255, b);
        }
    }
}
void applyTVFX(Image&img){
    for(int i=0;i<img.width;++i){
        if(i%2==0){
            for(int j=0;j<img.height;j++){
                for(int k=0;k<3;k++){
                    img.setPixel(j,i,k,img.getPixel(j,i,k)*0.5);
                }
            }
        }
    }
 }
void applyPurpleTint(Image& img) {
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            int r = img(i, j, 0);
            int g = img(i, j, 1);
            int b = img(i, j, 2);
            r = std::min(255, r + 40); 
            b = std::min(255, b + 60); 
            g= std::max(0, g - 20);
            img(i, j, 0) = r;
            img(i, j, 1) = g;
            img(i, j, 2) = b;
        }
    }
}
void applyInfrared(Image& img) {
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            int r = img(i, j, 0);
            int g = img(i, j, 1);
            int b = img(i, j, 2);

             img(i, j, 0) = 255;
             img(i, j, 1) = 255-g;
             img(i, j, 2) = 255 -b; 
        }
    }
}
int main() {
    Image img;
    int number = 0;
    cout <<"Step 1 :Enter 1 to load image or 19 to exit the program\n";
    while (number != 19) {
        showMenu();
        cout << "Enter your choice:(1-19) ";
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
            cout<<"Step 2 : Enter a filter number (2-18) or 19 to exit: \n";
        }
        else if (number == 2) {
            cout << "-> APPLYING GRAYSCALE FILTER...\n";
         applyGrayscale(img);
         cout<<"Next step : enter 18 to save the image or 19 to exit the program\n";
        }
        else if (number == 3) {
            cout << "-> APPLYING BLACK AND WHITE FILTER...\n";
         applyBlackAndWhite(img);
         cout<<"Next step : enter 18 to save the image or 19 to exit the program\n";  
        }
        else if (number == 4) {
            cout << "-> APPLYING INVERT COLORS FILTER...\n";
         applyInvertColors(img);
         cout<<"Next step : enter 18 to save the image or 19 to exit the program\n";  
        }
        else if (number == 5) {
            cout << "-> APPLYING fRAME IMAGES FILTER...\n";
           applyBorderFilter(img);
          cout<<"Next step : enter 18 to save the image or 19 to exit the program\n";
        }
        else if (number == 6) {
            cout << "-> APPLYING FLIP IMAGE FILTER...\n";
            applyFlipBoth(img);
           cout<<"Next step : enter 18 to save the image or 19 to exit the program\n";
        }
        else if (number == 7) {
            cout << "-> APPLYING ROTATE IMAGE FILTER...\n";
            int angle;
            cout << "ENTER THE ANGLE TO ROTATE (IN DEGREES): ";
            cin >> angle;
            applyRotate90(img, angle);
           cout<<"Next step : enter 18 to save the image or 19 to exit the program\n";
        }
        else if (number == 8) {
            cout << "-> APPLYING DARKEN/LIGHTEN FILTER...\n";
            float factor;
            cout << "ENTER THE FACTOR TO DARKEN/LIGHTEN (0 to 2): ";
            cin >> factor;
            applyDarkenandLighten(img, factor);
            cout<<"Next step : enter 18 to save the image or 19 to exit the program\n";
        }
        else if (number == 9) {
            cout << "-> APPLYING RESIZE FILTER...\n";
            resizeImage(img); 
           cout<<"Next step : enter 18 to save the image or 19 to exit the program\n";
        }
        else if (number == 10) {
            cout << "-> APPLYING MERGE FILTER...\n";
           string filename2;
    cout << "Enter the second image filename: ";
    cin >> filename2;
    Image img2(filename2);
    mergeImages(img, img2, img);
           cout<<"Next step : enter 18 to save the image or 19 to exit the program\n";
        }
        else if (number == 11) {
            cout << "-> APPLYING DETECT IMAGE EDGES FILTER...\n";
           detectEdges (img);
           cout<<"Next step : enter 18 to save the image or 19 to exit the program\n";
        }
           else if (number == 12) {
            cout << "-> APPLYING CROP IMAGE FILTER...\n";
            int x, y, width, height;
            cout<<"enter starting x and Y coordinates";
            cin>> x >> y ;
            cout<<"enter width and height of the crop area";
            cin>> width >> height ;
            applyCrop(img, x, y, width, height);      
            cout<<"Next step : enter 18 to save the image or 19 to exit the program\n";
        }
        else if (number == 13) {
            cout << "-> APPLYING BLUR FILTER...\n";
           applyBlurFilter(img)
           cout<<"Next step : enter 18 to save the image or 19 to exit the program\n";
        }
        else if (number == 14) {
            cout << "-> APPLYING NATURAL SUNLIGHT FILTER...\n";
           filter13_sunlight(img, img);
    cout << "Next step : enter 18 to save the image or 19 to exit the program\n";
}
        else if (number == 15) {
            cout << "-> APPLYING TV EFFECT /NOISE FILTER...\n";
           applyTVFX(img);
           cout<<"Next step : enter 18 to save the image or 19 to exit the program\n";
        }
        else if (number == 16) {
            cout << "-> APPLYING PURPLE TINT / WANO NIGHTFILTER...\n";
            applyPurpleTint(img);
           cout<<"Next step : enter 18 to save the image or 19 to exit the program\n";
        }
        else if (number == 17) {
            cout << "-> APPLY INFRARED PHOTOGRAPHY FILTER...\n";
            applyInfrared(img)
           cout<<"Next step : enter 18 to save the image or 19 to exit the program\n";
        }   
        else if (number == 18) {
            askToSaveImage(img);
        }
        else if (number == 19) {
            cout << "THANK YOU FOR USING THE PROGRAM. GOODBYE!\n";
            break;
        }
        else {
            cout << "INVALID CHOICE. PLEASE ENTER A NUMBER BETWEEN 1 AND 19.\n";
        }
    }
    return 0;
}
