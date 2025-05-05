# PomodoroTimer⏱️

The Pomodoro Timer Project is a project that seeks to improve study efficiency by helping people set a timer to focus deeply on their studies, then take a break. The user can freely add study and rest time.

## 🚀 Installation

📌 Requirements
Before running PomodoroTimer, make sure OpenAL is installed on your system. Follow the instructions for your operating system.
🛠 Windows
- Download OpenAL Installer from [Creative Labs](https://www.openal.org/downloads/).
- Install the Core SDK section, then extract the zip file and run the .exe
- clone the repository:
```bash
git clone https://github.com/Sac1802/PomodoroTimer.git
```
- Then we must make sure that in the class `TimeSound.hpp` in the includes section there is no error

- If the system does not recognize OpenAL, add its directory to the environment variables.

🖥️ Linux (Ubuntu/Debian)
- Install OpenAL with:sudo apt update
sudo apt install libopenal-dev
- clone the repository:
```bash
git clone https://github.com/Sac1802/PomodoroTimer.git
```

- Make sure the dependencies are correctly linked when compiling: g++ -o PomodoroTimer main.cpp -lopenal


💡 Note: If you have trouble with the configuration, please review the official OpenAL documentation at OpenAL Soft.

## ⚡ Run PomodoroTimer
To run PomodoroTimer, follow these steps:
### Windows
- Go to the cloned folder through the terminal and run the following command:
```bash
g++ -o PomodoroTimer main.cpp -lopenal32
```
- But if you don't have a standard route for OpenAL, we run:
```bash
g++ -o PomodoroTimer main.cpp TimerManager.cpp TimeSound.cpp -I"C:/OpenAL/include" -L"C:/OpenAL/lib" -lopenal32
```
Explanation of parameters:
- -I → Specifies the path to the OpenAL .h files.
- -L → Specifies the directory where the openal32.lib library is located.
- -lopenal32 → Links the OpenAL library.
- -o → Specifies the name of the output file (PomodoroTimer.exe).
- main.cpp → The main source file of the project.
- TimerManager.cpp → The source file for the TimerManager class.
- TimeSound.cpp → The source file for the TimeSound class.
- when we compile we run:
```bash
./PomodoroTimer.exe
```

### Linux
- Go to the cloned folder through the terminal and run the following command:
```bash
g++ -o PomodoroTimer main.cpp TimerManager.cpp TimeSound.cpp -lopenal
```
- when we compile we run:
```bash
./PomodoroTimer
```
- if you have problems with the sound, you can run the program with sudo:
```bash
sudo ./PomodoroTimer
```

En la sección **Usage** de tu `README.md`, puedes incluir detalles sobre cómo **usar** tu aplicación después de ejecutarla. Aquí te dejo un esquema para hacerla más clara y útil:

---

### 📌 **Usage**
#### **Run PomodoroTimer**
1. **Run the program following the "How to Run" section.**
2. **Select an option from the main menu.**
3. **Set the study and break duration.**

#### **Available Options**
When the program starts, you'll see a menu similar to this:
```plaintext
[ PomodoroTimer ]
1. Start Study Timer
2. Add Task
3. View Tasks
4. Complete Task
5. Exit
Select an option:
```
- `1` → Set the **study timer**.
- `2` → Add a **task** to the list.
- `3` → Display the **list of stored tasks**.
- `4` → Complete a task marked by its **ID**.
- `5` → Exit the program.

#### **Example Configuration**
```plaintext
Enter study time (minutes): 25
Enter rest time (minutes): 5
```
This will start a **Pomodoro cycle** with 25 minutes of study time and 5 minutes of rest time.

#### **Select Music for Study**
```plaintext
1. Music to study:
2. Music to NCS:
3. Music to motivate:
Select an option:
```
This will allow you to select the type of music you want to listen to while studying. The options are:
- `1` → Music to study.
- `2` → Music to NCS.
- `3` → Music to motivate.

#### **Sound Integration**
If OpenAL is properly configured, the program will play a sound when changing phases (study → break).





