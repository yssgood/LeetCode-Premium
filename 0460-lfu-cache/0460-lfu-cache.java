class Cache {
    int key;
    int value;
    int count; // 사용 빈도 (얼마나 자주 호출되었는가)
    Cache prev, next;

    public Cache(int key, int value) {
        this.key = key;
        this.value = value;
        this.count = 1; // 새로 추가된 캐시는 사용 빈도가 1
    }
}

class LFUCache {

    private final int capacity;
    private int size;
    private int minFreq;

    // key -> Cache 객체
    private Map<Integer, Cache> cacheMap;

    // 빈도수(freq) -> 해당 freq를 가진 캐시를 담는 LinkedHashSet
    private Map<Integer, LinkedHashSet<Cache>> freqMap;

    public LFUCache(int capacity) {
        this.capacity = capacity;
        this.size = 0;
        this.minFreq = 0;
        this.cacheMap = new HashMap<>();
        this.freqMap = new HashMap<>();
    }

    public int get(int key) {
        if (!cacheMap.containsKey(key)) return -1;

        Cache node = cacheMap.get(key);
        updateFrequency(node); // 사용 빈도 갱신
        return node.value;
    }

    public void put(int key, int value) {
        if (capacity == 0) return;

        // 이미 존재하는 key라면 value 업데이트 및 freq 증가
        if (cacheMap.containsKey(key)) {
            Cache node = cacheMap.get(key);
            node.value = value;
            updateFrequency(node);
            return;
        }

        // 새로 추가하는 경우
        if (size >= capacity) {
            // 가장 낮은 빈도(minFreq)의 LinkedHashSet에서 가장 오래된 Cache 제거
            LinkedHashSet<Cache> minFreqSet = freqMap.get(minFreq);
            Cache toRemove = minFreqSet.iterator().next();
            minFreqSet.remove(toRemove);
            if (minFreqSet.isEmpty()) freqMap.remove(minFreq);

            cacheMap.remove(toRemove.key);
            size--;
        }

        // 새로운 캐시 생성 및 등록
        Cache newNode = new Cache(key, value);
        cacheMap.put(key, newNode);
        freqMap.computeIfAbsent(1, k -> new LinkedHashSet<>()).add(newNode);
        minFreq = 1; // 새로 추가된 캐시는 freq=1
        size++;
    }

    private void updateFrequency(Cache node) {
        int oldFreq = node.count;
        LinkedHashSet<Cache> oldSet = freqMap.get(oldFreq);
        oldSet.remove(node);
        if (oldSet.isEmpty()) {
            freqMap.remove(oldFreq);
            if (oldFreq == minFreq) minFreq++; // 최소 빈도 갱신
        }

        node.count++;
        freqMap.computeIfAbsent(node.count, k -> new LinkedHashSet<>()).add(node);
    }
}
