#include "PPGIO.hpp"
#include <cstring>

class Editor{
    public:
        Camera3D MainCamera = {0}; 
        char Path[100];
        wstring WorldData;

};

static Editor OTEditor;

class GameModels
{
    public:
        Texture2D Skybox;
        
        Vector3 HeightMapPosition;

        // OBJ Models

        Model HeightMap;
        Texture2D HeightMapTexture;

        Model Model1;
        Texture2D Model1Texture;

        Model Model2;
        Texture2D Model2Texture;

        Model Model3;
        Texture2D Model3Texture;

        Model Model4;
        Texture2D Model4Texture;

        Model Model5;
        Texture2D Model5Texture;

        Model Model6;
        Texture2D Model6Texture;

        Model Model7;
        Texture2D Model7Texture;

        Model Model8;
        Texture2D Model8Texture;

        Model Model9;
        Texture2D Model9Texture;

        Model Model10;
        Texture2D Model10Texture;

        Model Model11;
        Texture2D Model11Texture;

        Model Model12;
        Texture2D Model12Texture;

        Model Model13;
        Texture2D Model13Texture;

        Model Model14;
        Texture2D Model14Texture;

        Model Model15;
        Texture2D Model15Texture;

        Model Model16;
        Texture2D Model16Texture;

        Model Model17;
        Texture2D Model17Texture;

        Model Model18;
        Texture2D Model18Texture;

        Model Model19;
        Texture2D Model19Texture;

        Model Model20;
        Texture2D Model20Texture;

        // GLTS Models

        // For Faster Rendering.

        Model FastModel1;
        Texture2D FastModel1Texture;
        Model FastModel2;
        Texture2D FastModel2Texture;
        Model FastModel3;
        Texture2D FastModel3Texture;
        Model FastModel4;
        Texture2D FastModel4Texture;
        Model FastModel5;
        Texture2D FastModel5Texture;
};

static GameModels WDLModels;

void Init(){
    OTEditor.MainCamera.position = (Vector3){ 18.0f, 10.0f, 18.0f };// Camera position perspective
    OTEditor.MainCamera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    OTEditor.MainCamera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    OTEditor.MainCamera.fovy = 60.0f;                               // Camera field-of-view Y
    OTEditor.MainCamera.projection = CAMERA_PERSPECTIVE;

    OTEditor.WorldData = LoadFile(TextFormat("%s/World.wdl", OTEditor.Path));



    if (IsPathFile(TextFormat("%s/Models/HeightMap.png", OTEditor.Path)))
    {
        WDLModels.HeightMapTexture = LoadTexture(TextFormat("%sModels/HeightMapTexture.png", OTEditor.Path));
        Image HeightMapImage = LoadImage(TextFormat("%sModels/HeightMap.png", OTEditor.Path));
        Texture2D Texture = LoadTextureFromImage(HeightMapImage);
        int X = PullConfigValue(TextFormat("%sModels/HeightMapConfig.conf", OTEditor.Path), 0);
        int Y = PullConfigValue(TextFormat("%sModels/HeightMapConfig.conf", OTEditor.Path), 1);
        int Z = PullConfigValue(TextFormat("%sModels/HeightMapConfig.conf", OTEditor.Path), 2);
        Mesh Mesh1 = GenMeshHeightmap(HeightMapImage, (Vector3){X, Y, Z});
        WDLModels.HeightMap = LoadModelFromMesh(Mesh1);
        WDLModels.HeightMap.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = WDLModels.HeightMapTexture;
        WDLModels.HeightMap.meshes[0] = Mesh1;
    }

    if (IsPathFile(TextFormat("%sModels/Model1.obj", OTEditor.Path)))
    {
        WDLModels.Model1 = LoadModel(TextFormat("%sModels/Model1.obj", OTEditor.Path));
        WDLModels.Model1Texture = LoadTexture(TextFormat("%sModels/Model1Texture.png", OTEditor.Path));
        WDLModels.Model1.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = WDLModels.Model1Texture;
    }

    if (IsPathFile(TextFormat("%sModels/Model2.obj", OTEditor.Path)))
    {
        WDLModels.Model2 = LoadModel(TextFormat("%sModels/Model2.obj", OTEditor.Path));
        WDLModels.Model2Texture = LoadTexture(TextFormat("%sModels/Model2Texture.png", OTEditor.Path));
        WDLModels.Model2.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = WDLModels.Model2Texture;

    }

    if (IsPathFile(TextFormat("%sModels/Model3.obj", OTEditor.Path)))
    {
        WDLModels.Model3 = LoadModel(TextFormat("%sModels/Model3.obj", OTEditor.Path));
        WDLModels.Model3Texture = LoadTexture(TextFormat("%sModels/Model3Texture.png", OTEditor.Path));
        WDLModels.Model3.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = WDLModels.Model3Texture;
    }

    if (IsPathFile(TextFormat("%sModels/Model4.obj", OTEditor.Path)))
    {
        WDLModels.Model4 = LoadModel(TextFormat("%sModels/Model4.obj", OTEditor.Path));
        WDLModels.Model4Texture = LoadTexture(TextFormat("%sModels/Model4Texture.png", OTEditor.Path));
        WDLModels.Model4.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = WDLModels.Model4Texture;
    }

    if (IsPathFile(TextFormat("%sModels/Model5.obj", OTEditor.Path)))
    {
        WDLModels.Model5 = LoadModel(TextFormat("%sModels/Model5.obj", OTEditor.Path));
        WDLModels.Model5Texture = LoadTexture(TextFormat("%sModels/Model5Texture.png", OTEditor.Path));
        WDLModels.Model5.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = WDLModels.Model5Texture;
    }

    if (IsPathFile(TextFormat("%sModels/Model6.obj", OTEditor.Path)))
    {
        WDLModels.Model6 = LoadModel(TextFormat("%sModels/Model6.obj", OTEditor.Path));
        WDLModels.Model6Texture = LoadTexture(TextFormat("%sModels/Model6Texture.png", OTEditor.Path));
        WDLModels.Model6.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = WDLModels.Model6Texture;
    }

    if (IsPathFile(TextFormat("%sModels/Model7.obj", OTEditor.Path)))
    {
        WDLModels.Model7 = LoadModel(TextFormat("%sModels/Model7.obj", OTEditor.Path));
        WDLModels.Model7Texture = LoadTexture(TextFormat("%sModels/Model7Texture.png", OTEditor.Path));
        WDLModels.Model7.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = WDLModels.Model7Texture;

    }

    if (IsPathFile(TextFormat("%sModels/Model8.obj", OTEditor.Path)))
    {
        WDLModels.Model8 = LoadModel(TextFormat("%sModels/Model8.obj", OTEditor.Path));
        WDLModels.Model8Texture = LoadTexture(TextFormat("%sModels/Model8Texture.png", OTEditor.Path));
        WDLModels.Model8.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = WDLModels.Model8Texture;
    }

    if (IsPathFile(TextFormat("%sModels/Model9.obj", OTEditor.Path)))
    {
        WDLModels.Model9 = LoadModel(TextFormat("%sModels/Model9.obj", OTEditor.Path));
        WDLModels.Model9Texture = LoadTexture(TextFormat("%sModels/Model9Texture.png", OTEditor.Path));
        WDLModels.Model9.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = WDLModels.Model9Texture;

    }

    if (IsPathFile(TextFormat("%sModels/Model10.obj", OTEditor.Path)))
    {
        WDLModels.Model10 = LoadModel(TextFormat("%sModels/Model10.obj", OTEditor.Path));
        WDLModels.Model10Texture = LoadTexture(TextFormat("%sModels/Model10Texture.png", OTEditor.Path));
        WDLModels.Model10.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = WDLModels.Model10Texture;

    }

    if (IsPathFile(TextFormat("%sModels/Model11.obj", OTEditor.Path)))
    {
        WDLModels.Model11 = LoadModel(TextFormat("%sModels/Model11.obj", OTEditor.Path));
        WDLModels.Model11Texture = LoadTexture(TextFormat("%sModels/Model11Texture.png", OTEditor.Path));
        WDLModels.Model11.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = WDLModels.Model11Texture;

    }

    if (IsPathFile(TextFormat("%sModels/Model12.obj", OTEditor.Path)))
    {
        WDLModels.Model12 = LoadModel(TextFormat("%sModels/Model12.obj", OTEditor.Path));
        WDLModels.Model12Texture = LoadTexture(TextFormat("%sModels/Model12Texture.png", OTEditor.Path));
        WDLModels.Model12.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = WDLModels.Model12Texture;
    }

    if (IsPathFile(TextFormat("%sModels/Model13.obj", OTEditor.Path)))
    {
        WDLModels.Model13 = LoadModel(TextFormat("%sModels/Model13.obj", OTEditor.Path));
        WDLModels.Model13Texture = LoadTexture(TextFormat("%sModels/Model13Texture.png", OTEditor.Path));
        WDLModels.Model13.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = WDLModels.Model13Texture;

    }

    if (IsPathFile(TextFormat("%sModels/Model14.obj", OTEditor.Path)))
    {
        WDLModels.Model14 = LoadModel(TextFormat("%sModels/Model14.obj", OTEditor.Path));
        WDLModels.Model14Texture = LoadTexture(TextFormat("%sModels/Model14Texture.png", OTEditor.Path));
        WDLModels.Model14.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = WDLModels.Model14Texture;
    }

    if (IsPathFile(TextFormat("%sModels/Model15.obj", OTEditor.Path)))
    {
        WDLModels.Model15 = LoadModel(TextFormat("%sModels/Model15.obj", OTEditor.Path));
        WDLModels.Model15Texture = LoadTexture(TextFormat("%sModels/Model15Texture.png", OTEditor.Path));
        WDLModels.Model15.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = WDLModels.Model15Texture;
    }

    if (IsPathFile(TextFormat("%sModels/Model16.obj", OTEditor.Path)))
    {
        WDLModels.Model16 = LoadModel(TextFormat("%sModels/Model16.obj", OTEditor.Path));
        WDLModels.Model16Texture = LoadTexture(TextFormat("%sModels/Model16Texture.png", OTEditor.Path));
        WDLModels.Model16.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = WDLModels.Model16Texture;
    }
    if (IsPathFile(TextFormat("%sModels/Model17.obj", OTEditor.Path)))
    {
        WDLModels.Model17 = LoadModel(TextFormat("%sModels/Model17.obj", OTEditor.Path));
        WDLModels.Model17Texture = LoadTexture(TextFormat("%sModels/Model17Texture.png", OTEditor.Path));
        WDLModels.Model17.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = WDLModels.Model17Texture;
    }
    if (IsPathFile(TextFormat("%sModels/Model18.obj", OTEditor.Path)))
    {
        WDLModels.Model18 = LoadModel(TextFormat("%sModels/Model18.obj", OTEditor.Path));
        WDLModels.Model18Texture = LoadTexture(TextFormat("%sModels/Model18Texture.png", OTEditor.Path));
        WDLModels.Model18.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = WDLModels.Model18Texture;
    }

    if (IsPathFile(TextFormat("%sModels/Model19.obj", OTEditor.Path)))
    {
        WDLModels.Model19 = LoadModel(TextFormat("%sModels/Model19.obj", OTEditor.Path));
        WDLModels.Model19Texture = LoadTexture(TextFormat("%sModels/Model19Texture.png", OTEditor.Path));
        WDLModels.Model19.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = WDLModels.Model19Texture;
    }

    if (IsPathFile(TextFormat("%sModels/Model20.obj", OTEditor.Path)))
    {
        WDLModels.Model20 = LoadModel(TextFormat("%sModels/Model20.obj", OTEditor.Path));
        WDLModels.Model20Texture = LoadTexture(TextFormat("%sModels/Model20Texture.png", OTEditor.Path));
        WDLModels.Model20.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = WDLModels.Model20Texture;
    }

}

static int ScriptTimer = 0;
static float X, Y, Z, S, Rotation, W, H, L;
bool NextCollision = false;

void WDLProcess()
{

    wstring WData = L"";
    int Size = 0;

    WData = OTEditor.WorldData;
    Size = GetWDLSize(OTEditor.WorldData, L"");
    

    bool Render = false;
    bool FoundPlatform = false;
    float PlatformHeight = 0.0f;

    for (int i = 0; i <= Size; i++)
    {
        wstring Instruction = WSplitValue(WData, i);

        if (Instruction == L"C")
        {
            NextCollision = true;
        }

        if (WReadValue(Instruction, 0, 4) == L"Model" || WReadValue(Instruction, 0, 1) == L"NE" || WReadValue(Instruction, 0, 6) == L"ClipBox" ||WReadValue(Instruction, 0, 5) == L"Object" || WReadValue(Instruction, 0, 5) == L"Script" || WReadValue(Instruction, 0, 8) == L"HeightMap" || WReadValue(Instruction, 0, 8) == L"Collision" || WReadValue(Instruction, 0, 11) == L"AdvCollision")
        {

            X = ToFloat(WSplitValue(WData, i + 1));
            Y = ToFloat(WSplitValue(WData, i + 2));
            Z = ToFloat(WSplitValue(WData, i + 3));
            S = ToFloat(WSplitValue(WData, i + 4));

            Rotation = ToFloat(WSplitValue(WData, i + 5));

            if (OTEditor.MainCamera.position.z - 1000 < Z && OTEditor.MainCamera.position.z + 1000 > Z)
            {
                if (OTEditor.MainCamera.position.x - 1000 < X && OTEditor.MainCamera.position.x + 1000 > X)
                {
                    Render = true;
                }
            }
        }

        if (Render)
        {
            if (WReadValue(Instruction, 0, 4) == L"Model")
            {
                int Identifier = ToFloat(WReadValue(Instruction, 5, 6));

                switch (Identifier)
                {
                case 1:
                    DrawModelEx(WDLModels.Model1, {X, Y, Z}, {0, Rotation, 0}, Rotation, {S, S, S}, WHITE);
                    break;
                case 2:
                    DrawModelEx(WDLModels.Model2, {X, Y, Z}, {0, Rotation, 0}, Rotation, {S, S, S}, WHITE);
                    break;
                case 3:
                    DrawModelEx(WDLModels.Model3, {X, Y, Z}, {0, Rotation, 0}, Rotation, {S, S, S}, WHITE);
                    break;
                case 4:
                    DrawModelEx(WDLModels.Model4, {X, Y, Z}, {0, Rotation, 0}, Rotation, {S, S, S}, WHITE);
                    break;
                case 5:
                    DrawModelEx(WDLModels.Model5, {X, Y, Z}, {0, Rotation, 0}, Rotation, {S, S, S}, WHITE);
                    break;
                case 6:
                    DrawModelEx(WDLModels.Model6, {X, Y, Z}, {0, Rotation, 0}, Rotation, {S, S, S}, WHITE);
                    break;
                case 7:
                    DrawModelEx(WDLModels.Model7, {X, Y, Z}, {0, Rotation, 0}, Rotation, {S, S, S}, WHITE);
                    break;
                case 8:
                    DrawModelEx(WDLModels.Model8, {X, Y, Z}, {0, Rotation, 0}, Rotation, {S, S, S}, WHITE);
                    break;
                case 9:
                    DrawModelEx(WDLModels.Model9, {X, Y, Z}, {0, Rotation, 0}, Rotation, {S, S, S}, WHITE);
                    break;
                case 10:
                    DrawModelEx(WDLModels.Model10, {X, Y, Z}, {0, Rotation, 0}, Rotation, {S, S, S}, WHITE);
                    break;
                case 11:
                    DrawModelEx(WDLModels.Model11, {X, Y, Z}, {0, Rotation, 0}, Rotation, {S, S, S}, WHITE);
                    break;
                case 12:
                    DrawModelEx(WDLModels.Model12, {X, Y, Z}, {0, Rotation, 0}, Rotation, {S, S, S}, WHITE);
                    break;
                case 13:
                    DrawModelEx(WDLModels.Model13, {X, Y, Z}, {0, Rotation, 0}, Rotation, {S, S, S}, WHITE);
                    break;
                case 14:
                    DrawModelEx(WDLModels.Model14, {X, Y, Z}, {0, Rotation, 0}, Rotation, {S, S, S}, WHITE);
                    break;
                case 15:
                    DrawModelEx(WDLModels.Model15, {X, Y, Z}, {0, Rotation, 0}, Rotation, {S, S, S}, WHITE);
                    break;
                case 16:
                    DrawModelEx(WDLModels.Model16, {X, Y, Z}, {0, Rotation, 0}, Rotation, {S, S, S}, WHITE);
                    break;
                case 17:
                    DrawModelEx(WDLModels.Model17, {X, Y, Z}, {0, Rotation, 0}, Rotation, {S, S, S}, WHITE);
                    break;
                case 18:
                    DrawModelEx(WDLModels.Model18, {X, Y, Z}, {0, Rotation, 0}, Rotation, {S, S, S}, WHITE);
                    break;
                case 19:
                    DrawModelEx(WDLModels.Model19, {X, Y, Z}, {0, Rotation, 0}, Rotation, {S, S, S}, WHITE);
                    break;
                case 20:
                    DrawModelEx(WDLModels.Model20, {X, Y, Z}, {0, Rotation, 0}, Rotation, {S, S, S}, WHITE);
                    break;
                default:
                    break;
                }
            }

            if (Instruction == L"Collision")
            {
                DrawCubeWires({X, Y, Z}, S, S, S, RED);
            }

            if (WReadValue(Instruction, 0, 5) == L"Script")
            {

                DrawCubeWires({X, Y, Z}, S, S, S, YELLOW);

            }
        }
        if (Instruction == L"ClipBox")
        { 

            W = ToFloat(WSplitValue(WData, i + 6));
            H = ToFloat(WSplitValue(WData, i + 7));
            L = ToFloat(WSplitValue(WData, i + 8));

            DrawBoundingBox((BoundingBox){(Vector3){X, Y, Z}, (Vector3){W, H  - 5, L}}, PURPLE);
            

            i += 3;
        }
        if (Instruction == L"AdvCollision")
        { // Collision

            if (Render)
            {
                W = ToFloat(WSplitValue(WData, i + 6));
                H = ToFloat(WSplitValue(WData, i + 7));
                L = ToFloat(WSplitValue(WData, i + 8));

                DrawBoundingBox((BoundingBox){(Vector3){X, Y, Z}, (Vector3){W, H, L}}, PURPLE);

            }

            i += 3;
        }

        if (Instruction == L"HeightMap")
        {
            WDLModels.HeightMapPosition.x = X;
            WDLModels.HeightMapPosition.y = Y;
            WDLModels.HeightMapPosition.z = Z;
            DrawModel(WDLModels.HeightMap, {X, Y, Z}, S, WHITE);
        }

        if (!NextCollision)
        {
            i += 5;
        }

        Render = false;
    }
}

class InEditor{
    public:
        bool DrawModel = false;
        int ModelID = 1;
        float X = 0;
        float Y = 0;
        float Z = 0;
        float S = 1;
        float R = 0;
        
        float L = 0;
        float H = 0;
        float W = 0;

};

static InEditor OmegaTechEditor;

bool OverlayEnabled = false;

bool WindowBox000Active = true;
bool Button001Pressed = false;
bool Button002Pressed = false;
bool Button003Pressed = false;
bool Button004Pressed = false;
bool Button005Pressed = false;
bool Button006Pressed = false;
bool Button007Pressed = false;
bool Button008Pressed = false;
bool Button009Pressed = false;
bool Button010Pressed = false;
bool Button011Pressed = false;
bool Button012Pressed = false;
bool Button013Pressed = false;
bool Button014Pressed = false;
bool Button015Pressed = false;
bool Button016Pressed = false;
bool Button017Pressed = false;
bool Button018Pressed = false;
bool Button019Pressed = false;
bool Button020Pressed = false;
bool WindowBox022Active = true;
bool Button023Pressed = false;
bool Button024Pressed = false;
bool Button025Pressed = false;
bool Button026Pressed = false;
bool Button027Pressed = false;
bool WindowBox028Active = true;
bool WindowBox029Active = true;
bool Button030Pressed = false;
bool Button031Pressed = false;
bool Button032Pressed = false;
bool Button033Pressed = false;
bool Button034Pressed = false;
bool Button035Pressed = false;
bool Button036Pressed = false;
bool Button037Pressed = false;
bool Button038Pressed = false;
bool Button039Pressed = false;
bool Button040Pressed = false;
bool WindowBox041Active = true;
bool Button042Pressed = false;
bool Button043Pressed = false;
bool Button044Pressed = false;
bool Toggle045Active = true;

void DrawOverlay(){
    if (WindowBox000Active)
    {
        WindowBox000Active = !GuiWindowBox((Rectangle){ 0, 0, 144, 720 }, "Model Menu");
        if (GuiButton((Rectangle){ 8, 32, 120, 24 }, "Model 1"))OmegaTechEditor.ModelID = 1;
        if (GuiButton((Rectangle){ 8, 64, 120, 24 }, "Model 2"))OmegaTechEditor.ModelID = 2;
        if (GuiButton((Rectangle){ 8, 96, 120, 24 }, "Model 3"))OmegaTechEditor.ModelID = 3;
        if (GuiButton((Rectangle){ 8, 128, 120, 24 }, "Model 4"))OmegaTechEditor.ModelID = 4;
        if (GuiButton((Rectangle){ 8, 160, 120, 24 }, "Model 5"))OmegaTechEditor.ModelID = 5;
        if (GuiButton((Rectangle){ 8, 192, 120, 24 }, "Model 6"))OmegaTechEditor.ModelID = 6;
        if (GuiButton((Rectangle){ 8, 224, 120, 24 }, "Model 7"))OmegaTechEditor.ModelID = 7;
        if (GuiButton((Rectangle){ 8, 256, 120, 24 }, "Model 8"))OmegaTechEditor.ModelID = 8;
        if (GuiButton((Rectangle){ 8, 288, 120, 24 }, "Model 9"))OmegaTechEditor.ModelID = 9;
        if (GuiButton((Rectangle){ 8, 320, 120, 24 }, "Model 10"))OmegaTechEditor.ModelID = 10;
        if (GuiButton((Rectangle){ 8, 352, 120, 24 }, "Model 11"))OmegaTechEditor.ModelID = 11;
        if (GuiButton((Rectangle){ 8, 384, 120, 24 }, "Model 12"))OmegaTechEditor.ModelID = 12;
        if (GuiButton((Rectangle){ 8, 416, 120, 24 }, "Model 13"))OmegaTechEditor.ModelID = 13;
        if (GuiButton((Rectangle){ 8, 448, 120, 24 }, "Model 14"))OmegaTechEditor.ModelID = 14;
        if (GuiButton((Rectangle){ 8, 480, 120, 24 }, "Model 15"))OmegaTechEditor.ModelID = 15;
        if (GuiButton((Rectangle){ 8, 512, 120, 24 }, "Model 16"))OmegaTechEditor.ModelID = 16;
        if (GuiButton((Rectangle){ 8, 544, 120, 24 }, "Model 17"))OmegaTechEditor.ModelID = 17;
        if (GuiButton((Rectangle){ 8, 576, 120, 24 }, "Model 18"))OmegaTechEditor.ModelID = 18;
        if (GuiButton((Rectangle){ 8, 608, 120, 24 }, "Model 19"))OmegaTechEditor.ModelID = 19;
        if (GuiButton((Rectangle){ 8, 640, 120, 24 }, "Model 20"))OmegaTechEditor.ModelID = 20;
        GuiLine((Rectangle){ 8, 664, 120, 24 }, NULL);

        if (IsMouseButtonPressed(0) && GetCollision( 0, 0, 144, 720 , GetMouseX(), GetMouseY() , 5 , 5) || IsMouseButtonPressed(0) && GetCollision( 912 + 184, 232, 184, 304 , GetMouseX(), GetMouseY() , 5 , 5)){
            OmegaTechEditor.DrawModel = true;

            OmegaTechEditor.X = OTEditor.MainCamera.position.x;
            OmegaTechEditor.Y = OTEditor.MainCamera.position.y;
            OmegaTechEditor.Z = OTEditor.MainCamera.position.z;
            OmegaTechEditor.R = 1;

            OverlayEnabled = false;
            DisableCursor();
        }
    }

    if (WindowBox022Active)
    {
        WindowBox022Active = !GuiWindowBox((Rectangle){ 144, 624, 408, 96 }, "Actions");
        if (GuiButton((Rectangle){ 152, 672, 80, 32 }, "Undo")){
            OTEditor.WorldData = LoadFile(TextFormat("%s/World.wdl", OTEditor.Path));
        }
        if (GuiButton((Rectangle){ 240, 672, 64, 32 }, "Save")){
            wofstream Outfile;
            Outfile.open(TextFormat("%s/World.wdl", OTEditor.Path));
            Outfile << OTEditor.WorldData << "\n";
        } 
        if (GuiButton((Rectangle){ 336, 672, 112, 32 }, "Reset Camera")) OTEditor.MainCamera.position = {0 , 10 , 0}; 
        if (GuiButton((Rectangle){ 456, 672, 40, 32 }, "UP")) OTEditor.MainCamera.position.y += 2;
        if (GuiButton((Rectangle){ 496, 672, 48, 32 }, "DOWN")) OTEditor.MainCamera.position.y -= 2;
    }        
    if (WindowBox028Active)
    {
        WindowBox028Active = !GuiWindowBox((Rectangle){ 912 + 184, 232, 184, 304 }, "Script Menu");
        if (GuiButton((Rectangle){ 944+ 184, 264, 120, 24 }, "Script 1"))OmegaTechEditor.ModelID = 101;
        if (GuiButton((Rectangle){ 944+ 184, 288, 120, 24 }, "Script 2"))OmegaTechEditor.ModelID = 102;
        if (GuiButton((Rectangle){ 944+ 184, 312, 120, 24 }, "Script 3"))OmegaTechEditor.ModelID = 103;
        if (GuiButton((Rectangle){ 944+ 184, 336, 120, 24 }, "Script 4"))OmegaTechEditor.ModelID = 104;
        if (GuiButton((Rectangle){ 944+ 184, 360, 120, 24 }, "Script 5"))OmegaTechEditor.ModelID = 105;
        if (GuiButton((Rectangle){ 944+ 184, 384, 120, 24 }, "Script 6"))OmegaTechEditor.ModelID = 106;
        if (GuiButton((Rectangle){ 944+ 184, 408, 120, 24 }, "Script 7"))OmegaTechEditor.ModelID = 107;
        if (GuiButton((Rectangle){ 944+ 184, 432, 120, 24 }, "Script 8"))OmegaTechEditor.ModelID = 108;
        if (GuiButton((Rectangle){ 944+ 184, 456, 120, 24 }, "Script 9"))OmegaTechEditor.ModelID = 109;
        if (GuiButton((Rectangle){ 944+ 184, 480, 120, 24 }, "Script 10"))OmegaTechEditor.ModelID = 110;
        if (GuiButton((Rectangle){ 944+ 184, 504, 120, 24 }, "Launch Script"));
    }
    if (WindowBox029Active)
    {
        WindowBox029Active = !GuiWindowBox((Rectangle){ 744+ 184, 552, 352, 168 }, "Script Editor");
    }
    if (WindowBox041Active)
    {
        WindowBox041Active = !GuiWindowBox((Rectangle){ 912+ 184, 24, 184, 192 }, "Collisions Menu");
        if (GuiButton((Rectangle){ 944+ 184, 56, 120, 24 }, "Box Collision")){
            OmegaTechEditor.ModelID = 100;
            OmegaTechEditor.X = OTEditor.MainCamera.position.x;
            OmegaTechEditor.Y = OTEditor.MainCamera.position.y;
            OmegaTechEditor.Z = OTEditor.MainCamera.position.z;
            OmegaTechEditor.R = 1;
        }
        if (GuiButton((Rectangle){ 944+ 184, 88, 120, 24 }, "Adv Collision")){
            OmegaTechEditor.ModelID = -1;
            OmegaTechEditor.W = OTEditor.MainCamera.position.x + 5;
            OmegaTechEditor.H = OTEditor.MainCamera.position.y + 5;
            OmegaTechEditor.L = OTEditor.MainCamera.position.z + 5;
            OmegaTechEditor.X = OTEditor.MainCamera.position.x;
            OmegaTechEditor.Y = OTEditor.MainCamera.position.y;
            OmegaTechEditor.Z = OTEditor.MainCamera.position.z;
            OmegaTechEditor.R = 1;
        } 
        if (GuiButton((Rectangle){ 944+ 184, 120, 120, 24 }, "Height Clip Box")){
            OmegaTechEditor.ModelID = -2;
            OmegaTechEditor.W = OTEditor.MainCamera.position.x + 5;
            OmegaTechEditor.H = OTEditor.MainCamera.position.y + 5;
            OmegaTechEditor.L = OTEditor.MainCamera.position.z + 5;
            OmegaTechEditor.X = OTEditor.MainCamera.position.x;
            OmegaTechEditor.Y = OTEditor.MainCamera.position.y;
            OmegaTechEditor.Z = OTEditor.MainCamera.position.z;
            OmegaTechEditor.R = 1;
        } 

        Toggle045Active = GuiToggle((Rectangle){ 920+ 184, 176, 160, 32 }, "Selected Model Col", Toggle045Active);
    }

}