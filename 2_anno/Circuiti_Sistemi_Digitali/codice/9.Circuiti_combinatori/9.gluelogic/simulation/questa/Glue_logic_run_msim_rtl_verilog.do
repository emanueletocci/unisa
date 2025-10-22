transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+/home/ubuntu/Documents/GitHub/uni-circuiti/quartus_projects/gluelogic {/home/ubuntu/Documents/GitHub/uni-circuiti/quartus_projects/gluelogic/Glue_logic.v}

vlog -vlog01compat -work work +incdir+/home/ubuntu/Documents/GitHub/uni-circuiti/quartus_projects/gluelogic {/home/ubuntu/Documents/GitHub/uni-circuiti/quartus_projects/gluelogic/tb_gluelogic.v}

vsim -t 1ps -L altera_ver -L lpm_ver -L sgate_ver -L altera_mf_ver -L altera_lnsim_ver -L cycloneive_ver -L rtl_work -L work -voptargs="+acc"  tb_gluelogic.v

add wave *
view structure
view signals
run -all
