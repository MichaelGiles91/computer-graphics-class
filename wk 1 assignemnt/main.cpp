#include "RasterSurface.h" 

const unsigned int width = 500;
const unsigned int height = 500;
const unsigned int numPixels = width * height;

unsigned int pixels[500 * 500] = {};
void clearBuffer()
{
	for (unsigned int& P : pixels)
	{
		P = 0x00FF0000;
	}
}
unsigned int Con2Dto1D(unsigned int x, unsigned int y) {

	return y * width + x;

}

void drawPixel(unsigned int x, unsigned int y, unsigned int color ) 
{
	if (x >= width || y >= height)
	{
		return;
	}
	unsigned int index = Con2Dto1D(x, y);
	pixels[index] = color;
}
void Blit()
{
	unsigned int startX = 250;
	unsigned int startY = 250;


	for (unsigned int i = 0; i < 20; i++) {
		for (unsigned int j = 0; j < 20; j++) {
			drawPixel(startX + i, startY + j , 0x000000FF);
		}
	}
}

int main() {

	

	RS_Initialize("Michael Giles", width, height);

	while (RS_Update(pixels, numPixels))
	{
		clearBuffer();
		Blit();
	}

	RS_Shutdown();

	return 0;

}
