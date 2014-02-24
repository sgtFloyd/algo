class Quicksort

  def self.sort(list, from=0, to=list.size-1)
    return list if to - from < 1
    pivot_index = partition(list, from, to)
    sort(list, from, pivot_index-1)
    sort(list, pivot_index+1, to)
    list
  end

  def self.partition(list, from, to)
    pivot_index = pivot(list, from, to)
    pivot_value = list[pivot_index]
    swap(list, pivot_index, to)

    cursor = from
    from.upto(to-1).each do |i|
      if list[i] <= pivot_value
        swap(list, i, cursor)
        cursor += 1
      end
    end
    swap(list, cursor, to)
    cursor
  end

  def self.pivot(list, from, to)
    samples = [from, from + (to-from)/2, to]
    samples.sort_by{|i| list[i]}[1] # use median of the three samples
  end

  def self.swap(list, i, j)
    list[i], list[j] = list[j], list[i]
  end

end
