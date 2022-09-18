# Height-Map-Creator
Height Map Creator in C++ using Raylib!

Background

The main idea of the project was to create a tool that would generate(and modify) a fully visualised HeightMap, interpreted as a 3D model.
Generated texture can be exported and used in the game engine like Unreal Engine or Unity. With realtime view, users can easily manipulate values of the height map.

The Application on start generates a default texture, which is used to build a mesh. A User can manipulate 3 main values of generator:
- Force (Parameter change a contrast of the image. Provide to more/less pits in the ground)
- Frequency (Amount of Hills)
- Flat (Sharpness of the edges)

[Aplication View](https://user-images.githubusercontent.com/25442811/190927600-8b182565-c40d-4de3-a74a-5d6ef9856fc1.png)

Instalation
- Windows:

    -Download Raylib c++ for Windows : https://github.com/raysan5/raylib/wiki/Working-on-Windows
    
    -Download a template of the project, configured for windows : [raygui-master.zip](https://github.com/Kyufujin/Height-Map-Creator/files/9595232/raygui-master.zip)
[order_invoice_01-09-2022_002114.pdf](https://github.com/Kyufujin/Height-Map-Creator/files/9595233/order_invoice_01-09-2022_002114.pdf)

    -Download this repository, delete CMAKELISTS.TXT and put everything in downloaded template folder. 
    
    -Compile with c++
    
- Linux:

    -CMAKE should download everything including raylib, if that won't happen please, try to install raylib c++ for linux system. 
    
    -create a build folder -> use cd build -> use cmake .. -> use make
    
    -open project with ./project command, in build directory 


