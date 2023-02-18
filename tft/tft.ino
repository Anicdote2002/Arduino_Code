void setup()
{
  Serial.begin(9600);
  tft.begin();
  screenRedrawNecessary = true;
}

void loop()
{
  /* Touch input detection omitted. See below */

  if(screenRedrawNecessary)
  {
  resetAndClearScreen();
  drawIntroText();
  drawTouchButton(b1[0], b1[1], b1[2], b1[3], "Previous");
  drawTouchButton(b2[0], b2[1], b2[2], b2[3], "Next");
    
  screenRedrawNecessary = false;
  }
}

void drawIntroText(void)
{
  tft.setCursor(15, 15);
  tft.setTextColor(font_colors[active_colors]);
  tft.setTextSize(2);
  tft.println("Hello, World!");
 
  tft.setCursor(15, 55);
  tft.println("Use the buttons below");
  tft.setCursor(15, 75);
  tft.println("to change the background");
  tft.setCursor(15, 95);
  tft.println("color!");
}

void drawTouchButton(unsigned x, unsigned y, unsigned width, unsigned height, String text)
{
  int x_text_pos = x + width / 2 - (text.length() / 2) * 11;
  int y_text_pos = y + height / 2 - 8;
 
  tft.drawRect(x, y, width, height, font_colors[active_colors]);
  tft.setTextSize(2);
  tft.setTextColor(font_colors[active_colors]);
  tft.setCursor(x_text_pos, y_text_pos);
  tft.print(text);
}
