impl Solution {
    pub fn target_indices(mut nums: Vec<i32>, target: i32) -> Vec<i32> {
        nums.sort();
        let mut res = Vec::new();
        for(i, &num) in nums.iter().enumerate() {
            if num == target {
                res.push(i as i32);
            }
        }
        res
    }
}