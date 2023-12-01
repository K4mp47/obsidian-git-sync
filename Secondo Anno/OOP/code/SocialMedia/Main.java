import java.util.*;

abstract class SocialMediaAction {
	private final String author;
	
	protected SocialMediaAction(String author) {
		this.author = author;
	}
	
	public boolean sameAction(SocialMediaAction action) {
		return author.equals(action.author);
	}
}

class Like extends SocialMediaAction {
  int postID;
  
  public Like(String author, int postID) {
    super(author);
    this.postID = postID;
  }
}

class SocialMediaActionWithText extends SocialMediaAction {
  String text;
  
  public SocialMediaActionWithText(String author, String text) {
    super(author);
    this.text = text;
  }
}

class Comment extends SocialMediaActionWithText {
  int commentID;
  
  public Comment(String author, String text, int commentID) {
    super(author, text);
    this.commentID = commentID;
  }
}

class Post extends SocialMediaActionWithText {
  int postID;
  
  public Post(String author, String text, int postID) {
    super(author, text);
    this.postID = postID;
  }
} 

public class Main {
  public static void main(String[] args) throws Exception {
    // Create a Like instance
    Like like = new Like("User123", 123);

    // Access inherited field
    System.out.println("Author: " + like.sameAction(like));
    // Access the new field in the Like class
  }  
}
