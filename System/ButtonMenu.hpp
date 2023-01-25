#ifndef _ButtonMenu_
#define _ButtonMenu_

#include "raylib.h"
#include <string>

#define BUTTON_TEXTURE "sprites/Menus/Default_Button.png"

class ButtonMenu
{
private:
    Texture2D _texture;
    Rectangle _bounds;
    Vector2 _position;
    Vector2 _text_position;
    Font _font;
    const char *_text;

public:
    ButtonMenu();
    ~ButtonMenu();

    void Button(const char *text, Vector2 position, const char *filepath = BUTTON_TEXTURE);
    void draw_button(Vector2 mouse);
    bool is_bouton_press(Vector2 mouse);
};

#endif