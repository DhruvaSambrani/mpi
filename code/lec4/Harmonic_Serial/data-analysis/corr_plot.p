set terminal postscript eps enhanced color

set output 'b64.eps'
set style fill solid 0.8 border -1

set encoding iso_8859_1 

set style textbox opaque 

set object 1 rectangle from screen -1,-1 to screen 1000,1000 fillcolor rgb"#ffffff" behind
set term pdfcairo font "sans,9"

set grid ytics lt 0 lw 2 lc rgb "#00008B"
set grid xtics lt 0 lw 2 lc rgb "#00008B"
#  Plot data

set xrange [0:63]
#set yrange [-0.5:2]

#set xtics 0.2
#set ytics 0.5


set key top right
#set label boxed "E_0^{(B)}=m_B=0.21419 \261 0.00345 " at 30.5,0.0135

set xlabel "Time" font "sans,12" offset 1
set ylabel "Bosonic Correlator" font "sans,12" offset 1

#f(x)=0.027186*(exp(-0.21419*x)+exp(0.21419*(x-64))) 

plot "phi.txt" with yerrorbars lt -1 pt 7 ps 0.5 lc rgb "#008040" title "Correlator"
