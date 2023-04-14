#include "..\Sprites\Space.c"
#include <gb/gb.h>

//STRUCS
struct Astronaut
{
    unsigned char *x;
    unsigned char *y;
};


//VARIABLES
struct Astronaut astronaut;

//UPDATES
void UpdateAstronaut()
{
    // Detección de teclas de dirección
    if (joypad() & J_LEFT)
    {
        --*(astronaut.x);
    }
    if (joypad() & J_RIGHT)
    {
        ++*(astronaut.x);
    }
    if (joypad() & J_UP)
    {
        --*(astronaut.y);
    }
    if (joypad() & J_DOWN)
    {
        ++*(astronaut.y);
    }

    move_sprite(0, *astronaut.x - 8, *astronaut.y - 8);
    move_sprite(1, *astronaut.x, *astronaut.y - 8);
    move_sprite(2, *astronaut.x - 8, *astronaut.y);
    move_sprite(3, *astronaut.x, *astronaut.y);
}


//SCENE
void SceneSpace_Init(unsigned char *data)
{
    astronaut.x = (unsigned char *)&data[9];
    astronaut.y = (unsigned char *)&data[11];

    *astronaut.x = 60;
    *astronaut.y = 70;

    set_sprite_data(1,10,SpaceGrid);

    //Set player sprites
    set_sprite_tile(0,1);
    set_sprite_tile(1,1); set_sprite_prop(1, S_FLIPX);
    set_sprite_tile(2,2);
    set_sprite_tile(3,2); set_sprite_prop(3, S_FLIPX);
}
void SceneSpace_Update()
{
    UpdateAstronaut();
}

