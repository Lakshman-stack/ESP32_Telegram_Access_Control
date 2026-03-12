#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

// -------- WiFi --------
const char* ssid = "MitronTech_5G";
const char* password = "Mitron&123";

// -------- Telegram Bot --------
#define BOTtoken "8572971335:AAGAGkc7nq3CGt5Xy7IrC7Zszr5PWij2tt4"
#define CHAT_ID "5463432064"

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

unsigned long lastTime = 0;
unsigned long timerDelay = 1000;

void setup() {

  Serial.begin(115200);

  WiFi.begin(ssid, password);

  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi connected");

  client.setInsecure();
}

void handleMessages(int numNewMessages) {

  for (int i = 0; i < numNewMessages; i++) {

    String text = bot.messages[i].text;
    String chat_id = bot.messages[i].chat_id;

    Serial.print("Message received: ");
    Serial.println(text);

    if (text == "/grant") {

      Serial.println("ACCESS GRANTED");

      bot.sendMessage(chat_id, "Access Granted", "");

    }

    if (text == "/deny") {

      Serial.println("ACCESS DENIED");

      bot.sendMessage(chat_id, "Access Denied", "");

    }

  }
}

void loop() {

  if (millis() - lastTime > timerDelay) {

    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);

    while (numNewMessages) {

      handleMessages(numNewMessages);

      numNewMessages = bot.getUpdates(bot.last_message_received + 1);

    }

    lastTime = millis();
  }
}