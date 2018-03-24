#ifdef UNIT_TEST

#include <AUnit.h>
#include <ESP8266WiFi.h>

namespace {

char ssid[] = "your_ssid";     //  your network SSID (name)
const char password[] = "your_password";  // your network password

}

void setup() {
    Serial.begin(9600);
	while (!Serial); // for the Arduino Leonardo/Micro only

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    /* Explicitly set the ESP8266 to be a WiFi-client, otherwise, it by default,
        would try to act as both a client and an access-point and could cause
        network-issues with your other WiFi-devices on your WiFi-network. */
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    aunit::TestRunner::setTimeout(0);
	aunit::TestRunner::exclude("api_*");
	aunit::TestRunner::include("api__test_account"); // TODO: inconsistent
	aunit::TestRunner::include("api__test_block");
	//aunit::TestRunner::include("api__test_delegate"); // does not work
	aunit::TestRunner::include("api__test_loader");
	aunit::TestRunner::include("api__test_peer");
	aunit::TestRunner::include("api__test_signature");
	aunit::TestRunner::include("api__test_transaction");

	delay(1000);
}

void loop() {
   aunit::TestRunner::run();
}

#endif
