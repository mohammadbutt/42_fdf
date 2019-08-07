# FDF Wireframe - 3D map rednering program.
### Purpose of the project is to read a file and generate a 3D map.

#### Project file: [FDF](https://github.com/mohammadbutt/42_fdf/blob/master/Media/doc.fdf.en.pdf)

Allowed C functions(2) - close(2), open(2), read(2), write(2).

Allowed C functions(3) - exit(3), free(3), malloc(3), perror(3), strerror(3).

Additional functions allowed - math library and miniLibx(library), library made by 42 students.

---
# Cloning repository
```
git clone https://github.com/mohammadbutt/42_fdf.git
```

# Installing FDF macOS only
```
make
./fdf resources/maps/test/maps/
```
# Demo

![](https://github.com/mohammadbutt/42_fdf/blob/master/Media/fdf_720p_25fps.gif)

# Program Controls

|Action                       |Controls                                            |
|---------------------------- |:--------------------------------------------------:|
|Move map: up down left right | :arrow_up: :arrow_down: :arrow_left: :arrow_right: |
|Rotate                       |I J K L                                             |
|ZOOM                         |Q A                                                 |
|Altitude                     |W S                                                 |
|Reset map                    |E                                                   |
|Random Color                 |R                                                   |
|Change Camera View           |C                                                   |

# Error messages

The user will get one of the following error messages if the file is invalid.
<img src= "https://github.com/mohammadbutt/42_fdf/blob/master/Media/invalid_messages.png">

# Project Summary
### Parsing and storing - [Source Code](https://github.com/mohammadbutt/42_fdf/blob/master/srcs/parse_and_store.c)
Program reads a file using the function [get_next_line](https://github.com/mohammadbutt/42_get_next_line), which I created to read a file that mimics the functionality of getline(3). Once a file is read, then it goes through several validation stages to ensure all lines or rows have the same number of elements.

If a file is valid then each row is stored as a string using the function `**str_data` malloc(3) is used to allocate memory to store the string and the temp_line is freed using free(3) before exiting the while loop to ensure there are no memory leaks. Since the numbers are stored as a string, these numbers are only characters. In order to convert these strings into numbers to perform arithmatic operations `*ft_2d_atoi` is called which takes one line and converts all of the elements of that string into numbers by using `ft_atoi`. String are converted into numbers for just 1 line.

To perform conversion on all of the rows, function, `**str_to_int` is created, which will perform this conversion on all of the lines.

### Render map - [Source Code](https://github.com/mohammadbutt/42_fdf/blob/master/srcs/render_map.c)
In order to create lines, Bresenham's line algorithm is used. Using the line algorithm, lines are created vertically(down) and horizontally(to the right). This almost works, but the only challenge is that it does not create smooth edges and produces the following lines:

```
 _ _ _ _ _ _ _
|_|_|_|_|_|_|_
|_|_|_|_|_|_|_
| | | | | | |
```
To rememedy this horizontal lines are rendered as long as y is less than height of the map. And vertical lines are only rendered as long as x is less than the width of the map, which will produce the following lines which is what we wanted to create to render a perfect map:

``` 
 _ _ _ _ _ _ _
|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|
```

### Rotation matrix - [Source Code](https://github.com/mohammadbutt/42_fdf/blob/master/srcs/rotate_matrix2.c)
Rotating the map is one of the useful features of the project in order. In order to rotate the map in any direction standard rotation matrix is used. Below is the rotation Matrix equation:
```
new_x = x cos(zθ) - y sin(zθ)
new_y = x sin(zθ) + y cos(zθ)
```
Thetha is replaced by the radian value or axis. For example if the map is being rotated on x_axis then we will use the below equation:

```
new_y = y cos(x_axis) - z sin(x_axis)
new_z = y sin(x_axis) + z cos(x_axis)
```
My source code [rotate_matrix](https://github.com/mohammadbutt/42_fdf/blob/master/srcs/rotate_matrix2.c) shows what all of the transformations look like to rotate the map on x_axis, y_axis, and z_axis. But in a nutshell when `sin` or `cos` are applied on x, y, or z, we get new x and y coordinates that creates the illusion that a map is 3 dimensional. [Wikipedia rotation matrix](https://en.wikipedia.org/wiki/Rotation_matrix) has additional information about rotation matrix.

# Resources
## Reading Resources
1. [Mac Virtual Key Code](https://stackoverflow.com/questions/3202629/where-can-i-find-a-list-of-mac-virtual-key-codes)
2. [FDF Cookbook for 42 students](https://forum.intra.42.fr/topics/19254/messages?page=1#93530)
3. [Wikipedia - Bresenham's line algorithm - Chooses just the color](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm)
4. [Wikipedia - Xiaolin Wu's line algorithm - Chooses the shade of each color](https://en.wikipedia.org/wiki/Xiaolin_Wu%27s_line_algorithm)
5. [Bresenham's Line Algorithm - Free Code Camp](https://www.freecodecamp.org/news/how-to-code-your-first-algorithm-draw-a-line-ca121f9a1395/)
6. [Rotation Matrix - Wikipedia](https://en.wikipedia.org/wiki/Rotation_matrix)
6. [Bresenham's Line Algorithm in C](https://www.thecrazyprogrammer.com/2017/01/bresenhams-line-drawing-algorithm-c-c.html)
7. [Color Gradient - Color Theory - Wikipedia](https://en.wikibooks.org/wiki/Color_Theory/Color_gradient)
7. [Isometric 2:1 Projections: Isometric Infographic Vectors](http://vectips.com/tutorials/isometric-infographic-vectors/)
8. [Military(Oblique) projection - Wikipedia](https://en.wikipedia.org/wiki/Oblique_projection)
9. [Mnemonics in trigonometry - Wikipedia](https://en.wikipedia.org/wiki/Mnemonics_in_trigonometry)
9. [Programming Operators](https://www.programiz.com/c-programming/c-operators)
10. [Ternary Operator - Free Code Camp](https://guide.freecodecamp.org/c/ternary-operator/)
11. [Data Type Ranges - Microsoft](https://docs.microsoft.com/en-us/cpp/cpp/data-type-ranges?view=vs-2019)

## Video Resources
1. [What are Radians](https://www.youtube.com/watch?v=cgPYLJ-s5II)
2. [Brief Intro to Vectors](https://www.youtube.com/watch?v=1G5E_x0MgLc)
3. [Essence of Linear Algebra 15 video series by 3Blue1Brown](https://www.youtube.com/playlist?list=PLZHQObOWTQDPD3MizzM2xVFitgF8hE_ab)
4. [Cartesian Coordinates in Three Dimensions](https://www.youtube.com/watch?v=VA5AmjhTA3A)
5. [Rotation in R3 around the x-axis | Matrix transformations - Khan Academy](https://www.youtube.com/watch?v=gkyuLPzfDV0)
6. [Rotating points using rotation Matrix](https://www.youtube.com/watch?v=OYuoPTRVzxY)
7. [Rotation Matrix](https://www.youtube.com/watch?v=Ta8cKqltPfU)
8. [Rotation in 3D](https://www.youtube.com/watch?v=wg9bI8-Qx2Q)
9. [Linear Transformation - Khan Academy](https://www.khanacademy.org/math/linear-algebra/matrix-transformations/lin-trans-examples/v/linear-transformation-examples-rotations-in-r2)

## Tools
1. [Online Graph Calculator](https://www.desmos.com/calculator)
2. [Change colors in echo](https://stackoverflow.com/questions/5947742/how-to-change-the-output-color-of-echo-in-linux)
