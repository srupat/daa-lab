# there is an element which is present more than or equal to n/2 times in the array. find that element

def find_majority_element(nums):
    cand, count = 0, 0
    for num in nums:
        if count == 0:
            cand = num        
        if num != cand:
            count -= 1
        else:
            count += 1
    return cand

nums = [1, 2, 1, 1, 2, 2, 2, 2, 2]
print(find_majority_element(nums))
        