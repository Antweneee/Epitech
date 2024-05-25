/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** Core
*/

#ifndef CORE_HPP_
    #define CORE_HPP_
    #include <raylib.h>
    #include <any>
    #include <vector>
    #include <string>
    #include <memory>

class Core {
    public:
        Core();
        ~Core();

        //! Window-related functions
        void initWindow(int width, int height, const std::string& title);              // Initialize window and OpenGL context
        bool windowShouldClose(void);                                           // Check if KEY_ESCAPE pressed or Close icon pressed
        void closeWindow(void);                                                 // Close window and unload OpenGL context
        bool isWindowReady(void);                                               // Check if window has been initialized successfully
        bool isWindowFullscreen(void);                                          // Check if window is currently fullscreen
        bool isWindowHidden(void);                                              // Check if window is currently hidden (only PLATFORM_DESKTOP)
        bool isWindowMinimized(void);                                           // Check if window is currently minimized (only PLATFORM_DESKTOP)
        bool isWindowMaximized(void);                                           // Check if window is currently maximized (only PLATFORM_DESKTOP)
        bool isWindowFocused(void);                                             // Check if window is currently focused (only PLATFORM_DESKTOP)
        bool isWindowResized(void);                                             // Check if window has been resized last frame
        bool isWindowState(unsigned int flag);                                  // Check if one specific window flag is enabled
        void setWindowState(unsigned int flags);                                // Set window configuration state using flags
        void clearWindowState(unsigned int flags);                              // Clear window configuration state flags
        void toggleFullscreen(void);                                            // Toggle window state: fullscreen/windowed (only PLATFORM_DESKTOP)
        void maximizeWindow(void);                                              // Set window state: maximized, if resizable (only PLATFORM_DESKTOP)
        void minimizeWindow(void);                                              // Set window state: minimized, if resizable (only PLATFORM_DESKTOP)
        void restoreWindow(void);                                               // Set window state: not minimized/maximized (only PLATFORM_DESKTOP)
        void setWindowIcon(Image image);                                        // Set icon for window (only PLATFORM_DESKTOP)
        void setWindowTitle(const std::string& title);                                 // Set title for window (only PLATFORM_DESKTOP)
        void setWindowPosition(int x, int y);                                   // Set window position on screen (only PLATFORM_DESKTOP)
        void setWindowMonitor(int monitor);                                     // Set monitor for the current window (fullscreen mode)
        void setWindowMinSize(int width, int height);                           // Set window minimum dimensions (for FLAG_WINDOW_RESIZABLE)
        void setWindowSize(int width, int height);                              // Set window dimensions
        std::any getWindowHandle(void);                                            // Get native window handle
        int getScreenWidth(void);                                               // Get current screen width
        int getScreenHeight(void);                                              // Get current screen height
        int getMonitorCount(void);                                              // Get number of connected monitors
        int getCurrentMonitor(void);                                            // Get current connected monitor
        Vector2 getMonitorPosition(int monitor);                                // Get specified monitor position
        int getMonitorWidth(int monitor);                                       // Get specified monitor width (max available by monitor)
        int getMonitorHeight(int monitor);                                      // Get specified monitor height (max available by monitor)
        int getMonitorPhysicalWidth(int monitor);                               // Get specified monitor physical width in millimetres
        int getMonitorPhysicalHeight(int monitor);                              // Get specified monitor physical height in millimetres
        int getMonitorRefreshRate(int monitor);                                 // Get specified monitor refresh rate
        Vector2 getWindowPosition(void);                                        // Get window position XY on monitor
        Vector2 getWindowScaleDPI(void);                                        // Get window scale DPI factor
        const std::string getMonitorName(int monitor);                                // Get the human-readable, UTF-8 encoded name of the primary monitor
        void setClipboardText(const std::string& text);                                // Set clipboard text content
        const std::string getClipboardText(void);                                     // Get clipboard text content


        //! Cursor-related functions
        void showCursor(void);                                                  // Shows cursor
        void hideCursor(void);                                                  // Hides cursor
        bool isCursorHidden(void);                                              // Check if cursor is not visible
        void enableCursor(void);                                                // Enables cursor (unlock cursor)
        void disableCursor(void);                                               // Disables cursor (lock cursor)
        bool isCursorOnScreen(void);                                            // Check if cursor is on the screen

        //! Drawing-related functions
        void clearBackground(Color color);                                      // Set background color (framebuffer clear color)
        void beginDrawing(void);                                                // Setup canvas (framebuffer) to start drawing
        void endDrawing(void);                                                  // End canvas drawing and swap buffers (double buffering)
        void beginMode2D(Camera2D camera);                                      // Begin 2D mode with custom camera (2D)
        void endMode2D(void);                                                   // Ends 2D mode with custom camera
        void beginMode3D(Camera3D camera);                                      // Begin 3D mode with custom camera (3D)
        void endMode3D(void);                                                   // Ends 3D mode and returns to default 2D orthographic mode
        void beginTextureMode(RenderTexture2D target);                          // Begin drawing to render texture
        void endTextureMode(void);                                              // Ends drawing to render texture
        void beginShaderMode(Shader shader);                                    // Begin custom shader drawing
        void endShaderMode(void);                                               // End custom shader drawing (use default shader)
        void beginBlendMode(int mode);                                          // Begin blending mode (alpha, additive, multiplied, subtract, custom)
        void endBlendMode(void);                                                // End blending mode (reset to default: alpha blending)
        void beginScissorMode(int x, int y, int width, int height);             // Begin scissor mode (define screen area for following drawing)
        void endScissorMode(void);                                              // End scissor mode
        void beginVrStereoMode(VrStereoConfig config);                          // Begin stereo rendering (requires VR simulator)
        void endVrStereoMode(void);                                             // End stereo rendering (requires VR simulator)

        //! VR stereo config functions for VR simulator
        VrStereoConfig loadVrStereoConfig(VrDeviceInfo device);                 // Load VR stereo config for VR simulator device parameters
        void unloadVrStereoConfig(VrStereoConfig config);                       // Unload VR stereo config

        //! Shader management functions
        //! NOTE: Shader functionality is not available on OpenGL 1.1
        Shader loadShader(const std::string& vsFileName, const std::string&fsFileName);      // Load shader from files and bind default locations
        Shader loadShaderFromMemory(const std::string& vsCode, const std::string&fsCode);    // Load shader from code strings and bind default locations
        int getShaderLocation(Shader shader, const std::string& uniformName);          // Get shader uniform location
        int getShaderLocationAttrib(Shader shader, const std::string& attribName);     // Get shader attribute location
        void setShaderValue(Shader shader, int locIndex, const std::string& value, int uniformType);               // Set shader uniform value
        void setShaderValueV(Shader shader, int locIndex, std::any value, int uniformType, int count);   // Set shader uniform value vector
        void setShaderValueMatrix(Shader shader, int locIndex, Matrix mat);         // Set shader uniform value (matrix 4x4)
        void setShaderValueTexture(Shader shader, int locIndex, Texture2D texture); // Set shader uniform value for texture (sampler2d)
        void unloadShader(Shader shader);                                       // Unload shader from GPU memory (VRAM)

        //! Screen-space-related functions
        Ray getMouseRay(Vector2 mousePosition, Camera camera);                  // Get a ray trace from mouse position
        Matrix getCameraMatrix(Camera camera);                                  // Get camera transform matrix (view matrix)
        Matrix getCameraMatrix2D(Camera2D camera);                              // Get camera 2d transform matrix
        Vector2 getWorldToScreen(Vector3 position, Camera camera);              // Get the screen space position for a 3d world space position
        Vector2 getWorldToScreenEx(Vector3 position, Camera camera, int width, int height); // Get size position for a 3d world space position
        Vector2 getWorldToScreen2D(Vector2 position, Camera2D camera);          // Get the screen space position for a 2d camera world space position
        Vector2 getScreenToWorld2D(Vector2 position, Camera2D camera);          // Get the world space position for a 2d camera screen space position

        //! Timing-related functions
        void setTargetFPS(int fps);                                             // Set target FPS (maximum)
        int getFPS(void);                                                       // Get current FPS
        float getFrameTime(void);                                               // Get time in seconds for last frame drawn (delta time)
        double getTime(void);                                                   // Get elapsed time in seconds since InitWindow()

        //! Misc. functions
        int getRandomValue(int min, int max);                                   // Get a random value between min and max (both included)
        void setRandomSeed(unsigned int seed);                                  // Set the seed for the random number generator
        void takeScreenshot(const std::string& fileName);                              // Takes a screenshot of current screen (filename extension defines format)
        void setConfigFlags(unsigned int flags);                                // Setup init configuration flags (view FLAGS)

        void traceLog(int logLevel, std::string& text, ...);                     // Show trace log messages (LOG_DEBUG, LOG_INFO, LOG_WARNING, LOG_ERROR...)
        void setTraceLogLevel(int logLevel);                                    // Set the current threshold (minimum) log level
        std::any memAlloc(int size);                                               // Internal memory allocator
        std::any memRealloc(std::any ptr, int size);                                  // Internal memory reallocator
        void memFree(std::any ptr);                                                // Internal memory free

        //! Set custom callbacks
        //! WARNING: Callbacks setup is intended for advance users
        void setTraceLogCallback(TraceLogCallback callback);                    // Set custom trace log
        void setLoadFileDataCallback(LoadFileDataCallback callback);            // Set custom file binary data loader
        void setSaveFileDataCallback(SaveFileDataCallback callback);            // Set custom file binary data saver
        void setLoadFileTextCallback(LoadFileTextCallback callback);            // Set custom file text data loader
        void setSaveFileTextCallback(SaveFileTextCallback callback);            // Set custom file text data saver

        //! Files management functions
        std::string loadFileData(const std::string& fileName, unsigned int bytesRead);     // Load file data as byte array (read)
        void unloadFileData(std::string& data);                               // Unload file data allocated by LoadFileData()
        bool saveFileData(const std::string& fileName, std::any data, unsigned int bytesToWrite); // Save data to file from byte array (write), returns true on success
        std::string loadFileText(const std::string& fileName);                               // Load text data from file (read), returns a '\0' terminated string
        void unloadFileText(std::string& text);                                        // Unload file text data allocated by LoadFileText()
        bool saveFileText(const std::string& fileName, std::string& text);                    // Save text data to file (write), string must be '\0' terminated, returns true on success
        bool fileExists(const std::string& fileName);                                  // Check if file exists
        bool directoryExists(const std::string& dirPath);                              // Check if a directory path exists
        bool isFileExtension(const std::string& fileName, const std::string& next);            // Check file extension (including point: .png, .wav)
        const std::string& getFileExtension(const std::string&fileName);                     // Get pointer to extension for a filename string (includes dot: '.png')
        const std::string& getFileName(const std::string&filePath);                          // Get pointer to filename for a path string
        const std::string& getFileNameWithoutExt(const std::string&filePath);                // Get filename string without extension (uses static string)
        const std::string& getDirectoryPath(const std::string&filePath);                     // Get full path for a given fileName with path (uses static string)
        const std::string& getPrevDirectoryPath(const std::string& dirPath);                  // Get previous directory path for a given path (uses static string)
        const std::string& getWorkingDirectory(void);                                  // Get current working directory (uses static string)
        void clearDirectoryFiles(void);                                         // Clear directory files paths buffers (free memory)
        bool changeDirectory(const std::string& dir);                                  // Change working directory, return true on success
        bool isFileDropped(void);                                               // Check if a file has been dropped into window
        void clearDroppedFiles(void);                                           // Clear dropped files paths buffer (free memory)
        long getFileModTime(const std::string& fileName);                              // Get file modification time (last write time)

        //! Compression/Encoding functionality
        std::string compressData(std::string& data, int dataLength, int compDataLength);        // Compress data (DEFLATE algorithm)
        std::string decompressData(std::string& compData, int compDataLength, int dataLength);  // Decompress data (DEFLATE algorithm)
        std::string encodeDataBase64(const std::string& data, int dataLength, int outputLength);         // Encode data to Base64 string
        std::string decodeDataBase64(std::string& data, int outputLength);                      // Decode Base64 string data

        //! Persistent storage management
        bool saveStorageValue(unsigned int position, int value);                // Save integer value to storage file (to defined position), returns true on success
        int loadStorageValue(unsigned int position);                            // Load integer value from storage file (from defined position)

        //! Misc.
        void openURL(const std::string& url);                                          // Open URL with default system browser (if available)

        //! Input-related functions: keyboard
        bool isKeyPressed(int key);                                             // Check if a key has been pressed once
        bool isKeyDown(int key);                                                // Check if a key is being pressed
        bool isKeyReleased(int key);                                            // Check if a key has been released once
        bool isKeyUp(int key);                                                  // Check if a key is NOT being pressed
        void setExitKey(int key);                                               // Set a custom key to exit program (default is ESC)
        int getKeyPressed(void);                                                // Get key pressed (keycode), call it multiple times for keys queued, returns 0 when the queue is empty
        int getCharPressed(void);                                               // Get char pressed (unicode), call it multiple times for chars queued, returns 0 when the queue is empty

        //! Input-related functions: gamepads
        bool isGamepadAvailable(int gamepad);                                   // Check if a gamepad is available
        const std::string& getGamepadName(int gamepad);                                // Get gamepad internal name id
        bool isGamepadButtonPressed(int gamepad, int button);                   // Check if a gamepad button has been pressed once
        bool isGamepadButtonDown(int gamepad, int button);                      // Check if a gamepad button is being pressed
        bool isGamepadButtonReleased(int gamepad, int button);                  // Check if a gamepad button has been released once
        bool isGamepadButtonUp(int gamepad, int button);                        // Check if a gamepad button is NOT being pressed
        int getGamepadButtonPressed(void);                                      // Get the last gamepad button pressed
        int getGamepadAxisCount(int gamepad);                                   // Get gamepad axis count for a gamepad
        float getGamepadAxisMovement(int gamepad, int axis);                    // Get axis movement value for a gamepad axis
        int setGamepadMappings(const std::string& mappings);                           // Set internal gamepad mappings (SDL_GameControllerDB)

        //! Input-related functions: mouse
        bool isMouseButtonPressed(int button);                                  // Check if a mouse button has been pressed once
        bool isMouseButtonDown(int button);                                     // Check if a mouse button is being pressed
        bool isMouseButtonReleased(int button);                                 // Check if a mouse button has been released once
        bool isMouseButtonUp(int button);                                       // Check if a mouse button is NOT being pressed
        int getMouseX(void);                                                    // Get mouse position X
        int getMouseY(void);                                                    // Get mouse position Y
        Vector2 getMousePosition(void);                                         // Get mouse position XY
        Vector2 getMouseDelta(void);                                            // Get mouse delta between frames
        void setMousePosition(int x, int y);                                    // Set mouse position XY
        void setMouseOffset(int offsetX, int offsetY);                          // Set mouse offset
        void setMouseScale(float scaleX, float scaleY);                         // Set mouse scaling
        float getMouseWheelMove(void);                                          // Get mouse wheel movement Y
        void setMouseCursor(int cursor);                                        // Set mouse cursor

        //! Input-related functions: touch
        int getTouchX(void);                                                    // Get touch position X for touch point 0 (relative to screen size)
        int getTouchY(void);                                                    // Get touch position Y for touch point 0 (relative to screen size)
        Vector2 getTouchPosition(int index);                                    // Get touch position XY for a touch point index (relative to screen size)
        int getTouchPointId(int index);                                         // Get touch point identifier for given index
        int getTouchPointCount(void);                                           // Get number of touch points

        //! Gestures and Touch Handling Functions (Module: rgestures)
        void setGesturesEnabled(unsigned int flags);                            // Enable a set of gestures using flags
        bool isGestureDetected(int gesture);                                    // Check if a gesture have been detected
        int getGestureDetected(void);                                           // Get latest detected gesture
        float getGestureHoldDuration(void);                                     // Get gesture hold time in milliseconds
        Vector2 getGestureDragVector(void);                                     // Get gesture drag vector
        float getGestureDragAngle(void);                                        // Get gesture drag angle
        Vector2 getGesturePinchVector(void);                                    // Get gesture pinch delta
        float getGesturePinchAngle(void);                                       // Get gesture pinch angle

        //! Camera System Functions (Module: rcamera)
        void setCameraMode(Camera camera, int mode);                            // Set camera mode (multiple camera modes available)
        void updateCamera(Camera camera);                                       // Update camera position for selected mode
        void setCameraPanControl(int keyPan);                                   // Set camera pan key to combine with mouse movement (free camera)
        void setCameraAltControl(int keyAlt);                                   // Set camera alt key to combine with mouse movement (free camera)
        void setCameraSmoothZoomControl(int keySmoothZoom);                     // Set camera smooth zoom key to combine with mouse (free camera)
        void setCameraMoveControls(int keyFront, int keyBack, int keyRight, int keyLeft, int keyUp, int keyDown); // Set camera move controls (1st person and 3rd person cameras)
    protected:
    private:
};

#endif /* !CORE_HPP_ */
