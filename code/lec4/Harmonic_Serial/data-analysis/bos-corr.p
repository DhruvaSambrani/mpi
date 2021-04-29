set terminal postscript eps enhanced color dashed lw 1 "Helvetica" 16
#set terminal postscript enhanced color dashed lw 1 "Helvetica" 15

#set key box
#set key box vertical width 1.5 height 0.2 maxcols 1 spacing 1 opaque
#set key left bottom

#####################################################
#defining colours and various linestyles


colour1="#00A0ff"
colour2="navy"
colour3="#ffA000"
colour4="#800000"
colour5="black"
colour6="red"
colour7="#0060ad"
colour8="#008000"
colour9='#dd181f'


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
    linecolor rgb colour9 \
    linetype 1 linewidth 1 \
    pointtype 7 pointsize 0.6  

#####################################################



#####################################################
#Imaginary Part 
   
################################################################

set output "phi-corr0.eps"


set tics font "Helvetica,16"
#set ytics 0.2

#set xrange[-1:17]
#set yrange[-0.03:0.03]
set key font ",16"


#############################################


#############################################

#set xlabel "t" font ",20"
#set ylabel "Re [ {/Symbol f}(0){/Symbol f}(t) ]" font "Times,20" offset 0.5,0,0


yzero=0
plot "phi_corr_av_err-.txt" using 1:2:3 with lp title ""
