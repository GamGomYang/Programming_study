
float calc_average() {
    float sum = 0.0;
    for (int i = 0; i < NUMMAX; i++) {
        sum += num[i];
    }
    return sum / NUMMAX;