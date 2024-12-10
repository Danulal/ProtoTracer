#include "Examples/UserConfiguration.h"
#include "../lib/ProtoTracer/ExternalDevices/InputDevices/ButtonHandler.h"

#ifdef TESTHARDWARE
#include "Examples/Protogen/ProtogenHardwareTest.h"
#endif

//#include "Examples/Commissions/UnicornZhenjaAnimation.h"
#include "Examples/Protogen/ProtogenHUB75Project.h"
//#include "Examples/VerifyEngine.h"
#include "../lib/ProtoTracer/Controller/HUB75Controller.h"

#include "Utils/Bluetooth.hpp"

//#include "Examples/Commissions/ArrowAnimation.h"
//#include "../lib/ProtoTracer/Examples/Protogen/BetaProject.h"

ProtogenHUB75Project project;
DanulalProto::Utils::BluetoothController bluetooth;

Menu menu;

void setup() {
    Serial.begin(115200);
    Serial.println("\nStarting...");

    project.Initialize();

    delay(100);
}

void loop() {
    bluetooth.run();

    if (bluetooth.getMenuOverride()) { // check if menu gets overriden by phone
        if(bluetooth.getGayMode()) {
            project.SelectColor(9);
        } else {
            if (bluetooth.getExpression() != 8) {
                project.CustomFaceColor(bluetooth.getColor());
            } else if (bluetooth.getExpression() == 8 && !bluetooth.getExpressionOverride()) {
                project.CustomFaceColor(bluetooth.getColor());
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