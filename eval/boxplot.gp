reset # fallback to default setting
inname = "pts.txt"
set term png
set output 'dist_box.png'
set border 2 front lt black linewidth 1.000 dashtype solid
set boxwidth 0.5 absolute
set style fill   solid 0.50 border lt -1
unset key
set style increment default
set pointsize 0.5
set style data boxplot
set style boxplot nooutliers
set xtics border in scale 0,0 nomirror norotate  autojustify
set xtics  norangelimit 
set xtics ("1" 1, "5" 5, "10" 10, "15" 15, "20" 20) scale 0.0
set ytics border in scale 1,0.5 nomirror norotate  autojustify
# set title "Distribution of maximum dice rolling results with multiple trials\n"
set xrange [ * : * ] noreverse writeback
set x2range [ * : * ] noreverse writeback
set xlabel "Available dice rolling trials per round" 
set ylabel "Maximum dice rolling results" 
set yrange [ * : * ] noreverse writeback
set y2range [ * : * ] noreverse writeback
set zrange [ * : * ] noreverse writeback
set cbrange [ * : * ] noreverse writeback
set rrange [ * : * ] noreverse writeback
plot inname using (1.0):1,\
    '' using (2.0):2,\
    '' using (3.0):3,\
    '' using (4.0):4,\
    '' using (5.0):5,\
    '' using (6.0):6,\
    '' using (7.0):7,\
    '' using (8.0):8,\
    '' using (9.0):9,\
    '' using (10.0):10,\
    '' using (11.0):11,\
    '' using (12.0):12,\
    '' using (13.0):13,\
    '' using (14.0):14,\
    '' using (15.0):15,\
    '' using (16.0):16,\
    '' using (17.0):17,\
    '' using (18.0):18,\
    '' using (19.0):19,\
    '' using (20.0):20
