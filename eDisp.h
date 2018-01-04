
#ifndef _EDISP_H_
#define _EDISP_H_

#include <WioLTEforArduino.h>



class eDisp {
public:

enum TextCode{
  SHIFT_JIS = 1,
  EUC_JP,
  UTF_8,
};

enum TextColor{
  TextBack = 30,
  TextRed,
  TextGreen,
  TextYellow,
  TextBlue,
  TextMagenta,
  TextCyan,
  TextWhite,
};


enum TextSize{
  TextSize4x8 = 4,
  TextSize5x12,
  TextSize8x16,
};

enum Baudrate{
  Baudrate_9600 = 10,
  Baudrate_14400,
  Baudrate_19200,
  Baudrate_38400,
  Baudrate_57600,
  Baudrate_115200,
};

  eDisp();
  void begin(HardwareSerial* eDispSerial);
  void cls();
  void print(char *s);
  void println(char *s);
  void printf(const char *f, ... );
  void setTextCursor(int x,int y);
  void setTextColor(TextColor c);
  void setTextColor(TextColor c, TextColor b);
  void setCursorDsp(bool on);
  void setTextCode(TextCode code);
  void setTextSize(TextSize size);
  void setBaud(Baudrate baud);
  void setBackgroundBufferNum(int num);
  void clearBackgroundBuffer(int num);
  void onBackLight(bool on);

  void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint32_t color);
  void drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint32_t color);
  void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint32_t color);
  void drawCircle(int16_t x0, int16_t y0, int16_t r, uint32_t color);
  void fillCircle(int16_t x0, int16_t y0, int16_t r, uint32_t color);
  void drawPixel(int16_t x, int16_t y, uint32_t color);
  void drawSdPicture(int16_t x, int16_t y, uint16_t num);
  void playMusic(uint16_t num);
  void stopMusic();
  void setVolume(uint16_t v);

private:
  HardwareSerial* _eDispSerial;
  int _bg_buffer_num;
  char buf[256];
};

#endif
