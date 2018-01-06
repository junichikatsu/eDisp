#include <eDisp.h>
#include <stdio.h>
#include <stdarg.h>

eDisp::eDisp()
{
  _bg_buffer_num = 0;
}

void eDisp::begin(HardwareSerial* eDispSerial)
{
  _eDispSerial = eDispSerial;
}

void eDisp::cls()
{
  _eDispSerial->print("\x1B[*");
}

void eDisp::print(char *s)
{
  _eDispSerial->print(s);
}

void eDisp::println(char *s)
{
  _eDispSerial->println(s);
}

void eDisp::printf(const char *f, ... )
{
  va_list ap;
  va_start(ap, f);
  vsprintf( buf, f, ap );
  va_end(ap);
  _eDispSerial->print(buf);
}

void eDisp::setTextCursor(int x,int y)
{
  sprintf(buf,"\x1B[%d;%dH",y,x);
  _eDispSerial->print(buf);
}

void eDisp::setTextColor(TextColor c)
{
  sprintf(buf,"\x1B[%d;m",c);
  _eDispSerial->print(buf);  
}

void eDisp::setTextColor(TextColor c, TextColor b)
{
  sprintf(buf,"\x1B[%d;%d;m",c,b+10);
  _eDispSerial->print(buf);  
}
void eDisp::setCursorDsp(bool on)
{
  if(on)
    sprintf(buf,"\x1B[>5l");
  else
    sprintf(buf,"\x1B[>5h");

  _eDispSerial->print(buf);  
}
void eDisp::setTextCode(TextCode code)
{
  sprintf(buf,"\x1B@%dZ",code);
  _eDispSerial->print(buf);  
}

void eDisp::setTextSize(TextSize size)
{
  sprintf(buf,"\x1B@%dZ",size);
  _eDispSerial->print(buf);  
}

void eDisp::setBaud(Baudrate baud)
{
  sprintf(buf,"\x1B@%dZ",baud);
  _eDispSerial->print(buf);  
}

void eDisp::setBackgroundBufferNum(int num)
{
  _bg_buffer_num = num;

  sprintf(buf,"\x1B@%dZ",num + 30);
  _eDispSerial->print(buf);  
}

void eDisp::clearBackgroundBuffer(int num)
{
  sprintf(buf,"\x1B@%dZ",num + 70);
  _eDispSerial->print(buf);  
}

void eDisp::onBackLight(bool on)
{
  if(on)
    sprintf(buf,"\x1B@80Z");
  else
    sprintf(buf,"\x1B@81Z");

  _eDispSerial->print(buf);  
}

void eDisp::drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint32_t color)
{
  uint16_t __color = (color & 0xF80000) >> 9;
  __color |= (color & 0x00F800) >> 6;
  __color |= (color & 0x0000F8) >> 3;

  sprintf(buf,"\x1B@2;%d;%d;%d;%d;%d;%dz",_bg_buffer_num,x0,y0,x1,y1,__color);
  _eDispSerial->print(buf);
}

void eDisp::drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint32_t color)
{
  uint16_t __color = (color & 0xF80000) >> 9;
  __color |= (color & 0x00F800) >> 6;
  __color |= (color & 0x0000F8) >> 3;

  sprintf(buf,"\x1B@4;%d;%d;%d;%d;%d;%dz",_bg_buffer_num,w,h,x,y,__color);
  _eDispSerial->print(buf);
}

void eDisp::fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint32_t color)
{
  uint16_t __color = (color & 0xF80000) >> 9;
  __color |= (color & 0x00F800) >> 6;
  __color |= (color & 0x0000F8) >> 3;

  sprintf(buf,"\x1B@0;%d;%d;%d;%d;%d;%dz",_bg_buffer_num,w,h,x,y,__color);
  _eDispSerial->print(buf);
}

void eDisp::drawCircle(int16_t x0, int16_t y0, int16_t r, uint32_t color)
{
  uint16_t __color = (color & 0xF80000) >> 9;
  __color |= (color & 0x00F800) >> 6;
  __color |= (color & 0x0000F8) >> 3;

  sprintf(buf,"\x1B@3;%d;0;%d;%d;%d;%d;%dz",_bg_buffer_num,x0,y0,r,r,__color);
  _eDispSerial->print(buf);
}

void eDisp::fillCircle(int16_t x0, int16_t y0, int16_t r, uint32_t color)
{
  uint16_t __color = (color & 0xF80000) >> 9;
  __color |= (color & 0x00F800) >> 6;
  __color |= (color & 0x0000F8) >> 3;

  sprintf(buf,"\x1B@3;%d;1;%d;%d;%d;%d;%dz",_bg_buffer_num,x0,y0,r,r,__color);
  _eDispSerial->print(buf);
}

void eDisp::drawPixel(int16_t x, int16_t y, uint32_t color)
{
  uint16_t __color = (color & 0xF80000) >> 9;
  __color |= (color & 0x00F800) >> 6;
  __color |= (color & 0x0000F8) >> 3;

  sprintf(buf,"\x1B@5;%d;%d;%d;%dz",_bg_buffer_num,x,y,__color);
  _eDispSerial->print(buf);
}

void eDisp::drawSdPicture(int16_t x, int16_t y, uint16_t num)
{
  sprintf(buf,"\x1B@%d;%d;%d;%dI",num,_bg_buffer_num,x,y);
  _eDispSerial->print(buf);
}

void eDisp::playMusic(uint16_t num)
{
  sprintf(buf,"\x1B<%dS",num);
  _eDispSerial->print(buf);
}

void eDisp::stopMusic()
{
  sprintf(buf,"\x1B<P");
  _eDispSerial->print(buf);
}

void eDisp::setVolume(uint16_t v)
{
  sprintf(buf,"\x1B<%dV",v);
  _eDispSerial->print(buf);
}
