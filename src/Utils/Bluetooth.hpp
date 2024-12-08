#pragma once
#include "../lib/ProtoTracer/Assets/Models/FBX/NukudeFlat.h"
#include <vector>

namespace DanulalProto::Utils
{
    class BluetoothController
    {
    public:
        BluetoothController();

        void run();

        RGBColor getColor() { return RGBColor(colorR, colorG, colorB); }
        bool getGayMode() { return gayMode; }
        bool getMenuOverride() { return menuOverride; }

    private:
        char msgBuf[128];
		char msg[128];

        uint8_t colorR = 255;
        uint8_t colorG = 162;
        uint8_t colorB = 28;
        
        uint8_t face;
        
        bool gayMode = false;
        bool menuOverride = true;
    };
}