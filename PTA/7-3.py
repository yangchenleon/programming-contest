def partitionSeq(theSeq, first, last):
    pivot = theSeq[first]
    # print('before partitionSeq', theSeq)

    left = first + 1
    right = last

    while True:
        # 找到第一个比pivot大的
        while left <= right and theSeq[left] < pivot:
            left += 1

        # 从右边开始找到比pivot小的
        while right >= left and theSeq[right] >= pivot:
            right -= 1

        if right < left:
            break
        else:
            theSeq[left], theSeq[right] = theSeq[right], theSeq[left]
    # 把pivot放到合适的位置
    theSeq[first], theSeq[right] = theSeq[right], theSeq[first]

    # print('after partitionSeq {}: {}\t'.format(theSeq, pivot))
    return right    # 返回pivot的位置

def nth_element(seq, beg, end, k):
    if beg == end:
        return seq[beg]
    pivot_index = partitionSeq(seq, beg, end)
    if pivot_index == k:
        return seq[k]
    elif pivot_index > k:
        return nth_element(seq, beg, pivot_index-1, k)
    else:
        return nth_element(seq, pivot_index+1, end, k)

n, idx = [int(i) for i in input().split()]
nums = [int(i) for i in input().split()]
print(nth_element(nums, 0, n-1, idx-1), end='')