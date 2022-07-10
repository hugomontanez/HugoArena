
#include "Map.hpp"
#include "TextureManager.hpp"
#include "Tile.hpp"
#include <vector>
#include <fstream>

using std::string;

int lvl1[20][25] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,3,3,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,2,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,2,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};



int lvl2[20][25] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},

    {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
};

Map::~Map()
{
    //dtor

}

Map::Map(SDL_Renderer* renderer, std::string path, int height, int width)
{
    background = TextureManager::LoadTexture("assets/tiles.png",renderer);
    //LoadMap(lvl1);
    /*
        LEER UN ARCHIVO Y CARGARLO EN EL ARRAY DE MAP
    */
    LoadMapWithFile(path, height,width);
    int positions[4][2] = {
        {0,0},
        {32,0},
        {64,0},
        {96,0}
    };
    //size positions
    int sizeArr = sizeof(positions)/sizeof(positions[0]);

    for (int i = 0; i < sizeArr; i++)
    {
        //std::cout << "x: " << positions[i][0] << " y: " << positions[i][1] << std::endl;
        this -> tilesX.insert(std::pair<int,int>(i,positions[i][0]));
        this -> tilesY.insert(std::pair<int,int>(i,positions[i][1]));
        //this -> tilesX[i] = positions[i][0];
        std::cout << "X: " << this -> tilesX[i];
    }



    //tiles = new int[2];
   // tiles = new int[0,32,64];

    // int positionsTiles[3] = {32,64,96};
    /*
    POSICIONES DE LA HOJA DE SPRITE. exampleL imagen de 64x64, si lo dividimos en un bloque de 32 entonces la primera
    posicion seria (0,0) y la segunda (32,21)
    */
    src.y = 0;
    src.x = 32;


    //src.x = src.y = 0;
    src.w = dest.w = 32;
    src.h = dest.h = 32;

    //dest.x = dest.y = 0;
    dest.y = 0;
    dest.x = 0;


};

void Map::LoadMap(int arr[20][25])
{
     for (int row = 0; row < 20; row++){
        for(int column = 0; column < 25; column++){
            map[row][column] = arr[row][column];
        }
     }
}


void Map::LoadMapWithFile(std::string path, int height, int width){
    /*
        Load Map with file.txt from assets/lvls

        ################# LVL 1  TO TEST #################
        {1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,3,3,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,2,1,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,2,1,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    */

std::ifstream myfile;
    myfile.open (path);
    string mapText [20][25];  
    string line;  

    std::vector<string> lines;


    if(myfile.is_open())
    {
        while (getline(myfile, line)){
            lines.push_back(line);
        }
        // leer el archivo
        for(int i = 0; i < 20; i++)
        {
            for(int j = 0; j < 25; j++)
            {
                if (lines[i][j] == '0') {
                    map[i][j] = STONE;
                }
                else if (lines[i][j] == '1') {
                    map[i][j] = EARTH;
                }
                else if (lines[i][j] == '2') {
                    map[i][j] = GRASS;
                }
                else if (lines[i][j] == '3') {
                    map[i][j] = WALL;
                }
            }
        }
        myfile.close();
    }
    else
    {
        std::cout << "No se pudo abrir el archivo" << std::endl;
    }

}       

void Map::Render(SDL_Renderer* renderer, SDL_Texture* texture ,SDL_Rect srcRect, SDL_Rect destR){
    SDL_RenderCopy(renderer, texture, &srcRect, &destR);
}

void Map::DrawMap(SDL_Renderer* renderer)
{
    int type = 0;
    for (int row = 0; row < 20; row++){
        for(int column = 0; column < 25; column++){

            dest.x = column * 32;
            dest.y = row * 32;

            /*

                POSICION DEL TILE EN LA IMAGEN

            */

           
            type = map[row][column];
            src.x = this ->tilesX[type];
            src.y = this ->tilesY[type];


            //std::cout << "x: " << src.x << std::endl;

            Map::Render(renderer,background,src,dest);


        }
     }
}


void Map::Collision(SDL_Renderer* renderer,Player* player) {
    /*
        DETECCION DE COLISIONES
    */
    SDL_Rect tileLeft, tileRight, tileUp, tileDown;

    //std::cout << "tile X: " << (player->getX() + 32) / 32 << std::endl;
    //std::cout << "tile Y: " << (player->getY() + 32) / 32 << std::endl;

    int y1 = (player->getY() + 32 )  / 32;
    int x1= (player->getX() + 32)  / 32;

    int rowLeft = player->getY() /32;
    int columnLeft = (player->getX()) /32;


    tileLeft.x = columnLeft*32;
    tileLeft.y = rowLeft*32;
    tileLeft.h = TILE_SIZE;
    tileLeft.w = TILE_SIZE;

    tileRight.x = x1 * 32;
    tileRight.y = y1 *32;
    tileRight.h = TILE_SIZE;
    tileRight.w = TILE_SIZE;

    tileUp.x = x1 * 32;
    tileUp.y = (y1  * 32)- 32;
    tileUp.h = TILE_SIZE;
    tileUp.w = TILE_SIZE;

    tileDown.x = x1 * 32;
    tileDown.y = (y1 * 32);
    tileDown.h = TILE_SIZE;
    tileDown.w = TILE_SIZE;


        if (map[y1][x1] == WALL) {
            if (SDL_HasIntersection(&player ->destR, &tileRight)) {
                //rigth
                std::cout << "right" << std::endl;
                if (player ->getX() + WIDTH_PLAYER > tileRight.x && player ->getX() < tileRight.x) {
                    player ->setX(tileRight.x -WIDTH_PLAYER);
                } 
            }


        }

        if (map[y1][x1 - 1] == WALL) {
            if (SDL_HasIntersection(&player ->destR, &tileLeft)) {
                //left
                std::cout << "left" << std::endl;
                if (player ->getX() < tileLeft.x + TILE_SIZE && player ->getX() + WIDTH_PLAYER > tileLeft.x + TILE_SIZE) {
                    player ->setX(tileLeft.x + TILE_SIZE);
                }
            }
        }



        if (map[y1 -1][x1] == WALL) {
            if (SDL_HasIntersection(&player ->destR, &tileUp)) {
                //up
                std::cout << "up" << std::endl;
                if (player ->getY() < tileUp.y + TILE_SIZE && player ->getY() + HEIGHT_PLAYER > tileUp.y + TILE_SIZE) {
                    player ->setY(tileUp.y + TILE_SIZE);
                }
            }
        }

        if (map[y1 + 1][x1] == WALL) {
            if (SDL_HasIntersection(&player ->destR, &tileDown)) {
                //down
                std::cout << "down" << std::endl;
                if (player ->getY() + HEIGHT_PLAYER > tileDown.y && player ->getY() < tileDown.y) {
                    player ->setY(tileDown.y - HEIGHT_PLAYER);
                }
            }
        }

    //draw left and right rect
    SDL_RenderDrawRect(renderer, &tileRight);
    SDL_RenderDrawRect(renderer, &tileLeft);
    SDL_RenderDrawRect(renderer, &tileUp);
    SDL_RenderDrawRect(renderer, &tileDown);

    //color
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);


   // crear una area de colision tiles alrededor del player

}

