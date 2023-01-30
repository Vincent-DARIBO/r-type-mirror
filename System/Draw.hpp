#ifndef _DRAW_
#define _DRAW_

#include "raylib.h"
#include "./Vector2Int.hpp"
#include <string>

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
    void drawText(std::string text, Vector2Int pos, int fontSize, Color color);
    void drawTexture(Texture2D texture, Vector2Int pos, Color tint);
    void drawTextureRec(Texture2D texture, Rectangle source, Vector2Int position, Color tint);
    void drawTexturePro(Texture2D texture, Rectangle source, Rectangle dest, Vector2 origin, float rotation, Color tint);
};

#endif