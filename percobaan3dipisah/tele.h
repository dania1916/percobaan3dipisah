#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

#define BOT_TOKEN "5390039796:AAEXTPEYL48xjHVfM-TvgaVB5WRBHN5Th90"
#define CHAT_ID "-759393234"

WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOT_TOKEN, secured_client);

void startTele() {
  
  Serial.println();
  secured_client.setCACert(TELEGRAM_CERTIFICATE_ROOT); // Add root certificate for api.telegram.org
  {
    Serial.print(".");
    delay(500);
  }
  
  Serial.print("Retrieving time: ");
  configTime(0, 0, "pool.ntp.org"); // get UTC time via NTP
  time_t now = time(nullptr);
  while (now < 24 * 3600)
  {
    Serial.print(".");
    delay(100);
    now = time(nullptr);
  }
  Serial.println(now); 
  //bot.sendMessage(CHAT_ID, "Halo", "");
}
