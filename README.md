# C++ AI Code Reviewer Assistant

An intelligent C++ application that automates code reviews using local AI models (Ollama/GPT). It supports interactive chat to explain code logic, detect bugs, and suggest improvements.

## 🚀 Key Features
* **AI Powered:** Utilizes the `gpt-oss:20b` model to analyze code for bugs, security issues, and clean code standards.
* **Smart Drag & Drop:** Easily drag and drop source files into the console window (Supports both CMD & PowerShell paths).
* **Interactive Chat:** Ask follow-up questions about the code analysis in a conversational interface.
* **Auto Report:** Automatically generates a `.txt` review report and opens it for immediate viewing.

## 🛠 System Requirements
* **OS:** Windows 10/11
* **Build Tools:** CMake 3.10+, Visual Studio / MinGW
* **Dependencies:** * libcurl (for Network Requests)
    * Ollama (Local AI Server)
    * Ngrok (For tunneling)

## 🌐 Server Setup (Kaggle Backend)
Since the AI model (`gpt-oss:20b`) requires high computational resources, we use **Kaggle** as the backend server.

1.  **Open the Kaggle Notebook:**
    Click here to access the host notebook: **https://www.kaggle.com/code/lnchau/ollama-ngok**

2.  **Configure Ngrok:**
    * In the notebook, go to Add-ons.
    * Enter your **Ngrok Authtoken** (Get it from [dashboard.ngrok.com](https://dashboard.ngrok.com)).

3.  **Start the Server:**
    * Run **"Run All"** in the notebook.
    * Wait for the system to download the model and start Ollama.
    * Look for the output log showing the public URL:
        > `Ngrok Tunnel: https://xxxx-xxxx.ngrok-free.app`

4.  **Connect the App:**
    * Copy that `https://...` URL.
    * Open the C++ Application (`reviewer.exe`).
    * Paste the URL when prompted (or update the configuration).
## 📦 Installation & Build
This project uses **Vcpkg** for dependency management.

```bash
# 1. Clone the repository
git clone [https://github.com/qaztyhn/basic-ai-code-review-assistance-using-ollama-ngrok.git](https://github.com/qaztyhn/basic-ai-code-review-assistance-using-ollama-ngrok.git)
cd basic-ai-code-review-assistance-using-ollama-ngrok

# 2. Configure CMake with Vcpkg toolchain
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE="[Path_to_Your_Vcpkg]/scripts/buildsystems/vcpkg.cmake"

# 3. Build (Release Mode)
cmake --build build --config Release
