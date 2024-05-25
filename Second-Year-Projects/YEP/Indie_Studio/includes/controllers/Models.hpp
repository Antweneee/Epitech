/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** Models
*/

#ifndef MODELS_HPP_
    #define MODELS_HPP_
    #include <raylib.h>
    #include <memory>
    #include <string>
    #include <any>

class Models {
    public:
        Models();
        ~Models();

        //! Basic geometric 3D shapes drawing functions
        void drawLine3D(Vector3 startPos, Vector3 endPos, Color color);
        void drawPoint3D(Vector3 position, Color color);
        void drawCircle3D(Vector3 center, float radius, Vector3 rotationAxis, float rotationAngle, Color color);
        void drawTriangle3D(Vector3 v1, Vector3 v2, Vector3 v3, Color color);
        void drawTriangleStrip3D(Vector3 points, int pointsCount, Color color);
        void drawCube(Vector3 position, float width, float height, float length, Color color);
        void drawCubeV(Vector3 position, Vector3 size, Color color);
        void drawCubeWires(Vector3 position, float width, float height, float length, Color color);
        void drawCubeTexture(Texture2D texture, Vector3 position, float width, float height, float length, Color color);
        void drawCubeTextureRec(Texture2D texture, Rectangle source, Vector3 position, float width, float height, float length, Color color);
        void drawSphere(Vector3 centerPos, float radius, Color color);
        void drawSphereEx(Vector3 centerPos, float radius, int rings, int slices, Color color);
        void drawSphereWires(Vector3 centerPos, float radius, int rings, int slices, Color color);
        void drawCylinder(Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color);
        void drawCylinderEx(Vector3 startPos, Vector3 endPos, float startRadius, float endRadius, int sides, Color color);
        void drawCylinderWires(Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color);
        void drawCylinderWiresEx(Vector3 startPos, Vector3 endPos, float startRadius, float endRadius, int sides, Color color);
        void drawPlane(Vector3 centerPos, Vector2 size, Color color);
        void drawRay(Ray ray, Color color);
        void drawGrid(int slices, float spacing);

        //! Model loading/unloading functions
        Model loadModel(const std::string& fileName);
        Model loadModelFromMesh(Mesh mesh);
        void unloadModel(Model model);
        void unloadModelKeepMeshes(Model model);
        BoundingBox getModelBoundingBox(Model model);
        BoundingBox getModelBoundingBoxEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle);

        //! Model drawing functions
        void drawModel(Model model, Vector3 position, float scale, Color tint);
        void drawModelEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint);
        void drawModelWires(Model model, Vector3 position, float scale, Color tint);
        void drawModelWiresEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint);
        void drawBoundingBox(BoundingBox box, Color color);
        void drawBillboard(Camera camera, Texture2D texture, Vector3 position, float size, Color tint);
        void drawBillboardRec(Camera camera, Texture2D texture, Rectangle source, Vector3 position, Vector2 size, Color tint);
        void drawBillboardPro(Camera camera, Texture2D texture, Rectangle source, Vector3 position, Vector3 up, Vector2 size, Vector2 origin, float rotation, Color tint);

        //! Mesh management functions
        void uploadMesh(Mesh mesh, bool dynamic);
        void updateMeshBuffer(Mesh mesh, int index, std::any data, int dataSize, int offset);
        void unloadMesh(Mesh mesh);
        void drawMesh(Mesh mesh, Material material, Matrix transform);
        void drawMeshInstanced(Mesh mesh, Material material, Matrix transforms, int instances);
        bool exportMesh(Mesh mesh, const std::string& fileName);
        BoundingBox getMeshBoundingBox(Mesh mesh);
        void genMeshTangents(Mesh mesh);
        void genMeshBinormals(Mesh mesh);

        //! Mesh generation functions
        Mesh genMeshPoly(int sides, float radius);
        Mesh genMeshPlane(float width, float length, int resX, int resZ);
        Mesh genMeshCube(float width, float height, float length);
        Mesh genMeshSphere(float radius, int rings, int slices);
        Mesh genMeshHemiSphere(float radius, int rings, int slices);
        Mesh genMeshCylinder(float radius, float height, int slices);
        Mesh genMeshCone(float radius, float height, int slices);
        Mesh genMeshTorus(float radius, float size, int radSeg, int sides);
        Mesh genMeshKnot(float radius, float size, int radSeg, int sides);
        Mesh genMeshHeightmap(Image heightmap, Vector3 size);
        Mesh genMeshCubicmap(Image cubicmap, Vector3 cubeSize);

        //! Material loading/unloading functions
        std::shared_ptr<Material> loadMaterials(const std::string& fileName, int materialCount);
        Material loadMaterialDefault(void);
        void unloadMaterial(Material material);
        void setMaterialTexture(Material material, int mapType, Texture2D texture);
        void setModelMeshMaterial(Model model, int meshId, int materialId);
        //! Model animations loading/unloading functions
        std::unique_ptr<ModelAnimation> loadModelAnimations(const std::string& fileName, unsigned int animCount);
        void updateModelAnimation(Model model, ModelAnimation anim, int frame);
        void unloadModelAnimation(ModelAnimation anim);
        void unloadModelAnimations(ModelAnimation animations, unsigned int count);
        bool isModelAnimationValid(Model model, ModelAnimation anim);

        //! Collision detection functions
        bool checkCollisionSpheres(Vector3 center1, float radius1, Vector3 center2, float radius2);
        bool checkCollisionBoxes(BoundingBox box1, BoundingBox box2);
        bool checkCollisionBoxSphere(BoundingBox box, Vector3 center, float radius);
        RayCollision getRayCollisionSphere(Ray ray, Vector3 center, float radius);
        RayCollision getRayCollisionBox(Ray ray, BoundingBox box);
        RayCollision getRayCollisionModel(Ray ray, Model model);
        RayCollision getRayCollisionMesh(Ray ray, Mesh mesh, Matrix transform);
        RayCollision getRayCollisionTriangle(Ray ray, Vector3 p1, Vector3 p2, Vector3 p3);
        RayCollision getRayCollisionQuad(Ray ray, Vector3 p1, Vector3 p2, Vector3 p3, Vector3 p4);
    protected:
    private:
};

#endif /* !MODELS_HPP_ */
