%ploting program for diode IV curve. 
%uses large signal model and ideal diode model

clc
clear all
n = 1.65;         %ideality factor
Is = 5*10^-9;     %diode reverse saturated current (1n4148 at low reverse voltages)
q = 1.602*10^-19; %electron charge
K = 1.38*10^-23;  %Boltzmann constant
T = 300;          %absolute temperature

Vd = -0.5:0.050:0.8; %voltage across diode
Id = Is*(exp((q*Vd)/(1.65*K*T))-1); %current across diode

plot(Vd,Id);
grid;
xlabel('Applied Diode Voltage (V)' );
ylabel('Diode Current (A)');

