#include <stdio.h>
#include <raylib.h>

#define WIDTH 800
#define HEIGHT 600

int main(void){
    #ifdef OS_Windows_NT
    printf("Windows dettected\n");
    #elif defined OS_Linux
    printf("LINUS dettected\n");
    #elif defined OS_Darwin
    printf("MacOS dettected\n");
    #endif

    InitWindow(WIDTH, HEIGHT, "This is a network test");
    SetTargetFPS(60);

    Camera3D camera = {0};

    camera.fovy = 45.0f;
    camera.target = (Vector3) {.0f, .0f, .0f};
    camera.position = (Vector3) { 0.0f, 10.0f, 10.0f };
    camera.up = (Vector3) { 0.0f, 1.0f, 0.0f };
    camera.type = CAMERA_PERSPECTIVE;
    
    Vector3 cube_position = {0.0f, 0.0f, 0.0f};

    while(!WindowShouldClose()){
        BeginDrawing();
        {

            ClearBackground(WHITE);
            DrawFPS(10, 10);

            BeginMode3D(camera);
            {
                DrawCube(cube_position, 1, 1, 1, RED);
                DrawCubeWires(cube_position, 1, 1, 1, BLUE);
                DrawGrid(10, 1);
            } EndMode3D();

            if(IsKeyDown(KEY_KP_ADD)) camera.fovy += 1.0f;
            if(IsKeyDown(KEY_KP_SUBTRACT)) camera.fovy -= 1.0f;

            if(IsKeyPressed(KEY_LEFT)) cube_position.x -= 1.0f;
            if(IsKeyPressed(KEY_RIGHT)) cube_position.x += 1.0f;
            if(IsKeyPressed(KEY_UP)) cube_position.z -= 1.0f;
            if(IsKeyPressed(KEY_DOWN)) cube_position.z += 1.0f;

        } EndDrawing();
    }

    CloseWindow();

    return 0;
}