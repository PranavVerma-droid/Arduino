#include "esp_camera.h"
#include <BluetoothSerial.h>
#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"

BluetoothSerial SerialBT;

// Camera configuration
#define CAMERA_MODEL_AI_THINKER
const int cameraWidth = 640;  // Adjust as needed
const int cameraHeight = 480; // Adjust as needed
const int jpegQuality = 10;   // Adjust as needed

camera_config_t config = {
    .pin_pwdn = -1,
    .pin_reset = 2,
    .pin_xclk = 0,
    .pin_sscb_sda = 26,
    .pin_sscb_scl = 27,
    .pin_d7 = 35,
    .pin_d6 = 34,
    .pin_d5 = 39,
    .pin_d4 = 36,
    .pin_d3 = 21,
    .pin_d2 = 19,
    .pin_d1 = 18,
    .pin_d0 = 5,
    .pin_vsync = 25,
    .pin_href = 23,
    .pin_pclk = 22,
    .xclk_freq_hz = 20000000,
    .ledc_timer = LEDC_TIMER_0,
    .ledc_channel = LEDC_CHANNEL_0,
    .pixel_format = PIXFORMAT_JPEG,
    .frame_size = FRAMESIZE_VGA, // Adjust for desired frame size
    .jpeg_quality = jpegQuality,
    .fb_count = 1
};

void setup() {
  SerialBT.begin("ESP32-Cam"); // Name of the Bluetooth device

  // Camera initialization
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x", err);
    return;
  }

  // Start streaming live video feed over Bluetooth
  startCameraStreaming();
}

void startCameraStreaming() {
  camera_fb_t *fb = NULL;
  while (1) {
    fb = esp_camera_fb_get();
    if (!fb) {
      Serial.println("Camera capture failed");
    } else {
      // Send the JPEG frame over Bluetooth
      SerialBT.write(fb->buf, fb->len);
      esp_camera_fb_return(fb);
    }
  }
}

void loop() {
  // You can add additional functionality here if needed
}
