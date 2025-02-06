#include "game/Game.h"

int main() {
    //Init game engine
    Game game;

    //Game loop
    while (game.isRunning()) {
        game.updateDt();

        //Update
        game.update();

        //Render
        game.render();
    }

    return 0;
}
