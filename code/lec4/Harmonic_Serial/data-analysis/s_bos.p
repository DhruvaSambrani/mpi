set terminal postscript eps enhanced color
#set key top left
set output 's_bos.eps'

colour1="#00A0ff"
colour2="navy"
colour3="#ffA000"
colour4="#800000"
colour5="black"
colour6="red"
colour7="#0060ad"
colour8="green"



set style line 1 \
    linecolor rgb colour8 \
    linetype 1 linewidth 1.5 \
    pointtype 2 pointsize 0.005 

set style line 2 \
    linecolor rgb colour5 \
    linetype 1 linewidth 1.5 \
    pointtype 2 pointsize 0.005 

set style line 3 \
    linecolor rgb colour2 \
    linetype 1 linewidth 1 \
    pointtype 6 pointsize 0.6 

set style line 4 \
    linecolor rgb colour3 \
    linetype 1 linewidth 1 \
    pointtype 13 pointsize 0.25  

set style line 5 \
    linecolor rgb '#dd181f' \
    linetype 1 linewidth 1 \
    pointtype 7 pointsize 0.6  



#set xrange [2000:3000]
#set yrange [50:100]

#set xtics 0.2
#set ytics 0.2

set mxtics 5
set mytics 5

#set format x "%2.0t * 10^{%L}"
#set format x "%.0s*10^{%T}"
#set format x "%2.0t{/Symbol \327}10^{%L}"

#set xtics rotate 45 offset -0.8,-1.8
# set label 3 at 360,4.6 "{/Symbol a} = " left offset 0,0.5
# set label 4 at 360,4.2 "{/Symbol d} = " left offset 0,0.5


set xlabel "Time" font "Times,15"
set ylabel "s_{bos} " font "Times,15"

#set logscale x
set key font "Verdana,10"
set key spacing "1.5"

plot   "s_bos.dat"  using 0:1 with p pt 3 title ""



