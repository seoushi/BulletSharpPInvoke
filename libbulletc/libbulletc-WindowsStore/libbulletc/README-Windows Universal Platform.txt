This VS 2015 project builds bullet physics with wrappers for ARM, x86 and x64 Windows Universal Platform.

These shared libraries are not included with the Unity Project because they cannot be used simultaneously with the other bullet physics libaries.

Here are the issues that make them non-compatible:

1) The Unity Editor does not recognise the -unsafe parameter in the smcs.rsp file when the build platform is Windows Store. A workaround for this
problem is to compile the C# wrappers in the BulletSharp project into a .dll (I used Visual Studio and compiled into .Net 3.5). Another problem is that
the import command that imports the libbulletc native plugin must be written 'libbulletc.dll' instead of 'libbulletc' in file native.cs. This means that
the compiled .dll is not compatible with the native library for other platforms.

2) Unity's Windows Store build platform is sensitive to the version of Windows Universal Platform that was used to compile the .dll. For Unity 5.4 and newer
 you must use Windows Universal Platform 10.0.10240.0. For Windows 5.3.1 and older then an older version of Windows Universal Platform must be used.
