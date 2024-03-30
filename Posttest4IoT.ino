#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <DHT.h>

// wifi
#define WIFI_SSID "Ipppppp"
#define WIFI_PASS "ipppahhh"

// bot token 
#define BOT_TOKEN "7106098452:AAG1VxHQ8vysHnfkMbObbBhT9Ue3vm9ikJ8"

// pin 
#define LED_ALL D2
#define LED_NARUPA D3
#define LED_JUNI D4
#define LED_RISA D5
#define DHT_PIN D7  
#define DHT_TYPE DHT11

const unsigned long BOT_MTBS = 250;

X509List cert(TELEGRAM_CERTIFICATE_ROOT);
WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOT_TOKEN, secured_client);
unsigned long bot_lasttime;

DHT dht(DHT_PIN, DHT_TYPE);

void handleNewMessages(int numNewMessages){
  Serial.println("handleNewMessages");
  Serial.println(String(numNewMessages));

  for (int i=0; i<numNewMessages; i++) {
    String chat_id = bot.messages[i].chat_id;
    String from_name = bot.messages[i].from_name;
    String from_id = bot.messages[i].from_id;
    String text = bot.messages[i].text;
    Serial.println(text);
    Serial.println("ID pengirim: " + from_id);

    if (from_name == ""){
      from_name = "Guest";
    }

    if (text == "/start") {
      String welcome = "Selamat datang, " + from_name + " diposttest 4 :).\n";
      welcome += "Gunakan perintah dibawah ini untuk mengendalikan LED dan Suhu.\n\n";
      welcome += "/LED untuk menyalakan semua LED \n";
      welcome += "/LED_Risa untuk menyalakan LED Risa \n";
      welcome += "/LED_Narupa untuk menyalakan LED Narupa \n";
      welcome += "/LED_Juni untuk menyalakan LED Juni \n";
      welcome += "/Off_LED untuk mematikan semua LED \n";
      welcome += "/Off_LED_Risa untuk mematikan LED Risa \n";
      welcome += "/Off_LED_Narupa untuk mematikan LED Narupa \n";
      welcome += "/Off_LED_Juni untuk mematikan LED Juni \n";
      welcome += "/Suhu untuk melihat suhu \n";
      bot.sendMessage(chat_id, welcome, "");
    }

    if (text == "/LED" || text == "/LED@k4iotrnj_bot") {
      digitalWrite(LED_ALL, HIGH);
      bot.sendMessage(chat_id, "Semua LED sudah menyala", "");
    }

    if (text == "/LED_Risa" || text == "/LED_Risa@k4iotrnj_bot") {
      Serial.println("ID pengirim: " + from_id);
      if (from_id == "5416842465"){
          digitalWrite(LED_RISA, HIGH);
          bot.sendMessage(chat_id, "LED Risa sudah menyala", "");
      }else{
        bot.sendMessage(chat_id, "Salah pilih lampu. Ini punya Risa :)", "");
      }
    }

    if (text == "/LED_Narupa" || text == "/LED_Narupa@k4iotrnj_bot") {
      Serial.println("ID pengirim: " + from_id);
      if (from_id == "5000544672"){
        digitalWrite(LED_NARUPA, HIGH);
        bot.sendMessage(chat_id, "LED Narupa sudah menyala", "");
     
      }else{
        bot.sendMessage(chat_id, "Salah pilih lampu. Ini punya Narupa :)", "");
      }
    }

    if (text == "/LED_Juni" || text == "/LED_Juni@k4iotrnj_bot") {
      Serial.println("ID pengirim: " + from_id);
      if (from_id == "1281817865"){
        digitalWrite(LED_JUNI, HIGH);
        bot.sendMessage(chat_id, "LED Juni sudah menyala", "");
        
      }else{
        bot.sendMessage(chat_id, "Salah pilih lampu. Ini punya Juni :)", "");
      }
    }

    if (text == "/Off_LED" || text == "/Off_LED@k4iotrnj_bot") {
      digitalWrite(LED_ALL, LOW);
      bot.sendMessage(chat_id, "Semua LED sudah dimatikan", "");
      
    }

    if (text == "/Off_LED_Risa" || text == "/Off_LED_Risa@k4iotrnj_bot") {
      if (from_id == "5416842465"){
        bot.sendMessage(chat_id, "LED Risa sudah dimatikan", "");
        digitalWrite(LED_RISA, LOW);
      }else{
        bot.sendMessage(chat_id, "Salah pilih lampu. Ini punya Risa :)", "");
      }  
    }

    if (text == "/Off_LED_Narupa" || text == "/Off_LED_Narupa@k4iotrnj_bot") {
      if (from_id == "5000544672"){
        bot.sendMessage(chat_id, "LED Narupa sudah dimatikan", "");
        digitalWrite(LED_NARUPA, LOW);
      }else{
        bot.sendMessage(chat_id, "Salah pilih lampu. Ini punya Narupa :)", "");
      }
    }

    if (text == "/Off_LED_Juni" || text == "/Off_LED_Juni@k4iotrnj_bot"){
      if (from_id == "1281817865"){
        bot.sendMessage(chat_id, "LED Juni sudah dimatikan", "");
        digitalWrite(LED_JUNI, LOW);
      }else{
        bot.sendMessage(chat_id, "Salah pilih lampu. Ini punya Juni :)", "");
      }
    }

    if (text == "/Suhu" || text == "/Off_Suhu@k4iotrnj_bot") {
      float suhu = dht.readTemperature();
      float lembab = dht.readHumidity();

      String message = "";
      message += "Suhu : "+ String(suhu) + "°C\n";
      message += "Kelembapan : "+ String(lembab) + " %";
      bot.sendMessage(chat_id, message, "");
    }
  }  
}

void setup(){
  Serial.begin(115200);
  Serial.println();

  dht.begin();
  pinMode(LED_ALL, OUTPUT);
  pinMode(LED_NARUPA, OUTPUT);
  pinMode(LED_RISA, OUTPUT);
  pinMode(LED_JUNI, OUTPUT);

  configTime(0, 0, "pool.ntp.org");      
  secured_client.setTrustAnchors(&cert); 
  Serial.print("Connecting to Wifi SSID ");
  Serial.print(WIFI_SSID);

  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.print("\nWiFi connected. IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  if (millis() - bot_lasttime > BOT_MTBS) {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    
    while (numNewMessages) {
      Serial.println("Got response");
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }

    bot_lasttime = millis();
  }
}