#define MAX_COLLIDERS 16

typedef struct {
    unsigned short* x;
    unsigned short* y;
    unsigned char* width;
    unsigned char* height;
} Collider;

static Collider colliders[MAX_COLLIDERS];
static unsigned char num_colliders = 0;

void cm_add_collider(unsigned short* x, unsigned short* y, unsigned char* width, unsigned char* height) {
    if (num_colliders >= MAX_COLLIDERS) return;

    Collider* new_collider = &colliders[num_colliders++];

    new_collider->x = x;
    new_collider->y = y;
    new_collider->width = width;
    new_collider->height = height;
}

void cm_remove_collider(unsigned char collider_id) {
    if (collider_id >= num_colliders) return;

    // Move last collider into the empty spot
    colliders[collider_id] = colliders[--num_colliders];
}

unsigned char cm_check_collisions(unsigned short x, unsigned short y, unsigned char width, unsigned char height) {
    for (unsigned char i = 0; i < num_colliders; i++) {
        Collider* c = &colliders[i];

        if (*c->x < x + width &&
            *c->x + *c->width > x &&
            *c->y < y + height &&
            *c->y + *c->height > y) {
            return i;
        }
    }

    return MAX_COLLIDERS; // No collisions
}
