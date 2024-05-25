/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** textures
*/

#include "Textures.hpp"

Textures::Textures()
{

}

Textures::~Textures()
{

}

//! Image loading functions
//! NOTE: These functions do not require GPU access
Image Textures::loadImage(const std::string& fileName)
{
    return LoadImage(fileName.c_str());
}

Image Textures::LoadImageRaw(const std::string& fileName, int width, int height, int format, int headerSize)
{
    return LoadImageRaw(fileName.c_str(), width, height, format, headerSize);
}

Image Textures::loadImageAnim(const std::string& fileName, int vframes)
{
    return LoadImageAnim(fileName.c_str(), &vframes);
}

Image Textures::loadImageFromMemory(const std::string& fileType, const std::string& fileData, int dataSize)
{
    return LoadImageFromMemory(fileType.c_str(), (unsigned const char*)fileData.c_str(), dataSize);
}

Image Textures::loadImageFromTexture(Texture2D texture)
{
    return LoadImageFromTexture(texture);
}

Image Textures::loadImageFromScreen(void)
{
    return LoadImageFromScreen();
}

void Textures::unloadImage(Image image)
{
    UnloadImage(image);
}

bool Textures::exportImage(Image image, const std::string& fileName)
{
    return ExportImage(image, fileName.c_str());
}

bool Textures::exportImageAsCode(Image image, const std::string& fileName)
{
    return ExportImageAsCode(image, fileName.c_str());
}

//! Image generation functions
Image Textures::genImageColor(Vector2 dimension, Color color)
{
    return GenImageColor(dimension.x, dimension.y, color);
}

Image Textures::genImageGradientV(Vector2 dimension, Color top, Color bottom)
{
    return GenImageGradientV(dimension.x, dimension.y, top, bottom);
}

Image Textures::genImageGradientH(Vector2 dimension, Color left, Color right)
{
    return GenImageGradientH(dimension.x, dimension.y, left, right);
}

Image Textures::genImageGradientRadial(Vector2 dimension, float density, Color inner, Color outer)
{
    return GenImageGradientRadial(dimension.x, dimension.y, density, inner, outer);
}

Image Textures::genImageChecked(Vector2 dimension, int checksX, int checksY, Color col1, Color col2)
{
    return GenImageChecked(dimension.x, dimension.y, checksX, checksY, col1, col2);
}

Image Textures::genImageWhiteNoise(Vector2 dimension, float factor)
{
    return GenImageWhiteNoise(dimension.x, dimension.y, factor);
}

Image Textures::genImageCellular(Vector2 dimension, int tileSize)
{
    return GenImageCellular(dimension.x, dimension.y, tileSize);
}

Image Textures::imageCopy(Image image)
{
    return ImageCopy(image);
}

Image Textures::imageFromImage(Image image, Rectangle rec)
{
    return ImageFromImage(image, rec);
}

Image Textures::imageText(const std::string& text, int fontSize, Color color)
{
    return ImageText(text.c_str(), fontSize, color);
}

Image Textures::imageTextEx(Font font, const std::string& text, float fontSize, float spacing, Color tint)
{
    return ImageTextEx(font, text.c_str(), fontSize, spacing, tint);
}

void Textures::imageFormat(Image image, int newFormat)
{
    ImageFormat(&image, newFormat);
}

void Textures::imageToPOT(Image image, Color fill)
{
    ImageToPOT(&image, fill);
}

void Textures::imageCrop(Image image, Rectangle crop)
{
    ImageCrop(&image, crop);
}

void Textures::imageAlphaCrop(Image image, float threshold)
{
    ImageAlphaCrop(&image, threshold);
}

void Textures::imageAlphaClear(Image image, Color color, float threshold)
{
    ImageAlphaClear(&image, color, threshold);
}

void Textures::imageAlphaMask(Image image, Image alphaMask)
{
    ImageAlphaMask(&image, alphaMask);
}

void Textures::imageAlphaPremultiply(Image image)
{
    ImageAlphaPremultiply(&image);
}

void Textures::imageResize(Image image, int newWidth, int newHeight)
{
    ImageResize(&image, newWidth, newHeight);
}

void Textures::imageResizeNN(Image image, int newWidth,int newHeight)
{
    ImageResizeNN(&image, newWidth, newHeight);
}

void Textures::imageResizeCanvas(Image image, int newWidth, int newHeight, int offsetX, int offsetY, Color fill)
{
    ImageResizeCanvas(&image, newWidth, newHeight, offsetX, offsetY, fill);
}

void Textures::imageMipmaps(Image image)
{
    ImageMipmaps(&image);
}

void Textures::imageDither(Image image, int rBpp, int gBpp, int bBpp, int aBpp)
{
    ImageDither(&image, rBpp, gBpp, bBpp, aBpp);
}

void Textures::imageFlipVertical(Image image)
{
    ImageFlipVertical(&image);
}

void Textures::imageFlipHorizontal(Image image)
{
    ImageFlipHorizontal(&image);
}

void Textures::imageRotateCW(Image image)
{
    ImageRotateCW(&image);
}

void Textures::imageRotateCCW(Image image)
{
    ImageRotateCCW(&image);
}

void Textures::imageColorTint(Image image, Color color)
{
    ImageColorTint(&image, color);
}

void Textures::imageColorInvert(Image image)
{
    ImageColorInvert(&image);
}

void Textures::imageColorGrayscale(Image image)
{
    ImageColorGrayscale(&image);
}

void Textures::imageColorContrast(Image image, float contrast)
{
    ImageColorContrast(&image, contrast);
}

void Textures::imageColorBrightness(Image image, int brightness)
{
    ImageColorBrightness(&image, brightness);
}

void Textures::imageColorReplace(Image image, Color color, Color replace)
{
    ImageColorReplace(&image, color, replace);
}

std::unique_ptr<Color> Textures::loadImageColors(Image image)
{
    std::unique_ptr<Color> data = std::unique_ptr<Color>(LoadImageColors(image));
    return data;
}

std::unique_ptr<Color> Textures::loadImagePalette(Image image, int maxPaletteSize, int colorsCount)
{
    auto data = std::unique_ptr<Color>(LoadImagePalette(image, maxPaletteSize, &colorsCount));
    return data;
}

void Textures::unloadImageColors(Color colors)
{
    UnloadImageColors(&colors);
}

void Textures::unloadImagePalette(Color colors)
{
    UnloadImagePalette(&colors);
}

Rectangle Textures::getImageAlphaBorder(Image image, float threshold)
{
    return GetImageAlphaBorder(image, threshold);
}

Color Textures::getImageColor(Image image, int x, int y)
{
    return GetImageColor(image, x, y);
}

//! Image drawing functions
//! NOTE: Image software-rendering functions (CPU)
void Textures::imageClearBackground(Image dst, Color color)
{
    ImageClearBackground(&dst, color);
}

void Textures::imageDrawPixel(Image dst, int posX, int posY, Color color)
{
    ImageDrawPixel(&dst, posX, posY, color);
}

void Textures::imageDrawPixelV(Image dst, Vector2 position, Color color)
{
    ImageDrawPixelV(&dst, position, color);
}

void Textures::imageDrawLine(Image dst, int startPosX, int startPosY, int endPosX, int endPosY, Color color)
{
    ImageDrawLine(&dst, startPosX, startPosY, endPosX, endPosY, color);
}

void Textures::imageDrawLineV(Image dst, Vector2 start, Vector2 end, Color color)
{
    ImageDrawLineV(&dst, start, end, color);
}

void Textures::imageDrawCircle(Image dst, int centerX, int centerY, int radius, Color color)
{
    ImageDrawCircle(&dst, centerX, centerY, radius, color);
}

void Textures::imageDrawCircleV(Image dst, Vector2 center, int radius, Color color)
{
    ImageDrawCircleV(&dst, center, radius, color);
}

void Textures::imageDrawRectangle(Image dst, int posX, int posY, int width, int height, Color color)
{
    ImageDrawRectangle(&dst, posX, posY, width, height, color);
}

void Textures::imageDrawRectangleV(Image dst, Vector2 position, Vector2 size, Color color)
{
    ImageDrawRectangleV(&dst, position, size, color);
}

void Textures::imageDrawRectangleRec(Image dst, Rectangle rec, Color color)
{
    ImageDrawRectangleRec(&dst, rec, color);
}

void Textures::imageDrawRectangleLines(Image dst, Rectangle rec, int thick, Color color)
{
    ImageDrawRectangleLines(&dst, rec, thick, color);
}

void Textures::imageDraw(Image dst, Image src, Rectangle srcRec, Rectangle dstRec, Color tint)
{
    ImageDraw(&dst, src, srcRec, dstRec, tint);
}

void Textures::imageDrawText(Image dst, const std::string& text, int posX, int posY, int fontSize, Color color)
{
    ImageDrawText(&dst, text.c_str(), posX, posY, fontSize, color);
}

void Textures::imageDrawTextEx(Image dst, Font font, const std::string& text, Vector2 position, float fontSize, float spacing, Color tint)
{
    ImageDrawTextEx(&dst, font, text.c_str(), position, fontSize, spacing, tint);
}

//! Texture loading functions
//! NOTE: These functions require GPU access
Texture2D Textures::loadTexture(const std::string& fileName)
{
    return LoadTexture(fileName.c_str());
}

Texture2D Textures::loadTextureFromImage(Image image)
{
    return LoadTextureFromImage(image);
}

TextureCubemap Textures::loadTextureCubemap(Image image, int layout)
{
    return LoadTextureCubemap(image, layout);
}

RenderTexture2D Textures::loadRenderTexture(int width, int height)
{
    return LoadRenderTexture(width, height);
}

void Textures::unloadTexture(Texture2D texture)
{
    UnloadTexture(texture);
}

void Textures::unloadRenderTexture(RenderTexture2D target)
{
    UnloadRenderTexture(target);
}

void Textures::updateTexture(Texture2D texture, const std::any pixels)
{
    UpdateTexture(texture, std::any_cast<const void*>(pixels));
}

void Textures::updateTextureRec(Texture2D texture, Rectangle rec, const std::any pixels)
{
    UpdateTextureRec(texture, rec, std::any_cast<const void*>(pixels));
}

//! Texture configuration functions
void Textures::genTextureMipmaps(std::unique_ptr<Texture2D> texture)
{
    GenTextureMipmaps(texture.get());
}

void Textures::setTextureFilter(Texture2D texture, int filter)
{
    SetTextureFilter(texture, filter);
}

void Textures::setTextureWrap(Texture2D texture, int wrap)
{
    SetTextureWrap(texture, wrap);
}

//! Texture drawing functions
void Textures::drawTexture(Texture2D texture, int posX, int posY, Color tint)
{
    DrawTexture(texture, posX, posY, tint);
}

void Textures::drawTextureV(Texture2D texture, Vector2 position, Color tint)
{
    DrawTextureV(texture, position, tint);
}

void Textures::drawTextureEx(Texture2D texture, Vector2 position, float rotation, float scale, Color tint)
{
    DrawTextureEx(texture, position, rotation, scale, tint);
}

void Textures::drawTextureRec(Texture2D texture, Rectangle source, Vector2 position, Color tint)
{
    DrawTextureRec(texture, source, position, tint);
}

void Textures::drawTextureQuad(Texture2D texture, Vector2 tiling, Vector2 offset, Rectangle quad, Color tint)
{
    DrawTextureQuad(texture, tiling, offset, quad, tint);
}

void Textures::drawTextureTiled(Texture2D texture, Rectangle source, Rectangle dest, Vector2 origin, float rotation, float scale, Color tint)
{
    DrawTextureTiled(texture, source, dest, origin, rotation, scale, tint);
}

void Textures::drawTexturePro(Texture2D texture, Rectangle source, Rectangle dest, Vector2 origin, float rotation, Color tint)
{
    DrawTexturePro(texture, source, dest, origin, rotation, tint);
}

void Textures::drawTextureNPatch(Texture2D texture, NPatchInfo nPatchInfo, Rectangle dest, Vector2 origin, float rotation, Color tint)
{
    DrawTextureNPatch(texture, nPatchInfo, dest, origin, rotation, tint);
}

void Textures::drawTexturePoly(Texture2D texture, Vector2 center, std::unique_ptr<Vector2> points, std::unique_ptr<Vector2> texcoords, int pointsCount, Color tint)
{
    DrawTexturePoly(texture, center, points.get(), texcoords.get(), pointsCount, tint);
}

//! Color/pixel related functions
Color Textures::fade(Color color, float alpha)
{
    return Fade(color, alpha);
}

int Textures::colorToInt(Color color)
{
    return ColorToInt(color);
}

Vector4 Textures::colorNormalize(Color color)
{
    return ColorNormalize(color);
}

Color Textures::colorFromNormalized(Vector4 normalized)
{
    return ColorFromNormalized(normalized);
}

Vector3 Textures::colorToHSV(Color color)
{
    return ColorToHSV(color);
}

Color Textures::colorFromHSV(float hue, float saturation, float value)
{
    return ColorFromHSV(hue, saturation, value);
}

Color Textures::colorAlpha(Color color, float alpha)
{
    return ColorAlpha(color, alpha);
}

Color Textures::colorAlphaBlend(Color dst, Color src, Color tint)
{
    return ColorAlphaBlend(dst, src, tint);
}

Color Textures::getColor(unsigned int hexValue)
{
    return GetColor(hexValue);
}

Color Textures::getPixelColor(std::any srcPtr, int format)
{
    return GetPixelColor(std::any_cast<void*>(srcPtr), format);
}

void Textures::setPixelColor(std::any dstPtr, Color color, int format)
{
    SetPixelColor(std::any_cast<void*>(dstPtr), color, format);
}

int Textures::getPixelDataSize(int width, int height, int format)
{
    return GetPixelDataSize(width, height, format);
}