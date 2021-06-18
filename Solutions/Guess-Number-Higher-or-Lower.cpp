/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int64_t low = 1, high = n, mid;
        while (low <= high) {
            mid = (low + high) >> 1;
            switch (guess(mid))
            {
            case 0: return mid;
                break;
            case 1: low = mid + 1; break;
            case -1: high = mid - 1; break;
            default:
                break;
            };
        };
        return mid;
    }
};