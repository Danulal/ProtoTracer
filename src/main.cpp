#include "Examples/UserConfiguration.h"
#include "../lib/ProtoTracer/ExternalDevices/InputDevices/ButtonHandler.h"

#ifdef TESTHARDWARE
#include "Examples/Protogen/ProtogenHardwareTest.h"
HardwareTest test;
#endif

//#include "Examples/Commissions/UnicornZhenjaAnimation.h"
#include "Examples/Protogen/ProtogenHUB75Project.h"
//#include "Examples/VerifyEngine.h"
#include "../lib/ProtoTracer/Controller/HUB75Controller.h"

#include "Utils/Bluetooth.hpp"

#include <EEPROM.h>

//#include "Examples/Commissions/ArrowAnimation.h"
//#include "../lib/ProtoTracer/Examples/Protogen/BetaProject.h"

ProtogenHUB75Project project;
DanulalProto::Utils::BluetoothController bluetooth;

Menu menu;

RGBColor color;
RGBColor BTcolor;

void setup() {
    Serial.begin(115200);
    Serial.println("\nStarting...");

    project.Initialize();

    color.R = EEPROM.read(15);
    color.G = EEPROM.read(16);
    color.B = EEPROM.read(17);

    delay(100);
}

void loop() {
    bluetooth.run();

    BTcolor = bluetooth.getColor();

    if(BTcolor.R != 0 && BTcolor.G != 0 && BTcolor.B != 0) {
        color = BTcolor;
    }

    if (bluetooth.getMenuOverride()) { // check if menu gets overriden by phone
        if(bluetooth.getGayMode()) {
            project.SelectColor(9);
        } else {
            if (bluetooth.getExpression() != 8) {
                project.CustomFaceColor(color);
            } else if (bluetooth.getExpression() == 8 && !bluetooth.getExpressionOverride()) {
                project.CustomFaceColor(color);
            }
        }
    }

    if (bluetooth.getExpressionOverride()) { // if both menu and bluetooth sets expression they will mix
        project.SelectFace(bluetooth.getExpression());
    }

    float ratio = (float)(millis() % 5000) / 5000.0f;

    project.Animate(ratio); 

    project.Render();

    project.Display();

    // project.PrintStats();
}