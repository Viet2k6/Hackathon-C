#include <stdio.h>
int main() {
    int arr[100];
    int size = 0;
    int choice;
    int key;
    int position;
    int value;
    int count = 0;
	do {
        printf("\nMENU\n");
        printf("1. Nhap so luong va gia tri cho cac phan tu\n");
        printf("2. In mang (arr[0]=..., arr[1]=...)\n");
        printf("3. Dem so luong so hoan hao\n");
        printf("4. Dem so luong so nguyen to\n");
        printf("5. Tim gia tri lon thu 2 (Khong sap xep)\n");
        printf("6. Tim gia tri nho thu 2 (Khong sap xep)\n");
        printf("7. Them phan tu tai vi tri\n");
        printf("8. Xoa phan tu tai vi tri\n");
        printf("9. Sap xep mang tang dan (sap xep chen)\n");
        printf("10. Sap xep mang giam dan (sap xep chen)\n");
        printf("11. Tim kiem phan tu (Tim kiem nhi phan)\n");
        printf("12. Xoa phan tu trung lap va in phan tu doc nhat\n");
        printf("13. Sap xep va hien thi so chan dung truoc, so le dung sau\n");
        printf("14. Dao nguoc mang\n");
        printf("15. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Nhap so luong phan tu: ");
                scanf("%d", &size);
                if (size <= 0 || size > 100) {
                    printf("So luong khong hop le!\n");
                    size = 0;
                } else {
                    for (int i = 0; i < size; i++) {
                        printf("Nhap gia tri cho arr[%d]: ", i);
                        scanf("%d", &arr[i]);
                    }
                }
                break;
            }
            case 2: {
                if (size == 0) {
                    printf("Mang rong\n");
                } else {
                    printf("Mang hien tai: ");
                    for (int i = 0; i < size; i++) {
                        printf("arr[%d]=%d ", i, arr[i]);
                    }
                    printf("\n");
                }
                break;
            }
            case 3: {
                for (int i = 0; i < size; i++) {
                    int sum = 0;
                    for (int j = 1; j <= arr[i] / 2; j++) {
                        if (arr[i] % j == 0) sum += j;
                    }
                    if (sum == arr[i]) count++;
                }
                printf("So luong so hoan hao: %d\n", count);
                break;
            }
            case 4: {
                for (int i = 0; i < size; i++) {
                    int isPrime = arr[i] > 1;
                    for (int j = 2; j * j <= arr[i] && isPrime; j++) {
                        if (arr[i] % j == 0) isPrime = 0;
                    }
                    if (isPrime) count++;
                }
                printf("So luong so nguyen to: %d\n", count);
                break;
            }
            case 5: {
                if (size < 2) {
                    printf("Mang phai co it nhat 2 phan tu!\n");
                } else {
                    int max1 = arr[0], max2 = arr[0];
                    for (int i = 1; i < size; i++) {
                        if (arr[i] > max1) {
                            max2 = max1;
                            max1 = arr[i];
                        } else if (arr[i] > max2 && arr[i] < max1) {
                            max2 = arr[i];
                        }
                    }
                    if (max1 == max2) {
                        printf("Khong ton tai gia tri lon thu hai.\n");
                    } else {
                        printf("Gia tri lon thu hai: %d\n", max2);
                    }
                }
                break;
            }
            case 6: {
                if (size < 2) {
                    printf("Mang phai co it nhat 2 phan tu!\n");
                } else {
                    int min1 = arr[0], min2 = arr[0];
                    for (int i = 1; i < size; i++) {
                        if (arr[i] < min1) {
                            min2 = min1;
                            min1 = arr[i];
                        } else if (arr[i] < min2 && arr[i] > min1) {
                            min2 = arr[i];
                        }
                    }
                    if (min1 == min2) {
                        printf("Không ton tai gia tri nho thu hai.\n");
                    } else {
                        printf("Gia tri nho thu hai: %d\n", min2);
                    }
                }
                break;
            }
            case 7: {
                if (size >= 100) {
                    printf("Mang da day khong the them phan tu\n");
                } else {
                    printf("Nhap gia tri can them: ");
                    scanf("%d", &value);
                    printf("Nhap vi tri can them (0-%d): ", size);
                    scanf("%d", &position);
                    if (position < 0 || position > size) {
                        printf("Vi tri khong hop le!\n");
                    } else {
                        for (int i = size; i > position; i--) {
                            arr[i] = arr[i - 1];
                        }
                        arr[position] = value;
                        size++;
                        printf("Da them %d vao vi tri %d.\n", value, position);
                    }
                }
                break;
            }
            case 8: {
                if (size == 0) {
                    printf("Mang rong\n");
                } else {
                    printf("Nhap vi tri can xoa (0-%d): ", size - 1);
                    scanf("%d", &position);
                    if (position < 0 || position >= size) {
                        printf("Vi tri khong hop le!\n");
                    } else {
                        for (int i = position; i < size - 1; i++) {
                            arr[i] = arr[i + 1];
                        }
                        size--;
                        printf("Da xoa phan tu tai vi tri %d.\n", position);
                    }
                }
                break;
            }
            case 9: {
                for (int i = 1; i < size; i++) {
                    int key = arr[i], j = i - 1;
                    while (j >= 0 && arr[j] > key) {
                        arr[j + 1] = arr[j];
                        j--;
                    }
                    arr[j + 1] = key;
                }
                printf("Mang da sap xep tang dan.\n");
                break;
            }
            case 10: {
                for (int i = 1; i < size; i++) {
                    int key = arr[i], j = i - 1;
                    while (j >= 0 && arr[j] < key) {
                        arr[j + 1] = arr[j];
                        j--;
                    }
                    arr[j + 1] = key;
                }
                printf("Mang da sap xep giam dan.\n");
                break;
            }
            case 11: {
                printf("Nhap gia tri can tim: ");
                scanf("%d", &key);
                int left = 0, right = size - 1, found = 0;
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (arr[mid] == key) {
                        printf("Tim thay %d tai vi tri %d.\n", key, mid);
                        found = 1;
                        break;
                    }
                    if (arr[mid] < key) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                if (!found) {
                    printf("%d không ton tai trong mang.\n", key);
                }
                break;
            }
            case 12:{
                for (int i = 0; i < size; i++) {
                    for (int j = i + 1; j < size;) {
                        if (arr[i] == arr[j]) {
                            for (int k = j; k < size - 1; k++) {
                                arr[k] = arr[k + 1];
                            }
                            size--;
                        } else {
                            j++;
                        }
                    }
                }
                printf("Mang sau khi xaa phan tu trung lap: ");
                for (int i = 0; i < size; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }
            case 13: {
                int i = 0, j = size - 1;
                while (i < j) {
                    if (arr[i] % 2 == 0) {
                        i++;
                    } else if (arr[j] % 2 != 0) {
                        j--;
                    } else {
                        int temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
                printf("Mang sau khi sap xep: ");
                for (i = 0; i < size; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }
            case 14: {
                for (int i = 0; i < size / 2; i++) {
                    int temp = arr[i];
                    arr[i] = arr[size - 1 - i];
                    arr[size - 1 - i] = temp;
                }
                printf("Mang da duoc dao nguoc.\n");
                break;
            }
            case 15: {
                printf("Thoat chuong trinh.\n");
                break;
            }
            default: {
                printf("Lua chon khong hop le!\n");
                break;
            }
        }
    } while (choice != 15);

    return 0;
}

