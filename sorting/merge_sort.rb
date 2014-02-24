class MergeSort

  def self.sort(list)
    return list if list.size < 2
    left = list.take(list.size/2)
    right = list.drop(list.size/2)
    merge(sort(left), sort(right))
  end

  def self.merge(left, right)
    return left if right.empty?
    return right if left.empty?

    if right.last >= left.last
      highest = right.pop
    else
      highest = left.pop
    end
    merge(left, right).push(highest)
  end

end
