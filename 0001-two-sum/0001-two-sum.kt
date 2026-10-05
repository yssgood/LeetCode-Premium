class Solution {
    fun twoSum(nums: IntArray, target: Int): IntArray {
        val seen = HashMap<Int,Int>() 

        for((i,num) in nums.withIndex()){
            val j = seen[target - num] 
            if(j != null) return intArrayOf(j,i) 
            seen[num] = i 
        }
        return intArrayOf() 
    }
}