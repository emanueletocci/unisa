transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+C:/Users/emanuele/Desktop/quartus_projects/decoder {C:/Users/emanuele/Desktop/quartus_projects/decoder/decoder.v}

vlog -vlog01compat -work work +incdir+C:/Users/emanuele/Desktop/quartus_projects/decoder {C:/Users/emanuele/Desktop/quartus_projects/decoder/tb_decoder.v}

vsim -t 1ps -L altera_ver -L lpm_ver -L sgate_ver -L altera_mf_ver -L altera_lnsim_ver -L cycloneive_ver -L rtl_work -L work -voptargs="+acc"  tb_decoder

add wave *
view structure
view signals
run -all
