class Solution {
    fun maximumSum(nums: IntArray): Int {
        var result = -1
        val digitMapping = IntArray(82) { 0 }

        for (element in nums) {
            var digitSum = 0
            var currValue = element

            // Calculating digit sum
            while (currValue != 0) {
                digitSum += currValue % 10
                currValue /= 10
            }

            // Check if there's already an element with the same digit sum
            if (digitMapping[digitSum] > 0) {
                result = maxOf(result, digitMapping[digitSum] + element)
            }

            // Update the mapping to store the larger value
            digitMapping[digitSum] = maxOf(digitMapping[digitSum], element)
        }

        return result
    }
}
