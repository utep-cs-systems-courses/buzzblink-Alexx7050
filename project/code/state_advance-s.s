    .arch msp430g2553
    .p2align 1,0

    .text
jt: .word case0
    .word case1
    .word case2
    .word case3

    .global state_advance
    .extern n_switch

state_advance:
    ;; if (n_switch > 3) goto dend
    cmp &n_switch, #3
    jnc end
    ;; PC = jt[n_switch]
    mov &n_switch, r12
    add r12, r12
    mov jt(r12), r0
case0:
    call #toggle_red()
    jmp end
case1:
    call #toggle_green()
    jmp end
case2:
    call #toggle_both()
    jmp end
case3:
    call #turn_off()
    jmp end
end:
    pop r0
