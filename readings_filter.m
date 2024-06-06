fc = 10; % cutoff frequency
num = 2*pi*fc;
den = [1 num];
H = tf(num,den); % Transfer function
Hd = c2d(H,0.0001); % z - transform