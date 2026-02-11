# C Memory Manager

![C](https://img.shields.io/badge/Language-C-00599C?style=flat&logo=c) 
![License](https://img.shields.io/badge/License-MIT-green?style=flat) 
![Build](https://img.shields.io/badge/Build-Pass-brightgreen?style=flat)
![Version](https://img.shields.io/badge/Version-1.0.0-blue?style=flat)

---

## Overview

**C Memory Manager** is a project I worked on to create my own memory manager written in C. This project helped me to better understand how memory is stored in the HEAP, this program provides fast allocation and deallocation without relying on the standard `malloc` and `free` functions.  

---

## Features

- Fixed-size memory pool allocation
- Efficient free-list management
- Fast `allocate` and `free` operations
- Easy-to-use API
- Memory pool statistics display
- Prevents fragmentation and reduces heap allocation overhead

---

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Installation](#installation)
- [Compile Instructions](#compile-instructions)
- [Usage](#usage)
- [API](#api)
- [Memory Layout](#memory-layout)
- [Example](#example)
- [Contributing](#contributing)
- [License](#license)

---

## Installation

1. Clone the repository:

```bash
git clone https://github.com/yourusername/c-memory-manager.git
cd c-memory-manager


##Compile Instructions
- In the root directory compile the main.c file in the terminal

gcc main.c mm.c -o memory_manager

