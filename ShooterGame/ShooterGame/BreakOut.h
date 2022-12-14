#pragma once
#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

class BreakOut : public olc::PixelGameEngine
{
public:
    BreakOut()
    {
        sAppName = "TUTORIAL - BreakOut Clone";
    }

private:
    float fBatPos = 20.0f;
    float fBatWidth = 40.0f;
    float fBatSpeed = 250.0f;

    olc::vf2d vBall = { 200.0f, 200.0f };

    /* // if we want to virutalize fps instead of forcing vsync
    float fTargetFrameTime = 1.0f / 100.0f; // Virtual FPS of 100fps
    float fAccumulatedTime = 0.0f;
    */

public:
    bool OnUserCreate() override
    {
        return true;
    }

    bool OnUserUpdate(float fElapsedTime) override
    {
        /* // if we want to virtualize fps instead of force vsync
        fAccumulatedTime += fElapsedTime;
        if (fAccumulatedTime >= fTargetFrameTime)
        {
            fAccumulatedTime -= fTargetFrameTime;
            fElapsedTime = fTargetFrameTime;
        }
        else
            return true; // Don't do anything this frame
        */

        // Handle user input
        if (GetKey(olc::Key::LEFT).bHeld) fBatPos -= fBatSpeed * fElapsedTime;
        if (GetKey(olc::Key::RIGHT).bHeld) fBatPos += fBatSpeed * fElapsedTime;

        // Update bat position
        if (fBatPos < 11.0f) fBatPos = 11.0f;
        if (fBatPos + fBatWidth > float(ScreenWidth()) - 10.0f) fBatPos = float(ScreenWidth()) - 10.0f - fBatWidth;

        // Erase previous frame
        Clear(olc::DARK_BLUE);

        // Draw Boundary
        DrawLine(10, 10, ScreenWidth() - 10, 10, olc::YELLOW);
        DrawLine(10, 10, 10, ScreenHeight() - 10, olc::YELLOW);
        DrawLine(ScreenWidth() - 10, 10, ScreenWidth() - 10, ScreenHeight() - 10, olc::YELLOW);

        // Draw Bat
        FillRect(int(fBatPos), ScreenHeight() - 20, int(fBatWidth), 10, olc::GREEN);

        // Draw Ball
        FillCircle(vBall, 5, olc::CYAN);
        return true;
    }
};