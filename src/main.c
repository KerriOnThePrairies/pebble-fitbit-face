
#include "pebble_os.h"
#include "pebble_app.h"
#include "pebble_fonts.h"
#include "http.h"
#include "steps_layer.h"


#define MY_UUID { 0x91, 0x41, 0xB6, 0x28, 0xBC, 0x89, 0x49, 0x8E, 0xB1, 0x47, 0x04, 0x9F, 0x49, 0xC0, 0x99, 0xAD }
PBL_APP_INFO_SIMPLE(MY_UUID, "Fitbit Face", "Gerald Patterson", 1 /* App version */);

Window window;

TextLayer textLayer;

void success(int32_t cookie, int http_status, DictionaryIterator* received, void* context) {
}

void failure(int32_t cookie, int http_status, void* context) {
}

void reconnect(void* context) {
}

// Standard app initialisation

void handle_init(AppContextRef ctx) {
  (void)ctx;

  window_init(&window, "Fitbit Experiment");
  window_stack_push(&window, true /* Animated */);

  text_layer_init(&textLayer, window.layer.frame);
  text_layer_set_text(&textLayer, "Hello World");
  text_layer_set_font(&textLayer, fonts_get_system_font(FONT_KEY_GOTHAM_30_BLACK));
  layer_add_child(&window.layer, &textLayer.layer);
	http_set_app_id(34525638);
	http_register_callbacks((HTTPCallbacks){
		.failure=failure,
		.success=success,
		.reconnect=reconnect,
	}, (void*)ctx);	
	fake_it();
}

void pbl_main(void *params) {
  PebbleAppHandlers handlers = {
    .init_handler = &handle_init
  };
  app_event_loop(params, &handlers);
}

void request_steps(){
	DictionaryIterator *body;
	//dict_write_
	//HTTPResult result = http_out_get("http://urlhere", WEATHER_HTTP_COOKIE, &body);
	//http_out_send();
}
