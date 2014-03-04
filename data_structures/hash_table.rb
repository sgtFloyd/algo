require 'zlib' # for crc32 hash function

class HashTable

  def initialize(max_buckets=100)
    @max_buckets = max_buckets
    @num_entries = 0
    @_buckets = Array.new(@max_buckets)
  end

  def [](key)
    index = hash(key)
    bucket = @_buckets[index]
    return if bucket.nil?

    bucket.each do |k, v|
      return v if k == key
    end
    nil
  end

  def []=(key, val)
    index = hash(key)
    bucket = @_buckets[index]

    if bucket.nil?
      @_buckets[index] = [[key, val]]
      @num_entries += 1
    else
      for i in 0...bucket.length
        k, v = bucket[i]
        if k == key
          bucket[i] = [key, val]
          return val
        end
      end
      bucket << [key, val]
      @num_entries += 1
    end
    resize_buckets if load_factor > 3
    val
  end

private

  def hash(key)
    Zlib.crc32(key.to_s) % @max_buckets
  end

  def load_factor
    @num_entries.fdiv @max_buckets
  end

  def resize_buckets
    @max_buckets *= 2
    @num_entries = 0

    old_buckets = @_buckets
    @_buckets = Array.new(@max_buckets)
    old_buckets.each do |bucket|
      next unless bucket
      bucket.each{|k,v| self[k] = v}
    end
  end

end
