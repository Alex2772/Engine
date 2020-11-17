#include "Image.h"


#include <memory>
#include <stdexcept>

// этот define нужно написать ОДИН РАЗ И В ОДНОМ ФАЙЛЕ НА ПРОЕКТ
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

Image Image::loadFromFile(const std::string& path)
{
	int x, y, channels;

	// std::unique_ptr сам за нас освободит память, когда надо
	std::unique_ptr<stbi_uc> data = std::unique_ptr<stbi_uc>(stbi_load(("res/texture/" + path).c_str(), &x, &y, &channels, 0));
	if (data == nullptr)
	{
		// не удалось загрузить
		throw std::runtime_error("could not load image: " + path);
	}
	Format format;

	switch (channels)
	{
	case 3:
		format = RGB;
		break;
		
	case 4:
		format = RGBA;
		break;

	default:
		throw std::runtime_error("invalid channel count (" + std::to_string(channels) + ") in file: " + path);
	}

	// размер изображения (в байтах)
	int size = x * y * channels;
	return Image(x, y, std::vector<char>{data.get(), data.get() + size}, format);
}
