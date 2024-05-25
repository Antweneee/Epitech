/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** Text
*/

#ifndef TEXT_HPP_
    #define TEXT_HPP_
    #include <raylib.h>
    #include <string>
    #include <memory>

class Text {
    public:
        Text();
        ~Text();

        //! Text drawing functions
        void drawFPS(Vector2 position);
        void drawText(const std::string& text, Vector2 position, int fontSize, Color color);
        void drawTextEx(Font font, const std::string& text, Vector2 position, float fontSize, float spacing, Color tint);
        void drawTextPro(Font font, const std::string& , Vector2 position, Vector2 origin, float rotation, float fontSize, float spacing, Color tint);
        void drawTextCodepoint(Font font, int codepoint, Vector2 position, float fontSize, Color tint);
        //! Text misc. functions
        int measureText(const std::string& text, int fontSize);
        Vector2 measureTextEx(Font font, const std::string& text, float fontSize, float spacing);
        int getGlyphIndex(Font font, int codepoint);
        GlyphInfo getGlyphInfo(Font font, int codepoint);
        Rectangle getGlyphAtlasRec(Font font, int codepoint);
        // Text codepoints management functions (unicode characters)
        std::unique_ptr<int> loadCodepoints(const std::string& text, int count);
        void unloadCodepoints(int codepoints);
        int getCodepointCount(const std::string& text);
        int getCodepoint(const std::string& text, int bytesProcessed);
        const std::string codepointToUTF8(int codepoint, int byteSize);
        std::string textCodepointsToUTF8(int codepoints, int length);
        //! Text strings management functions (no utf8 strings, only byte chars)
        //! NOTE: Some strings allocate memory internally for returned strings, just be careful!
        int textCopy(std::string& dst, const std::string& src);
        bool textIsEqual(const std::string& text1, const std::string& text2);
        unsigned int textLength(const std::string& text);
        const std::string textFormat(const std::string& text, va_list args);
        const std::string textSubtext(const std::string& text, int position, int length);
        std::string textReplace(std::string& text, const std::string& replace, const std::string& by);
        std::string textInsert(const std::string& text, const std::string& insert, int position);
        int textFindIndex(const std::string& text, const std::string& find);
        const std::string textToUpper(const std::string& text);
        const std::string textToLower(const std::string& text);
        const std::string textToPascal(const std::string& text);
        int textToInteger(const std::string& text);
    protected:
    private:
};

#endif /* !TEXT_HPP_ */