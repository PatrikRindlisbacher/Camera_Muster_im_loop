#include <Arduino.h>
camera_fb_t * fb_gray = NULL;                                                                     // Data structure of camera frame buffer
camera_fb_t * fb_jpg = NULL;                                                                      // Data structure of camera frame buffer

bool change_Picture_Format_to_JPEG() {
  sensor_t *s = esp_camera_sensor_get();
  if (s == NULL) {
    Serial.println("Error: problem reading camera sensor settings");
    return 0;
  }
  s->set_pixformat(s,PIXFORMAT_JPEG) ; 
  
  //s->set_framesize(s,FRAMESIZE_SVGA);
  s->set_framesize(s,FRAMESIZE_VGA);
  return 1;
}

bool change_Picture_Format_to_GRAYSCALE() {
  sensor_t *s = esp_camera_sensor_get();
  if (s == NULL) {
    Serial.println("Error: problem reading camera sensor settings");
    return 0;
  }
  s->set_pixformat(s,PIXFORMAT_GRAYSCALE) ; 
  s->set_framesize(s,FRAMESIZE_96X96);
  return 1;
}

void take_Camera_Image_JPG(){                                                                         // Bild aufnehmen
  //change_Picture_Format_to_JPEG();
  fb_jpg = esp_camera_fb_get();                                                                       // Bild in Framerbuffer
  if (!fb_jpg){                                                                                       // Bei Fehler
    Serial.println("photo failed");
    while(1);                                                                                     //stop
  }
}

void take_Camera_Image_GRAY(){                                                                         // Bild aufnehmen
  //change_Picture_Format_to_GRAYSCALE();
  fb_gray = esp_camera_fb_get();                                                                       // Bild in Framerbuffer
  if (!fb_gray){                                                                                       // Bei Fehler
    Serial.println("photo failed");
    while(1);                                                                                     //stop
  }
}