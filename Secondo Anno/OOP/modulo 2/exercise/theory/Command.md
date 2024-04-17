In command pattern, the request is send to the `invoker` and invoker pass it to the encapsulated `command` object. Command object passes the request to the appropriate method of `Receiver` to perform the specific action. The client program create the receiver object and then attach it to the Command. Then it creates the invoker object and attach the command object to perform an action. Now when client program executes the action, it’s processed based on the command and receiver object.

We create a class `Command` 

```java
package com.journaldev.design.command;

public interface Command {

	void execute();
}
```

Now we need to create an implementation of that class. I don't got you the implementation of the `CloseFileCommand` and `OpenFileCommand`, but you can imagine it.

```java
package com.journaldev.design.command;

public class WriteFileCommand implements Command {

	private FileSystemReceiver fileSystem;
	
	public WriteFileCommand(FileSystemReceiver fs){
		this.fileSystem=fs;
	}
	@Override
	public void execute() {
		this.fileSystem.writeFile();
	}

}
```

Let's now create our command pattern example client program to use the system utility

```java
package com.journaldev.design.command;

public class FileSystemClient {

	public static void main(String[] args) {
		//Creating the receiver object
		FileSystemReceiver fs = FileSystemReceiverUtil.getUnderlyingFileSystem();
		
		//creating command and associating with receiver
		OpenFileCommand openFileCommand = new OpenFileCommand(fs);
		
		//Creating invoker and associating with Command
		FileInvoker file = new FileInvoker(openFileCommand);
		
		//perform action on invoker object
		file.execute();
		
		WriteFileCommand writeFileCommand = new WriteFileCommand(fs);
		file = new FileInvoker(writeFileCommand);
		file.execute();
		
		CloseFileCommand closeFileCommand = new CloseFileCommand(fs);
		file = new FileInvoker(closeFileCommand);
		file.execute();
	}

}
```