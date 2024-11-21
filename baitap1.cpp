#include <stdio.h>
#define MAX_VAL 30001 
#define MAX_N 100     

int main() {
    int n, a[MAX_N];
    int freq[MAX_VAL] = {0}; 
    int i, maxFreq = 0, maxValue = -1;

    printf("Nhap so phan tu cua day (khong qua 100): ");
    scanf("%d", &n);

    printf("Nhap cac phan tu trong day (khong qua 30000):\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] >= 0 && a[i] < MAX_VAL) {
            freq[a[i]]++; 
        }
    }

    
    for (i = 0; i < MAX_VAL; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            maxValue = i;
        }
    }

    if (maxFreq > 1) {
        printf("So xuat hien nhieu lan nhat la: %d voi tan suat %d lan.\n", maxValue, maxFreq);
    } else {
        printf("Khong co so nao xuat hien nhieu lan nhat.\n");
    }

    return 0;
}
