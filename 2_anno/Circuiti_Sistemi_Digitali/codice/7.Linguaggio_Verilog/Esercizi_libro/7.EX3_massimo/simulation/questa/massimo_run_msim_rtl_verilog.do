transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+/home/ubuntu/Documents/GitHub/uni-circuiti/7.Linguaggio_Verilog/Esercizi_libro/7.EX3_massimo {/home/ubuntu/Documents/GitHub/uni-circuiti/7.Linguaggio_Verilog/Esercizi_libro/7.EX3_massimo/massimo.v}

vlog -vlog01compat -work work +incdir+/home/ubuntu/Documents/GitHub/uni-circuiti/7.Linguaggio_Verilog/Esercizi_libro/7.EX3_massimo {/home/ubuntu/Documents/GitHub/uni-circuiti/7.Linguaggio_Verilog/Esercizi_libro/7.EX3_massimo/tb_massimo.v}

vsim -t 1ps -L altera_ver -L lpm_ver -L sgate_ver -L altera_mf_ver -L altera_lnsim_ver -L cycloneive_ver -L rtl_work -L work -voptargs="+acc"  tb_massimo

add wave *
view structure
view signals
run -all
