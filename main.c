#include <gb/gb.h>
  //////////////////////
 // Autor: Mabox1509 //
//////////////////////



#include "scene_manager.c"
#include "Resources/Sprites/Tiles.c"


void main()
{
    set_bkg_data(1, 22, TilesGrid); //Carga los tiles en vram
    SHOW_BKG;//Instruccion de ensamblador que indica a la gameboy que empieze a renderizar el fondo

    delay(10);//Delay

    Load(SCENE_SPACE); //Cargar la scena "SPACE"

    while (1) //GAME LOOP
    {
        Update();//Actualizar la scena

        wait_vbl_done();//Esperar al que el renderizado haya finalizado
    }
    
}