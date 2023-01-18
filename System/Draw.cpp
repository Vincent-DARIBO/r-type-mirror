#include "./Draw.hpp"

Draw::Draw(/* args */)
{
}

Draw::~Draw()
{
}

void Draw::clearBackground(Color color)
{
    ClearBackground(color);
}

void Draw::beginDrawing()
{
    BeginDrawing();
}

void Draw::endDrawing()
{
    EndDrawing();
}

void Draw::drawRectangle(int posx, int posy, int width, int height, Color color)
{
    DrawRectangle(posx, posy, width, height, color);
}

void Draw::drawRectangleLines(int posX, int posY, int width, int height, Color color)
{
    DrawRectangleLines(posX, posY, width, height, color);
}

void Draw::drawText(const char *text, int posX, int posY, int fontSize, Color color)
{
    DrawText(text, posX, posY, fontSize, color);
}

void Draw::drawTexture(Texture2D texture, int posX, int posY, Color tint)
{
    DrawTexture(texture, posX, posY, tint);
}

void Draw::drawTextureRec(Texture2D texture, Rectangle source, Vector2 position, Color tint)
{
    DrawTextureRec(texture, source, position, tint);
}