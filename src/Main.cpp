#include <iostream>
#include "core/Game.h"

int main(int argc, char* argv[]) {
    // TODO: Check, this creates an object in the stack
    Game game;

    game.Initialize();
    game.Run();
    game.Destroy();

    return 0;
    // once the scope of this function is finished the object
    // is removed from the stack
}

// in the heap memory is allocated dynamically and it's
// usually not contiguous

// accessing memory in the heap is slower than in the stack

// the new keyword does two things:
// allocates memory as malloc in C
// initializes the object calling the constructor

// the `delete` keyword does two things:
// calls the destructor of the object
// frees the memory