require_relative '../data_structures/heap.rb'

class Heapsort

  def self.sort(list)
    heap = Heap.new
    list.each do |item|
      heap.insert(item)
    end
    result = []
    result.unshift heap.pop while heap.peek
    result
  end

end
