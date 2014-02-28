class Heap

  def initialize
    @_elements = []
  end

  def insert(element)
    @_elements.push(element)
    trickle_up(@_elements.size-1)
  end

  def peek
    @_elements.first
  end

  def pop
    root = @_elements.shift
    @_elements.unshift(@_elements.pop)
    trickle_down(0)
    root
  end

private

  def parent_node(i); (i-1) / 2; end
  def left_child(i);  (i*2) + 1; end
  def right_child(i); (i*2) + 2; end

  def root_node?(i); i == 0; end
  def leaf_node?(i)
    left_child(i) >= @_elements.size
  end

  def swap(i, j)
    @_elements[i], @_elements[j] =
      @_elements[j], @_elements[i]
  end

  def trickle_up(i)
    return if root_node?(i)
    parent = parent_node(i)
    if @_elements[i] > @_elements[parent]
      swap(i, parent)
      trickle_up(parent)
    end
  end

  def trickle_down(i)
    return if leaf_node?(i)
    max_child = [left_child(i), right_child(i)]
                  .reject{|c| c >= @_elements.size}
                  .max_by{|c| @_elements[c]}
    if @_elements[i] < @_elements[max_child]
      swap(i, max_child)
      trickle_down(max_child)
    end
  end

end
