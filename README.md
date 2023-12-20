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
