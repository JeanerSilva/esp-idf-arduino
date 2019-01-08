// https://medium.com/home-wireless/how-to-program-an-esp32-in-arduino-while-using-esp-idf-functions-90033d860f75

#include "C:\msys32\home\Mark\esp\esp-idf\components\esp32\include\esp_wifi.h"

// set up Wifi for promiscuous mode, random channel
void WifiInitialize()
{
	wifi_init_config_t config = WIFI_INIT_CONFIG_DEFAULT();
	esp_wifi_init(&config);
	// Promiscuous works only with station mode	esp_wifi_set_mode(WIFI_MODE_STA);
	esp_wifi_set_promiscuous(0);
	// Set up promiscuous callback	esp_wifi_set_promiscuous_rx_cb(promisc_cb);
	esp_wifi_set_promiscuous(1);
	esp_wifi_set_channel(1, WIFI_SECOND_CHAN_NONE );
}

// the callback function

void promisc_cb(void *buf, wifi_promiscuous_pkt_type_t ttype)
{
wifi_promiscuous_pkt_t* snifpak = (wifi_promiscuous_pkt_t*)buf;
wifi_pkt_rx_ctrl_t& snifctrl = snifpak->rx_ctrl;  // the metadata
//... more code
}