# TouchGrafx_QP
This is a partially functioning modified example of a TouchGrafx example project for the STM32H747i-Disco Development Kit that uses QP instead of FreeRTOS.  I modified the example to remove the dependency on FreeRTOS and use the Quantum Platform toolkit from Quantum Leaps (State-Machine.com).

The screen draws graphics and responds to touch but text rendering is "glitchy" and illegible.  At least as of this writing anyway.  Part of the reason for putting this work on a public repo is to hopefully get some insight into correcting this problem.  With any luck, this might evolve into a fully working example.

Licenses:
QP, TouchGrafx, and STM code are owned by their respective companies.  The only code I am contributing is licensed GPL.  I believe I am using the third party code within allowed license but please let me know if not.

Warranty, Liability, Fitness, Merchantability:
This code has no warranty and is not endorsed by my employer.  It is for educational purposes and any other usage is at your own risk.  It is not represented to be suitable for any commercial purpose.

How to build in TouchGrafx Version 4.17 (latest as of this writing)
- Open TouchGrafx and select open project.
- Navigate to the project file in CM7/TouchGFX/TouchGfx_Tutorial.touchgfx and open it.
- Both the desktop simulator and the run on target buttons in the lower left should work.  
- Obviously you must possess the target to run on the target.

How to run in STM32CubeIDE
-Import the project as existing code and navigate to the STM32CubeIDE folder.
-The importer should find 4 projects nested within that folder.
-The H7 is an odd platform, it has separate sub-projects for the separate cores.  But the M7 core is the only one doing anything so far.  But realize that by default you are only debugging one core unless you modify the debug configuration to load both cores.  The debug configuration loaded under the CM7 project should do this correctly (hopefully).

Red Herrings and other trivia:
There are some bits and pieces of QP related stuff like the template class for launching active objects that have nothing to do with the integration with TouchGrafx.  Same for the BSP stuff.  The QSPY build routes the CM7 output to the USB virtual com port associated with the ST-Link.

I know there are some files under version control that do not need to be.  Any cleanups are welcome.

This is my first open source rodeo with me creating and posting the repo so any constructive feedback welcome.  

David
davidsmoot (at) gmail.com
