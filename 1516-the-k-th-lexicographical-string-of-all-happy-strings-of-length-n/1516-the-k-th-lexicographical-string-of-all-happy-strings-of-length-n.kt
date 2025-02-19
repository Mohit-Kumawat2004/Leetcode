class Solution {
    fun getHappyString(n: Int, k: Int): String {
        if (k > 3 * (1 shl n - 1)) return ""

        val last = n - 2
        val index = k - 1
        var curr = index ushr n - 1
        return String(CharArray(n) {
            ('a' + curr).apply { curr = nextChars[curr][(index ushr last - it) and 1] }
        })
    }

    companion object {
        val nextChars = arrayOf(intArrayOf(1, 2), intArrayOf(0, 2), intArrayOf(0, 1))
    }
}