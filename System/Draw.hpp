#ifndef _DRAW_
#define _DRAW_

#include "raylib.h"

class Draw
{
private:
    /* data */
public:
    Draw(/* args */);
    ~Draw();
    void beginDrawing();
    void endDrawing();
    void clearBackground(Color color);
    void drawRectangle(int posx, int posy, int width, int height, Color color);
    void drawRectangleLines(int posx, int posy, int width, int height, Color color);
    void drawText(const char *text, int posX, int posY, int fontSize, Color color);
    void drawTexture(Texture2D texture, int posX, int posY, Color tint);
    void drawTextureRec(Texture2D texture, Rectangle source, Vector2 position, Color tint);
};

#endif