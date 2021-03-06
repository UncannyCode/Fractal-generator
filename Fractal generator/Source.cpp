#include <iostream>
#include <cstdint>


#include "Bitmap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"


using namespace std;

int main()
{
	
	int WIDTH = 800;
	int HEIGHT = 600;

	Bitmap bitmap(WIDTH, HEIGHT);

	double min = 99999;
	double max = -99999; 

	unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS + 1]{});
	unique_ptr<int[]> fractal(new int[WIDTH*HEIGHT]{ 0 });

	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			double xFractal = (x - WIDTH / 2 - 200) * 2.0 / HEIGHT;
			double yFractal = (y - HEIGHT / 2) * 2.0 / HEIGHT;

			int iterations = Mandelbrot::getIterations(xFractal, yFractal);
			fractal[y*WIDTH + x] = iterations;

			

				if (iterations != Mandelbrot::MAX_ITERATIONS)
				{
					histogram[iterations]++;

			}

		

		}
	}
	int total{ 0 };
	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++)
	{
		total += histogram[i];
	}
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {

			int iterations = fractal[y*WIDTH + x];

			if (iterations >= Mandelbrot::MAX_ITERATIONS)
			{
				bitmap.setPixel(x, y, 0, 0, 0);
			}
			else
			{
				uint8_t color = (uint8_t)(256 * (double)iterations / Mandelbrot::MAX_ITERATIONS);

				double hue = 0.0;

				for (int i = 0; i <= iterations; i++)
				{
					hue += static_cast<double>(histogram[i]) / total;
				}

				uint8_t red{ 0 };
				uint8_t green{ 0 };
				uint8_t blue{ 0 };

				red = 0;
				green = pow(255, hue);
				blue = 0;

				bitmap.setPixel(x, y, red, green, blue);
			}

	
		}
	}
	
	

	bitmap.write("bitmapkee.bmp");
}