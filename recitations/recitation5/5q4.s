.text
main:
    addi $sp, $sp -4
    sw $ra, 0($sp)

    li $s0, 5
    li $s1, 6

    move $a0, $s0
    move $a1, $s1

    jal foo
    move $t3, $v0

    add $t3, $t3, $s0
    add $t3, $t3, $s1

    li $v0, 1
    move $a0, $t3
    syscall

    lw $ra, 0($sp)
    addi $sp, $sp 4

    jr $ra
foo:
    addi $sp, $sp -8
    sw $s0, 0($sp)
    sw $s1, 4($sp)

    add $v0, $a0, $a1

    lw $s0, 0($sp)
    lw $s1, 4($sp)
    addi $sp, $sp 8

    jr $ra
