#include <gb/gb.h>
#include <stdio.h>

#include "scene_manager.c"
#include "Resources/Sprites/Tiles.c"


void main()
{
    set_bkg_data(1, 22, TilesGrid);
    SHOW_BKG;

    delay(10);

    Load(SCENE_SPACE);

    while (1)
    {
        Update();

        wait_vbl_done();
    }
    
}