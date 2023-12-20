clc
time = load('orignalData/time'); % Read time data
liquidFraction = load('orignalData/liquidFraction'); % Read liquid-fraction data
figure
plot(time,liquidFraction(1:2:end))
grid on
xlabel("Time(s)")
ylabel("Liquid fraction")