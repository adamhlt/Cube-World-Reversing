![Banner](https://user-images.githubusercontent.com/48086737/170087278-da09b7c6-0971-48f9-bfc9-558164330de7.png)

# Cube World Reversing

 [![C++](https://img.shields.io/badge/language-C%2B%2B-%23f34b7d.svg?style=for-the-badge&logo=appveyor)](https://en.wikipedia.org/wiki/C%2B%2B) [![Windows](https://img.shields.io/badge/platform-Windows-0078d7.svg?style=for-the-badge&logo=appveyor)](https://en.wikipedia.org/wiki/Microsoft_Windows) [![x64](https://img.shields.io/badge/arch-x64-green.svg?style=for-the-badge&logo=appveyor)](https://en.wikipedia.org/wiki/X64)

## :open_book: Project Overview :

The goal of this project is to reverse Cube World (1.0) and to implements some cheat functions like god mode, fly hack, speed hack... Also I will try to make a great C++ structure for the game using [ReClass](https://github.com/ReClassNET/ReClass.NET).

I update this repository the same time I write new posts on my blog. You can easily follow my work with IDA project, I try to make the code the most clean and easiest to understand.

#### Tools used :

- [Cheat Engine](https://www.cheatengine.org)
- [x64dbg](https://x64dbg.com)
- [ReClass.NET](https://github.com/ReClassNET/ReClass.NET)
- [IDA Pro](https://hex-rays.com/ida-pro/) / [Ghidra](https://ghidra-sre.org/)
- [PE Bear](https://github.com/hasherezade/pe-bear-releases)
- [Detect It Easy](https://github.com/horsicq/Detect-It-Easy)

#### Project / Libraries used :

- [MS Detours](https://github.com/microsoft/Detours)
- [ImGui Standalone](https://github.com/adamhlt/ImGui-Standalone)
- [Easy Code Cave](https://github.com/adamhlt/Easy-Code-Cave)

## :rocket: Getting Started :

This is a **x64 dll**, you can't compile this project in x86, the game made in x64 and the project use x64 assembly.

### Visual Studio :

1. Open the solution file (.sln).
2. Build the project in Release (x64)

⚠️ If you have crash when injecting in the game try to look if addresses are still up to date.

## 🧪 Demonstration :

#### Features :

- Retrieve LocalPlayer
- Movement Speed Multiplier

https://user-images.githubusercontent.com/48086737/166975554-8c54f7b5-4eec-4398-87f2-8009d1ad8cdb.mp4
