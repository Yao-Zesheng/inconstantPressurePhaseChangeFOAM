%% Thermal parameters of metal foam
% Reference:
% [1] Numerical modeling for solid-liquid phase change phenomena in porou media: Shell-and-tube type latent heat thermal energy storage
% [2] Numerical study on the influence of inclinationangle on the melting behaviour of metal foam-PCM latent heat storage unit

e = 0.98; % Porosity 
ppi = 10; % Pore density

dp = 0.0254/ppi; % pore size of the metal foam,[2] Eq.(5) 
X = 2+2*cos(4*pi/3+acos(2*e-1)/3); % tortuosity coefficient of the metal foam,[2] Eq.(6)
dk = X*dp/(3-X); % characteristic length,[2] Eq.(7)
df = 1.18*dp*sqrt((1-e)/(3*pi))*(1/(1-exp(-(1-e)/0.04))); % fibre diameter,[2] Eq.(8)
Cl = 0.00212*((1-e)^(-0.132))*((df/dp)^(-1.63)); % inertial cofficient,[2] Eq.(5)
K = e^2*dk^2/(36*(X-1)*X); % permeability coefficient,[2] Eq.(4)
Dv = 1/K % Viscous resistance coefficient
Cv = 2*Cl/sqrt(K) % Inertial resistance coefficient£¬[2] Eq.(3)
a = 0.00073*((1-e)^(-0.224))*(df^(-1.11))*(dp*0.89); % Permeability, [1] Eq.(14)



