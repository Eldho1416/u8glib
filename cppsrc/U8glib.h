/*

  U8glib.h
  
  C++ Interface

  Universal 8bit Graphics Library
  
  Copyright (c) 2011, olikraus@gmail.com
  All rights reserved.

  Redistribution and use in source and binary forms, with or without modification, 
  are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice, this list 
    of conditions and the following disclaimer.
    
  * Redistributions in binary form must reproduce the above copyright notice, this 
    list of conditions and the following disclaimer in the documentation and/or other 
    materials provided with the distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND 
  CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, 
  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
  NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF 
  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  

*/

#ifndef _CPP_U8GLIB
#define _CPP_U8GLIB

#include "u8g.h"

class U8GLIB 
{
  private:
    u8g_t u8g;
    uint8_t initSPI(u8g_dev_t *dev, uint8_t sck, uint8_t mosi, uint8_t cs, uint8_t a0, uint8_t reset = U8G_PIN_NONE);
    uint8_t initHWSPI(u8g_dev_t *dev, uint8_t cs, uint8_t a0, uint8_t reset = U8G_PIN_NONE);
    uint8_t init8Bit(u8g_dev_t *dev, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7, 
        uint8_t en, uint8_t cs1, uint8_t cs2, uint8_t di, uint8_t rw = U8G_PIN_NONE, uint8_t reset = U8G_PIN_NONE);
  public:
  
    /* constructor */
    U8GLIB(u8g_dev_t *dev)
      { u8g_Init(&u8g, dev); }
    U8GLIB(u8g_dev_t *dev, uint8_t sck, uint8_t mosi, uint8_t cs, uint8_t a0, uint8_t reset) 
      { initSPI(dev, sck, mosi, cs, a0, reset); }
    U8GLIB(u8g_dev_t *dev, uint8_t cs, uint8_t a0, uint8_t reset) 
      { initHWSPI(dev, cs, a0, reset); }
    U8GLIB(u8g_dev_t *dev, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7, 
        uint8_t en, uint8_t cs1, uint8_t cs2, uint8_t di, uint8_t rw, uint8_t reset) 
      { init8Bit(dev, d0, d1, d2, d3, d4, d5, d6, d7, en, cs1, cs2, di, rw, reset); }
    
     /* picture loop */
    void firstPage(void) { u8g_FirstPage(&u8g); }
    uint8_t nextPage(void) { return u8g_NextPage(&u8g); }
    
    /* graphic primitives */
    void setColorIndex(uint8_t color_index) { u8g_SetColorIndex(&u8g, color_index); }
    uint8_t getColorIndex(void) { return u8g_GetColorIndex(&u8g); }
    u8g_uint_t getWidth(void) { return u8g_GetWidth(&u8g); }
    u8g_uint_t getHeight(void) { return u8g_GetHeight(&u8g); }
    uint8_t getMode(void) { return u8g_GetMode(&u8g); }

    void drawPixel(u8g_uint_t x, u8g_uint_t y) { return u8g_DrawPixel(&u8g, x, y); }
    void drawHLine(u8g_uint_t x, u8g_uint_t y, u8g_uint_t w) { u8g_DrawHLine(&u8g, x, y, w); }  
    void drawVLine(u8g_uint_t x, u8g_uint_t y, u8g_uint_t h) { u8g_DrawVLine(&u8g, x, y, h); }
    
    void drawFrame(u8g_uint_t x, u8g_uint_t y, u8g_uint_t w, u8g_uint_t h) { u8g_DrawFrame(&u8g, x, y, w, h); }
    void drawBox(u8g_uint_t x, u8g_uint_t y, u8g_uint_t w, u8g_uint_t h) { u8g_DrawBox(&u8g, x, y, w, h); }
    
    /* bitmap handling */
    void drawBitmap(u8g_uint_t x, u8g_uint_t y, u8g_uint_t cnt, u8g_uint_t h, const uint8_t *bitmap) 
      { u8g_DrawBitmap(&u8g, x, y, cnt, h, bitmap); }
    void drawBitmapP(u8g_uint_t x, u8g_uint_t y, u8g_uint_t cnt, u8g_uint_t h, const u8g_pgm_uint8_t *bitmap)
      { u8g_DrawBitmapP(&u8g, x, y, cnt, h, bitmap); }
    
    /* font handling */
    void setFont(const u8g_fntpgm_uint8_t *font) {u8g_SetFont(&u8g, font); }
    u8g_uint_t drawStr(u8g_uint_t x, u8g_uint_t y, const char *s) { return u8g_DrawStr(&u8g, x, y, s); }
    u8g_uint_t drawStrP(u8g_uint_t x, u8g_uint_t y, const u8g_pgm_uint8_t *s) { return u8g_DrawStrP(&u8g, x, y, s); }
    
    /* cursor handling */
    void setCursorFont(const u8g_pgm_uint8_t *cursor_font) { u8g_SetCursorFont(&u8g, cursor_font); }
    void setCursorStyle(uint8_t encoding) { u8g_SetCursorStyle(&u8g, encoding); }
    void setCursorPos(u8g_uint_t cursor_x, u8g_uint_t cursor_y) { u8g_SetCursorPos(&u8g, cursor_x, cursor_y); }
    void setCursorColor(uint8_t fg, uint8_t bg) { u8g_SetCursorColor(&u8g, fg, bg); }
    void enableCursor(void) { u8g_EnableCursor(&u8g); }
    void disableCursor(void) { u8g_DisableCursor(&u8g); }
    void drawCursor(void)  { u8g_DrawCursor(&u8g); }
};


class U8GLIB_DOGS102 : public U8GLIB 
{
  public:
    U8GLIB_DOGS102(uint8_t sck, uint8_t mosi, uint8_t cs, uint8_t a0, uint8_t reset = U8G_PIN_NONE) 
      : U8GLIB(&u8g_dev_uc1701_dogs102_sw_spi, sck, mosi, cs, a0, reset)
      { }
    U8GLIB_DOGS102(uint8_t cs, uint8_t a0, uint8_t reset = U8G_PIN_NONE) 
      : U8GLIB(&u8g_dev_uc1701_dogs102_hw_spi, cs, a0, reset)
      { }
};

class U8GLIB_DOGM132 : public U8GLIB 
{
  public:
    U8GLIB_DOGM132(uint8_t sck, uint8_t mosi, uint8_t cs, uint8_t a0, uint8_t reset = U8G_PIN_NONE) 
      : U8GLIB(&u8g_dev_st7565_dogm132_sw_spi, sck, mosi, cs, a0, reset)
      { }
    U8GLIB_DOGM132(uint8_t cs, uint8_t a0, uint8_t reset = U8G_PIN_NONE) 
      : U8GLIB(&u8g_dev_st7565_dogm132_hw_spi, cs, a0, reset)
      { }
};

class U8GLIB_DOGM128 : public U8GLIB 
{
  public:
    U8GLIB_DOGM128(uint8_t sck, uint8_t mosi, uint8_t cs, uint8_t a0, uint8_t reset = U8G_PIN_NONE) 
      : U8GLIB(&u8g_dev_st7565_dogm128_sw_spi, sck, mosi, cs, a0, reset)
      { }
    U8GLIB_DOGM128(uint8_t cs, uint8_t a0, uint8_t reset = U8G_PIN_NONE) 
      : U8GLIB(&u8g_dev_st7565_dogm128_hw_spi, cs, a0, reset)
      { }
};

class U8GLIB_DOGXL160_BW : public U8GLIB 
{
  public:
    U8GLIB_DOGXL160_BW(uint8_t sck, uint8_t mosi, uint8_t cs, uint8_t a0, uint8_t reset = U8G_PIN_NONE) 
      : U8GLIB(&u8g_dev_uc1610_dogxl160_bw_sw_spi, sck, mosi, cs, a0, reset)
      { }
    U8GLIB_DOGXL160_BW(uint8_t cs, uint8_t a0, uint8_t reset = U8G_PIN_NONE) 
      : U8GLIB(&u8g_dev_uc1610_dogxl160_bw_hw_spi, cs, a0, reset)
      { }
};

class U8GLIB_DOGXL160_GR : public U8GLIB 
{
  public:
    U8GLIB_DOGXL160_GR(uint8_t sck, uint8_t mosi, uint8_t cs, uint8_t a0, uint8_t reset = U8G_PIN_NONE) 
      : U8GLIB(&u8g_dev_uc1610_dogxl160_gr_sw_spi, sck, mosi, cs, a0, reset)
      { }
    U8GLIB_DOGXL160_GR(uint8_t cs, uint8_t a0, uint8_t reset = U8G_PIN_NONE) 
      : U8GLIB(&u8g_dev_uc1610_dogxl160_gr_hw_spi, cs, a0, reset)
      { }
};

class U8GLIB_NHD27OLED_BW : public U8GLIB 
{
  public:
    U8GLIB_NHD27OLED_BW(uint8_t sck, uint8_t mosi, uint8_t cs, uint8_t a0, uint8_t reset = U8G_PIN_NONE) 
      : U8GLIB(&u8g_dev_ssd1325_nhd27oled_bw_sw_spi, sck, mosi, cs, a0, reset)
      { }
    U8GLIB_NHD27OLED_BW(uint8_t cs, uint8_t a0, uint8_t reset = U8G_PIN_NONE) 
      : U8GLIB(&u8g_dev_ssd1325_nhd27oled_bw_hw_spi, cs, a0, reset)
      { }
};

class U8GLIB_NHD27OLED_GR : public U8GLIB 
{
  public:
    U8GLIB_NHD27OLED_GR(uint8_t sck, uint8_t mosi, uint8_t cs, uint8_t a0, uint8_t reset = U8G_PIN_NONE) 
      : U8GLIB(&u8g_dev_ssd1325_nhd27oled_gr_sw_spi, sck, mosi, cs, a0, reset)
      { }
    U8GLIB_NHD27OLED_GR(uint8_t cs, uint8_t a0, uint8_t reset = U8G_PIN_NONE) 
      : U8GLIB(&u8g_dev_ssd1325_nhd27oled_gr_hw_spi, cs, a0, reset)
      { }
};

class U8GLIB_PCF8812 : public U8GLIB 
{
  public:
    U8GLIB_PCF8812(uint8_t sck, uint8_t mosi, uint8_t cs, uint8_t a0, uint8_t reset = U8G_PIN_NONE) 
      : U8GLIB(&u8g_dev_pcf8812_96x65_sw_spi, sck, mosi, cs, a0, reset)
      { }
};

class U8GLIB_PCD8544 : public U8GLIB 
{
  public:
    U8GLIB_PCD8544(uint8_t sck, uint8_t mosi, uint8_t cs, uint8_t a0, uint8_t reset = U8G_PIN_NONE) 
      : U8GLIB(&u8g_dev_pcd8544_84x48_sw_spi, sck, mosi, cs, a0, reset)
      { }
};

#endif /* _CPP_U8GLIB */