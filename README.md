# mini top command in kernel-level

This repository contains simple kernel-level programming exercises written in C.  
It is designed for beginners to explore Linux kernel modules, basic system calls, and low-level programming concepts.  

## Usage

1. Clone the repository:

```bash
git clone https://github.com/FreyKernel/mini_top
cd mini_top
```
2. Compile a kernel module (example):
```bash
make
```
3. Insert the module into the kernel:
```bash
sudo insmod mini_top.ko
```

4. Check kernel messages:
```bash
dmesg | tail
```

5. Remove the module when done:
```bash
sudo rmmod mini_top
```
*Enjoy It!*
