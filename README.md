# BSQ @ SBER school 21 (42)

**"Piscine" final project.**

[Program Specs](https://github.com/kravchenkovmiit/bsq/blob/master/Project_BSQ.pdf)

[School Code Formatting Standards - The Norm](https://github.com/kravchenkovmiit/flt/blob/master/Norm.pdf)

## Compiling
`make bsq`

## Usage
`./bsq [file]`

### What BSQ Does
Given a map and its legend (in the first line of the map file):

![Valid Map](https://github.com/kravchenkovmiit/bsq/blob/master/assets/bsq_map.png)

BSQ find the biggest square that it can make without encountering any obstacle:

```
~ ./bsq maps/map_10_10_4 
.oxxxx.oo.
..xxxx..o.
..xxxxo..o
..xxxxo...
.........o
ooo.o.o...
..o.......
.......o.o
......o...
..........
```

In case of multiplous squares of the same size it choses the most upper one and then the one which is most left.
