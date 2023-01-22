#ifndef _DRAW_
#define _DRAW_

#include "raylib.h"
#include "./Vector2Int.hpp"

class Draw
{
private:
    /* data */
public:
    Draw(/* args */);
    ~Draw();
    void clearBackground(Color color);
    void beginDrawing();
    void endDrawing();
    void drawRectangle(Vector2Int pos, int width, int height, Color color);
    void drawRectangleLines(Vector2Int pos, int width, int height, Color color);
    void drawText(const char *text, Vector2Int pos, int fontSize, Color color);
    void drawTexture(Texture2D texture, Vector2Int pos, Color tint);
    void drawTextureRec(Texture2D texture, Rectangle source, Vector2Int position, Color tint);
};

#endif