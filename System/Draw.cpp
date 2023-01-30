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

void Draw::drawRectangle(Vector2Int pos, int width, int height, Color color)
{
    DrawRectangle(pos.x, pos.y, width, height, color);
}

void Draw::drawRectangleLines(Vector2Int pos, int width, int height, Color color)
{
    DrawRectangleLines(pos.x, pos.y, width, height, color);
}

void Draw::drawText(std::string text, Vector2Int pos, int fontSize, Color color)
{
    DrawText(text.c_str() , pos.x, pos.y, fontSize, color);
}

void Draw::drawTexture(Texture2D texture, Vector2Int pos, Color tint)
{
    DrawTexture(texture, pos.x, pos.y, tint);
}

void Draw::drawTextureRec(Texture2D texture, Rectangle source, Vector2Int position, Color tint)
{
    DrawTextureRec(texture, source, {(float)position.x, (float)position.y}, tint);
}

void Draw::drawTexturePro(Texture2D texture, Rectangle source, Rectangle dest, Vector2 origin, float rotation, Color tint)
{
    DrawTexturePro(texture, source, dest, origin, rotation, tint);
}