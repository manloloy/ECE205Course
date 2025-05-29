# `vi` Cheat Sheet for Beginners

Provides a beginner-friendly reference for using the `vi` text editor, a powerful and widely available editor in Unix/Linux environments. This cheat sheet focuses on navigation, editing, saving, and quitting — the core skills needed to start using `vi` effectively.

---

## Launching `vi`

```bash
vi filename
```

- Opens `filename` for editing. If the file does not exist, it will be created when saved.

---

## vi Modes

`vi` has multiple modes. The two primary ones are:

| Mode         | Description                             |
|--------------|-----------------------------------------|
| **Normal**   | Default mode for navigation and commands|
| **Insert**   | Mode for editing text                   |

To **enter insert mode**, press `i`.  
To **return to normal mode**, press `Esc`.

---

## Entering Insert Mode

| Command   | Description                    |
|-----------|--------------------------------|
| `i`       | Insert before cursor           |
| `I`       | Insert at the beginning of line|
| `a`       | Append after cursor            |
| `A`       | Append at end of line          |
| `o`       | Open new line below and insert |
| `O`       | Open new line above and insert |

---

## Saving and Quitting

| Command    | Description                            |
|------------|----------------------------------------|
| `:w`       | Save (write) the file                  |
| `:q`       | Quit                                   |
| `:wq`      | Save and quit                          |
| `:q!`      | Quit without saving                    |
| `:x`       | Save and quit (same as `:wq`)          |

Type these **after pressing `Esc`** to return to normal mode.

---

## Navigation (Normal Mode)

| Key        | Action                                |
|------------|----------------------------------------|
| `h`        | Move left                              |
| `l`        | Move right                             |
| `j`        | Move down                              |
| `k`        | Move up                                |
| `0`        | Move to beginning of line              |
| `^`        | Move to first non-whitespace character |
| `$`        | Move to end of line                    |
| `w`        | Move to next word                      |
| `b`        | Move back a word                       |
| `G`        | Go to end of file                      |
| `gg`       | Go to beginning of file                |
| `:n`       | Go to line `n`                         |

---

## Deleting Text

| Command    | Description                            |
|------------|----------------------------------------|
| `x`        | Delete character under cursor          |
| `dd`       | Delete current line                    |
| `ndd`      | Delete `n` lines                       |
| `d$`       | Delete to end of line                  |
| `D`        | Delete to end of line (same as `d$`)   |
| `dw`       | Delete to end of current word          |

---

## Undo and Redo

| Command   | Description            |
|-----------|------------------------|
| `u`       | Undo last change       |
| `U`       | Undo all changes on line|
| `Ctrl + r`| Redo undone change     |

---

## Copy, Paste, and Yank

| Command    | Description                            |
|------------|----------------------------------------|
| `yy`       | Copy (yank) current line               |
| `nyy`      | Yank `n` lines                         |
| `p`        | Paste after cursor                     |
| `P`        | Paste before cursor                    |
| `y$`       | Yank to end of line                    |

---

## Search and Replace

| Command                  | Description                              |
|--------------------------|------------------------------------------|
| `/text`                 | Search for `text` forward                 |
| `?text`                 | Search for `text` backward                |
| `n`                     | Repeat last search in same direction      |
| `N`                     | Repeat search in opposite direction       |
| `:%s/old/new/g`         | Replace all occurrences in file           |
| `:s/old/new/g`          | Replace all occurrences on current line   |

---

## Indentation

| Command    | Description                              |
|------------|------------------------------------------|
| `>>`       | Indent current line                      |
| `<<`       | Unindent current line                    |
| `n>>`      | Indent `n` lines                         |

---

## Marking and Jumping

| Command       | Description                          |
|---------------|--------------------------------------|
| `ma`          | Mark current location with label `a` |
| `'a`          | Jump to line of mark `a`             |
| `` `a ``      | Jump to exact cursor of mark `a`     |

---

## Visual Mode

| Command     | Description                           |
|-------------|---------------------------------------|
| `v`         | Start character-wise visual mode      |
| `V`         | Start line-wise visual mode           |
| `Ctrl + v`  | Start block-wise visual mode          |
| `d`, `y`, `>` | Use after selection to delete, yank, indent |

---

## Command-Line Mode Basics

Begin command-line mode with `:` from normal mode.

| Command        | Description                       |
|----------------|-----------------------------------|
| `:w filename`  | Save to a new file                |
| `:e filename`  | Open a new file                   |
| `:!command`    | Run a shell command               |
| `:r filename`  | Insert contents of file           |
| `:set nu`      | Show line numbers                 |
| `:set nonu`    | Hide line numbers                 |

---

## Example Session

```bash
cd ~
mkdir labs
cd labs
mkdir Lab01
cd Lab01
vi hello.c
```

Inside `vi`, press `i` and type:

```c
#include <stdio.h>

int main() {
    printf("Hello, world!\n");
    return 0;
}
```

Press `Esc`, then type:

```
:wq
```

Then compile and run:

```bash
gcc hello.c -o hello
./hello
```

---

## Final Tips

- Always press `Esc` to return to normal mode.
- Use `:help` inside `vi` for built-in documentation.
- Practice basic navigation and editing until it feels natural.

```bash
echo "Happy Editing with vi!"
```
