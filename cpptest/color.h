#pragma once
#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"
#include <iostream>

void write_color(std::ostream& out, color pixel_color,int samples_per_pixel) {
	//输出每个像素的颜色
	auto r = pixel_color.x();
	auto g = pixel_color.y();
	auto b = pixel_color.z();
	//按照SPP将颜色分开，并且进行伽马矫正

	auto scale = 1.0/samples_per_pixel;
	r = sqrt(scale * r);
	g = sqrt(scale * g);
	b = sqrt(scale * b);


	out << static_cast<int>(256 * clamp(r,0.0,0.999)) << ' '
		<< static_cast<int>(256 * clamp(g,0.0,0.999)) << ' '
		<< static_cast<int>(256 * clamp(b,0.0,0.999)) << '\n';
}


#endif // !COLOR_H
