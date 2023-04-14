#ifndef SCENE_SPACE_H
#define SCENE_SPACE_H

#include <gb/gb.h>

//STRUCS
struct Astronaut
{
unsigned char *x;
unsigned char *y;
};

//VARIABLES
extern struct Astronaut astronaut;

//FUNCTIONS
void SceneSpace_Init(unsigned char *data);
void SceneSpace_Update();

#endif // SCENE_SPACE_H