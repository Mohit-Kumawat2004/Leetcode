class Solution {
    fun queryResults(limit: Int, queries: Array<IntArray>): IntArray {
        val n = queries.size
        val result = IntArray(n)
        val colorMap = mutableMapOf<Int, Int>()
        val ballMap = mutableMapOf<Int, Int>()

        for (i in queries.indices) {
            val ball = queries[i][0]
            val color = queries[i][1]

            // If the ball already has a color, decrement the previous color count
            ballMap[ball]?.let { prevColor ->
                colorMap[prevColor] = colorMap.getOrDefault(prevColor, 0) - 1
                if (colorMap[prevColor] == 0) {
                    colorMap.remove(prevColor)
                }
            }

            // Assign the new color to the ball
            ballMap[ball] = color

            // Increment the count of the new color
            colorMap[color] = colorMap.getOrDefault(color, 0) + 1

            result[i] = colorMap.size
        }

        return result
    }
}
