# thermoassistant
Thermodynamics Experiment Assistant

## Formulas
![equation](https://latex.codecogs.com/gif.latex?PV=nRT)

![equation](https://latex.codecogs.com/gif.latex?a=\frac{N[xy]-[x][y]}{N[xx]-[x][x]})

![equation](https://latex.codecogs.com/gif.latex?b=\frac{[y][xx]-[x][xy]}{N[xx]-[x][x]})

![equation](https://latex.codecogs.com/gif.latex?[x]=\sum_{i=1}^{N}x_i)

![equation](https://latex.codecogs.com/gif.latex?[xx]=\sum_{i=1}^{N}x_i^2)

![equation](https://latex.codecogs.com/gif.latex?[xy]=\sum_{i=1}^{N}x_iy_i)

![equation](https://latex.codecogs.com/gif.latex?[y]=\sum_{i=1}^{N}y_i)

![equation](https://latex.codecogs.com/gif.latex?a=\frac{[xy]}{[xx]},b=0)

![equation](https://latex.codecogs.com/gif.latex?\alpha^2=\frac{[dd]}{N-2})

![equation](https://latex.codecogs.com/gif.latex?[dd]=\sum_{i=1}^{N}d_i^2)

![equation](https://latex.codecogs.com/gif.latex?\frac{\alpha_a^2}{N}=\frac{\alpha_b^2}{[xx]}=\frac{\alpha^2}{\Delta})

![equation](https://latex.codecogs.com/gif.latex?\Delta=\begin{vmatrix}&space;[xx]&space;&&space;[x]&space;\\&space;[x]&space;&&space;N&space;\end{vmatrix})

![equation](https://latex.codecogs.com/gif.latex?V=(\frac{nR}{P})T)

![equation](https://latex.codecogs.com/gif.latex?P=(\frac{nR}{V})T)

## Output

```
{DD M D H:M:S Y}
N:{$number_of_expriments}
constant_parameter:{P/V}
constant_value:{$constant_value} ({Pa/lit})
Temperature(C deg):{V/P} ({lit/Pa})
{$temp1}:{$value1}
...
---
{DD M D H:M:S Y}
a:{$a}
alpha_a:{$alpha_a}
V=({$a}±{$alpha_a})T
R:8.314
n:{$n} (mole)
```
