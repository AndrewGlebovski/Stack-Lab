double test1(Stack *stack) {
    clock_t t1 = clock();

    for (int i = 0; i < 1000000; i++)
        stack_push(stack, i + 1);

    while (stack -> size > 100000) {
        int count = stack -> size >> 1;

        for (int i = 0; i < count; i++)
            stack_pop(stack);
        
        count = count >> 1;

        for (int i = 0; i < count; i++)
            stack_push(stack, i + 1);
    }
    
    clock_t t2 = clock();

    return 1000.0 * (t2 - t1) / CLOCKS_PER_SEC;
}


double test2(Stack *stack) {
    clock_t t1 = clock();

    for (int i = 0; i < 1000000; i++)
        stack_push(stack, i + 1);

    for (int i = 0; i < 100; i++) {
        for (int i = 0; i < 10000; i++)
            stack_pop(stack);

        for (int i = 0; i < 10000; i++)
            stack_push(stack, i + 1);
    }

    while (stack -> size > 100000) {
        int count = stack -> size >> 1;

        for (int i = 0; i < count; i++)
            stack_pop(stack);
        
        count = count >> 1;

        for (int i = 0; i < count; i++)
            stack_push(stack, i + 1);
    }
    
    for (int i = 0; i < 100; i++) {
        for (int i = 0; i < 10000; i++)
            stack_pop(stack);

        for (int i = 0; i < 10000; i++)
            stack_push(stack, i + 1);
    }

    clock_t t2 = clock();

    return 1000.0 * (t2 - t1) / CLOCKS_PER_SEC;
}


double test3(Stack *stack) {
    for (int i = 0; i < 1000000; i++)
        stack_push(stack, i + 1);

    clock_t t1 = clock();

    for (int i = 0; i < 1000000; i++) {
        if (rand() % 2) stack_pop(stack);
        else stack_push(stack, i + 1);
    }

    clock_t t2 = clock();

    for (int i = 0; i < 1000000; i++)
        stack_pop(stack);

    return 1000.0 * (t2 - t1) / CLOCKS_PER_SEC;
}
