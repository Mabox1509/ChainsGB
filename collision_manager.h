#define MAX_COLLIDERS 16

typedef struct {
    unsigned short* x;
    unsigned short* y;
    unsigned char* width;
    unsigned char* height;
} Collider;

void cm_add_collider(unsigned short* x, unsigned short* y, unsigned char* width, unsigned char* height);
void cm_remove_collider(unsigned char collider_id);
unsigned char cm_check_collisions(unsigned short x, unsigned short y, unsigned char width, unsigned char height);
