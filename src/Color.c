#include "Color.h"

struct Colors Init_Colors() {
	struct Colors colors;

	Log(INFO, "Initializing Colors ...", NULL);

	// LIGHT_GREY
	colors.LIGHT_GREY.r = 0x40;
	colors.LIGHT_GREY.g = 0x40;
	colors.LIGHT_GREY.b = 0x40;
	colors.LIGHT_GREY.a = 0xff;
	
	// DARK_GREY
	colors.DARK_GREY.r = 0x10;
	colors.DARK_GREY.g = 0x10;
	colors.DARK_GREY.b = 0x10;
	colors.DARK_GREY.a = 0xff;

	// RAINBOW
	colors.RAINBOW.r = 0xff;
	colors.RAINBOW.g = 0x0;
	colors.RAINBOW.b = 0x0;
	colors.RAINBOW.a = 0xff;

	// WHITE
	colors.WHITE.r = 0xff;
	colors.WHITE.g = 0xff;
	colors.WHITE.b = 0xff;
	colors.WHITE.a = 0xff;
	
	// BLACK
	colors.BLACK.r = 0x0;
	colors.BLACK.g = 0x0;
	colors.BLACK.b = 0x0;
	colors.BLACK.a = 0xff;

	// RED
	colors.RED.r = 0xff;
	colors.RED.g = 0x0;
	colors.RED.b = 0x0;
	colors.RED.a = 0xff;

	// YELLOW
	colors.YELLOW.r = 0xff;
	colors.YELLOW.g = 0xff;
	colors.YELLOW.b = 0x0;
	colors.YELLOW.a = 0xff;
	
	// GREEN
	colors.GREEN.r = 0x0;
	colors.GREEN.g = 0xff;
	colors.GREEN.b = 0x0;
	colors.GREEN.a = 0xff;
	
	// CYAN
	colors.CYAN.r = 0x0;
	colors.CYAN.g = 0xff;
	colors.CYAN.b = 0xff;
	colors.CYAN.a = 0xff;
	
	// BLUE
	colors.BLUE.r = 0x0;
	colors.BLUE.g = 0x0;
	colors.BLUE.b = 0xff;
	colors.BLUE.a = 0xff;
	
	// MAGENTA
	colors.MAGENTA.r = 0xff;
	colors.MAGENTA.g = 0x0;
	colors.MAGENTA.b = 0xff;
	colors.MAGENTA.a = 0xff;

	return colors;
}
