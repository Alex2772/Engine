#pragma once
#include <string>
#include <vector>


/**
 * \brief Класс, описывающий прямоугольное растровое изображение.
 */
class Image
{
public:
	enum Format
	{
		RGB,
		RGBA
	};
private:
	unsigned mWidth, mHeight;
	std::vector<char> mData;
	Format mFormat;

public:


	Image(unsigned width, unsigned height, const std::vector<char>& data, Format format)
		: mWidth(width),
		  mHeight(height),
		  mData(data),
		  mFormat(format)
	{
	}


	unsigned getWidth() const
	{
		return mWidth;
	}

	unsigned getHeight() const
	{
		return mHeight;
	}

	const std::vector<char>& getData() const
	{
		return mData;
	}

	Format getFormat() const
	{
		return mFormat;
	}

	/**
	 * \brief Загрузить изображение из файла.
	 * \param path путь до файла
	 * \return загруженное изображение
	 * \throws std::runtime_error, если не получилось загрузить изображение
	 */
	static Image loadFromFile(const std::string& path);
};
