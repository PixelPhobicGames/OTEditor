#include "Editor.hpp"
#include "raylib.h"

int main(int argc, char **argv){
    InitWindow(1280 , 720 , "OTE");
    SetTargetFPS(60);
    GuiLoadStyleDark();


    for (int i = 0 ; i <= strlen(argv[1]) - 10; i ++){
        OTEditor.Path[i] = argv[1][i];
    }

    Init();

    RenderTexture2D Target = LoadRenderTexture(320 , 200);

    DisableCursor();

    while (!WindowShouldClose())

    {

        for (int i = 0 ; i <= 7 ; i ++){
            if(!OverlayEnabled || IsMouseButtonDown(0) )UpdateCamera(&OTEditor.MainCamera, CAMERA_FIRST_PERSON);
        }
        
        BeginTextureMode(Target);
        ClearBackground(BLACK);

        BeginMode3D(OTEditor.MainCamera);

            DrawGrid(1000, 1.0f);

            WDLProcess();

            if (OmegaTechEditor.DrawModel)
            {
                switch (OmegaTechEditor.ModelID)
                {
                case 1:
                    DrawModelEx(WDLModels.Model1, {OmegaTechEditor.X, OmegaTechEditor.Y, OmegaTechEditor.Z}, {0, OmegaTechEditor.R, 0}, OmegaTechEditor.R, {OmegaTechEditor.S, OmegaTechEditor.S, OmegaTechEditor.S}, WHITE);
                    break;
                case 2:
                    DrawModelEx(WDLModels.Model2, {OmegaTechEditor.X, OmegaTechEditor.Y, OmegaTechEditor.Z}, {0, OmegaTechEditor.R, 0}, OmegaTechEditor.R, {OmegaTechEditor.S, OmegaTechEditor.S, OmegaTechEditor.S}, WHITE);
                    break;
                case 3:
                    DrawModelEx(WDLModels.Model3, {OmegaTechEditor.X, OmegaTechEditor.Y, OmegaTechEditor.Z}, {0, OmegaTechEditor.R, 0}, OmegaTechEditor.R, {OmegaTechEditor.S, OmegaTechEditor.S, OmegaTechEditor.S}, WHITE);
                    break;
                case 4:
                    DrawModelEx(WDLModels.Model4, {OmegaTechEditor.X, OmegaTechEditor.Y, OmegaTechEditor.Z}, {0, OmegaTechEditor.R, 0}, OmegaTechEditor.R, {OmegaTechEditor.S, OmegaTechEditor.S, OmegaTechEditor.S}, WHITE);
                    break;
                case 5:
                    DrawModelEx(WDLModels.Model5, {OmegaTechEditor.X, OmegaTechEditor.Y, OmegaTechEditor.Z}, {0, OmegaTechEditor.R, 0}, OmegaTechEditor.R, {OmegaTechEditor.S, OmegaTechEditor.S, OmegaTechEditor.S}, WHITE);
                    break;
                case 6:
                    DrawModelEx(WDLModels.Model6, {OmegaTechEditor.X, OmegaTechEditor.Y, OmegaTechEditor.Z}, {0, OmegaTechEditor.R, 0}, OmegaTechEditor.R, {OmegaTechEditor.S, OmegaTechEditor.S, OmegaTechEditor.S}, WHITE);
                    break;
                case 7:
                    DrawModelEx(WDLModels.Model7, {OmegaTechEditor.X, OmegaTechEditor.Y, OmegaTechEditor.Z}, {0, OmegaTechEditor.R, 0}, OmegaTechEditor.R, {OmegaTechEditor.S, OmegaTechEditor.S, OmegaTechEditor.S}, WHITE);
                    break;
                case 8:
                    DrawModelEx(WDLModels.Model8, {OmegaTechEditor.X, OmegaTechEditor.Y, OmegaTechEditor.Z}, {0, OmegaTechEditor.R, 0}, OmegaTechEditor.R, {OmegaTechEditor.S, OmegaTechEditor.S, OmegaTechEditor.S}, WHITE);
                    break;
                case 9:
                    DrawModelEx(WDLModels.Model9, {OmegaTechEditor.X, OmegaTechEditor.Y, OmegaTechEditor.Z}, {0, OmegaTechEditor.R, 0}, OmegaTechEditor.R, {OmegaTechEditor.S, OmegaTechEditor.S, OmegaTechEditor.S}, WHITE);
                    break;
                case 10:
                    DrawModelEx(WDLModels.Model10, {OmegaTechEditor.X, OmegaTechEditor.Y, OmegaTechEditor.Z}, {0, OmegaTechEditor.R, 0}, OmegaTechEditor.R, {OmegaTechEditor.S, OmegaTechEditor.S, OmegaTechEditor.S}, WHITE);
                    break;
                case 11:
                    DrawModelEx(WDLModels.Model11, {OmegaTechEditor.X, OmegaTechEditor.Y, OmegaTechEditor.Z}, {0, OmegaTechEditor.R, 0}, OmegaTechEditor.R, {OmegaTechEditor.S, OmegaTechEditor.S, OmegaTechEditor.S}, WHITE);
                    break;
                case 12:
                    DrawModelEx(WDLModels.Model12, {OmegaTechEditor.X, OmegaTechEditor.Y, OmegaTechEditor.Z}, {0, OmegaTechEditor.R, 0}, OmegaTechEditor.R, {OmegaTechEditor.S, OmegaTechEditor.S, OmegaTechEditor.S}, WHITE);
                    break;
                case 13:
                    DrawModelEx(WDLModels.Model13, {OmegaTechEditor.X, OmegaTechEditor.Y, OmegaTechEditor.Z}, {0, OmegaTechEditor.R, 0}, OmegaTechEditor.R, {OmegaTechEditor.S, OmegaTechEditor.S, OmegaTechEditor.S}, WHITE);
                    break;
                case 14:
                    DrawModelEx(WDLModels.Model14, {OmegaTechEditor.X, OmegaTechEditor.Y, OmegaTechEditor.Z}, {0, OmegaTechEditor.R, 0}, OmegaTechEditor.R, {OmegaTechEditor.S, OmegaTechEditor.S, OmegaTechEditor.S}, WHITE);
                    break;
                case 15:
                    DrawModelEx(WDLModels.Model15, {OmegaTechEditor.X, OmegaTechEditor.Y, OmegaTechEditor.Z}, {0, OmegaTechEditor.R, 0}, OmegaTechEditor.R, {OmegaTechEditor.S, OmegaTechEditor.S, OmegaTechEditor.S}, WHITE);
                    break;
                case 16:
                    DrawModelEx(WDLModels.Model16, {OmegaTechEditor.X, OmegaTechEditor.Y, OmegaTechEditor.Z}, {0, OmegaTechEditor.R, 0}, OmegaTechEditor.R, {OmegaTechEditor.S, OmegaTechEditor.S, OmegaTechEditor.S}, WHITE);
                    break;
                case 17:
                    DrawModelEx(WDLModels.Model17, {OmegaTechEditor.X, OmegaTechEditor.Y, OmegaTechEditor.Z}, {0, OmegaTechEditor.R, 0}, OmegaTechEditor.R, {OmegaTechEditor.S, OmegaTechEditor.S, OmegaTechEditor.S}, WHITE);
                    break;
                case 18:
                    DrawModelEx(WDLModels.Model18, {OmegaTechEditor.X, OmegaTechEditor.Y, OmegaTechEditor.Z}, {0, OmegaTechEditor.R, 0}, OmegaTechEditor.R, {OmegaTechEditor.S, OmegaTechEditor.S, OmegaTechEditor.S}, WHITE);
                    break;
                case 19:
                    DrawModelEx(WDLModels.Model19, {OmegaTechEditor.X, OmegaTechEditor.Y, OmegaTechEditor.Z}, {0, OmegaTechEditor.R, 0}, OmegaTechEditor.R, {OmegaTechEditor.S, OmegaTechEditor.S, OmegaTechEditor.S}, WHITE);
                    break;
                case 20:
                    DrawModelEx(WDLModels.Model20, {OmegaTechEditor.X, OmegaTechEditor.Y, OmegaTechEditor.Z}, {0, OmegaTechEditor.R, 0}, OmegaTechEditor.R, {OmegaTechEditor.S, OmegaTechEditor.S, OmegaTechEditor.S}, WHITE);
                    break;
                case -1:
                    DrawBoundingBox((BoundingBox){(Vector3){OmegaTechEditor.X, OmegaTechEditor.Y, OmegaTechEditor.Z}, (Vector3){OmegaTechEditor.W, OmegaTechEditor.H, OmegaTechEditor.L}}, ORANGE);
                    DrawCubeWires({OmegaTechEditor.W, OmegaTechEditor.H, OmegaTechEditor.L}, OmegaTechEditor.S, OmegaTechEditor.S, OmegaTechEditor.S, PINK);
                    break;
                case -2:
                    DrawBoundingBox((BoundingBox){(Vector3){OmegaTechEditor.X, OmegaTechEditor.Y, OmegaTechEditor.Z}, (Vector3){OmegaTechEditor.W, OmegaTechEditor.H - 5, OmegaTechEditor.L}}, ORANGE);
                    DrawCubeWires({OmegaTechEditor.W, OmegaTechEditor.H - 5, OmegaTechEditor.L}, OmegaTechEditor.S, OmegaTechEditor.S, OmegaTechEditor.S, PINK);
                    break;
                }

                if (OmegaTechEditor.ModelID <= 100 || OmegaTechEditor.ModelID == -3){
                    DrawCubeWires({OmegaTechEditor.X, OmegaTechEditor.Y, OmegaTechEditor.Z}, OmegaTechEditor.S, OmegaTechEditor.S, OmegaTechEditor.S, PINK);
                    DrawLine3D({OmegaTechEditor.X, OmegaTechEditor.Y, OmegaTechEditor.Z}, {OmegaTechEditor.X + OmegaTechEditor.S * 3 , OmegaTechEditor.Y, OmegaTechEditor.Z}, RED); 
                    DrawLine3D({OmegaTechEditor.X, OmegaTechEditor.Y, OmegaTechEditor.Z}, {OmegaTechEditor.X, OmegaTechEditor.Y + OmegaTechEditor.S * 3 , OmegaTechEditor.Z}, BLUE); 
                    DrawLine3D({OmegaTechEditor.X, OmegaTechEditor.Y, OmegaTechEditor.Z}, {OmegaTechEditor.X , OmegaTechEditor.Y, OmegaTechEditor.Z + OmegaTechEditor.S * 3 }, GREEN); 
                }
                else
                {
                    DrawCubeWires({OmegaTechEditor.X, OmegaTechEditor.Y, OmegaTechEditor.Z}, OmegaTechEditor.S, OmegaTechEditor.S, OmegaTechEditor.S, ORANGE);
                    DrawLine3D({OmegaTechEditor.X, OmegaTechEditor.Y, OmegaTechEditor.Z}, {OmegaTechEditor.X + OmegaTechEditor.S * 3 , OmegaTechEditor.Y, OmegaTechEditor.Z}, RED); 
                    DrawLine3D({OmegaTechEditor.X, OmegaTechEditor.Y, OmegaTechEditor.Z}, {OmegaTechEditor.X, OmegaTechEditor.Y + OmegaTechEditor.S * 3 , OmegaTechEditor.Z}, BLUE); 
                    DrawLine3D({OmegaTechEditor.X, OmegaTechEditor.Y, OmegaTechEditor.Z}, {OmegaTechEditor.X , OmegaTechEditor.Y, OmegaTechEditor.Z + OmegaTechEditor.S * 3 }, GREEN); 
                }

                if (!IsMouseButtonDown(2))
                {
                    if (IsKeyPressed(KEY_U))
                    {
                        OmegaTechEditor.X -= 2.0f;
                    }
                    if (IsKeyPressed(KEY_J))
                    {
                        OmegaTechEditor.X += 2.0f;
                    }
                    if (IsKeyPressed(KEY_H))
                    {
                        OmegaTechEditor.Z += 2.0f;
                    }
                    if (IsKeyPressed(KEY_K))
                    {
                        OmegaTechEditor.Z -= 2.0f;
                    }
                    if (IsKeyPressed(KEY_Y))
                    {
                        OmegaTechEditor.Y -= 2.0f;
                    }
                    if (IsKeyPressed(KEY_I))
                    {
                        OmegaTechEditor.Y += 2.0f;
                    }
                }
                else
                {
                    if (IsKeyPressed(KEY_U))
                    {
                        OmegaTechEditor.W -= 2.0f;
                    }
                    if (IsKeyPressed(KEY_J))
                    {
                        OmegaTechEditor.W +=  2.0f;
                    }
                    if (IsKeyPressed(KEY_H))
                    {
                        OmegaTechEditor.L +=  2.0f;
                    }
                    if (IsKeyPressed(KEY_K))
                    {
                        OmegaTechEditor.L -= 2.0f;
                    }
                    if (IsKeyPressed(KEY_Y))
                    {
                        OmegaTechEditor.H -= 2.0f;
                    }
                    if (IsKeyPressed(KEY_I))
                    {
                        OmegaTechEditor.H += 2.0f;
                    }
                }

                if (IsKeyPressed(KEY_O))
                {
                    OmegaTechEditor.R += 90.0f;
                }
                if (IsKeyPressed(KEY_L))
                {
                    OmegaTechEditor.R -= 90.0f;
                }
                if (IsKeyDown(KEY_T))
                {
                    OmegaTechEditor.S += .5f;
                }
                if (IsKeyDown(KEY_G))
                {
                    OmegaTechEditor.S -= .5f;
                }

                if (IsKeyPressed(KEY_ENTER))
                {
                    wstring WDLCommand = L"";

                    wstring Id = L"";

                    if (Toggle045Active){
                        WDLCommand += L":C:";
                    }

                    if (OmegaTechEditor.ModelID > 0)
                    {
                        if (OmegaTechEditor.ModelID != 100)
                        {
                            if (OmegaTechEditor.ModelID < 100)
                            {
                                Id = L"Model";
                                WDLCommand += Id + to_wstring(OmegaTechEditor.ModelID) + L":";
                            }
                            else
                            {
                                Id = L"Script";
                                WDLCommand += Id + to_wstring(OmegaTechEditor.ModelID - 100) + L":";
                            }
                        }
                        else
                        {
                            Id = L"Collision";
                            WDLCommand += Id + L":";
                        }

                        WDLCommand += to_wstring(OmegaTechEditor.X) + L":" + to_wstring(OmegaTechEditor.Y) + L":" + to_wstring(OmegaTechEditor.Z) + L":" + to_wstring(OmegaTechEditor.S) + L":" + to_wstring(OmegaTechEditor.R) + L":";
                    }
                    else {
                        if (OmegaTechEditor.ModelID == -1)
                        {
                            WDLCommand += L"AdvCollision:";
                            WDLCommand += to_wstring(OmegaTechEditor.X) + L":" + to_wstring(OmegaTechEditor.Y) + L":" + to_wstring(OmegaTechEditor.Z) + L":" + to_wstring(OmegaTechEditor.S) + L":" + to_wstring(OmegaTechEditor.R) + L":" + to_wstring(OmegaTechEditor.W) + L":" + to_wstring(OmegaTechEditor.H) + L":" + to_wstring(OmegaTechEditor.L) + L":";
                        }

                        if (OmegaTechEditor.ModelID == -2)
                        {
                            WDLCommand += L"ClipBox:";
                            WDLCommand += to_wstring(OmegaTechEditor.X) + L":" + to_wstring(OmegaTechEditor.Y) + L":" + to_wstring(OmegaTechEditor.Z) + L":" + to_wstring(OmegaTechEditor.S) + L":" + to_wstring(OmegaTechEditor.R) + L":" + to_wstring(OmegaTechEditor.W) + L":" + to_wstring(OmegaTechEditor.H) + L":" + to_wstring(OmegaTechEditor.L) + L":";
                        }

                        if (OmegaTechEditor.ModelID == -3){
                            WDLCommand += L"NE1:" + to_wstring(OmegaTechEditor.X) + L":" + to_wstring(OmegaTechEditor.Y) + L":" + to_wstring(OmegaTechEditor.Z) + L":" + to_wstring(OmegaTechEditor.S) + L":" + to_wstring(OmegaTechEditor.R) + L":";
                        }
                    }

                    wcout << WDLCommand << "\n";

                    OTEditor.WorldData += WDLCommand;

                    OmegaTechEditor.DrawModel = false;
                }

            }

        EndMode3D();

        EndTextureMode();

        BeginDrawing();  
        DrawTexturePro(Target.texture, (Rectangle){ 0, 0, Target.texture.width, -Target.texture.height }, (Rectangle){ 0, 0, float(GetScreenWidth()), float(GetScreenHeight())}, (Vector2){ 0, 0 } , 0.f , WHITE);
        DrawFPS(10, 10);

        if (OverlayEnabled)DrawOverlay();

        EndDrawing();

        if (IsKeyPressed(KEY_F11))ToggleFullscreen();
        if (IsKeyPressed(KEY_TAB)){
            if (OverlayEnabled){
                OverlayEnabled = false;
                DisableCursor();
            }
            else {
                OverlayEnabled = true;
                EnableCursor();
            }
        }

    }
    
    CloseWindow();
}