//
// Created by Luke Belinc on 4/8/21.
//

#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

class BreakOut : public olc::PixelGameEngine
{
public:
    BreakOut()
    {
        sAppName = "TUTORIAL - BreakOut Clone";
    }

public:
    bool OnUserCreate() override
    {
        return true;
    }

    bool OnUserUpdate(float fElapsedTime) override
    {
        return true;
    }
};