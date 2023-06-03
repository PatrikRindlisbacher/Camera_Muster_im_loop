#include <Arduino.h>
#include <esp_camera.h>                                                                           // ESP Camera https://github.com/espressif/esp32-camera
#include "camera_pins.h"                                                                          // Camera Pins OV3660
#include "camera_config.h"                                                                        // Camera config
#include "camera_functions.h"                                                                     // Camera Funktionen

unsigned long Timer_Millis;


void setup() {
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  delay(3000);
  Serial.println("Start");
  camera_config_gray();
  //camera_config_jpg();
}

void Take_Pictures(){                                                           // Aktualisieren Winsocks Clients
  if ((Timer_Millis + 5000) < millis()){                                                 // Alle ?? mS
    Serial.print("Start ms ");
    Serial.println(millis());
    //esp_camera_deinit();
    //camera_config_jpg();
    change_Picture_Format_to_JPEG();
    take_Camera_Image_JPG();                                                                       // Bild aufnehmen JPG
    Serial.print("Jpg Buffer Len ");
    Serial.println(fb_jpg->len);
    esp_camera_fb_return(fb_jpg);
    fb_jpg = NULL;

    //esp_camera_deinit();
    //camera_config_gray();
    change_Picture_Format_to_GRAYSCALE();
    take_Camera_Image_GRAY();
    esp_camera_fb_return(fb_gray);
    Serial.print("Gray Buffer Len ");
    Serial.println(fb_gray->len);
    fb_gray = NULL;
    Serial.print("Ende ms ");
    Serial.println(millis());

    Timer_Millis = millis();                                                            // Zeit merken
  }
}

void loop() {
  Take_Pictures();
}  

