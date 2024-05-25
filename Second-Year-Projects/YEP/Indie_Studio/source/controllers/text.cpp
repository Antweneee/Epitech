/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** text
*/

#include "Text.hpp"
#include <string>
#include <vector>
#include <memory>

Text::Text()
{

}

Text::~Text()
{

}
//! Text drawing functions
void Text::drawFPS(Vector2 position)
{
    DrawFPS(position.x, position.y);
}

void Text::drawText(const std::string& text, Vector2 position, int fontSize, Color color)
{
    DrawText(text.c_str(), position.x, position.y, fontSize, color);
}

void Text::drawTextEx(Font font, const std::string& text, Vector2 position, float fontSize, float spacing, Color tint)
{
    DrawTextEx(font, text.c_str(), position, fontSize, spacing, tint);
}

void Text::drawTextPro(Font font, const std::string& text, Vector2 position, Vector2 origin, float rotation, float fontSize, float spacing, Color tint)
{
    DrawTextPro(font, text.c_str(), position, origin, rotation, fontSize, spacing, tint);
}

void Text::drawTextCodepoint(Font font, int codepoint, Vector2 position, float fontSize, Color tint)
{
    DrawTextCodepoint(font, codepoint, position, fontSize, tint);
}

int Text::measureText(const std::string& text, int fontSize)
{
    return MeasureText(text.c_str(), fontSize);
}

Vector2 Text::measureTextEx(Font font, const std::string& text, float fontSize, float spacing)
{
    return MeasureTextEx(font, text.c_str(), fontSize, spacing);
}

int Text::getGlyphIndex(Font font, int codepoint)
{
    return GetGlyphIndex(font, codepoint);
}

GlyphInfo Text::getGlyphInfo(Font font, int codepoint)
{
    return GetGlyphInfo(font, codepoint);
}

Rectangle Text::getGlyphAtlasRec(Font font, int codepoint)
{
    return GetGlyphAtlasRec(font, codepoint);
}

//! Text codepoints management functions (unicode characters)
std::unique_ptr<int> Text::loadCodepoints(const std::string& text, int count)
{
    std::unique_ptr<int> data = std::unique_ptr<int>(LoadCodepoints(text.c_str(), &count));
    return data;
}

void Text::unloadCodepoints(int codepoints)
{
    UnloadCodepoints(&codepoints);
}

int Text::getCodepointCount(const std::string& text)
{
    return GetCodepointCount(text.c_str());
}

int Text::getCodepoint(const std::string& text, int bytesProcessed)
{
    return GetCodepoint(text.c_str(), &bytesProcessed);
}

const std::string Text::codepointToUTF8(int codepoint, int byteSize)
{
    const std::string data = CodepointToUTF8(codepoint, &byteSize);
    return data;
}

std::string Text::textCodepointsToUTF8(int codepoints, int length)
{
    std::string data = TextCodepointsToUTF8(&codepoints, length);
    return data;
}

//! Text strings management functions (no utf8 strings, only byte chars)
//! NOTE: Some strings allocate memory internally for returned strings, just be careful!
int Text::textCopy(std::string& dst, const std::string& src)
{
    return TextCopy(dst.data(), src.c_str());
}

bool Text::textIsEqual(const std::string& text1, const std::string& text2)
{
    return TextIsEqual(text1.c_str(), text2.c_str());
}

unsigned int Text::textLength(const std::string& text)
{
    return TextLength(text.c_str());
}

const std::string Text::textFormat(const std::string& text, va_list args)
{
    const std::string data = TextFormat(text.c_str(), args);
    return data;
}

const std::string Text::textSubtext(const std::string& text, int position, int length)
{
    const std::string data = TextSubtext(text.c_str(), position, length);
    return data;
}

std::string Text::textReplace(std::string& text, const std::string& replace, const std::string& by)
{
    std::string data = TextReplace(text.data(), replace.c_str(), by.c_str());
    return data;
}

int Text::textFindIndex(const std::string& text, const std::string& find)
{
    return TextFindIndex(text.c_str(), find.c_str());
}

const std::string Text::textToUpper(const std::string& text)
{
    const std::string data = TextToUpper(text.c_str());
    return data;
}

const std::string Text::textToLower(const std::string& text)
{
    const std::string data = TextToLower(text.c_str());
    return data;
}

const std::string Text::textToPascal(const std::string& text)
{
    const std::string data = TextToPascal(text.c_str());
    return data;
}

int Text::textToInteger(const std::string& text)
{
    return TextToInteger(text.c_str());
}