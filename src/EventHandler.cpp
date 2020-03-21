/*-----------------------------------------------------------------------------
 **
 ** - Ordinator -
 **
 ** Copyright 2020 by SwordLord - the coding crew and the contributing authors
 **
 ** This program is free software; you can redistribute it and/or modify it
 ** under the terms of the GNU Affero General Public License as published by the
 ** Free Software Foundation, either version 3 of the License, or (at your option)
 ** any later version.
 **
 ** This program is distributed in the hope that it will be useful, but WITHOUT
 ** ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 ** FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License
 ** for more details.
 **
 ** You should have received a copy of the GNU Affero General Public License
 ** along with this program. If not, see <http://www.gnu.org/licenses/>.
 **
 ** -----------------------------------------------------------------------------*/
#include "EventHandler.h"

EventHandler::EventHandler(HardwareSerial* hws) : hs(hws)
{
    pinMode(TP_PWR_PIN, PULLUP);
    digitalWrite(TP_PWR_PIN, HIGH);
    pinMode(TP_PIN_PIN, INPUT_PULLUP);
}

void EventHandler::poll()
{
    lastPressed5 = lastPressed4;
    lastPressed4 = lastPressed3;
    lastPressed3 = lastPressed2;
    lastPressed2 = lastPressed1;
    lastPressed1 = isPressed;

    isPressed = gpio_get_level(GPIO_NUM_33);

    if(isPressed)
    {
        _lastEventAt = millis();
    }

    /*
    _hs->println("__--__--__");
    _hs->println(digitalRead(TP_PIN_PIN)); // this
    _hs->println("__");

    _hs->println(GPIO_REG_READ(GPIO_OUT_REG));
    _hs->println(GPIO_REG_READ(GPIO_OUT1_REG));
    _hs->println(GPIO_REG_READ(GPIO_IN_REG));
    _hs->println(GPIO_REG_READ(GPIO_IN1_REG)); // this

    _hs->println("**");

    _hs->println(gpio_get_level(GPIO_NUM_33)); // this
    _hs->println("==");

    __--__--__
    1 -> pressed
    __
    249561120
    0
    115592875
    2
    **
    1
    ==
    __--__--__
    0 -> not pressed
    __
    249561120
    0
    115592875
    0
    **
    0
    ==
    */
}

bool EventHandler::timeoutForSleepReached()
{
    return _lastEventAt + _maxTimeOut <= millis();
}

bool EventHandler::isButtonPressed(){

    return isPressed;
}

bool EventHandler::isButtonJustPressed(){

    return !lastPressed1 && isPressed;
}

bool EventHandler::isButtonReleased(){

    return !isPressed;
}

bool EventHandler::isButtonJustReleased(){

    return lastPressed1 && !isPressed;
}


void EventHandler::shortPress()
{
    // what happens if
}

void EventHandler::longPress()
{
    // what happens if
}
