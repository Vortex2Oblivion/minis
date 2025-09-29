#include <raylib.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    //SetTraceLogLevel(LOG_NONE);

    SetConfigFlags(FLAG_WINDOW_TRANSPARENT);
    SetConfigFlags(FLAG_WINDOW_MOUSE_PASSTHROUGH);
    SetConfigFlags(FLAG_WINDOW_TOPMOST);
    SetConfigFlags(FLAG_WINDOW_UNDECORATED);

    InitWindow(GetScreenWidth(), GetScreenHeight(), "MINIS");

    SetTargetFPS(15);

    SetWindowPosition(0, 30);

    Texture minis[27] = {
        LoadTexture("minis/sparkles.png"),
        LoadTexture("minis/subspace.png"),
        LoadTexture("minis/vinestaff.png"),
        LoadTexture("minis/firebrand.png"),
        LoadTexture("minis/pbucket.png"),
        LoadTexture("minis/skateboard.png"),
        LoadTexture("minis/sword.png"),
        LoadTexture("minis/katana.png"),
        LoadTexture("minis/coil.png"),
        LoadTexture("minis/traffic.png"),
        LoadTexture("minis/biograft.png"),
        LoadTexture("minis/ducky.png"),
        LoadTexture("minis/valk.png"),
        LoadTexture("minis/venomshank.png"),
        LoadTexture("minis/boombox.png"),
        LoadTexture("minis/shuriken.png"),
        LoadTexture("minis/scythe.png"),
        LoadTexture("minis/dollmaker.png"),
        LoadTexture("minis/medkit.png"),
        LoadTexture("minis/broker.png"),
        LoadTexture("minis/slingshit.png"),
        LoadTexture("minis/hyperlaser.png"),
        LoadTexture("minis/rocket.png"),
        LoadTexture("minis/dom.png"),
        LoadTexture("minis/banhammer.png"),
        LoadTexture("minis/mxbot.png"),
        LoadTexture("minis/zuka.png")};

    int minisLen = sizeof(minis) / sizeof(minis[0]);

    srand((unsigned int)time(NULL));
    int index = rand() % (minisLen);
    Image icon = LoadImageFromTexture(minis[index]);

    SetWindowIcon(icon);

    UnloadImage(icon);

    double scale = 1.3;

    for (int i = 0; i < minisLen; i++)
    {
        int oldWidth = minis[i].width;
        minis[i].height = minis[i].width = (int)((GetScreenWidth() / minisLen) * scale);
        SetTextureFilter(minis[i], TEXTURE_FILTER_BILINEAR);
    }
    int miniOffset = 45;
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLANK);
        for (int i = 0; i < minisLen; i++)
        {
            DrawTexture(minis[i], i * (int)(minis[i].width / scale), GetScreenHeight() - minis[i].height - miniOffset - 30, WHITE);
        }
        if (IsKeyPressed(KEY_F1))
        {
            if (miniOffset == 45)
            {
                miniOffset = 0;
            }
            else
            {
                miniOffset = 45;
            }
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
