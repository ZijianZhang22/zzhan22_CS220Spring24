.global digit_freq
digit_freq:
    // Function prologue
    stp x29, x30, [sp, -16]!   // Save frame pointer and link register
    mov x29, sp                // Set up new frame pointer

    // Initialize frequency array with zeros
    mov x2, x1                 // x2 = pointer to freq array
    mov w3, 0                  // Initialize loop counter

init_loop:
    cmp w3, 10
    bge end_init_loop          // Exit loop if loop counter >= 10

    str xzr, [x2, w3, lsl #3]  // freq[loop_counter] = 0 (use lsl to scale by 8 for QWORD)

    add w3, w3, 1              // Increment loop counter
    b init_loop                // Repeat loop

end_init_loop:

    // Process each digit in the number
    cbz x0, end_digit_loop     // Exit if n == 0

digit_loop:
    mov x1, x0                 // x1 = n (number to extract digit from)
    mov x2, 10                 // x2 = 10 (divisor)

    udiv x1, x1, x2            // x1 = n / 10 (remaining number), x3 = n % 10 (digit)
    
    str x3, [x2, x3, lsl #3]   // Increment the corresponding frequency

    cbz x1, end_digit_loop     // Exit loop if remaining number is zero
    b digit_loop               // Repeat loop

end_digit_loop:

    // Function epilogue
    ldp x29, x30, [sp], 16     // Restore frame pointer and link register
    ret
