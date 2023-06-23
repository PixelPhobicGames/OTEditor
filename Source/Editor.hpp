#include "PPGIO.hpp"
#include <cstring>

#define MaxCachedModels 200

RenderTexture2D Target;
RenderTexture2D PreviewTarget;
Model CurrentModel;

class Editor{
    public:
        Camera3D MainCamera = {0}; 
        Camera3D PreviewCamera = {0}; 
        char Path[100];
        wstring WorldData;
        wstring OtherData;

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

class GameData{
    public:
        float X;
        float Y;
        float Z;
        float R;
        float S;
        int ModelId;
        bool Collision;

        void Init(){
            X = 0;
            Y = 0;
            Z = 0;
            R = 0;
            S = 0;
            ModelId = 0;
            Collision = false;
        }

};

static int CachedModelCounter = 0;
static GameData CachedModels[MaxCachedModels];

class CollisionData{
    public:
        float X;
        float Y;
        float Z;
        float W;
        float H;
        float L;

        void Init(){
            X = 0;
            Y = 0;
            Z = 0;
            W = 0;
            H = 0;
            L = 0;
        }

};

static int CachedCollisionCounter = 0;
static CollisionData CachedCollision[MaxCachedModels];

void Init(){
    OTEditor.MainCamera.position = (Vector3){ 18.0f, 10.0f, 18.0f };
    OTEditor.MainCamera.target = (Vector3){ 0.0f, 10.0f, 0.0f };   
    OTEditor.MainCamera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          
    OTEditor.MainCamera.fovy = 60.0f;                         
    OTEditor.MainCamera.projection = CAMERA_PERSPECTIVE;

    OTEditor.PreviewCamera.position = (Vector3){ 5.0f, 4.0f, 5.0f };  
    OTEditor.PreviewCamera.target = (Vector3){ 0.0f, 0.0f, 0.0f };    
    OTEditor.PreviewCamera.up = (Vector3){ 0.0f, 1.0f, 0.0f };         
    OTEditor.PreviewCamera.fovy = 45.0f;                                
    OTEditor.PreviewCamera.projection = CAMERA_PERSPECTIVE;         

    OTEditor.WorldData = LoadFile(TextFormat("%s/World.wdl", OTEditor.Path));

    Target = LoadRenderTexture(320 , 200);
    PreviewTarget = LoadRenderTexture(256 , 256);



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

void CacheWDL()
{
    wstring WData = OTEditor.WorldData;

    OTEditor.OtherData = L"";

    CachedModelCounter = 0;
    CachedCollisionCounter = 0;

    bool NextCollision = false;

    for (int i = 0; i <= MaxCachedModels - 1; i++)
    {
        CachedModels[i].Init();
        CachedCollision[i].Init();
    }

    for (int i = 0; i <= GetWDLSize(OTEditor.WorldData, L""); i++)
    {

        if (CachedModelCounter == MaxCachedModels)
            break;

        wstring Instruction = WSplitValue(WData, i);

        if (WReadValue(Instruction, 0, 4) == L"Model" || WReadValue(Instruction, 0, 8) == L"HeightMap")
        {
            if (WReadValue(Instruction, 0, 8) != L"HeightMap")
            {
                CachedModels[CachedModelCounter].ModelId = int(ToFloat(WReadValue(Instruction, 5, 6)));
            }
            else
            {
                CachedModels[CachedModelCounter].ModelId = -1;
            }
            
            CachedModels[CachedModelCounter].X = ToFloat(WSplitValue(WData, i + 1));
            CachedModels[CachedModelCounter].Y = ToFloat(WSplitValue(WData, i + 2));
            CachedModels[CachedModelCounter].Z = ToFloat(WSplitValue(WData, i + 3));
            CachedModels[CachedModelCounter].S = ToFloat(WSplitValue(WData, i + 4));
            CachedModels[CachedModelCounter].R = ToFloat(WSplitValue(WData, i + 5));

            if (NextCollision)
            {
                CachedModels[CachedModelCounter].Collision = true;
                NextCollision = false;
            }

            CachedModelCounter++;
        }

        if (WReadValue(Instruction, 0, 8) == L"Collision")
        {
            CachedModels[CachedModelCounter].ModelId = -2;
            CachedModels[CachedModelCounter].X = ToFloat(WSplitValue(WData, i + 1));
            CachedModels[CachedModelCounter].Y = ToFloat(WSplitValue(WData, i + 2));
            CachedModels[CachedModelCounter].Z = ToFloat(WSplitValue(WData, i + 3));
            CachedModels[CachedModelCounter].S = ToFloat(WSplitValue(WData, i + 4));
            CachedModels[CachedModelCounter].R = ToFloat(WSplitValue(WData, i + 5));
        }

        if (WReadValue(Instruction, 0, 11) == L"AdvCollision")
        {
            CachedCollision[CachedCollisionCounter].X =  ToFloat(WSplitValue(WData, i + 1));
            CachedCollision[CachedCollisionCounter].Y =  ToFloat(WSplitValue(WData, i + 2));
            CachedCollision[CachedCollisionCounter].Z =  ToFloat(WSplitValue(WData, i + 3));
            CachedCollision[CachedCollisionCounter].W =  ToFloat(WSplitValue(WData, i + 6));
            CachedCollision[CachedCollisionCounter].H =  ToFloat(WSplitValue(WData, i + 7));
            CachedCollision[CachedCollisionCounter].L =  ToFloat(WSplitValue(WData, i + 8));
            CachedCollisionCounter ++;
        }

        if (WReadValue(Instruction, 0, 5) == L"Object" || WReadValue(Instruction, 0, 5) == L"Script") // Dont Cache Dynamic Objs
        {
            OTEditor.OtherData += WSplitValue(WData, i) + L":" + WSplitValue(WData, i + 1) + L":" + WSplitValue(WData, i + 2) + L":" + WSplitValue(WData, i + 3) + L":" + WSplitValue(WData, i + 4) + L":" + WSplitValue(WData, i + 5) + L":";
        }

        if (Instruction == L"C")
        {
            NextCollision = true;
        }
    }
}

void CWDLProcess()
{
    for (int i = 0; i <= CachedCollisionCounter; i++)
    {
        X = CachedCollision[i].X;
        Y = CachedCollision[i].Y;
        Z = CachedCollision[i].Z;
        W = CachedCollision[i].W;
        H = CachedCollision[i].H;
        L = CachedCollision[i].L;
        DrawBoundingBox((BoundingBox){(Vector3){X, Y, Z}, (Vector3){W, H, L}}, PURPLE);
    }
    
    for (int i = 0; i <= CachedModelCounter; i++)
    {
        X = CachedModels[i].X;
        Y = CachedModels[i].Y;
        Z = CachedModels[i].Z;
        S = CachedModels[i].S;
        Rotation = CachedModels[i].R;

        if (CachedModels[i].Collision){
            DrawCubeWires({X, Y, Z}, S, S, S, RED);
        }

        if (OTEditor.MainCamera.position.z - 1000 < Z && OTEditor.MainCamera.position.z + 1000 > Z)
        {
            if (OTEditor.MainCamera.position.x - 1000 < X && OTEditor.MainCamera.position.x + 1000 > X)
            {

                switch (CachedModels[i].ModelId)
                {
                case -2:
                    DrawCubeWires({X, Y, Z}, S, S, S, RED);
                    break;
                case -1:
                    DrawModelEx(WDLModels.HeightMap, {X, Y, Z}, {0, Rotation, 0}, Rotation, {S, S, S}, WHITE);
                    break;
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
        }
    }
}

void WDLProcess()
{

    wstring WData = L"";
    int Size = 0;

    WData = OTEditor.OtherData;
    Size = GetWDLSize(OTEditor.OtherData , L"");

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

char ScriptEditorBuffer[1200];


void ConvertConstCharToCharArray(const char* constString, char* charArray, int arraySize) {
    std::strncpy(charArray, constString, arraySize - 1);
    charArray[arraySize - 1] = '\0';
}

void LoadEditor(const char* File){
    ifstream file(File);

    string fileContents;
    string line;

    while (getline(file, line)) {
        fileContents += line + "\n";
    }

    file.close();

    ConvertConstCharToCharArray(fileContents.c_str() , ScriptEditorBuffer , 1200);
}

int EMID = 1;

bool OverlayEnabled = false;

bool CollisionToggle = false;

bool TextmultiBox005EditMode = false;
char TextmultiBox005Text[128] = "Tab - Opens Overlay Shift - Places Last Model U / J - Model X Control H / K - Model Z Control Y / I - Model Y Control";
bool TextmultiBox006EditMode = false;
char TextmultiBox006Text[128] = "T / G - Model Scale Control O / L - Model Rotation  Double Click / R Enter - Place";
bool TextmultiBox007EditMode = false;
char TextmultiBox007Text[128] = "Hold Right Click - Left / Right - X Up / Down - Y Scroll - Z";
bool TextmultiBox008EditMode = false;
char TextmultiBox008Text[128] = "Hold Left Click - Left / Right - W Up / Down - H Scroll - L";

auto DrawOverlay(){

    if (IsKeyDown(KEY_H)){
        GuiWindowBox((Rectangle){ 288, 72, 672, 384 }, "Help");
        GuiLabel((Rectangle){ 312, 112, 152, 24 }, "OmegaTech Editor v.1.0");
        GuiLine((Rectangle){ 312, 136, 624, 24 }, NULL);
        GuiLabel((Rectangle){ 872, 112, 120, 24 }, "EC");
        GuiLabel((Rectangle){ 320, 160, 120, 24 }, "Editor Controls");
        if (GuiTextBox((Rectangle){ 320, 192, 184, 112 }, TextmultiBox005Text, 128, TextmultiBox005EditMode)) TextmultiBox005EditMode = !TextmultiBox005EditMode;
        if (GuiTextBox((Rectangle){ 320, 304, 192, 88 }, TextmultiBox006Text, 128, TextmultiBox006EditMode)) TextmultiBox006EditMode = !TextmultiBox006EditMode;
        if (GuiTextBox((Rectangle){ 520, 192, 168, 112 }, TextmultiBox007Text, 128, TextmultiBox007EditMode)) TextmultiBox007EditMode = !TextmultiBox007EditMode;
        if (GuiTextBox((Rectangle){ 520, 304, 168, 88 }, TextmultiBox008Text, 128, TextmultiBox008EditMode)) TextmultiBox008EditMode = !TextmultiBox008EditMode;
        GuiLabel((Rectangle){ 696, 240, 120, 24 }, "Models - Scripts");
        GuiLabel((Rectangle){ 696, 336, 120, 24 }, "Collisions - ClipBox");
    }
    GuiWindowBox((Rectangle){ 0, 0, 144, 720 }, "Model Menu");
    if (GuiButton((Rectangle){ 8, 32, 120, 24 }, "Model 1")){EMID = 1;        }
    if (GuiButton((Rectangle){ 8, 64, 120, 24 }, "Model 2")){EMID = 2;        }
    if (GuiButton((Rectangle){ 8, 96, 120, 24 }, "Model 3")){EMID = 3;        }
    if (GuiButton((Rectangle){ 8, 128, 120, 24 }, "Model 4")){EMID = 4;        }
    if (GuiButton((Rectangle){ 8, 160, 120, 24 }, "Model 5")){EMID = 5;        }
    if (GuiButton((Rectangle){ 8, 192, 120, 24 }, "Model 6")){EMID = 6;        }
    if (GuiButton((Rectangle){ 8, 224, 120, 24 }, "Model 7")){EMID = 7;        }
    if (GuiButton((Rectangle){ 8, 256, 120, 24 }, "Model 8")){EMID = 8;        }
    if (GuiButton((Rectangle){ 8, 288, 120, 24 }, "Model 9")){EMID = 9;        }
    if (GuiButton((Rectangle){ 8, 320, 120, 24 }, "Model 10")){EMID = 10;        }
    if (GuiButton((Rectangle){ 8, 352, 120, 24 }, "Model 11")){EMID = 11;        }
    if (GuiButton((Rectangle){ 8, 384, 120, 24 }, "Model 12")){EMID = 12;        }
    if (GuiButton((Rectangle){ 8, 416, 120, 24 }, "Model 13")){EMID = 13;        }
    if (GuiButton((Rectangle){ 8, 448, 120, 24 }, "Model 14")){EMID = 14;        }
    if (GuiButton((Rectangle){ 8, 480, 120, 24 }, "Model 15")){EMID = 15;        }
    if (GuiButton((Rectangle){ 8, 512, 120, 24 }, "Model 16")){EMID = 16;        }
    if (GuiButton((Rectangle){ 8, 544, 120, 24 }, "Model 17")){EMID = 17;        }
    if (GuiButton((Rectangle){ 8, 576, 120, 24 }, "Model 18")){EMID = 18;        }
    if (GuiButton((Rectangle){ 8, 608, 120, 24 }, "Model 19")){EMID = 19;        }
    if (GuiButton((Rectangle){ 8, 640, 120, 24 }, "Model 20")){EMID = 20;        }
    GuiLine((Rectangle){ 8, 664, 120, 24 }, NULL);

    
    GuiWindowBox((Rectangle){ 144, 624, 408, 96 }, "Actions");
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
        
    GuiWindowBox((Rectangle){ 912 + 184, 232, 184, 304 }, "Scripts");

    if (GuiButton((Rectangle){ 944+ 184, 264, 120, 24 }, "Script 1")){EMID = 101;LoadEditor(TextFormat("%s/Scripts/Script1.ps", OTEditor.Path));}
    if (GuiButton((Rectangle){ 944+ 184, 288, 120, 24 }, "Script 2")){EMID = 102;LoadEditor(TextFormat("%s/Scripts/Script2.ps", OTEditor.Path));}
    if (GuiButton((Rectangle){ 944+ 184, 312, 120, 24 }, "Script 3")){EMID = 103;LoadEditor(TextFormat("%s/Scripts/Script3.ps", OTEditor.Path));}
    if (GuiButton((Rectangle){ 944+ 184, 336, 120, 24 }, "Script 4")){EMID = 104;LoadEditor(TextFormat("%s/Scripts/Script4.ps", OTEditor.Path));}
    if (GuiButton((Rectangle){ 944+ 184, 360, 120, 24 }, "Script 5")){EMID = 105;LoadEditor(TextFormat("%s/Scripts/Script5.ps", OTEditor.Path));}
    if (GuiButton((Rectangle){ 944+ 184, 384, 120, 24 }, "Script 6")){EMID = 106;LoadEditor(TextFormat("%s/Scripts/Script6.ps", OTEditor.Path));}
    if (GuiButton((Rectangle){ 944+ 184, 408, 120, 24 }, "Script 7")){EMID = 107;LoadEditor(TextFormat("%s/Scripts/Script7.ps", OTEditor.Path));}
    if (GuiButton((Rectangle){ 944+ 184, 432, 120, 24 }, "Script 8")){EMID = 108;LoadEditor(TextFormat("%s/Scripts/Script8.ps", OTEditor.Path));}
    if (GuiButton((Rectangle){ 944+ 184, 456, 120, 24 }, "Script 9")){EMID = 109;LoadEditor(TextFormat("%s/Scripts/Script9.ps", OTEditor.Path));}
    if (GuiButton((Rectangle){ 944+ 184, 480, 120, 24 }, "Script 10")){EMID = 110;LoadEditor(TextFormat("%s/Scripts/Script10.ps", OTEditor.Path));}

    if (GuiButton((Rectangle){ 944+ 184, 504, 120, 24 }, "Launch Script"))LoadEditor(TextFormat("%s/Scripts/Launch.ps", OTEditor.Path));
    
    if(GetCollision( 912 + 184, 232, 184, 304 , GetMouseX(), GetMouseY() , 5 , 5)){
        GuiWindowBox((Rectangle){ 600, 50, 352, 500 }, "Script Preview");
        GuiTextBox((Rectangle){ 600, 50 + 20, 352, 500 }, ScriptEditorBuffer, sizeof(ScriptEditorBuffer), 1);

        DrawLine( GetMouseX(), GetMouseY(), 600 + 352, 570, RED);
    }
    
        GuiWindowBox((Rectangle){ 912+ 184, 24, 184, 192 }, "Collisions Menu");
        if (GuiButton((Rectangle){ 944+ 184, 56, 120, 24 }, "Box Collision")){
            EMID = 100;
            OmegaTechEditor.X = OTEditor.MainCamera.position.x;
            OmegaTechEditor.Y = OTEditor.MainCamera.position.y;
            OmegaTechEditor.Z = OTEditor.MainCamera.position.z;
            OmegaTechEditor.R = 1;
        }
        if (GuiButton((Rectangle){ 944+ 184, 88, 120, 24 }, "Adv Collision")){
            EMID = -1;
            OmegaTechEditor.W = OTEditor.MainCamera.position.x + 5;
            OmegaTechEditor.H = OTEditor.MainCamera.position.y + 5;
            OmegaTechEditor.L = OTEditor.MainCamera.position.z + 5;
            OmegaTechEditor.X = OTEditor.MainCamera.position.x;
            OmegaTechEditor.Y = OTEditor.MainCamera.position.y;
            OmegaTechEditor.Z = OTEditor.MainCamera.position.z;
            OmegaTechEditor.R = 1;
        } 
        if (GuiButton((Rectangle){ 944+ 184, 120, 120, 24 }, "Height Clip Box")){
            EMID = -2;
            OmegaTechEditor.W = OTEditor.MainCamera.position.x + 5;
            OmegaTechEditor.H = OTEditor.MainCamera.position.y + 5;
            OmegaTechEditor.L = OTEditor.MainCamera.position.z + 5;
            OmegaTechEditor.X = OTEditor.MainCamera.position.x;
            OmegaTechEditor.Y = OTEditor.MainCamera.position.y;
            OmegaTechEditor.Z = OTEditor.MainCamera.position.z;
            OmegaTechEditor.R = 1;
        } 

        CollisionToggle = GuiToggle((Rectangle){ 920+ 184, 176, 160, 32 }, "Selected Model Col", CollisionToggle);
    

    if (IsMouseButtonPressed(0) && GetCollision( 0, 0, 144, 720 , GetMouseX(), GetMouseY() , 5 , 5) || IsMouseButtonPressed(0) && GetCollision( 912 + 184, 232, 184, 304 , GetMouseX(), GetMouseY() , 5 , 5)){
        OmegaTechEditor.DrawModel = true;
        OmegaTechEditor.X = OTEditor.MainCamera.position.x;
        OmegaTechEditor.Y = OTEditor.MainCamera.position.y;
        OmegaTechEditor.Z = OTEditor.MainCamera.position.z;
        OmegaTechEditor.R = 1;
    }

    if (IsMouseButtonPressed(0) && GetCollision( 912+ 184, 24, 184, 192, GetMouseX(), GetMouseY() , 5 , 5)){
        OmegaTechEditor.DrawModel = true;

        OmegaTechEditor.W = OTEditor.MainCamera.position.x + 5;
        OmegaTechEditor.H = OTEditor.MainCamera.position.y + 5;
        OmegaTechEditor.L = OTEditor.MainCamera.position.z + 5;

        OmegaTechEditor.X = OTEditor.MainCamera.position.x;
        OmegaTechEditor.Y = OTEditor.MainCamera.position.y;
        OmegaTechEditor.Z = OTEditor.MainCamera.position.z;
        
        OmegaTechEditor.R = 1;
    }
}

int PreviewEMID = 0;

void RenderPreview(){
    DrawLine(288, 200 , GetMouseX(), GetMouseY() , WHITE);
    BeginTextureMode(PreviewTarget);
    ClearBackground(BLACK);
    UpdateCamera(&OTEditor.PreviewCamera, CAMERA_ORBITAL);
    BeginMode3D(OTEditor.PreviewCamera);

    DrawGrid(10, 1.0f);  

    PreviewEMID = int((GetMouseY() - 32) / 32);

    switch (PreviewEMID){
        case 1:
            CurrentModel = WDLModels.Model1;
            break;
        case 2:
            CurrentModel = WDLModels.Model2;
            break;
        case 3:
            CurrentModel = WDLModels.Model3;
            break;
        case 4:
            CurrentModel = WDLModels.Model4;
            break;
        case 5:
            CurrentModel = WDLModels.Model5;
            break;
        case 6:
            CurrentModel = WDLModels.Model6;
            break;
        case 7:
            CurrentModel = WDLModels.Model7;
            break;
        case 8:
            CurrentModel = WDLModels.Model8;
            break;
        case 9:
            CurrentModel = WDLModels.Model9;
            break;
        case 10:
            CurrentModel = WDLModels.Model10;
            break;
        case 11:
            CurrentModel = WDLModels.Model11;
            break;
        case 12:
            CurrentModel = WDLModels.Model12;
            break;
        case 13:
            CurrentModel = WDLModels.Model13;
            break;
        case 14:
            CurrentModel = WDLModels.Model14;
            break;
        case 15:
            CurrentModel = WDLModels.Model15;
            break;
        case 16:
            CurrentModel = WDLModels.Model16;
            break;
        case 17:
            CurrentModel = WDLModels.Model17;
            break;
        case 18:
            CurrentModel = WDLModels.Model18;
            break;
        case 19:
            CurrentModel = WDLModels.Model19;
            break;
        case 20:
            CurrentModel = WDLModels.Model20;
            break;
        default:
            break;
    }
    DrawModelEx(CurrentModel, {0 , 0 , 0}, {0, 0, 0}, 0, {1,1,1}, WHITE);
    DrawLine3D({0 , 0 , 0}, {3 , 0 , 0}, RED); 
    DrawLine3D({0 , 0 , 0}, {0 , 3, 0}, BLUE); 
    DrawLine3D({0 , 0 , 0}, {0 , 0 , 3}, GREEN); 

    EndMode3D();

    EndTextureMode();
    DrawTextureRec(PreviewTarget.texture , {0, 0, 256 , -256}, {288, 200}, WHITE);
    DrawRectangleLines(288, 200 , 256 , 256, WHITE);
    if(CurrentModel.meshes != NULL){
        DrawText(TextFormat("Triangles:%i" , CurrentModel.meshes[0].triangleCount), 288 , 456 , 15 , WHITE);
        DrawText(TextFormat("Model ID:%i" , PreviewEMID), 288 , 456 + 15, 15 , WHITE);
        if (CurrentModel.meshes[0].triangleCount > 2000){
            DrawText("Very Low Preformance", 288 , 456 + 30, 15 , DARKBLUE);
        }
        else if (CurrentModel.meshes[0].triangleCount > 1000){
            DrawText("Low Preformance", 288 , 456 + 30, 15 , BLUE);
        }
        else if (CurrentModel.meshes[0].triangleCount > 500){
            DrawText("Med Preformance", 288 , 456 + 30, 15 , ORANGE);
        }
        else if (CurrentModel.meshes[0].triangleCount > 100){
            DrawText("High Preformance", 288 , 456 + 30, 15 , RED);
        }
        else if (CurrentModel.meshes[0].triangleCount > 1){
            DrawText("Very High Preformance", 288 , 456 + 30, 15 , PINK);
        }
    }
  
            
}