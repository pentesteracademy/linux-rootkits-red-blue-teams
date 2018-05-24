# Linux Rootkits for Red Blue Teams

<p align="center">
  <img width="200" src="https://s3.amazonaws.com/videos.pentesteracademy.com/videos/badges/low/rootkits.png">
</p>

This repository contains the supporting course material for our [Linux Rootkits for Red-Blue Teams training][1]

**The entire video course is available online:  [Linux Rootkits for Red-Blue Teams][1] on  [Pentester Academy][2]**

Linux dominates the Server, Embedded and now the Internet of Things (IoT) device market. In recent times, embedded systems and IoT devices in particular have been the weapons of choice in online attacks: botnets like Mirai and Reaper to name a few. Soon the simple attack vectors that these botnets and malware use get patched, it is obvouis that the attacker will move and hide his tools in Kernel mode. This course will teach Red-Blue teams how kernel mode attack kits work and what to go about protecting their systems against it. We will use examples on x86_64, ARM and MIPS based architectures.

This entire course will be run on the latest Linux Kernel 4.15.x. This course is completely hands-on and everything will be taught with practical examples in the form of Kernel Modules written in C. You can however follow this course with a basic knowledge of Linux as we discuss everything from the very basics.

A non-exhaustive list of topics include:

* Linux Boot Process
* Browsing the Kernel code
* Linux Architecture and Process Internals
* Loadable Kernel Module (LKM) Programming Basics
* Understading internal kernel structures and the syscall mechanism
* Interrupt and Process context, Timers and Watchdogs
* Manipulating internal process structures
* Hijacking the system call table
* Subverting kernel memory protections
* Monitoring the system with Kprobes
* Kernel syncronization methods and common LKM pitfalls
* User space - Kernel space data transfers
* Monitoring a user space process from the kernel
* Accessing user space process memory
* Modifying the core kernel code to create custom hooks
* Understanding the kernel network stack
* Netfilters and Custom Hooks
* Network packet filtering and mangling with custom LKMs
* Analyzing Kernel mode Rootkits
* Defending against Kernel Mode attacks
* Chain of trust implementations
* and other topics


We cover all of these topics in the online course and how to use these files. 

[1]: http://www.pentesteracademy.com/course?id=38
[2]: http://www.PentesterAcademy.com/topics
