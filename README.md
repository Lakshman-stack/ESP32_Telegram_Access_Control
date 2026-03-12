# ESP32 Telegram Access Control System

## Overview

This project implements a remote access control system using an ESP32 microcontroller and a Telegram bot. The ESP32 connects to WiFi and listens for commands sent from a Telegram chat. Based on the received command, the system prints access status.

## Features

* Remote control using Telegram bot
* Works from anywhere using internet
* Commands supported:

  * `/grant` → Access Granted
  * `/deny` → Access Denied

## Hardware Required

* ESP32 Development Board
* WiFi Connection
* Mobile phone with Telegram

## Software Required

* Arduino IDE
* Libraries:

  * UniversalTelegramBot
  * ArduinoJson

## Working Principle

1. ESP32 connects to WiFi.
2. Telegram bot receives commands from the user.
3. ESP32 checks Telegram messages.
4. When `/grant` is received → ESP32 prints **ACCESS GRANTED**.
5. When `/deny` is received → ESP32 prints **ACCESS DENIED**.

## Author

Lakshman Gowda
