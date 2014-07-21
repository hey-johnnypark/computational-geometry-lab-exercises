function [C,R] = incircle(x,y)

% Vektoren zusammenfassen
  xy = [x(:),y(:)];
% Berechnen der kovexen Hüllen mit Hilfe von Matlab Funktion "convhulln"
ecken = convhulln(xy);

ne = size(ecken,1);

% Die Endpunkte jeder Kante
A = xy(ecken(:,1),:);
B = xy(ecken(:,2),:);

% Der Normalenvektor zu jeder Kante
N = (B - A)*[0 1;-1 0];

% Normalisierung des Vektors
Betrag = sqrt(sum(N.^2,2));
N = N./[Betrag,Betrag];

Aeq = [N,zeros(ne,1),-eye(ne)];
beq = sum(N.*A,2);

A = [zeros(ne,2),ones(ne,1),-eye(ne)];
b = zeros(ne,1);

f = zeros(ne+3,1);
f(3) = -1;


% lineprog zum Lösen des Gleichungssystems
result = linprog(f,A,b,Aeq,beq);

% Parameter für den Kreis
C = result(1:2)';
R = result(3);
