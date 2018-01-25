function pump_analysis
% pump_analysis  Analyze pump curve data from ME 120

% -- Read data from text file and copy to working vectors
D = importdata('pump_data.txt','\t',1);
h = D.data(:,1);    %  Head: height of outlet tube above reservoir (inch)
V = D.data(:,2);    %  Voltage supplied to pump motor
I = D.data(:,3);    %  Current through pump motor (A)
dm = D.data(:,4);   %  Mass collected in time interval dt (gram)
dt = D.data(:,5);   %  Time interval for mass measurement (seconds)

% -- Constants for data analysis
g = 9.81;                 %  Acceleration of gravity (m/s^2)
rhow = 1000;              %  Density of water (kg/m^3)
dtube = 6.35e-3;          %  Inside diameter of nylon tubing (m)
Atube = 0.25*pi*dtube^2;  %  Cross-section area of nylon tubing (m^2)

% -- Compute and plot the pump curve
hm = h*2.54e-2;            %  Convert head from inches to meters
Q = ((dm/1000)./dt)/rhow;  %  Convert mass measurements to volumetric flow rate (m^3/s)
Lpm = Q*1000/60;           %  Convert m^3/s to L/min

plot(Lpm,h,'o')