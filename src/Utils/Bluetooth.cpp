#include "Bluetooth.hpp"
#include <EEPROM.h>

namespace DanulalProto::Utils
{
    BluetoothController::BluetoothController() 
    {
        Serial4.begin(9600); // Start Bluetooth Serial
    }

    static constexpr uint8_t PacketSignature1 = 0xAA;

    byte lastRecievedData[4];
    uint8_t data[1];
    byte currentByte;
    int8_t currentDataPosition;

    byte currentDataSum = 0;

    void BluetoothController::run() 
    {
        if (Serial4.available()) 
        {
            currentByte = Serial4.readBytes(data, 1);
            currentByte = data[0];

            switch (currentDataPosition)
            {
                case 0:
                {
                    if (currentByte == PacketSignature1)
                    {
                        currentDataPosition = 1;
                    }
                    break;
                }
                case 5:
                {
                    // for (int i = 0; i < 5; i++)
                    // {
                    //     currentDataSum += lastRecievedData[i];
                    // }

                    // for (int i = 0; i < 4; i++)  // Print out all data into single line (Bluetooth communication debug)
                    // {
                    //     Serial.print(lastRecievedData[i]);
                    //     Serial.print(" ");
                    // }
                    // Serial.println(); // end of BT debug code

                    if (currentDataSum == currentByte)
                    {
                        currentDataSum = 0;
                        // Do something with the data
                        switch (lastRecievedData[3])
                        {
                            case 0: // color changing
                            {
                                colorR = lastRecievedData[0];
                                colorG = lastRecievedData[1];
                                colorB = lastRecievedData[2];
                                break;
                            }
                            case 1: // gay mode toggle
                            {
                                gayMode ^= 1;
                                break;
                            }
                            case 2: // Override menu Colors
                            {
                                if(lastRecievedData[0] == 1){
                                    menuOverride = true;
                                } else if (lastRecievedData[0] == 0) {
                                    menuOverride = false;
                                }
                                break;
                            }
                            case 3: // Override menu expressions
                            {
                                if (lastRecievedData[0] == 1)
                                {
                                    expressionOverride = true;
                                } else if (lastRecievedData[0] == 0) {
                                    expressionOverride = false;
                                }
                                break;
                            }
                            case 4: // Expression changing
                            {
                                expression = lastRecievedData[0];
                                break;
                            }
                            case 5: // write default color to eeprom
                            {
                                EEPROM.write(15, colorR);
                                EEPROM.write(16, colorG);
                                EEPROM.write(17, colorB);
                                break;
                            }
                            case 6: // settings stuff
                            {
                                switch (lastRecievedData[0]) // settings type
                                {
                                case 0: // menu button
                                    menuButtonPressed = lastRecievedData[1];
                                    break;
                                default:
                                    break;
                                }
                                break;
                            }
                    }

                    currentDataPosition = 0;
                    break;
                    }
                    default:
                    {
                        lastRecievedData[currentDataPosition - 1] = currentByte;
                        currentDataPosition++;
                        break;
                    }
                }
            }
        }
    }
}