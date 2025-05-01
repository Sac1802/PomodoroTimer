# CMakeList.txt: proyecto de CMake para PomodoroTime, incluya el origen y defina
# la lógica específica del proyecto aquí.
#

# Agregue un origen al ejecutable de este proyecto.
add_executable (PomodoroTime "PomodoroTime.cpp" "PomodoroTime.h" 
"App/App.cpp" "TimeManagment/TimeManager.cpp" "Menu/Menu.cpp" 
"ListMusicForSpeck/Music.cpp" "OpenBrowser/Open.cpp" 
"TimeSound/TimeSound.cpp" "Filter/FilterErrors.cpp" "Models/Task.cpp" "ClearTerminal/ClearTerminal.cpp" "Controller/ControllerTask.cpp")

target_include_directories(PomodoroTime PRIVATE 
"C:/Program Files (x86)/OpenAL 1.1 SDK/include"
"C:/Users/Acost/source/repos/PomodoroTime/PomodoroTime/include"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET PomodoroTime PROPERTY CXX_STANDARD 20)
endif()

# TODO: Agregue pruebas y destinos de instalación si es necesario.
target_link_libraries(PomodoroTime 
    "C:/Program Files (x86)/OpenAL 1.1 SDK/libs/Win64/OpenAL32.lib"
)

