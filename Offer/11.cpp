class Solution {
public:
    int minArray(vector<int>& numbers) {
        int _min = 0x7fffffff, left = 0, right = numbers.size() - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (numbers[left] < numbers[mid]) {
                _min = min(_min, numbers[left]);
                left = mid + 1;
            } else if (numbers[mid] < numbers[right]) {
                _min = min(_min, numbers[mid]);
                right = mid - 1;
            } else {
                _min = min(_min, min(numbers[left], numbers[right]));
                left++;
                right --;
            };
        };
        return _min;
    }
};