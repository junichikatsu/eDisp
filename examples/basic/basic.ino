#include <WioLTEforArduino.h>
#include <eDisp.h>

eDisp dsp;
int count = 0;

WioLTE Wio;

void setup() {
  Wio.Init();
  Wio.PowerSupplyGrove(true);
  dsp.begin(&Serial);
  delay(10000);				// オープニング画面を非表示にしている場合は不要です。
  dsp.cls();
  dsp.println("count start");
}

void loop() {
  dsp.setTextCursor(0,1);	// カーソル位置をx=0,Y=1で指定
  dsp.printf("%d",count);
  count++;
  delay(1000);
}