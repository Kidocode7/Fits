#include <raylib.h>
#include <stdio.h>

#define COLS 10
#define ROWS 20

const int screenWidth = 400;
const int screenHeight = 800;


int cellWidth = screenWidth / COLS;
int cellHeight = screenHeight / ROWS;

typedef struct Cell
{
   int i;
   int j;
} Cell;

Cell grid[COLS][ROWS];


void CellDraw(Cell);

int main()
{
    Image backgroundImage = LoadImage("src/BGs/bg sized.png");
    if (backgroundImage.data == NULL)
    {
        return 1;
    }
    int imageWidth = 1366;
    int imageHeight = 800;
    int windowWidth = imageWidth;
    int windowHeight = imageHeight;

    InitWindow(windowWidth, windowHeight, "Fits!");

    Texture2D backgroundTexture = LoadTextureFromImage(backgroundImage);
    UnloadImage(backgroundImage);

     for (int i=0; i < COLS; i++)
        {
            for (int j=0; j < ROWS; j++)
            {
                grid[i][j]=  (Cell)
                {.i=i,.j=j} ;

         }
            
        }

    SetTargetFPS(60);
    while (WindowShouldClose() == false)
    {

        BeginDrawing();
        ClearBackground(WHITE);
        DrawTexture(backgroundTexture, 0, 0, WHITE); 
          for (int i=0; i < COLS; i++)
        {
            for (int j=0; j < ROWS; j++)
            {
               CellDraw(grid[i][j]);

         }
            
        }
        EndDrawing();
    }
    UnloadTexture(backgroundTexture);
    CloseWindow();
    return 0;
}

void CellDraw(Cell cell){
    DrawRectangleLines(cell.i*cellWidth,cell.j*cellHeight,cellWidth,cellHeight,RED);
};