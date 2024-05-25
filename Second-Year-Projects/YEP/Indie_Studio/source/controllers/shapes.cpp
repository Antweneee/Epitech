/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** rectangle
*/

#include "Shapes.hpp"
#include <memory>

Rectangle Shapes::initRectangle(Vector2 position, Vector2 dimension)
{
    Rectangle rec = {position.x, position.y, dimension.x, dimension.y};
    return rec;
}

//! Basic shapes drawing functions
void Shapes::drawPixel(Vector2 position, Color color)
{
    DrawPixel(position.x, position.y, color);
}

void Shapes::drawPixelV(Vector2 position, Color color)
{
    DrawPixelV(position, color);
}

void Shapes::drawLine(Vector2 startPosition, Vector2 endPosition, Color color)
{
    DrawLine(startPosition.x, startPosition.y, endPosition.x, endPosition.y, color);
}

void Shapes::drawLineV(Vector2 startPos, Vector2 endPos, Color color)
{
    DrawLineV(startPos, endPos, color);
}

void Shapes::drawLineEx(Vector2 startPos, Vector2 endPos, float thick, Color color)
{
    DrawLineEx(startPos, endPos, thick, color);
}

void Shapes::drawLineBezier(Vector2 startPos, Vector2 endPos, float thick, Color color)
{
    DrawLineBezier(startPos, endPos, thick, color);
}

void Shapes::drawLineBezierQuad(Vector2 startPos, Vector2 endPos, Vector2 controlPos, float thick, Color color)
{
    DrawLineBezierQuad(startPos, endPos, controlPos, thick, color);
}

void Shapes::drawLineBezierCubic(Vector2 startPos, Vector2 endPos, Vector2 startControlPos, Vector2 endControlPos, float thick, Color color)
{
    DrawLineBezierCubic(startPos, endPos, startControlPos, endControlPos, thick, color);
}

void Shapes::drawLineStrip(Vector2 points, int pointsCount, Color color)
{
    DrawLineStrip(&points, pointsCount, color);
}

void Shapes::drawCircle(int centerX, int centerY, float radius, Color color)
{
    DrawCircle(centerX, centerY, radius, color);
}

void Shapes::drawCircleSector(Vector2 center, float radius, float startAngle, float endAngle, int segments, Color color)
{
    DrawCircleSector(center, radius, startAngle, endAngle, segments, color);
}

void Shapes::drawCircleSectorLines(Vector2 center, float radius, float startAngle, float endAngle, int segments, Color color)
{
    DrawCircleSectorLines(center, radius, startAngle, endAngle, segments, color);
}

void Shapes::drawCircleGradient(int centerX, int centerY, float radius, Color color1, Color color2)
{
    DrawCircleGradient(centerX, centerY, radius, color1, color2);
}

void Shapes::drawCircleV(Vector2 center, float radius, Color color)
{
    DrawCircleV(center, radius, color);
}

void Shapes::drawCircleLines(int centerX, int centerY, float radius, Color color)
{
    DrawCircleLines(centerX, centerY, radius, color);
}

void Shapes::drawEllipse(int centerX, int centerY, float radiusH, float radiusV, Color color)
{
    DrawEllipse(centerX, centerY, radiusH, radiusV, color);
}

void Shapes::drawEllipseLines(int centerX, int centerY, float radiusH, float radiusV, Color color)
{
    DrawEllipseLines(centerX, centerY, radiusH, radiusV, color);
}

void Shapes::drawRing(Vector2 center, float innerRadius, float outerRadius, float startAngle, float endAngle, int segments, Color color)
{
    DrawRing(center, innerRadius, outerRadius, startAngle, endAngle, segments, color);
}

void Shapes::drawRingLines(Vector2 center, float innerRadius, float outerRadius, float startAngle, float endAngle, int segments, Color color)
{
    DrawRingLines(center, innerRadius, outerRadius, startAngle, endAngle, segments, color);
}

void Shapes::drawRectangleRec(Rectangle rec, Color color)
{
    DrawRectangleRec(rec, color);
}

void Shapes::drawRectangleLines(Vector2 position, Vector2 dimension, Color color)
{
    DrawRectangleLines(position.x, position.y, dimension.y, dimension.x, color);
}

void Shapes::drawRectangle(Vector2 position, Vector2 dimension, Color color)
{
    DrawRectangle(position.x, position.y, dimension.x, dimension.y, color);
}

void Shapes::drawRectangleV(Vector2 position, Vector2 size, Color color)
{
    DrawRectangleV(position, size, color);
}

void Shapes::drawRectanglePro(Rectangle rec, Vector2 origin, float rotation, Color color)
{
    DrawRectanglePro(rec, origin, rotation, color);
}

void Shapes::drawRectangleGradientV(Vector2 position, Vector2 dimension, Color color1, Color color2)
{
    DrawRectangleGradientV(position.x, position.y, dimension.x, dimension.y, color1, color2);
}

void Shapes::drawRectangleGradientH(Vector2 position, Vector2 dimension, Color color1, Color color2)
{
    DrawRectangleGradientH(position.x, position.y, dimension.x, dimension.y, color1, color2);
}

void Shapes::drawRectangleGradientEx(Rectangle rec, Color col1, Color col2, Color col3, Color col4)
{
    DrawRectangleGradientEx(rec, col1, col2, col3, col4);
}

void Shapes::drawRectangleLinesEx(Rectangle rec, int lineThick, Color color)
{
    DrawRectangleLinesEx(rec, lineThick, color);
}

void Shapes::drawRectangleRounded(Rectangle rec, float roundness, int segments, Color color)
{
    DrawRectangleRounded(rec, roundness, segments, color);
}

void Shapes::drawRectangleRoundedLines(Rectangle rec, float roundness, int segments, int lineThick, Color color)
{
    DrawRectangleRoundedLines(rec, roundness, segments, lineThick, color);
}

void Shapes::drawTriangle(Vector2 v1, Vector2 v2, Vector2 v3, Color color)
{
    DrawTriangle(v1, v2, v3, color);
}

void Shapes::drawTriangleLines(Vector2 v1, Vector2 v2, Vector2 v3, Color color)
{
    DrawTriangleLines(v1, v2, v3, color);
}

void Shapes::drawTriangleFan(Vector2 points, int pointsCount, Color color)
{
    DrawTriangleFan(&points, pointsCount, color);
}

void Shapes::drawTriangleStrip(Vector2 points, int pointsCount, Color color)
{
    DrawTriangleStrip(&points, pointsCount, color);
}

void Shapes::drawPoly(Vector2 center, int sides, float radius, float rotation, Color color)
{
    DrawPoly(center, sides, radius, rotation, color);
}

void Shapes::drawPolyLines(Vector2 center, int sides, float radius, float rotation, Color color)
{
    DrawPolyLines(center, sides, radius, rotation, color);
}

void Shapes::drawPolyLinesEx(Vector2 center, int sides, float radius, float rotation, float lineThick, Color color)
{
    DrawPolyLinesEx(center, sides, radius, rotation, lineThick, color);
}
//! Basic shapes collision detection functions
bool Shapes::checkCollisionRecs(Rectangle rec1, Rectangle rec2)
{
    return CheckCollisionRecs(rec1, rec2);
}

bool Shapes::checkCollisionCircles(Vector2 center1, float radius1, Vector2 center2, float radius2)
{
    return CheckCollisionCircles(center1, radius1, center2, radius2);
}

bool Shapes::checkCollisionCircleRec(Vector2 center, float radius, Rectangle rec)
{
    return CheckCollisionCircleRec(center, radius, rec);
}

bool Shapes::checkCollisionPointRec(Vector2 point, Rectangle rec)
{
    return CheckCollisionPointRec(point, rec);
}

bool Shapes::checkCollisionPointCircle(Vector2 point, Vector2 center, float radius)
{
    return CheckCollisionPointCircle(point, center, radius);
}

bool Shapes::checkCollisionPointTriangle(Vector2 point, Vector2 p1, Vector2 p2, Vector2 p3)
{
    return CheckCollisionPointTriangle(point, p1, p2, p3);
}

bool Shapes::checkCollisionLines(Vector2 startPos1, Vector2 endPos1, Vector2 startPos2, Vector2 endPos2, Vector2 collisionPoint)
{
    return CheckCollisionLines(startPos1, endPos1, startPos2, endPos2, &collisionPoint);
}

bool Shapes::checkCollisionPointLine(Vector2 point, Vector2 p1, Vector2 p2, int threshold)
{
    return CheckCollisionPointLine(point, p1, p2, threshold);
}

Rectangle Shapes::getCollisionRec(Rectangle rec1, Rectangle rec2)
{
    return GetCollisionRec(rec1, rec2);
}