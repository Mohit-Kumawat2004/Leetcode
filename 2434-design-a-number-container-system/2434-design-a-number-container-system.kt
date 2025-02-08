class NumberContainers {
    private val indexToNumber = mutableMapOf<Int, Int>()
    private val numberToIndices = mutableMapOf<Int, SortedSet<Int>>()

    fun change(index: Int, number: Int) {
        indexToNumber[index]?.let { prevNumber ->
            numberToIndices[prevNumber]?.remove(index)
            if (numberToIndices[prevNumber]?.isEmpty() == true) {
                numberToIndices.remove(prevNumber)
            }
        }

        indexToNumber[index] = number
        numberToIndices.computeIfAbsent(number) { sortedSetOf() }.add(index)
    }

    fun find(number: Int): Int {
        return numberToIndices[number]?.firstOrNull() ?: -1
    }
}

/**
 * Your NumberContainers object will be instantiated and called as such:
 * var obj = NumberContainers()
 * obj.change(index,number)
 * var param_2 = obj.find(number)
 */
