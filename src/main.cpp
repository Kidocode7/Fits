#include <raylib.h>
#include <stdio.h>
int main()
{
    Image backgroundImage = LoadImage("src/BGs/bg sized.png");
    if (backgroundImage.data == NULL)
    {
        return 1;
    }
    int imageWidth = 1366;
    int imageHeight = 768;
    int windowWidth = imageWidth;
    int windowHeight = imageHeight;

    InitWindow(windowWidth, windowHeight, "Fits!");

    Texture2D backgroundTexture = LoadTextureFromImage(backgroundImage);
    UnloadImage(backgroundImage);

    SetTargetFPS(60);
    while (WindowShouldClose() == false)
    {

        BeginDrawing();
        ClearBackground(WHITE);
        DrawTexture(backgroundTexture, 0, 0, WHITE);
        EndDrawing();
    }
    UnloadTexture(backgroundTexture);
    CloseWindow();
    return 0;
}