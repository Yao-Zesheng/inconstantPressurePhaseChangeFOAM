# inconstantPressurePhaseChangeFOAM
Solver for PCM-based ocean thermal engine using open-source CFD software OpenFOAM
1) Install open-source software OpenFOAM-v2012
2) Compile the solver
```
cd solver/inconstantPressurePhaseChangeFOAM
wclean
wmake
```
3) Running cases
```
cd case/PCM-MF_15-20MPa
./Allclean
./Allrun
```
4) Extract simulation results
```
./makeFiles
```
5) Run "readResults.m" in Matlab to creat figures of simulation results.
Please refer to our paper for algorithm details:
Yao Z, Yang C, Chen B, Dai G, Chen Y. Computational fluid dynamics analysis of PCM-based ocean thermal engine with external rib turbulators. Applied Thermal Engineering 2024;238:122054. https://doi.org/10.1016/j.applthermaleng.2023.122054.
