class Quicksort

  def self.sort(list, from=0, to=list.size-1)
    return list if to - from < 2
    pivot_index = partition(list, from, to)
    sort(list, from, pivot_index-1)
    sort(list, pivot_index+1, to)
    list
  end

  def self.partition(list, from, to)
    pivot_index = from # naïve!
    pivot_value = list[from]
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

  def self.swap(list, i, j)
    list[i], list[j] = list[j], list[i]
  end

end
