/*
 * Bitmap.cpp
 *
 *  Created on: Jul 2, 2015
 *      Author: johnpurcell
 */

#include "Bitmap.h"

namespace caveofprogramming {
                                                                        //*3 olmasinin sebebi RGB oldu�u i�in 3 byte gerekiyor 3 renk byte'i icin.
Bitmap::Bitmap(int width, int height): m_width(width), m_height(height), m_pPixels(new uint8_t[width*height*3])  {
	// TODO Auto-generated constructor stub

}

bool Bitmap::write(string filename) {
	return false;
}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {

}

Bitmap::~Bitmap() {
	// TODO Auto-generated destructor stub
}

} /* namespace caveofprogramming */
