/**
 * @file main.cpp
 * @brief Entry point for various projects, managing initialization and main loop operations.
 *
 * This file determines which project to run based on the defined preprocessor directive
 * and provides functionality for initializing and executing the selected project.
 *
 * Supported projects:
 * - PROJECT_PROTOGEN_HUB75
 * - PROJECT_PROTOGEN_WS35
 * - PROJECT_PROTOGEN_BETA
 * - PROJECT_VERIFY_ENGINE
 * - PROJECT_VERIFY_HARDWARE
 *
 * @date 22/12/2024
 * @version 1.0
 * @author Coela Can't
 */

#include "Examples/UserConfiguration.h"
#include "../lib/ProtoTracer/ExternalDevices/InputDevices/ButtonHandler.h"

#if defined(PROJECT_PROTOGEN_HUB75)
    #include "Examples/Protogen/ProtogenHUB75Project.h"
    ProtogenHUB75Project project; ///< Instance of the Protogen HUB75 project.

#elif defined(PROJECT_PROTOGEN_WS35)
    #include "Examples/Protogen/ProtogenWS35Project.h"
    ProtogenWS35Project project; ///< Instance of the Protogen WS35 project.

#elif defined(PROJECT_PROTOGEN_BETA)
    #include "Examples/Protogen/BetaProject.h"
    BetaProject project; ///< Instance of the Beta project.

#elif defined(PROJECT_VERIFY_ENGINE)
    #include "Examples/VerifyEngine.h"
    VerifyEngine project; ///< Instance of the Verify Engine project.

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

/**
 * @brief Arduino setup function, initializes the selected project.
 *
 * If PROJECT_VERIFY_HARDWARE is defined, runs continuous hardware testing.
 */
void setup() {
    Serial.begin(115200); ///< Initializes the serial port for debugging.
    Serial.println("\nStarting...");

    #ifndef PROJECT_VERIFY_HARDWARE
    project.Initialize(); ///< Initializes the selected project.

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

    delay(100); ///< Ensures stability after initialization.
    #else
    while (true) {
        HardwareTest::ScanDevices(); ///< Scans for connected hardware devices.
        HardwareTest::TestNeoTrellis(); ///< Tests the NeoTrellis input device.
        HardwareTest::TestBoopSensor(); ///< Tests the proximity (boop) sensor.
        HardwareTest::TestHUD(); ///< Tests the HUD (Head-Up Display) functionality.
    }
    #endif
}

/**
 * @brief Arduino main loop function, animates, renders, and updates the selected project.
 *
 * If PROJECT_VERIFY_HARDWARE is defined, this function is disabled.
 */
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

    float ratio = (float)(millis() % 5000) / 5000.0f; ///< Calculates animation ratio based on time.

    project.Animate(ratio); ///< Animates the project based on the current ratio.
    project.Render(); ///< Renders the project's scene.
    project.Display(); ///< Displays the rendered frame.
    project.PrintStats(); ///< Outputs debugging and performance statistics.
    #endif
}
