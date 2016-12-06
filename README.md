# BulletSharp

This is a fork of the BulletSharpPInvoke project. The c# wrappers have been modified slightly so that they work in Unity3d and Mono 2.0 instead of .Net 4.5.

BulletSharp is a .NET wrapper for the [Bullet](http://bulletphysics.org/) physics library.

This version uses Platform Invoke. There is also an equivalent version written in C++/CLI: https://github.com/AndresTraks/BulletSharp

libbulletc is a C interface to Bullet. It compiles into a .dll or .so file that exports Bullet functions.

BulletSharpPInvoke is a .NET library that proxies calls from .NET to libbulletc.

BulletSharpGen generates partial code for BulletSharp P/Invoke, libbulletc and also BulletSharp C++/CLI based on Bullet header files.

The benefit of P/Invoke over C++/CLI is that it runs on all platforms that support P/Invoke into shared user-mode libraries (Windows, Unix, Mac OS). See also [Supported platforms](https://github.com/AndresTraks/BulletSharp/wiki/Supported-platforms).

Currently using Bullet3 2.84
