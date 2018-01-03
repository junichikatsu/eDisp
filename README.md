e-DISP4用ライブラリ
=====

[e-DIPS4](https://www.ddl.co.jp/shop/html/user_data/edisp)をWio LTEに接続するためのライブラリです。
確認してはいませんが、Arduino UNO等でも使用できると思います。


## How To Use

Include library(`#include <eDisp.h>`), and write a code like below.

```
eDisp dsp;
int count = 0;

void setup() {
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
```

### 四角形を描画

x=0,y=0の位置に50x50の四角形を線色赤で描画
```
  dsp.drawRect(10,10,50,50,0x00FF00);
```

### SDカードの写真を表示

SDカード上のImage\1.jpgファイルをx=0,y=0の位置に表示する
```
  dsp.drawSdPicture(0,0,1);
```

## LICENSE

MIT


