## Feature-2 Report Questions

**1. Explain the linking rule in this part's Makefile: $(TARGET):$(OBJECTS). How does it differ from a Makefile rule that links against a library?**
This rule tells the compiler to take all the raw, individual object files (the `.o` files) and stitch them directly together to create the final executable program. It differs from a library linking rule because there is no middleman. When you link against a library, you have to pack the `.o` files into a single massive archive file first (like a `.a` or `.so` file), and then link that archive to your program using special flags. Direct linking just grabs the raw `.o` files straight from the folder.

**2. What is a git tag and why is it useful in a project? What is the difference between a simple tag and an annotated tag?**
A git tag is a permanent, unmoving bookmark placed on a specific commit (save file) in your project's timeline. It is extremely useful because it lets developers easily find stable versions of the software (like v1.0) without digging through hundreds of random saves. A simple tag is just a basic name pointing to a commit. An annotated tag is a full, permanent object stored in the Git database; it contains the creator's name, email, timestamp, and a detailed description message. 

**3. What is the purpose of creating a "Release" on GitHub? What is the significance of attaching binaries (like your client executable) to it?**
The purpose of a GitHub Release is to provide an official, packaged download page for a specific version of your software. Attaching binaries (like the compiled `client` executable) is absolutely critical because it allows end-users to just download the program and double-click it to run it immediately. If you do not attach the binary, users would be forced to download your raw source code, install a C compiler, and run the Makefile themselves just to use your app.
