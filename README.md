# 🧵 Parallel Merge Sort

This project implements **Parallel Merge Sort**, a multi-threaded version of the classic merge sort algorithm, which leverages concurrency to improve performance on large datasets.


---

## 📖 About

Merge sort is a divide-and-conquer sorting algorithm with a guaranteed time complexity of O(n log n). In this project, the sorting is executed in **parallel**, utilizing threads to sort divided subarrays simultaneously, hence reducing total execution time on multi-core processors.

This project demonstrates how to apply parallel programming techniques to optimize traditional algorithms.

---

## 🚀 Features

- Fast and efficient sorting of large datasets
- Utilizes **multi-threading / parallelism**
- Clean, modular code with comments
- Adjustable thread limits to test performance scaling

---

## 🛠️ Tech Stack

- Programming Language: **C++** 
- Parallelism: **std::thread**
- IDE: VS Code + Makefile

---

## 🔍 How It Works

1. The input array is recursively divided into halves.
2. If the size is below a threshold or thread limit is reached, sorting proceeds sequentially.
3. Otherwise, new threads are spawned for the left and right halves.
4. After both halves are sorted in parallel, they are merged.
5. The final result is a sorted array.

---

## 📊 Performance

| Input Size | Sequential Time | Parallel Time | Speedup |
|------------|------------------|----------------|---------|
| 10^5       | 150 ms           | 80 ms          | ~1.8x   |
| 10^6       | 1.4 s            | 0.7 s          | ~2x     |

*(Replace with your actual benchmark results)*

------image-------
<img width="1440" alt="Screenshot 2025-01-13 at 11 36 33 PM" src="https://github.com/user-attachments/assets/b4250d56-0888-42bf-bff0-9bbd3b6f8e47" />

## 📦 Usage

### 🧪 Run the Code

```bash
# If C++
g++ parallel_mergesort.cpp -o sort -pthread
./sort










