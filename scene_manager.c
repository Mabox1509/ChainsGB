#include <gb/gb.h>
#include "Resources/Scenes/scene_space.c"

typedef enum {
    SCENE_TITLE,
    SCENE_SPACE,
    // Agregar más escenas aquí según sea necesario
    SCENE_NONE // Valor para indicar que no hay escena cargada actualmente
} Scene;


// Definir un array de bytes compartido entre las escenas
#define MAX_BYTES 1024 // por ejemplo, un máximo de 1024 bytes
static unsigned char ram[MAX_BYTES] = {0};
static unsigned char tiles[MAX_BYTES] = {0};

// Declarar una variable global para almacenar la escena actual
static Scene current_scene = SCENE_NONE;

// Declarar una función privada para limpiar el array de bytes compartido
static void clear_ram_data() {
    for (int i = 0; i < MAX_BYTES; i++) {
        ram[i] = 0;
        tiles[0] = 0;
    }
}


void Load(Scene scene_index) {
    if(current_scene != SCENE_NONE)
    {
        // Limpiar el array de bytes compartido
        clear_ram_data();


        set_sprite_data(0, 0, NULL);
        set_bkg_data(0, 0, NULL);

        // Resetear los sprites
        HIDE_SPRITES;
    }

    // Cargar la escena especificada
    switch (scene_index) {
        case SCENE_SPACE:
            SceneSpace_Init(ram,tiles);
            current_scene = SCENE_SPACE;
            break;
        // Agregar más escenas aquí según sea necesario
        default:
            // Escena no válida, no hacer nada
            break;
    }

    SHOW_SPRITES;
}
void Update() {
    // Actualizar la escena actual
    switch (current_scene) {
        case SCENE_SPACE:
            SceneSpace_Update(tiles);
            break;
        // Agregar más escenas aquí según sea necesario
        default:
            // Escena no válida, no hacer nada
            break;
    }
}
