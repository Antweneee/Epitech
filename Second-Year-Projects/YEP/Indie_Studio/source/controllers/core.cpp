/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** core
*/

#include "Core.hpp"

Core::Core()
{

}

Core::~Core()
{

}

//! Window-related functions
void Core::initWindow(int width, int height, const std::string& title)
{
    InitWindow(width, height, title.c_str());
}

bool Core::windowShouldClose(void)
{
    return WindowShouldClose();
}

void Core::closeWindow(void)
{
    CloseWindow();
}

bool Core::isWindowReady(void)
{
    return IsWindowReady();
}

bool Core::isWindowFullscreen(void)
{
    return IsWindowFullscreen();
}

bool Core::isWindowHidden(void)
{
    return IsWindowHidden();
}

bool Core::isWindowMinimized(void)
{
    return IsWindowMinimized();
}

bool Core::isWindowMaximized(void)
{
    return IsWindowMaximized();
}

bool Core::isWindowFocused(void)
{
    return IsWindowFocused();
}

bool Core::isWindowResized(void)
{
    return IsWindowResized();
}

bool Core::isWindowState(unsigned int flag)
{
    return IsWindowState(flag);
}

void Core::setWindowState(unsigned int flags)
{
    SetWindowState(flags);
}

void Core::clearWindowState(unsigned int flags)
{
    ClearWindowState(flags);
}

void Core::toggleFullscreen(void)
{
    ToggleFullscreen();
}

void Core::maximizeWindow(void)
{
    MaximizeWindow();
}

void Core::minimizeWindow(void)
{
    MinimizeWindow();
}

void Core::restoreWindow(void)
{
    RestoreWindow();
}

void Core::setWindowIcon(Image image)
{
    SetWindowIcon(image);
}

void Core::setWindowTitle(const std::string& title)
{
    SetWindowTitle(title.c_str());
}

void Core::setWindowPosition(int x, int y)
{
    SetWindowPosition(x, y);
}

void Core::setWindowMonitor(int monitor)
{
    SetWindowMonitor(monitor);
}

void Core::setWindowMinSize(int width, int height)
{
    SetWindowMinSize(width, height);
}

void Core::setWindowSize(int width, int height)
{
    SetWindowSize(width, height);
}

std::any Core::getWindowHandle(void)
{
    return std::any(std::make_shared<void*>(GetWindowHandle()));
}

int Core::getScreenWidth(void)
{
    return GetScreenWidth();
}

int Core::getScreenHeight(void)
{
    return GetScreenHeight();
}

int Core::getMonitorCount(void)
{
    return GetMonitorCount();
}

int Core::getCurrentMonitor(void)
{
    return GetCurrentMonitor();
}

Vector2 Core::getMonitorPosition(int monitor)
{
    return GetMonitorPosition(monitor);
}

int Core::getMonitorWidth(int monitor)
{
    return GetMonitorWidth(monitor);
}

int Core::getMonitorHeight(int monitor)
{
    return GetMonitorHeight(monitor);
}

int Core::getMonitorPhysicalWidth(int monitor)
{
    return GetMonitorPhysicalWidth(monitor);
}

int Core::getMonitorPhysicalHeight(int monitor)
{
    return GetMonitorPhysicalHeight(monitor);
}

int Core::getMonitorRefreshRate(int monitor)
{
    return GetMonitorRefreshRate(monitor);
}

Vector2 Core::getWindowPosition(void)
{
    return GetWindowPosition();
}

Vector2 Core::getWindowScaleDPI(void)
{
    return GetWindowScaleDPI();
}

const std::string Core::getMonitorName(int monitor)
{
    return GetMonitorName(monitor);
}

void Core::setClipboardText(const std::string& text)
{
    SetClipboardText(text.c_str());
}

const std::string Core::getClipboardText(void)
{
    return GetClipboardText();
}

//! Cursor-related functions
void Core::showCursor(void)
{
    ShowCursor();
}

void Core::hideCursor(void)
{
    HideCursor();
}

bool Core::isCursorHidden(void)
{
    return IsCursorHidden();
}

void Core::enableCursor(void)
{
    EnableCursor();
}

void Core::disableCursor(void)
{
    DisableCursor();
}

bool Core::isCursorOnScreen(void)
{
    return IsCursorOnScreen();
}

//! Drawing-related functions
void Core::clearBackground(Color color)
{
    ClearBackground(color);
}

void Core::beginDrawing(void)
{
    BeginDrawing();
}

void Core::endDrawing(void)
{
    EndDrawing();
}

void Core::beginMode2D(Camera2D camera)
{
    BeginMode2D(camera);
}

void Core::endMode2D(void)
{
    EndMode2D();
}

void Core::beginMode3D(Camera3D camera)
{
    BeginMode3D(camera);
}

void Core::endMode3D(void)
{
    EndMode3D();
}

void Core::beginTextureMode(RenderTexture2D target)
{
    BeginTextureMode(target);
}

void Core::endTextureMode(void)
{
    EndTextureMode();
}

void Core::beginShaderMode(Shader shader)
{
    BeginShaderMode(shader);
}

void Core::endShaderMode(void)
{
    EndShaderMode();
}

void Core::beginBlendMode(int mode)
{
    BeginBlendMode(mode);
}

void Core::endBlendMode(void)
{
    EndBlendMode();
}

void Core::beginScissorMode(int x, int y, int width, int height)
{
    BeginScissorMode(x, y, width, height);
}

void Core::endScissorMode(void)
{
    EndScissorMode();
}

void Core::beginVrStereoMode(VrStereoConfig config)
{
    BeginVrStereoMode(config);
}

void Core::endVrStereoMode(void)
{
    EndVrStereoMode();
}

//! VR stereo config functions for VR simulator
VrStereoConfig Core::loadVrStereoConfig(VrDeviceInfo device)
{
    return LoadVrStereoConfig(device);
}

void Core::unloadVrStereoConfig(VrStereoConfig config)
{
    UnloadVrStereoConfig(config);
}

//! Shader management functions
//! NOTE: Shader functionality is not available on OpenGL 1.1
Shader Core::loadShader(const std::string& vsFileName, const std::string& fsFileName)
{
    return LoadShader(vsFileName.c_str(), fsFileName.c_str());
}
Shader Core::loadShaderFromMemory(const std::string& vsCode, const std::string& fsCode)
{
    return LoadShaderFromMemory(vsCode.c_str(), fsCode.c_str());
}

int Core::getShaderLocation(Shader shader, const std::string& uniformName)
{
    return GetShaderLocation(shader, uniformName.c_str());
}

int Core::getShaderLocationAttrib(Shader shader, const std::string& attribName)
{
    return GetShaderLocationAttrib(shader, attribName.c_str());
}

void Core::setShaderValue(Shader shader, int locIndex, const std::string& value, int uniformType)
{
    SetShaderValue(shader, locIndex, value.c_str(), uniformType);
}

void Core::setShaderValueV(Shader shader, int locIndex, std::any value, int uniformType, int count)
{
    SetShaderValueV(shader, locIndex, std::any_cast<const void*>(value), uniformType, count);
}

void Core::setShaderValueMatrix(Shader shader, int locIndex, Matrix mat)
{
    SetShaderValueMatrix(shader, locIndex, mat);
}
void Core::setShaderValueTexture(Shader shader, int locIndex, Texture2D texture)
{
    SetShaderValueTexture(shader, locIndex, texture);
}

void Core::unloadShader(Shader shader)
{
    UnloadShader(shader);
}

//! Screen-space-related functions
Ray Core::getMouseRay(Vector2 mousePosition, Camera camera)
{
    return GetMouseRay(mousePosition, camera);
}

Matrix Core::getCameraMatrix(Camera camera)
{
    return GetCameraMatrix(camera);
}

Matrix Core::getCameraMatrix2D(Camera2D camera)
{
    return GetCameraMatrix2D(camera);
}

Vector2 Core::getWorldToScreen(Vector3 position, Camera camera)
{
    return GetWorldToScreen(position, camera);
}

Vector2 Core::getWorldToScreenEx(Vector3 position, Camera camera, int width, int height)
{
    return GetWorldToScreenEx(position, camera, width, height);
}

Vector2 Core::getWorldToScreen2D(Vector2 position, Camera2D camera)
{
    return GetWorldToScreen2D(position, camera);
}

Vector2 Core::getScreenToWorld2D(Vector2 position, Camera2D camera)
{
    return GetScreenToWorld2D(position, camera);
}

//! Timing-related functions
void Core::setTargetFPS(int fps)
{
    SetTargetFPS(fps);
}

int Core::getFPS(void)
{
    return GetFPS();
}

float Core::getFrameTime(void)
{
    return GetFrameTime();
}

double Core::getTime(void)
{
    return GetTime();
}

//! Misc. functions
int Core::getRandomValue(int min, int max)
{
    return GetRandomValue(min, max);
}

void Core::setRandomSeed(unsigned int seed)
{
    SetRandomSeed(seed);
}

void Core::takeScreenshot(const std::string& fileName)
{
    TakeScreenshot(fileName.c_str());
}

void Core::setConfigFlags(unsigned int flags)
{
    SetConfigFlags(flags);
}

// void Core::traceLog(int logLevel, std::string& text, ...)
// {
//     va_list args;
//     va_start(args, text);
//     TraceLog(logLevel, text.c_str(), args);
//     va_end(args);
// }

void Core::setTraceLogLevel(int logLevel)
{
    SetTraceLogLevel(logLevel);
}

std::any Core::memAlloc(int size)
{
    return std::any(std::make_shared<void*>(MemAlloc(size)));
}

std::any Core::memRealloc(std::any ptr, int size)
{
    return std::any(std::make_shared<void*>(MemRealloc(std::any_cast<void*>(ptr), size)));
}

void Core::memFree(std::any ptr)
{
    MemFree(std::any_cast<void*>(ptr));
}

//! Set custom callbacks
//! WARNING: Callbacks setup is intended for advance users
void Core::setTraceLogCallback(TraceLogCallback callback)
{
    SetTraceLogCallback(callback);
}

void Core::setLoadFileDataCallback(LoadFileDataCallback callback)
{
    SetLoadFileDataCallback(callback);
}

void Core::setSaveFileDataCallback(SaveFileDataCallback callback)
{
    SetSaveFileDataCallback(callback);
}

void Core::setLoadFileTextCallback(LoadFileTextCallback callback)
{
    SetLoadFileTextCallback(callback);
}

void Core::setSaveFileTextCallback(SaveFileTextCallback callback)
{
    SetSaveFileTextCallback(callback);
}

//! Files management functions
std::string loadFileData(const std::string& fileName, std::unique_ptr<unsigned int> bytesRead)
{
    return reinterpret_cast<char*>(LoadFileData(fileName.c_str(), bytesRead.get()));
}

void Core::unloadFileData(std::string& data)
{
    UnloadFileData(reinterpret_cast<unsigned char*>(data.data()));
}

bool Core::saveFileData(const std::string& fileName, std::any data, unsigned int bytesToWrite)
{
    return SaveFileData(fileName.c_str(), std::any_cast<void*>(data), bytesToWrite);
}

std::string Core::loadFileText(const std::string& fileName)
{
    return reinterpret_cast<char*>(LoadFileText(fileName.c_str()));
}

void Core::unloadFileText(std::string& text)
{
    UnloadFileText(reinterpret_cast<char*>(text.data()));
}

bool Core::saveFileText(const std::string& fileName, std::string& text)
{
    return SaveFileText(fileName.c_str(), reinterpret_cast<char*>(text.data()));
}

bool Core::fileExists(const std::string& fileName)
{
    return FileExists(fileName.c_str());
}

bool Core::directoryExists(const std::string& dirPath)
{
    return DirectoryExists(dirPath.c_str());
}

bool Core::isFileExtension(const std::string& fileName, const std::string& next)
{
    return IsFileExtension(fileName.c_str(), next.c_str());
}

const std::string& Core::getFileExtension(const std::string&fileName)
{
    return GetFileExtension(fileName.c_str());
}

const std::string& Core::getFileName(const std::string&filePath)
{
    return GetFileName(filePath.c_str());
}

const std::string& Core::getFileNameWithoutExt(const std::string&filePath)
{
    return GetFileNameWithoutExt(filePath.c_str());
}

const std::string& Core::getDirectoryPath(const std::string&filePath)
{
    return GetDirectoryPath(filePath.c_str());
}

const std::string& Core::getPrevDirectoryPath(const std::string& dirPath)
{
    return GetPrevDirectoryPath(dirPath.c_str());
}

const std::string& Core::getWorkingDirectory(void)
{
    return GetWorkingDirectory();
}

void Core::clearDirectoryFiles(void)
{
    ClearDirectoryFiles();
}

bool Core::changeDirectory(const std::string& dir)
{
    return ChangeDirectory(dir.c_str());
}

bool Core::isFileDropped(void)
{
    return IsFileDropped();
}

void Core::clearDroppedFiles(void)
{
    ClearDroppedFiles();
}

long Core::getFileModTime(const std::string& fileName)
{
    return GetFileModTime(fileName.c_str());
}

//! Compression/Encoding functionality
std::string Core::compressData(std::string& data, int dataLength, int compDataLength)
{
    return reinterpret_cast<char*>(CompressData(reinterpret_cast<unsigned char*>(data.data()), dataLength, &compDataLength));
}

std::string Core::decompressData(std::string& compData, int compDataLength, int dataLength)
{
    return reinterpret_cast<char*>(DecompressData(reinterpret_cast<unsigned char*>(compData.data()), compDataLength, &dataLength));
}

std::string Core::encodeDataBase64(const std::string& data, int dataLength, int outputLength)
{
    return reinterpret_cast<char*>(EncodeDataBase64(reinterpret_cast<const unsigned char*>(data.data()), dataLength, &outputLength));
}

std::string Core::decodeDataBase64(std::string& data, int outputLength)
{
    return reinterpret_cast<char*>(DecodeDataBase64(reinterpret_cast<unsigned char*>(data.data()), &outputLength));
}

//! Persistent storage management
bool Core::saveStorageValue(unsigned int position, int value)
{
    return SaveStorageValue(position, value);
}

int Core::loadStorageValue(unsigned int position)
{
    return LoadStorageValue(position);
}

//! Misc.
void Core::openURL(const std::string& url)
{
    OpenURL(url.c_str());
}

//! Input-related functions: keyboard
bool Core::isKeyPressed(int key)
{
    return IsKeyPressed(key);
}

bool Core::isKeyDown(int key)
{
    return IsKeyDown(key);
}
bool Core::isKeyReleased(int key)
{
    return IsKeyReleased(key);
}

bool Core::isKeyUp(int key)
{
    return IsKeyUp(key);
}

void Core::setExitKey(int key)
{
    SetExitKey(key);
}

int Core::getKeyPressed(void)
{
    return GetKeyPressed();
}

int Core::getCharPressed(void)
{
    return GetCharPressed();
}

//! Input-related functions: gamepads
bool Core::isGamepadAvailable(int gamepad)
{
    return IsGamepadAvailable(gamepad);
}

const std::string& Core::getGamepadName(int gamepad)
{
    return GetGamepadName(gamepad);
}

bool Core::isGamepadButtonPressed(int gamepad, int button)
{
    return IsGamepadButtonPressed(gamepad, button);
}

bool Core::isGamepadButtonDown(int gamepad, int button)
{
    return IsGamepadButtonDown(gamepad, button);
}

bool Core::isGamepadButtonReleased(int gamepad, int button)
{
    return IsGamepadButtonReleased(gamepad, button);
}

bool Core::isGamepadButtonUp(int gamepad, int button)
{
    return IsGamepadButtonUp(gamepad, button);
}

int Core::getGamepadButtonPressed(void)
{
    return GetGamepadButtonPressed();
}

int Core::getGamepadAxisCount(int gamepad)
{
    return GetGamepadAxisCount(gamepad);
}

float Core::getGamepadAxisMovement(int gamepad, int axis)
{
    return GetGamepadAxisMovement(gamepad, axis);
}

int Core::setGamepadMappings(const std::string& mappings)
{
    return SetGamepadMappings(mappings.c_str());
}

//! Input-related functions: mouse
bool Core::isMouseButtonPressed(int button)
{
    return IsMouseButtonPressed(button);
}

bool Core::isMouseButtonDown(int button)
{
    return IsMouseButtonDown(button);
}

bool Core::isMouseButtonReleased(int button)
{
    return IsMouseButtonReleased(button);
}

bool Core::isMouseButtonUp(int button)
{
    return IsMouseButtonUp(button);
}

int Core::getMouseX(void)
{
    return GetMouseX();
}

int Core::getMouseY(void)
{
    return GetMouseY();
}

Vector2 Core::getMousePosition(void)
{
    return GetMousePosition();
}

Vector2 Core::getMouseDelta(void)
{
    return GetMouseDelta();
}

void Core::setMousePosition(int x, int y)
{
    SetMousePosition(x, y);
}

void Core::setMouseOffset(int offsetX, int offsetY)
{
    SetMouseOffset(offsetX, offsetY);
}

void Core::setMouseScale(float scaleX, float scaleY)
{
    SetMouseScale(scaleX, scaleY);
}

float Core::getMouseWheelMove(void)
{
    return GetMouseWheelMove();
}

void Core::setMouseCursor(int cursor)
{
    SetMouseCursor(cursor);
}

//! Input-related functions: touch
int Core::getTouchX(void)
{
    return GetTouchX();
}

int Core::getTouchY(void)
{
    return GetTouchY();
}

Vector2 Core::getTouchPosition(int index)
{
    return GetTouchPosition(index);
}

int Core::getTouchPointId(int index)
{
    return GetTouchPointId(index);
}

int Core::getTouchPointCount(void)
{
    return GetTouchPointCount();
}

//! Gestures and Touch Handling Functions (Module: rgestures)
void Core::setGesturesEnabled(unsigned int flags)
{
    SetGesturesEnabled(flags);
}

bool Core::isGestureDetected(int gesture)
{
    return IsGestureDetected(gesture);
}

int Core::getGestureDetected(void)
{
    return GetGestureDetected();
}

float Core::getGestureHoldDuration(void)
{
    return GetGestureHoldDuration();
}

Vector2 Core::getGestureDragVector(void)
{
    return GetGestureDragVector();
}

float Core::getGestureDragAngle(void)
{
    return GetGestureDragAngle();
}

Vector2 Core::getGesturePinchVector(void)
{
    return GetGesturePinchVector();
}

float Core::getGesturePinchAngle(void)
{
    return GetGesturePinchAngle();
}

//! Camera System Functions (Module: rcamera)
void Core::setCameraMode(Camera camera, int mode)
{
    SetCameraMode(camera, mode);
}

void Core::updateCamera(Camera camera)
{
    UpdateCamera(&camera);
}

void Core::setCameraPanControl(int keyPan)
{
    SetCameraPanControl(keyPan);
}

void Core::setCameraAltControl(int keyAlt)
{
    SetCameraAltControl(keyAlt);
}

void Core::setCameraSmoothZoomControl(int keySmoothZoom)
{
    SetCameraSmoothZoomControl(keySmoothZoom);
}

void Core::setCameraMoveControls(int keyFront, int keyBack, int keyRight, int keyLeft, int keyUp, int keyDown)
{
    SetCameraMoveControls(keyFront, keyBack, keyRight, keyLeft, keyUp, keyDown);
}