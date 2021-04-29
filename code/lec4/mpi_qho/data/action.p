set terminal postscript eps enhanced color font ',18'

set output 'action.eps'

#set key box vertical width -1.5 height 0.5 maxcols 1 spacing 1 opaque
#set key bottom


colour1="#00A0ff"
colour2="navy"
colour3="#ffA000"
colour4="#800000"
colour5="black"
colour6="red"
colour7="#0060ad"
colour8="#008000"



set style line 1 \
    linecolor rgb colour8 \
    linetype 1 linewidth 2.5 \
    pointtype 2 pointsize 0.9 


set style line 2 \
    linecolor rgb '#dd181f' \
    linetype 1 linewidth 1 \
    pointtype 9 pointsize 0.8


set style line 3 \
    linecolor rgb colour2 \
    linetype 1 linewidth 1 \
    pointtype 6 pointsize 0.6 

set style line 4 \
    linecolor rgb colour3 \
    linetype 1 linewidth 1 \
    pointtype 13 pointsize 0.9

set style line 5 \
    linecolor rgb colour5 \
    linetype 1 dashtype "." linewidth 3.5 \
    pointtype 2 pointsize 0.9


#set xrange [-2:2]
#set yrange [-1:25]

#set xtics 20
#set ytics 1

set mxtics 5
set mytics 5




set xlabel "Simulation Time" font "Times,23" offset 0,0.5,0
#set ylabel "B_{{/Symbol a}}" font "Times,23" offset 0.5,0,0
#set key title "{/Symbol a}=0.4, g=1, {/Symbol m}=2, N_{lat}=10" font 'Times, 18'


set key font "Times,18"
set key spacing "1.0"
#set key left top outside
#set key box linestyle 1


#set output 'theta.eps'

#plot  "acceptance.txt" using 0:1 with points ls 2 title "Acc", "acceptance.txt" using 0:2 with points ls 5 title "Rej"

#set output 'sb.eps'

#plot  "corr.txt" using 1:2 with points ls 1 title "corr"

#set output 'noise.eps'

#plot  "noise.txt" using 0:1 with points ls 3 title "noise"

#plot  "site.txt" using 1:2 with points ls 3 title "site"

plot  "s_bos.dat" using 0:1 with points ls 3 title "acion_{real}"




