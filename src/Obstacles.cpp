#include <raylib.h>

class Obstacle{

  public:
    Texture2D Obs, Obs1, Obs2, Obs3;
    Vector2 PosObs, PosObs1, PosObs2, PosObs3;
    Rectangle rec, rec1, rec2, rec3 ;
    void LoadObs(){
        Obs = LoadTexture("assets/tile64_dark.png");
        PosObs.x = GetRandomValue(40, 40+Obs.width);
        PosObs.y = GetRandomValue(40, 40+Obs.height);
        rec.x = PosObs.x;
        rec.y = PosObs.y;
        rec.width = Obs.width;
        rec.height = Obs.height;

        Obs1 = LoadTexture("assets/tile64_light.png");
        PosObs1.x = GetRandomValue(760-Obs1.width,800-Obs1.width);
        PosObs1.y = GetRandomValue(410-Obs1.height,450-Obs1.height);
        rec1.x = PosObs1.x;
        rec1.y = PosObs1.y;
        rec1.width = Obs1.width;
        rec1.height = Obs1.height;


        Obs2 = LoadTexture("assets/tile64_dark.png");
        PosObs2.x = GetRandomValue(760-Obs2.width,800-Obs2.width);
        PosObs2.y = GetRandomValue(40,40+Obs2.height);
        rec2.x = PosObs2.x;
        rec2.y = PosObs2.y;
        rec2.width = Obs2.width;
        rec2.height = Obs2.height;

        Obs3 = LoadTexture("assets/tile64_light.png");
        PosObs3.x = GetRandomValue(40,40+Obs3.width);
        PosObs3.y = GetRandomValue(410-Obs3.height,450-Obs3.height);
        rec3.x = PosObs3.x;
        rec3.y = PosObs3.y;
        rec3.width = Obs3.width;
        rec3.height = Obs3.height;

    }
    void DrawObs(){
            DrawTexture(Obs,PosObs.x,PosObs.y,WHITE);
            DrawTexture(Obs1,PosObs1.x,PosObs1.y,WHITE);
            DrawTexture(Obs2,PosObs2.x,PosObs2.y,WHITE);
            DrawTexture(Obs3,PosObs3.x,PosObs3.y,WHITE);

    }
    void UnloadObs(){
            UnloadTexture(Obs);
            UnloadTexture(Obs1);
            UnloadTexture(Obs2);
            UnloadTexture(Obs3);
    }
};
