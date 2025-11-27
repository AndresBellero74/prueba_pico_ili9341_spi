#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

// Pines según tu wiring
#define TFT_CS   17   // Chip Select
#define TFT_DC   16   // Data/Command
#define TFT_RST  20   // Reset
#define TFT_MOSI 19   // MOSI (si tu core lo permite)
#define TFT_CLK  18   // SCK

// Backlight control
#define TFT_LED 10   // GPIO10 para el pin LED del display

// Objeto del display
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  Serial.begin(115200);
  Serial.println("Inicializando ILI9341...");

  // Configuración del pin LED como salida
  pinMode(TFT_LED, OUTPUT);
  digitalWrite(TFT_LED, HIGH); // Enciende el backlight

  // Inicializa el display
  tft.begin();
  tft.setRotation(1);       // Orientación horizontal
  tft.fillScreen(ILI9341_BLUE);

  // Texto de prueba
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.setCursor(10, 10);
  tft.println("Hola Andres!");
}

void loop() {
  // Alterna colores para verificar funcionamiento
  delay(1000);
  tft.fillScreen(ILI9341_RED);
  delay(1000);
  tft.fillScreen(ILI9341_GREEN);
  delay(1000);
  tft.fillScreen(ILI9341_BLUE);

}
