
# 💼 Expense Tracker – Technical Datasheet

## 🎯 Project Objective

The goal of this project is to build a **personal expense manager** in C, capable of:
- Reading and validating a `.txt` file containing expense records;
- Dynamically saving each entry in memory;
- Allowing the user to **filter expenses** by category or time range;
- Displaying results clearly in the terminal;
- Exiting upon request, freeing all allocated memory.

---

## 🧱 Data Structure

### `t_tracker`

```c
typedef struct s_tracker {
    char date[11];          // Format: "YYYY-MM-DD"
    float amount;           // Expense amount
    char *category;         // Category (e.g., "food", "transport")
    char *description;      // Free description
    struct s_tracker *next; // Pointer to next node (linked list)
} t_tracker;
```

- Expenses are stored in a **dynamically allocated linked list**, ideal for managing a variable number of entries without wasting memory.
- Each node represents a single expense record.

---

## 📂 File Handling

- The input file is opened and verified via the `check_file()` function.
- It is read **line by line** with `get_next_line()`.
- Valid lines are split into components and stored using:
  - `check_line()`
  - `divide_and_save_infos()`
  - `save_infos_in_list()`
- Textual strings are duplicated dynamically using `ft_strdup()`.

---

## 🔄 Main Flow (`main()`)

1. Displays the **initial prompt** via `put_prompt_line()`.
2. Receives user input using `get_input()`:
   - `1` → Filter by category
   - `2` → Filter by time interval
   - `3` → Show all expenses
   - `exit` → Exit the program
3. Validates input with `check_input_1()` and `check_input_2()`.
4. Performs the **search** with `search()`, filtering and returning results.
5. Displays output with `print_res()`.
6. Finally, frees memory using `free_all()`.

---

## 🧠 Main Functions

| Function                 | Description                                                                 |
|--------------------------|-----------------------------------------------------------------------------|
| `check_file()`           | Opens the file and starts line-by-line reading                              |
| `save_infos_in_list()`   | Adds each valid line to the linked list                                     |
| `check_line()`           | Validates the syntax of the line                                            |
| `divide_and_save_infos()`| Splits line into date, amount, category, description                        |
| `get_filter_choice()`    | Asks the user which filter to apply                                         |
| `search()`               | Filters saved data based on user criteria                                   |
| `print_res()`            | Displays the results                                                        |
| `free_all()`             | Frees the entire list and allocated memory                                  |

---

## 📈 Dynamic Memory Management

- The list is created dynamically, avoiding allocating space for 1000 elements unnecessarily.
- A maximum of **1000 expenses** (`MAX_CONSULT = 1000`) is defined to avoid excessive memory usage.

---

## ⚙️ Utilities and Checks

- Helper functions include:
  - `ft_strtrim()` → to clean up whitespace and newline characters
  - `ft_strdup()` → to duplicate strings
  - `ft_strcasestr()` → case-insensitive string comparison
  - `ft_to_lower()` → convert strings to lowercase for comparison

---

## 📌 Final Considerations

The project adheres to the subject requirements and features a **clear, modular, and maintainable** structure:
- The choice of a **linked list** ensures flexibility and efficiency in data handling.
- The code is logically modularized, with good separation of concerns between reading, parsing, storing, and user interaction.

---

## 👩‍💻 Author

**Petra**  
_a 42 coding School student_
