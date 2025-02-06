class Solution {
    func canMakeSubsequence(_ source: String, _ target: String) -> Bool {
        var targetIdx = 0
        let targetLen = target.count
        let targetArray = Array(target)
        
        for currChar in source {
            if targetIdx < targetLen && (Int(targetArray[targetIdx].asciiValue!) - Int(currChar.asciiValue!) + 26) % 26 <= 1 {
                targetIdx += 1
            }
        }
        return targetIdx == targetLen
    }
}