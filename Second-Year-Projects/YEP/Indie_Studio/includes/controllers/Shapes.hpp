/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** Rectangle
*/

#ifndef RECTANGLE_HPP_
    #define RECTANGLE_HPP_
    #include <raylib.h>
    #include <memory>


class Shapes {
    public:
        Shapes() {};
        ~Shapes() {};

        Rectangle initRectangle(Vector2 position, Vector2 dimension);
        //! Basic Shapes drawing functions
        void drawPixel(Vector2 position, Color color);
        void drawPixelV(Vector2 position, Color color);
        void drawLine(Vector2 startPos, Vector2 endPos, Color color);
        void drawLineV(Vector2 startPos, Vector2 endPos, Color color);
        void drawLineEx(Vector2 startPos, Vector2 endPos, float thick, Color color);
        void drawLineBezier(Vector2 startPos, Vector2 endPos, float thick, Color color);
        void drawLineBezierQuad(Vector2 startPos, Vector2 endPos, Vector2 controlPos, float thick, Color color);
        void drawLineBezierCubic(Vector2 startPos, Vector2 endPos, Vector2 startControlPos, Vector2 endControlPos, float thick, Color color);
        void drawLineStrip(Vector2 points, int pointsCount, Color color);
        void drawCircle(int centerX, int centerY, float radius, Color color);
        void drawCircleSector(Vector2 center, float radius, float startAngle, float endAngle, int segments, Color color);
        void drawCircleSectorLines(Vector2 center, float radius, float startAngle, float endAngle, int segments, Color color);
        void drawCircleGradient(int centerX, int centerY, float radius, Color color1, Color color2);
        void drawCircleV(Vector2 center, float radius, Color color);
        void drawCircleLines(int centerX, int centerY, float radius, Color color);
        void drawEllipse(int centerX, int centerY, float radiusH, float radiusV, Color color);
        void drawEllipseLines(int centerX, int centerY, float radiusH, float radiusV, Color color);
        void drawRing(Vector2 center, float innerRadius, float outerRadius, float startAngle, float endAngle, int segments, Color color);
        void drawRingLines(Vector2 center, float innerRadius, float outerRadius, float startAngle, float endAngle, int segments, Color color);
        void drawRectangleRec(Rectangle rec, Color color);
        void drawRectangleLines(Vector2 pos, Vector2 dim, Color color);
        void drawRectangle(Vector2 pos, Vector2 dim, Color color);
        void drawRectangleV(Vector2 position, Vector2 size, Color color);
        void drawRectanglePro(Rectangle rec, Vector2 origin, float rotation, Color color);
        void drawRectangleGradientV(Vector2 position, Vector2 dimension, Color color1, Color color2);
        void drawRectangleGradientH(Vector2 position, Vector2 dimension, Color color1, Color color2);
        void drawRectangleGradientEx(Rectangle rec, Color col1, Color col2, Color col3, Color col4);
        void drawRectangleLinesEx(Rectangle rec, int lineThick, Color color);
        void drawRectangleRounded(Rectangle rec, float roundness, int segments, Color color);
        void drawRectangleRoundedLines(Rectangle rec, float roundness, int segments, int lineThick, Color color);
        void drawTriangle(Vector2 v1, Vector2 v2, Vector2 v3, Color color);
        void drawTriangleLines(Vector2 v1, Vector2 v2, Vector2 v3, Color color);
        void drawTriangleFan(Vector2 points, int pointsCount, Color color);
        void drawTriangleStrip(Vector2 points, int pointsCount, Color color);
        void drawPoly(Vector2 center, int sides, float radius, float rotation, Color color);
        void drawPolyLines(Vector2 center, int sides, float radius, float rotation, Color color);
        void drawPolyLinesEx(Vector2 center, int sides, float radius, float rotation, float lineThick, Color color);

        //! Basic shapes collision detection functions
        bool checkCollisionRecs(Rectangle rec1, Rectangle rec2);
        bool checkCollisionCircles(Vector2 center1, float radius1, Vector2 center2, float radius2);
        bool checkCollisionCircleRec(Vector2 center, float radius, Rectangle rec);
        bool checkCollisionPointRec(Vector2 point, Rectangle rec);
        bool checkCollisionPointCircle(Vector2 point, Vector2 center, float radius);
        bool checkCollisionPointTriangle(Vector2 point, Vector2 p1, Vector2 p2, Vector2 p3);
        bool checkCollisionLines(Vector2 startPos1, Vector2 endPos1, Vector2 startPos2, Vector2 endPos2, Vector2 collisionPoint);
        bool checkCollisionPointLine(Vector2 point, Vector2 p1, Vector2 p2, int threshold);
        Rectangle getCollisionRec(Rectangle rec1, Rectangle rec2);
    protected:
    private:
};

#endif /* !RECTANGLE_HPP_ */
