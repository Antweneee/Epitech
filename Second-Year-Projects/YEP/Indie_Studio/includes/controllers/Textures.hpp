/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** Textures
*/

#ifndef TEXTURES_HPP_
    #define TEXTURES_HPP_
    #include <raylib.h>
    #include <string>
    #include <vector>
    #include <any>
    #include <memory>

class Textures {
    public:
        Textures();
        ~Textures();

        //! Image loading functions
        //! NOTE: These functions do not require GPU access
        Image loadImage(const std::string& fileName);
        Image LoadImageRaw(const std::string& fileName, int width, int height, int format, int headerSize);
        Image loadImageAnim(const std::string& fileName, int vframes);
        Image loadImageFromMemory(const std::string& fileType, const std::string& fileData, int dataSize);
        Image loadImageFromTexture(Texture2D texture);
        Image loadImageFromScreen(void);
        void unloadImage(Image image);
        bool exportImage(Image image, const std::string& fileName);
        bool exportImageAsCode(Image image, const std::string& fileName);

        //! Image generation functions
        Image genImageColor(Vector2 dimension, Color color);
        Image genImageGradientV(Vector2 dimension, Color top, Color bottom);
        Image genImageGradientH(Vector2 dimension, Color left, Color right);
        Image genImageGradientRadial(Vector2 dimension, float density, Color inner, Color outer);
        Image genImageChecked(Vector2 dimension, int checksX, int checksY, Color col1, Color col2);
        Image genImageWhiteNoise(Vector2 dimension, float factor);
        Image genImageCellular(Vector2 dimension, int tileSize);

        //! Image manipulation functions
        Image imageCopy(Image image);
        Image imageFromImage(Image image, Rectangle rec);
        Image imageText(const std::string& text, int fontSize, Color color);
        Image imageTextEx(Font font, const std::string& text, float fontSize, float spacing, Color tint);
        void imageFormat(Image image, int newFormat);
        void imageToPOT(Image image, Color fill);
        void imageCrop(Image image, Rectangle crop);
        void imageAlphaCrop(Image image, float threshold);
        void imageAlphaClear(Image image, Color color, float threshold);
        void imageAlphaMask(Image image, Image alphaMask);
        void imageAlphaPremultiply(Image image);
        void imageResize(Image image, int newWidth, int newHeight);
        void imageResizeNN(Image image, int newWidth,int newHeight);
        void imageResizeCanvas(Image image, int newWidth, int newHeight, int offsetX, int offsetY, Color fill);
        void imageMipmaps(Image image);
        void imageDither(Image image, int rBpp, int gBpp, int bBpp, int aBpp);
        void imageFlipVertical(Image image);
        void imageFlipHorizontal(Image image);
        void imageRotateCW(Image image);
        void imageRotateCCW(Image image);
        void imageColorTint(Image image, Color color);
        void imageColorInvert(Image image);
        void imageColorGrayscale(Image image);
        void imageColorContrast(Image image, float contrast);
        void imageColorBrightness(Image image, int brightness);
        void imageColorReplace(Image image, Color color, Color replace);
        std::unique_ptr<Color> loadImageColors(Image image);
        std::unique_ptr<Color> loadImagePalette(Image image, int maxPaletteSize, int colorsCount);
        void unloadImageColors(Color colors);
        void unloadImagePalette(Color colors);
        Rectangle getImageAlphaBorder(Image image, float threshold);
        Color getImageColor(Image image, int x, int y);

        //! Image drawing functions
        //! NOTE: Image software-rendering functions (CPU)
        void imageClearBackground(Image dst, Color color);
        void imageDrawPixel(Image dstt, int posX, int posY, Color color);
        void imageDrawPixelV(Image dst, Vector2 position, Color color);
        void imageDrawLine(Image dst, int startPosX, int startPosY, int endPosX, int endPosY, Color color);
        void imageDrawLineV(Image dst, Vector2 start, Vector2 end, Color color);
        void imageDrawCircle(Image dst, int centerX, int centerY, int radius, Color color);
        void imageDrawCircleV(Image dst, Vector2 center, int radius, Color color);
        void imageDrawRectangle(Image dst, int posX, int posY, int width, int height, Color color);
        void imageDrawRectangleV(Image dst, Vector2 position, Vector2 size, Color color);
        void imageDrawRectangleRec(Image dst, Rectangle rec, Color color);
        void imageDrawRectangleLines(Image dst, Rectangle rec, int thick, Color color);
        void imageDraw(Image dst, Image src, Rectangle srcRec, Rectangle dstRec, Color tint);
        void imageDrawText(Image dst, const std::string& text, int posX, int posY, int fontSize, Color color);
        void imageDrawTextEx(Image dst, Font font, const std::string& text, Vector2 position, float fontSize, float spacing, Color tint);

        //! Texture loading functions
        //! NOTE: These functions require GPU access
        Texture2D loadTexture(const std::string& fileName);
        Texture2D loadTextureFromImage(Image image);
        TextureCubemap loadTextureCubemap(Image image, int layout);
        RenderTexture2D loadRenderTexture(int width, int height);
        void unloadTexture(Texture2D texture);
        void unloadRenderTexture(RenderTexture2D target);
        void updateTexture(Texture2D texture, const std::any pixels);
        void updateTextureRec(Texture2D texture, Rectangle rec, const std::any pixels);

        //! Texture configuration functions
        void genTextureMipmaps(std::unique_ptr<Texture2D> texture);
        void setTextureFilter(Texture2D texture, int filter);
        void setTextureWrap(Texture2D texture, int wrap);

        //! Texture drawing functions
        void drawTexture(Texture2D texture, int posX, int posY, Color tint);
        void drawTextureV(Texture2D texture, Vector2 position, Color tint);
        void drawTextureEx(Texture2D texture, Vector2 position, float rotation, float scale, Color tint);
        void drawTextureRec(Texture2D texture, Rectangle source, Vector2 position, Color tint);
        void drawTextureQuad(Texture2D texture, Vector2 tiling, Vector2 offset, Rectangle quad, Color tint);
        void drawTextureTiled(Texture2D texture, Rectangle source, Rectangle dest, Vector2 origin, float rotation, float scale, Color tint);
        void drawTexturePro(Texture2D texture, Rectangle source, Rectangle dest, Vector2 origin, float rotation, Color tint);
        void drawTextureNPatch(Texture2D texture, NPatchInfo nPatchInfo, Rectangle dest, Vector2 origin, float rotation, Color tint);
        void drawTexturePoly(Texture2D texture, Vector2 center, std::unique_ptr<Vector2> points, std::unique_ptr<Vector2> texcoords, int pointsCount, Color tint);

        //! Color/pixel related functions
        Color fade(Color color, float alpha);
        int colorToInt(Color color);
        Vector4 colorNormalize(Color color);
        Color colorFromNormalized(Vector4 normalized);
        Vector3 colorToHSV(Color color);
        Color colorFromHSV(float hue, float saturation, float value);
        Color colorAlpha(Color color, float alpha);
        Color colorAlphaBlend(Color dst, Color src, Color tint);
        Color getColor(unsigned int hexValue);
        Color getPixelColor(std::any srcPtr, int format);
        void setPixelColor(std::any dstPtr, Color color, int format);
        int getPixelDataSize(int width, int height, int format);


    protected:
    private:
};

#endif /* !TEXTURES_HPP_ */
