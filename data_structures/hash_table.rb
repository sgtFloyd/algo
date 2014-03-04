require 'zlib' # for crc32 hash function

class HashTable

  def initialize
    @_buckets = []
    @_array_size = 100
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
    else
      for i in 0...bucket.length
        k, v = bucket[i]
        if k == key
          bucket[i] = [key, val]
          return val
        end
        bucket << [key, val]
      end
    end
    val
  end

private

  def hash(key)
    Zlib.crc32(key.to_s) % @_array_size
  end

end
