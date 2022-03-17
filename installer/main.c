/*
(C) Copyright 2022-2027 Venkatesh Mishra
Soul Linux CLI installer
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// using a enum for Debian and Arch Linux
enum distro = {Deb = 0, Arch = 1};

// Defining a struct to get the info of the base chosen by the user
struct base {
    char * name;
    char * release;
    float verison;
};

// pre-installation script
int short pre_installation() {
    system("timedatectl set-ntp true");
    // cleaning 
    system("history -c");
    // arch
    system("rm /var/lib/pacman/sync/*.db");
    system("pacman -Sy");
    //debian
    system("apt clean");
    system("apt update");
}


int timezone(){
    char * lct;
    printf("Enter your timezone's locational Continet: ");
    scanf("%s",lct);
    if(strcmp(lct, "Asia")==0){
        return 0;
    }else{
        return 1;
    }
}

// wired networking
// use nm-applet for wireless
int networking(char * interface) {
    int short i;
    if(strcmp(interface, "e")==0){
        for(i=0;i<1;i++){
            return 0;
        }
    } else if(strcmp(interface, "w")==0) {
        for(i=0;i<1;i++){
            return 0;
        }
    }else{
        for(i=0;i<1;i++){
            return 0;
        }
    }
}

// choosing base os and getting it ready for installation
int base(char * distro) {
    int short i;
    for(i=0;i<1;i++){
        if(strcmp(distro, "debian-stable")==0){
            return 0;
        }else if(strcmp(distro, "debian-rolling")==0){
            return 0;
        }else if(strcmp(distro, "arch")==0){
            return 0;
        }else if(strcmp(distro, "arch-stable")==0){
            return 0;
        }else{
            return 0;
        }
    }
}

// set keyboard layout
int keyboard_layout(char * lyt) {
    if(strcmp(lyt, "en")==0){
        system("localectl set-keymap en");
        return 0;
    }else if(strcmp(lyt,"de")==0){
        system("localectl set-keymap de");
        return 0;
    }else{
        return 1;
    }
}

// dual boot support
int dualboot(char * os){
    int short i;
    for(i=0;i<1;i++){
        char * choise;
        printf("Are you dual booting Soul Linux with another Operating System ? (yes or no):\n");
        scanf("%s",&choise);
        if(strcmp(choise, "yes")==0){
            return 0;
        } else if(strcmp(choise, "no")==0) {
            return 0;
        } else {
            printf("value out of range");
            return 1;
        }
        return 0;
    }
}

// disk partioning
int partioning() {
    int short i;
    for(i=0;i<1;i++){
        system("fdisk -lc");
        char * disk,partprog;
        printf("Enter the name the disk you want to install Soul Linux to:\n");
        scanf("%s",&disk);
        return 0;
    }
}

// disk formating
// fmtprog means formating tool used: example: fdisk, gparted, etc
int formating(char * fmtprog) {
    if(strcmp(fmtprog, "fdisk")==0){
        int short i;
        for(i=0;i<1;i++){
            return 0;
        }
    } else if(strcmp(fmtprog, "efdisk")==0){
        for(i=0;i<1;i++){
            return 0;
        }
    } else {
        for(i=0;i<1;i++){
            return 0;
        }
    }
}

// detect if there is a existing os in the chosen drive
int prev_os_detector(char * drive){
    int short i;   
    for(i=0;i<1;i++){
        #ifdef __linux__
            printf("Detected Linux on chosen drive");
            return 0;
        #endif
        #ifdef _WIN32_
            printf("Detected Windows-32-bit on chosen drive");
            return 0;
        #endif
        #ifdef _WIN64_
            printf("Detected Windows-64-bit on chosen drive");
            return 0;
        #endif
    }
}

// lvm drive encrption
int lvm_encryption(){
    int short i;
    for(i=0;i<1;i++){
        char * choise;
        printf("Do you want to encrpt your hard drive, (recomended if using laptop): \n");
        scanf("%s",&choise);
        if(strcmp(choise, "yes")==0){
            return 0;
        }else if(strcmp(choise, "no")==0){
            return 0;
        }else{
            for(i=0;i<2;i++){
                printf("Error!, value out of range!\n");
            }
            return 1;
        }
    }
}

int editor(){
    char * edtr;
    printf("Please choose a editor from the given list below:\n");
    printf("%s","Vi");
    printf("%s","Vim");
    printf("%s","Nano");
    printf("%s","UEmacs");
    scanf("%s",&edtr);
    if(strcmp(editor, "Vi")==0){
        system("EDITOR=vi");
        return 0;
    }else if(strcmp(editor, "Vim")==0){
       system("EDITOR=vim");
       return 0; 
    }
    else{
        return 1;
    }
}

int list(){
    printf("%s","English US");
    printf("%s","English UK");
    printf("%s","English AUS");
    printf("%s","English IND");
    printf("%s","English CANADA");
    printf("%s", "Mexican");
    printf("%s", "Italian");
    printf("%s", "German");
    printf("%s", "French");
    printf("%s", "Russian");
    printf("%s", "Chinese");
    printf("%s", "Hindi");
    printf("%s", "Japanese");
    printf("%s", "Mongolian");
    printf("%s", "Zulu");
    printf("%s", "Spanish");
    printf("%s", "Odia");
    printf("%s", "Punjabi");
    printf("%s", "Urdu");
    printf("%s", "Tamil");
    printf("%s", "Telugu");
    printf("%s", "Malyalam");
    printf("%s", "Sanskrit");
}

// main code
int main(int short argc, char * const argv[]){
    int short i;
    for(i=0;i<1;i++){
        printf("Welcome to the Soul Linux CLI installer!\n");
        printf("Please wait while run some pre-installation scripts...\n");
        pre_installation();
        printf("Choose a keyboard laguage from the list given below to continue:\n");
        list();
    }
    return 0;
}
