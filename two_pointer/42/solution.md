```C=
if (height[left] < height[right]) {
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                } else {
                    water += leftMax - height[left];
                }
                left++;
            } else {
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                } else {
                    water += rightMax - height[right];
                }
                right--;
            }
```

假設我們有這樣的高度數組：[3, 1, 4, 2, 5]

初始狀態：left = 0 (高度 3), right = 4 (高度 5), leftMax = 0, rightMax = 0
height[left] (3) < height[right] (5)，所以我們處理左側：

更新 leftMax = 3
left++ (移動到高度 1 的位置)

現在 left = 1 (高度 1), right = 4 (高度 5)
height[left] (1) < height[right] (5)，我們繼續處理左側：

此時 leftMax = 3, height[left] = 1
我們可以裝水：water += 3 - 1 = 2
left++ (移動到高度 4 的位置)
繼續這個過程...

關鍵點在於，當我們在處理左側時，我們知道右側有一個高度至少為 5 的柱子。這保證了即使我們還沒有處理中間的柱子，水也不會從右側流出。
同樣的邏輯適用於處理右側。當我們處理右側時，我們知道左側有一個足夠高的柱子來保證水不會流出。
