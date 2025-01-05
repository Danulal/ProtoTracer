#include "Examples/UserConfiguration.h"
#include "../lib/ProtoTracer/ExternalDevices/InputDevices/ButtonHandler.h"

#if defined(PROJECT_PROTOGEN_HUB75)
    #include "Examples/Protogen/ProtogenHUB75Project.h"
    ProtogenHUB75Project project;
#elif defined(PROJECT_PROTOGEN_WS35)
    #include "Examples/Protogen/ProtogenWS35Project.h"
    ProtogenWS35Project project;
#elif defined(PROJECT_PROTOGEN_BETA)
    #include "Examples/Protogen/BetaProject.h"
    BetaProject project;
#elif defined(PROJECT_VERIFY_ENGINE)
    #include "Examples/VerifyEngine.h"
    VerifyEngine project;
#elif defined(PROJECT_VERIFY_HARDWARE)
    #include "Examples/Protogen/ProtogenHardwareTest.h"
#else
    #error "No project defined! Please define one of PROJECT_PROTOGEN_HUB75, PROJECT_PROTOGEN_WS35, or PROJECT_VERIFY_ENGINE."
#endif

//#include "Examples/Commissions/UnicornZhenjaAnimation.h"
#include "Examples/Protogen/ProtogenHUB75Project.h"
//#include "Examples/VerifyEngine.h"
#include "../lib/ProtoTracer/Controller/HUB75Controller.h"

#include "Utils/Bluetooth.hpp"

#include <EEPROM.h>
#include <SparkFun_APDS9960.h>
#include <Wire.h>

//#include "Examples/Commissions/ArrowAnimation.h"
//#include "../lib/ProtoTracer/Examples/Protogen/BetaProject.h"

DanulalProto::Utils::BluetoothController bluetooth;

#include "../lib/ProtoTracer/ExternalDevices/InputDevices/Menu/Menu.h"
Menu menu;

SparkFun_APDS9960 boopSensor = SparkFun_APDS9960();
uint8_t proximity_data = 0;
bool booped = false;

RGBColor color;
RGBColor BTcolor;

void setup() {
    Serial.begin(115200);
    Serial.println("\nStarting...");
    
    #ifndef PROJECT_VERIFY_HARDWARE
    project.Initialize();

    if ( boopSensor.init() ) {
        Serial.println(F("APDS-9960 initialization complete"));
    } else {
        Serial.println(F("Something went wrong during APDS-9960 init!"));
    }

      // Adjust the Proximity sensor gain
    if ( !boopSensor.setProximityGain(PGAIN_2X) ) {
        Serial.println(F("Something went wrong trying to set PGAIN"));
    }

    // Start running the APDS-9960 proximity sensor (no interrupts)
    if ( boopSensor.enableProximitySensor(false) ) {
        Serial.println(F("Proximity sensor is now running"));
    } else {
        Serial.println(F("Something went wrong during sensor init!"));
    }

    color.R = EEPROM.read(15);
    color.G = EEPROM.read(16);
    color.B = EEPROM.read(17);

    delay(100);
    #else
        while(true){
            HardwareTest::ScanDevices();
            HardwareTest::TestNeoTrellis();
            HardwareTest::TestBoopSensor();
            HardwareTest::TestHUD();
        }
    #endif
}

void loop() {
    
    #ifndef PROJECT_VERIFY_HARDWARE
    bluetooth.run();

    BTcolor = bluetooth.getColor();

    if(bluetooth.getMenuButton()) { // faking the menu button
        digitalWrite(23, LOW);
    } else {
        digitalWrite(23, HIGH);
    }

    if ( boopSensor.readProximity(proximity_data) && menu.UseBoopSensor() ) { // proximity sensor custom implementation
        if (proximity_data > 50) {
            booped = true;
        } else {
            booped = false;
        }
    }

    if(!(BTcolor.R == 0 && BTcolor.G == 0 && BTcolor.B == 0)) {
        color = BTcolor;
    }

    if (bluetooth.getMenuOverride()) { // check if menu gets overriden by phone
        if(bluetooth.getGayMode()) {
            project.SelectColor(9);
        } else {
            if (bluetooth.getExpression() != 8 && !booped) {
                project.CustomFaceColor(color);
            } else if (bluetooth.getExpression() == 8 && !bluetooth.getExpressionOverride()) {
                project.CustomFaceColor(color);
            }
        }
    }

    if (bluetooth.getExpressionOverride()) { // if both menu and bluetooth sets expression they will mix
        if(!booped) {
            project.SelectFace(bluetooth.getExpression());
        }
    }
    if(booped) {
        project.SelectFace(8);
    }

    float ratio = (float)(millis() % 5000) / 5000.0f;

    project.Animate(ratio); 
    project.Render();
    project.Display();
    project.PrintStats();
    #endif
}

