class MyCircularDeque {
private:
    list<int> deq;  // Using list instead of vector
    int cnt;        // Current number of elements
    int k;          // Maximum capacity
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        this->k = k;   // Assign capacity
        cnt = 0;       // Initialize count to 0
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (cnt == k) {
            return false; // If the deque is full, insertion fails
        }
        deq.push_front(value); // Insert at the front of the deque
        ++cnt;                 // Increment count
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (cnt == k) {
            return false; // If the deque is full, insertion fails
        }
        deq.push_back(value); // Insert at the rear of the deque
        ++cnt;                // Increment count
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (cnt == 0) {
            return false; // If the deque is empty, deletion fails
        }
        deq.pop_front();  // Remove the front element
        --cnt;            // Decrement count
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (cnt == 0) {
            return false; // If the deque is empty, deletion fails
        }
        deq.pop_back();   // Remove the last element
        --cnt;            // Decrement count
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (cnt == 0) {
            return -1; // If the deque is empty, return -1
        }
        return deq.front(); // Return the front element
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (cnt == 0) {
            return -1; // If the deque is empty, return -1
        }
        return deq.back(); // Return the last element
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return cnt == 0; // Return true if the deque is empty
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return cnt == k; // Return true if the deque is full
    }
};