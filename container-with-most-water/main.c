int min(int a, int b) {
    return a <= b ? a : b;
}

int max(int a, int b) {
    return a >= b ? a : b;
}

int maxArea(int* height, int heightSize){
    int left = 0;
    int right = heightSize - 1;
    int area_max = 0;

    while ( left < right) {
        int area = (right - left) * min(height[left], height[right]);
        area_max = max(area, area_max);
        if (height[left] <= height[right]) {
            left++;
        }
        else {
            right--;
        }
    }

    return area_max;
}

int main() {
    int height1[] = {1,8,6,2,5,4,8,3,7};
    int height1Size = sizeof(height1) / sizeof(height1[0]);
    printf("%d\n", maxArea(height1, height1Size));
    return 0;
}