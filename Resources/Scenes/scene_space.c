#include "..\Sprites\Space.c"
#include <gb/gb.h>

//STRUCS
struct Astronaut
{
    unsigned char *x;
    unsigned char *y;
};


//VARIABLES
const unsigned char gui_map_rom[] = 
{
    0, 8, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0,
    0, 10, 11, 0, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 0, 0, 0, 0, 0, 0
};

const unsigned background = 1;


struct Astronaut astronaut;

//METHODS

void UpdateAstronaut()
{
    // Detección de teclas de dirección
    if (joypad() & J_LEFT)
    {
        --*(astronaut.x);

        set_sprite_tile(0,4); set_sprite_prop(0, S_FLIPX | 0);
        set_sprite_tile(1,3); set_sprite_prop(1, S_FLIPX | 0);
        set_sprite_tile(2,4); set_sprite_prop(2, S_FLIPX | S_FLIPY);
        set_sprite_tile(3,3); set_sprite_prop(3, S_FLIPX | S_FLIPY);
    }
    if (joypad() & J_RIGHT)
    {
        ++*(astronaut.x);

        set_sprite_tile(0,3); set_sprite_prop(0, 0 | 0);
        set_sprite_tile(1,4); set_sprite_prop(1, 0 | 0);
        set_sprite_tile(2,3); set_sprite_prop(2, 0 | S_FLIPY);
        set_sprite_tile(3,4); set_sprite_prop(3, 0 | S_FLIPY);
    }
    if (joypad() & J_UP)
    {
        --*(astronaut.y);

        set_sprite_tile(0,1); set_sprite_prop(0, 0 | 0);
        set_sprite_tile(1,1); set_sprite_prop(1, S_FLIPX | 0);
        set_sprite_tile(2,2); set_sprite_prop(2, 0 | 0);
        set_sprite_tile(3,2); set_sprite_prop(3, S_FLIPX | 0);
    }
    if (joypad() & J_DOWN)
    {
        ++*(astronaut.y);

        set_sprite_tile(0,2); set_sprite_prop(0, 0 | S_FLIPY);
        set_sprite_tile(1,2); set_sprite_prop(1, S_FLIPX | S_FLIPY);
        set_sprite_tile(2,1); set_sprite_prop(2, 0 | S_FLIPY);
        set_sprite_tile(3,1); set_sprite_prop(3, S_FLIPX | S_FLIPY);
    }

    /*
            ^
            |
            |
            |
    Codigo terrible XD
    
    */

    move_sprite(0, *astronaut.x - 8, *astronaut.y - 8);
    move_sprite(1, *astronaut.x, *astronaut.y - 8);
    move_sprite(2, *astronaut.x - 8, *astronaut.y);
    move_sprite(3, *astronaut.x, *astronaut.y);
}


//SCENE
void SceneSpace_Init(unsigned char *data)
{
    astronaut.x = (unsigned char *)&data[9];
    astronaut.y = (unsigned char *)&data[10];

    *astronaut.x = 60;
    *astronaut.y = 70;
    
    //Set background tile
    
    //set_bkg_tiles(0, 0, 20, 18, background);

    //Set HUD
    set_bkg_tiles(0, 16, 20, 2, gui_map_rom);


    set_sprite_data(1,10,SpaceGrid);
    //Set player sprites
    set_sprite_tile(0,1); set_sprite_prop(0, 0 | 0);
    set_sprite_tile(1,1); set_sprite_prop(1, S_FLIPX | 0);
    set_sprite_tile(2,2); set_sprite_prop(2, 0 | 0);
    set_sprite_tile(3,2); set_sprite_prop(3, S_FLIPX | 0);
}
void SceneSpace_Update()
{
    UpdateAstronaut();
}

