#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#define SCRIPT_VERSION "1.0 [ Build Refresh Rate SETTINGS ]"

// Function to display a notification
void shell(const char *message, int fps) {
    char command[512];
    snprintf(command, sizeof(command),
             "cmd notification post -S bigtext -t '♨️ VelocityHz ' 'Tag' '%s %d Hz' > /dev/null 2>&1",
             message, fps);
    system(command);
}

// Function to set the refresh rate
void setFps(int fps) {
    char prop[512];
    FILE *get = popen("getprop ro.product.vendor.brand", "r");

    if (get == NULL) {
        perror("popen failed");
        return;
    }
    
    if (fgets(prop, sizeof(prop), get) == NULL) {
        perror("fgets failed");
        pclose(get);
        return;
    }

    pclose(get);

    char commands[1024];

    if (strstr(prop, "xiaomi")) {
        snprintf(commands, sizeof(commands),
                 "cmd display clear-user-preferred-display-mode 0 && "
                 "cmd display set-user-preferred-display-mode $(wm size | awk -F '[ x]+' '{print $3}') $(wm size | awk -F '[ x]+' '{print $4}') %d 0 && "
                 "setprop debug.sf.use_phase_offsets_as_durations 1 &&"
                 "settings put system peak_refresh_rate %d && "
                 "settings put system user_refresh_rate %d && "
                 "settings put system min_refresh_rate %d && "
                 "settings put secure miui_refresh_rate %d && "
                 "settings put secure user_refresh_rate %d &&"
                 "cmd activity kill-all && "
                 "sync", fps, fps, fps, fps, fps, fps);
    } else {
        snprintf(commands, sizeof(commands),
                 "cmd display clear-user-preferred-display-mode 0 && "
                 "cmd display set-user-preferred-display-mode $(wm size | awk -F '[ x]+' '{print $3}') $(wm size | awk -F '[ x]+' '{print $4}') %d 0 && "
                 "setprop debug.sf.use_phase_offsets_as_durations 1 &&"
                 "settings put system peak_refresh_rate %d && "
                 "settings put system user_refresh_rate %d && "
                 "settings put system min_refresh_rate %d && "
                 "settings put secure user_refresh_rate %d &&"
                 "cmd activity kill-all && "
                 "sync", fps, fps, fps, fps, fps);
    }

    int result = system(commands);
    if (result != 0) {
        printf("Error: Failed to apply refresh rate settings.\n");
        return;
    }

    shell("Successfully applied settings:", fps);

    // Display chosen refresh rate
    printf("Description Notes VelocityHz %s\n\n", SCRIPT_VERSION);
    printf("\n");
    printf("ID    : Script Kecepatan Penyegaran Cerdas\n");
    printf("          VelocityHz, Meningkatkan respons UI\n"); 
    printf("          dan kelancaran animasi, dengan memilih \n"); 
    printf("          Hz sesuai dengan kemampuan perangkat\n"); 
    printf("          Refresh Rate yang dipilih adalah: %d Hz\n\n", fps);     
    printf("US   : VelocityHz Smart Refresh Rate script,\n");
    printf("          Increase UI response and animation\n");
    printf("          smoothness, by selecting Hz\n");
    printf("          according to device capabilities\n");
    printf("          Refresh Rate the one chosen is: %d Hz\n\n", fps);
    printf("success\n");
}

// Function to reset refresh rate settings
void Delfps() {
    char commands[512];
    snprintf(commands, sizeof(commands),
             "cmd display clear-user-preferred-display-mode 0 && "
             "settings delete system peak_refresh_rate > /dev/null 2>&1 && "
             "settings delete system user_refresh_rate > /dev/null 2>&1 && "
             "settings delete system min_refresh_rate > /dev/null 2>&1 && "
             "settings delete secure miui_refresh_rate > /dev/null 2>&1 && "
             "settings delete secure user_refresh_rate > /dev/null 2>&1 ");

    int result = system(commands);
    if (result != 0) {
        printf("Error: Failed to reset refresh rate settings.\n");
        return;
    }

    shell("VelocityHz scripting success Delete", 0);
    printf("Success: Refresh rate reset to default settings.\n");
}

// Function to display usage instructions
void Usage() {
    printf("\nVelocityHz %s - Lightweight System Utility\n\n", SCRIPT_VERSION);
    printf("SYNOPSIS:\n");
    printf("  VelocityHz [OPTIONS]\n\n");
    printf("DESCRIPTION:\n");
    printf("  VelocityHz is a lightweight system utility designed to dynamically\n");
    printf("  adjust the device's refresh rate and optimize display performance.\n\n");
    printf("OPTIONS:\n");
    printf("  -E    Set refresh rate to 60Hz\n");
    printf("  -l    Set refresh rate to 90Hz\n");
    printf("  -F    Set refresh rate to 120Hz\n");
    printf("  -d    Delete refresh rate settings\n");
    printf("  -h    Display this help message\n\n");
    printf("EXAMPLES:\n");
    printf("  Set refresh rate to 60Hz:\n");
    printf("      VelocityHz -E\n\n");
    printf("  Set refresh rate to 90Hz:\n");
    printf("      VelocityHz -l\n\n");
    printf("  Set refresh rate to 120Hz:\n");
    printf("      VelocityHz -F\n\n");
    printf("  Delete refresh rate script:\n");
    printf("      VelocityHz -d\n\n");
    printf("SEE ALSO:\n");
    printf("  ADB Commands - https://developer.android.com/studio/command-line/adb\n");
    printf("  Android Display Modes - https://source.android.com/docs/core/display\n");
    printf("  Settings Provider - https://developer.android.com/reference/android/provider/Settings\n");
    printf("\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        Usage();
    }

    int selectedFps = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-E") == 0) {  
            sleep(1);
            selectedFps = 60;
        } else if (strcmp(argv[i], "-l") == 0) { 
            sleep(1);
            selectedFps = 98;
        } else if (strcmp(argv[i], "-F") == 0) { 
            sleep(1);
            selectedFps = 120;
        } else if (strcmp(argv[i], "-d") == 0) {
            Delfps();
        } else if (strcmp(argv[i], "-h") == 0) {
            Usage();
        } else {  
            printf("Unknown option: %s\n", argv[i]);  
            Usage();  
        }  
    }

    if (selectedFps > 0) {
        setFps(selectedFps);
    }

    sleep(1);
    printf("\n");
    printf(" ⚠️ This module is protected by copyright and is\n");
    printf(" intended for use by regular users only. Any use of\n");
    printf(" this module, including its code, design, or features,\n");
    printf(" by other developers without written permission from\n");
    printf(" the copyright owner is strictly prohibited.\n");
    printf("______________________________________________(+)\n\n");  

    return 0;
}