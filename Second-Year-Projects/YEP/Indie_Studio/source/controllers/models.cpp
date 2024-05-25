/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** models
*/

#include "Models.hpp"

Models::Models()
{

}

Models::~Models()
{

}

void Models::drawLine3D(Vector3 startPos, Vector3 endPos, Color color)
{
    DrawLine3D(startPos, endPos, color);
}

void Models::drawPoint3D(Vector3 position, Color color)
{
    DrawPoint3D(position, color);
}

void Models::drawCircle3D(Vector3 center, float radius, Vector3 rotationAxis, float rotationAngle, Color color)
{
    DrawCircle3D(center, radius, rotationAxis, rotationAngle, color);
}

void Models::drawTriangle3D(Vector3 v1, Vector3 v2, Vector3 v3, Color color)
{
    DrawTriangle3D(v1, v2, v3, color);
}

void Models::drawTriangleStrip3D(Vector3 points, int pointsCount, Color color)
{
    DrawTriangleStrip3D(&points, pointsCount, color);
}

void Models::drawCube(Vector3 position, float width, float height, float length, Color color)
{
    DrawCube(position, width, height, length, color);
}

void Models::drawCubeV(Vector3 position, Vector3 size, Color color)
{
    DrawCubeV(position, size, color);
}

void Models::drawCubeWires(Vector3 position, float width, float height, float length, Color color)
{
    DrawCubeWires(position, width, height, length, color);
}

void Models::drawCubeTexture(Texture2D texture, Vector3 position, float width, float height, float length, Color color)
{
    DrawCubeTexture(texture, position, width, height, length, color);
}

void Models::drawCubeTextureRec(Texture2D texture, Rectangle source, Vector3 position, float width, float height, float length, Color color)
{
    DrawCubeTextureRec(texture, source, position, width, height, length, color);
}

void Models::drawSphere(Vector3 centerPos, float radius, Color color)
{
    DrawSphere(centerPos, radius, color);
}

void Models::drawSphereEx(Vector3 centerPos, float radius, int rings, int slices, Color color)
{
    DrawSphereEx(centerPos, radius, rings, slices, color);
}

void Models::drawSphereWires(Vector3 centerPos, float radius, int rings, int slices, Color color)
{
    DrawSphereWires(centerPos, radius, rings, slices, color);
}

void Models::drawCylinder(Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color)
{
    DrawCylinder(position, radiusTop, radiusBottom, height, slices, color);
}

void Models::drawCylinderEx(Vector3 startPos, Vector3 endPos, float startRadius, float endRadius, int sides, Color color)
{
    DrawCylinderEx(startPos, endPos, startRadius, endRadius, sides, color);
}

void Models::drawCylinderWires(Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color)
{
    DrawCylinderWires(position, radiusTop, radiusBottom, height, slices, color);
}

void Models::drawCylinderWiresEx(Vector3 startPos, Vector3 endPos, float startRadius, float endRadius, int sides, Color color)
{
    DrawCylinderWiresEx(startPos, endPos, startRadius, endRadius, sides, color);
}

void Models::drawPlane(Vector3 centerPos, Vector2 size, Color color)
{
    DrawPlane(centerPos, size, color);
}

void Models::drawRay(Ray ray, Color color)
{
    DrawRay(ray, color);
}

void Models::drawGrid(int slices, float spacing)
{
    DrawGrid(slices, spacing);
}

//! Model loading/unloading functions
Model Models::loadModel(const std::string& fileName)
{
    return LoadModel(fileName.c_str());
}

Model Models::loadModelFromMesh(Mesh mesh)
{
    return LoadModelFromMesh(mesh);
}

void Models::unloadModel(Model model)
{
    UnloadModel(model);
}

void Models::unloadModelKeepMeshes(Model model)
{
    UnloadModelKeepMeshes(model);
}

BoundingBox Models::getModelBoundingBox(Model model)
{
    return GetModelBoundingBox(model);
}

//! Model drawing functions
void Models::drawModel(Model model, Vector3 position, float scale, Color tint)
{
    DrawModel(model, position, scale, tint);
}

void Models::drawModelEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint)
{
    DrawModelEx(model, position, rotationAxis, rotationAngle, scale, tint);
}

void Models::drawModelWires(Model model, Vector3 position, float scale, Color tint)
{
    DrawModelWires(model, position, scale, tint);
}

void Models::drawModelWiresEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint)
{
    DrawModelWiresEx(model, position, rotationAxis, rotationAngle, scale, tint);
}

void Models::drawBoundingBox(BoundingBox box, Color color)
{
    DrawBoundingBox(box, color);
}

void Models::drawBillboard(Camera camera, Texture2D texture, Vector3 position, float size, Color tint)
{
    DrawBillboard(camera, texture, position, size, tint);
}

void Models::drawBillboardRec(Camera camera, Texture2D texture, Rectangle source, Vector3 position, Vector2 size, Color tint)
{
    DrawBillboardRec(camera, texture, source, position, size, tint);
}

void Models::drawBillboardPro(Camera camera, Texture2D texture, Rectangle source, Vector3 position, Vector3 up, Vector2 size, Vector2 origin, float rotation, Color tint)
{
    DrawBillboardPro(camera, texture, source, position, up, size, origin, rotation, tint);
}

//! Mesh management functions
void Models::uploadMesh(Mesh mesh, bool dynamic)
{
    UploadMesh(&mesh, dynamic);
}

void Models::updateMeshBuffer(Mesh mesh, int index, std::any data, int dataSize, int offset)
{
    UpdateMeshBuffer(mesh, index, std::any_cast<void*>(data), dataSize, offset);
}

void Models::unloadMesh(Mesh mesh)
{
    UnloadMesh(mesh);
}
void Models::drawMesh(Mesh mesh, Material material, Matrix transform)
{
    DrawMesh(mesh, material, transform);
}

void Models::drawMeshInstanced(Mesh mesh, Material material, Matrix transforms, int instances)
{
    DrawMeshInstanced(mesh, material, &transforms, instances);
}

bool Models::exportMesh(Mesh mesh, const std::string& fileName)
{
    return ExportMesh(mesh, fileName.c_str());
}

BoundingBox Models::getMeshBoundingBox(Mesh mesh)
{
    return GetMeshBoundingBox(mesh);
}

void Models::genMeshTangents(Mesh mesh)
{
    GenMeshTangents(&mesh);
}

void Models::genMeshBinormals(Mesh mesh)
{
    GenMeshBinormals(&mesh);
}

//! Mesh generation functions
Mesh Models::genMeshPoly(int sides, float radius)
{
    return GenMeshPoly(sides, radius);
}

Mesh Models::genMeshPlane(float width, float length, int resX, int resZ)
{
    return GenMeshPlane(width, length, resX, resZ);
}

Mesh Models::genMeshCube(float width, float height, float length)
{
    return GenMeshCube(width, height, length);
}
Mesh Models::genMeshSphere(float radius, int rings, int slices)
{
    return GenMeshSphere(radius, rings, slices);
}

Mesh Models::genMeshHemiSphere(float radius, int rings, int slices)
{
    return GenMeshHemiSphere(radius, rings, slices);
}

Mesh Models::genMeshCylinder(float radius, float height, int slices)
{
    return GenMeshCylinder(radius, height, slices);
}

Mesh Models::genMeshCone(float radius, float height, int slices)
{
    return GenMeshCone(radius, height, slices);
}

Mesh Models::genMeshTorus(float radius, float size, int radSeg, int sides)
{
    return GenMeshTorus(radius, size, radSeg, sides);
}

Mesh Models::genMeshKnot(float radius, float size, int radSeg, int sides)
{
    return GenMeshKnot(radius, size, radSeg, sides);
}

Mesh Models::genMeshHeightmap(Image heightmap, Vector3 size)
{
    return GenMeshHeightmap(heightmap, size);
}

Mesh Models::genMeshCubicmap(Image cubicmap, Vector3 cubeSize)
{
    return GenMeshCubicmap(cubicmap, cubeSize);
}

std::shared_ptr<Material> Models::loadMaterials(const std::string& fileName, int materialCount)
{
    std::shared_ptr<Material> data = std::shared_ptr<Material>(LoadMaterials(fileName.c_str(), &materialCount));
    return data;
}

Material Models::loadMaterialDefault(void)
{
    return LoadMaterialDefault();
}

void Models::unloadMaterial(Material material)
{
    UnloadMaterial(material);
}

void Models::setMaterialTexture(Material material, int mapType, Texture2D texture)
{
    SetMaterialTexture(&material, mapType, texture);
}

void Models::setModelMeshMaterial(Model model, int meshId, int materialId)
{
    SetModelMeshMaterial(&model, meshId, materialId);
}

//! Model animations loading/unloading functions
std::unique_ptr<ModelAnimation> Models::loadModelAnimations(const std::string& fileName, unsigned int animCount)
{
    std::unique_ptr<ModelAnimation> data = std::unique_ptr<ModelAnimation>(LoadModelAnimations(fileName.c_str(), &animCount));
    return data;
}

void Models::updateModelAnimation(Model model, ModelAnimation anim, int frame)
{
    UpdateModelAnimation(model, anim, frame);
}

void Models::unloadModelAnimation(ModelAnimation anim)
{
    UnloadModelAnimation(anim);
}

void Models::unloadModelAnimations(ModelAnimation animations, unsigned int count)
{
    UnloadModelAnimations(&animations, count);
}

bool Models::isModelAnimationValid(Model model, ModelAnimation anim)
{
    return IsModelAnimationValid(model, anim);
}

//! Collision detection functions
bool Models::checkCollisionSpheres(Vector3 center1, float radius1, Vector3 center2, float radius2)
{
    return CheckCollisionSpheres(center1, radius1, center2, radius2);
}

bool Models::checkCollisionBoxes(BoundingBox box1, BoundingBox box2)
{
    return CheckCollisionBoxes(box1, box2);
}

bool Models::checkCollisionBoxSphere(BoundingBox box, Vector3 center, float radius)
{
    return CheckCollisionBoxSphere(box, center, radius);
}

RayCollision Models::getRayCollisionSphere(Ray ray, Vector3 center, float radius)
{
    return GetRayCollisionSphere(ray, center, radius);
}

RayCollision Models::getRayCollisionBox(Ray ray, BoundingBox box)
{
    return GetRayCollisionBox(ray, box);
}

RayCollision Models::getRayCollisionModel(Ray ray, Model model)
{
    return GetRayCollisionModel(ray, model);
}

RayCollision Models::getRayCollisionMesh(Ray ray, Mesh mesh, Matrix transform)
{
    return GetRayCollisionMesh(ray, mesh, transform);
}

RayCollision Models::getRayCollisionTriangle(Ray ray, Vector3 p1, Vector3 p2, Vector3 p3)
{
    return GetRayCollisionTriangle(ray, p1, p2, p3);
}

RayCollision Models::getRayCollisionQuad(Ray ray, Vector3 p1, Vector3 p2, Vector3 p3, Vector3 p4)
{
    return GetRayCollisionQuad(ray, p1, p2, p3, p4);
}