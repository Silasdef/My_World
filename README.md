🌍 My World – Terrain Editor with CSFML
🧠 Project Overview

My World is a terrain editing tool inspired by Tycoon Terrain for Unity3D. Built in C using CSFML, this program displays and allows real-time editing of a 3D wireframe map composed of square tiles. Users can modify the terrain by raising, lowering, or tilting tiles, offering an intuitive and dynamic editing experience.
🛠️ Technologies

    Language: C

    Graphics: CSFML

    Build System: Makefile (all, clean, fclean, re rules)

🎯 Objectives
✅ Mandatory Features

    A window that can be closed using event handling

    Input handling from both mouse and keyboard

    Frame rate–independent animations

✅ Must-Have Features

    3D projection (isometric or parallel)

    Textured map tiles

    Tile selection via mouse click

    A toolbar with at least 3 selectable terrain-editing effects:

        Modify altitude

        Reset altitude

        Change area-of-effect size

✅ Should-Have Features

    Window resolution between 800x600 and 1920x1080

    Editable textboxes to define map size

    Tooltips on toolbar hover

    Button visual states: idle, hover, and clicked

    Additional terrain layers (e.g., water, lava)

    Zoom with keyboard/mouse scroll

    Camera movement with arrow keys

    Save maps in .legend format

🧪 Could-Have Features (Optional)

    Save and load maps at runtime

    Choose filenames dynamically

    Full 3D camera control

    Animated terrain layers

    Tool selection via keyboard shortcuts

    Interactive sound effects

    Slope-based texture adaptation

    Map elements (buildings, roads, etc.)

    Animated or dynamic environmental layers (lava, water, etc.)

📦 Compilation

To build the project, simply run:

make

Other useful commands:

make clean     # Removes object files
make fclean    # Removes object files and binaries
make re        # Cleans and rebuilds everything

🎮 Controls & Interaction
Action	Input
Select tile	Mouse click
Move camera	Arrow keys
Zoom	Scroll wheel / keyboard
Modify terrain	Toolbar buttons
Resize effect area	Toolbar option
Reset tile altitudes	Toolbar option

📌 Notes

This project is a great opportunity to apply game development concepts, improve UI/UX design in C, and explore real-time rendering techniques using CSFML.
