

f(x) = (1/(2*m*c))*(exp(-c*x)+exp(c*(x-16)));
fit f(x) "phi_corr_av_err-.txt" using 1:2:3 via m,c





