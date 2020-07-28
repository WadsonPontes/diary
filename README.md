# Diary

## Contents

- [About](#about)
- [Running the app on Windows](#running-the-app-on-windows)
- [Running the app on Linux](#running-the-app-on-linux)
- [Features](#features)
- [Author](#author)
- [License](#license)

## About

Simple diary application to take notes and record important events through the terminal. Currently, the application contains the following features: add, edit, remove, list, search and interactive mode.

## Running the app on Windows

Clone this repository:
```
git clone https://github.com/WadsonPontes/diary.git
```
Navigate into the project directory:
```
cd diary
```
Compile the app:
```
script.bat
```
Run the app:
```
build/Diary.exe <command>
```

## Running the app on Linux

Clone this repository:
```
git clone https://github.com/WadsonPontes/diary.git
```
Navigate into the project directory:
```
cd diary
```
Compile the app:
```
make
```
Run the app:
```
build/Diary <command>
```

## Features

### Add

You can add messages to the diary. To do this, run the command (depending on the OS):
```
build/Diary.exe add
build/Diary add
```
You will be asked to write your message and right after you type Enter your message will be stored in the file diary.md

### Edit

You can edit a message from the diary. To do this, run the command (depending on the OS):
```
build/Diary.exe edit
build/Diary edit
```
All of your messages will be displayed and you must enter the ID of the message you want to change. Then enter a new message.

### Remove

You can remove a message from the diary. To do this, run the command (depending on the OS):
```
build/Diary.exe remove
build/Diary remove
```
All of your messages will be displayed and you must enter the ID of the message you want to remove and after typing Enter the message will be removed from the file diary.md

### List

You can list all of your messages in the diary. To do this, run the command (depending on the OS):
```
build/Diary.exe list
build/Diary list
```
All your messages stored in the diary.md file will be displayed.

### Search

You can search for messages in your diary that contain a term or phrase. To do this, run the command (depending on the OS):
```
build/Diary.exe search
build/Diary search
```
You will be asked to enter a word or phrase. After typing Enter, all messages containing the searched term or phrase will be displayed.

### Interactive

You enter the interactive mode of the application. To do this, run the command (depending on the OS):
```
build/Diary.exe interactive
build/Diary interactive
```
A menu will appear with all the previous options. To access a resource, just type the number indicated next to the option and type Enter. After completing a task you will be returned to the menu where you can execute a new function. To end the program, type 0 (zero).

## Author

- Wadson Pontes - [@WadsonPontes](https://github.com/WadsonPontes)


## License

Copyright (c) 2020 Wadson Pontes

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
