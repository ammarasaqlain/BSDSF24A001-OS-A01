## Feature-2 Report Questions

**1. Explain the linking rule in this part's Makefile: $(TARGET):$(OBJECTS). How does it differ from a Makefile rule that links against a library?**
This rule tells the compiler to take all the raw, individual object files (the `.o` files) and stitch them directly together to create the final executable program. It differs from a library linking rule because there is no middleman. When you link against a library, you have to pack the `.o` files into a single massive archive file first (like a `.a` or `.so` file), and then link that archive to your program using special flags. Direct linking just grabs the raw `.o` files straight from the folder.

**2. What is a git tag and why is it useful in a project? What is the difference between a simple tag and an annotated tag?**
A git tag is a permanent, unmoving bookmark placed on a specific commit (save file) in your project's timeline. It is extremely useful because it lets developers easily find stable versions of the software (like v1.0) without digging through hundreds of random saves. A simple tag is just a basic name pointing to a commit. An annotated tag is a full, permanent object stored in the Git database; it contains the creator's name, email, timestamp, and a detailed description message. 

**3. What is the purpose of creating a "Release" on GitHub? What is the significance of attaching binaries (like your client executable) to it?**
The purpose of a GitHub Release is to provide an official, packaged download page for a specific version of your software. Attaching binaries (like the compiled `client` executable) is absolutely critical because it allows end-users to just download the program and double-click it to run it immediately. If you do not attach the binary, users would be forced to download your raw source code, install a C compiler, and run the Makefile themselves just to use your app.

## Feature-3 Report Questions

**1. Compare the Makefile from Part 2 and Part 3. What are the key differences in the variables and rules that enable the creation of a static library?**
In Part 2, we just took all the `.o` files and directly linked them to make the executable. In Part 3, we had to add a completely new rule that uses the `ar` command to pack those `.o` files into a single `.a` library file first. Then, we updated the compiler rule to use the `-L` (library directory) and `-l` (library name) flags so it knows to link our new static library instead of raw object files.

**2. What is the purpose of the ar command? Why is ranlib often used immediately after it?**
The `ar` (archiver) command basically acts like a zip program; it bundles a bunch of loose `.o` object files into one massive static library file. `ranlib` is used right after it to build a searchable index (like a table of contents) for that library file, which helps the compiler find specific functions way faster without having to scan the whole file. 

**3. When you run nm on your client_static executable, are the symbols for functions like mystrlen present? What does this tell you about how static linking works?**
Yes, the symbols like `mystrlen` are physically present inside the executable. This proves that static linking literally copy-pastes the raw code directly out of the library and permanently injects it into the final program's binary file, meaning the program doesn't need the external library file anymore to run.

## Feature-4 Report Questions

**1. What happens if you run the dynamic client without setting LD_LIBRARY_PATH? Why?**
If you try to run it without setting `LD_LIBRARY_PATH`, the program immediately crashes and says it can't find the shared object file. This happens because Linux only checks its default system folders (like `/usr/lib`) for dynamic libraries. It has no idea our custom `lib/` folder even exists, so we have to use the `LD_LIBRARY_PATH` variable to manually point it there.

**2. What does the ldd command do? How does its output confirm that your executable is using the shared library?**
The `ldd` command basically just lists out all the dynamic libraries that a program needs to run. When we run it on our executable, it physically lists `libmyutils.so` and shows the exact path to our `lib/` folder, which proves our program is successfully linked to our custom shared library.

**3. Compare the nm output for mystrlen in Part 3 and Part 4. What does the difference signify?**
In Part 3 (static library), the `nm` command showed a `T` (Text) next to `mystrlen`, which meant the code was physically copied directly inside the executable file. But in Part 4 (dynamic library), it shows a `U` (Undefined). This proves the actual code isn't inside the executable anymore, and the program is just borrowing it from the `.so` file on the fly.
