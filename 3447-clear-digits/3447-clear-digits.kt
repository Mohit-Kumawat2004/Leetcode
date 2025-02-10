class Solution {
    fun clearDigits(s: String): String {
        val answer = StringBuilder()

        for (char in s) {
            if (char.isDigit() && answer.isNotEmpty()) {
                answer.setLength(answer.length - 1)
            } else {
                answer.append(char)
            }
        }

        return answer.toString()
    }
}
