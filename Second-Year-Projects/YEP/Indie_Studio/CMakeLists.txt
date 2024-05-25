cmake_minimum_required(VERSION 3.17)
project(bomberman)

if (NOT WIN32)
  set(CMAKE_CXX_FLAGS "-W -Wall -Wextra")
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/modules")
set(Findraylib_DIR "/modules")

find_package(raylib REQUIRED)
include_directories("includes/")
include_directories("includes/interfaces")
include_directories("includes/pages")
include_directories("includes/controllers")
include_directories("includes/map_creation")

add_executable(bomberman
               ${CMAKE_SOURCE_DIR}/source/main.cpp
               ${CMAKE_SOURCE_DIR}/source/Error.cpp
               ${CMAKE_SOURCE_DIR}/source/pages/menu/menu.cpp
               ${CMAKE_SOURCE_DIR}/source/pages/menu/secondMenu.cpp
               ${CMAKE_SOURCE_DIR}/source/game/init_game.cpp
               ${CMAKE_SOURCE_DIR}/source/utils/create_button.cpp
               ${CMAKE_SOURCE_DIR}/source/pages/score/score.cpp
               ${CMAKE_SOURCE_DIR}/source/pages/settings/setting.cpp
               ${CMAKE_SOURCE_DIR}/source/controllers/shapes.cpp
               ${CMAKE_SOURCE_DIR}/source/controllers/text.cpp
               ${CMAKE_SOURCE_DIR}/source/controllers/audio.cpp
               ${CMAKE_SOURCE_DIR}/source/controllers/models.cpp
               ${CMAKE_SOURCE_DIR}/source/controllers/core.cpp
               ${CMAKE_SOURCE_DIR}/source/controllers/textures.cpp
               ${CMAKE_SOURCE_DIR}/source/pages/askUser/askUser.cpp
               ${CMAKE_SOURCE_DIR}/source/parser/parser.cpp
               ${CMAKE_SOURCE_DIR}/source/LocalMultiplayer/LocalMultiplayer.cpp
               ${CMAKE_SOURCE_DIR}/source/player/player.cpp
               ${CMAKE_SOURCE_DIR}/source/bombe/bombe.cpp
               ${CMAKE_SOURCE_DIR}/source/pages/GameEngine/gameEngine.cpp
               ${CMAKE_SOURCE_DIR}/source/map_creation/map.cpp
               ${CMAKE_SOURCE_DIR}/source/PlayerSettings/PlayerSettings.cpp
               ${CMAKE_SOURCE_DIR}/source/save/saveGame.cpp
               ${CMAKE_SOURCE_DIR}/source/load/loadGame.cpp
               ${CMAKE_SOURCE_DIR}/source/pages/pause/pause.cpp
               ${CMAKE_SOURCE_DIR}/source/pages/menu/AnimScreen.cpp
               ${CMAKE_SOURCE_DIR}/source/pages/menu/LoadScreen.cpp
               ${CMAKE_SOURCE_DIR}/source/pages/score/Best_Scores.cpp
               ${CMAKE_SOURCE_DIR}/source/pages/Victory/victory.cpp
            )
TARGET_LINK_LIBRARIES(bomberman raylib)

file(COPY "assets" DESTINATION ${CMAKE_BINARY_DIR})
file(COPY "backup" DESTINATION ${CMAKE_BINARY_DIR})